#include "Character/CLASH_PlayerCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "CLASH_GameplayTag.h"

#include "Component/Input/CLASH_EnhancedInputComponent.h"
#include "DataAsset/Input/CLASH_InputConfig.h"
#include "GAS/CLASH_AbilitySystemComponent.h"
#include "Component/LockOn/LockOnComoponent.h"
#include "Component/UI/CLASH_UIComponent_Player.h"
#include "GAS/AttributeSet/CLASH_AttributeSet_Player.h"
#include "Component/Combat/CLASH_CombatComponent_Player.h"

ACLASH_PlayerCharacter::ACLASH_PlayerCharacter()
{
	PlayerCharacterInit();
}

void ACLASH_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACLASH_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	PlayerUIComponent->InitUIComponent(this);
}

void ACLASH_PlayerCharacter::PlayerCharacterInit()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->SocketOffset = FVector(0.0f, 20.0f, 80.0f);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritYaw = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = DEFAULT_WALK_SPEED;
	GetCharacterMovement()->MaxAcceleration = 500.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 500.f;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	GetCapsuleComponent()->SetCollisionProfileName("PlayerCapsuleCollision");

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	LockOnComponent = CreateDefaultSubobject<ULockOnComoponent>(TEXT("LockOnComponent"));
	PlayerUIComponent = CreateDefaultSubobject<UCLASH_UIComponent_Player>(TEXT("PlayerUIComponent"));
	PlayerCombatComponent = CreateDefaultSubobject<UCLASH_CombatComponent_Player>(TEXT("PlayerCombatComponent"));

	PlayerAttributeSet = CreateDefaultSubobject<UCLASH_AttributeSet_Player>(TEXT("PlayerAttributeSet"));
}

void ACLASH_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfig, TEXT("Forget to assgin a vaild data asset as input config"));

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC) { return; }

	ULocalPlayer* LocalPlayer = PC->GetLocalPlayer();
	if (!LocalPlayer) { return; }

	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	if (SubSystem)
	{
		SubSystem->AddMappingContext(InputConfig->DefaultMappingContext, 0);
	}

	UCLASH_EnhancedInputComponent* CLASH_EIC = CastChecked<UCLASH_EnhancedInputComponent>(PlayerInputComponent);
	CLASH_EIC->BindNativeInputAction(InputConfig, ClashGameplayTags::Input_Move, ETriggerEvent::Triggered, this, &ACLASH_PlayerCharacter::InputMove);
	CLASH_EIC->BindNativeInputAction(InputConfig, ClashGameplayTags::Input_Look, ETriggerEvent::Triggered, this, &ACLASH_PlayerCharacter::InputLook);

	CLASH_EIC->BindAbilityInputAction(InputConfig, this, &ACLASH_PlayerCharacter::InputAbilityInputPressed, &ACLASH_PlayerCharacter::InputAbilityInputReleased);
}

void ACLASH_PlayerCharacter::InputMove(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (MovementVector.Y != 0.0f)
	{
		const FVector ForwardDirection = MovementRotator.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.0f)
	{
		const FVector RightDirection = MovementRotator.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ACLASH_PlayerCharacter::InputLook(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.0f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
	if (LookAxisVector.Y != 0.0f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACLASH_PlayerCharacter::InputAbilityInputPressed(FGameplayTag InInputTag)
{
	if (!ClashASC) { return; }

	ClashASC->OnAbilityInputPressed(InInputTag);
	//Ability 작동;
}

void ACLASH_PlayerCharacter::InputAbilityInputReleased(FGameplayTag InInputTag)
{
	ClashASC->OnAbilityInputReleased(InInputTag);
	//Ability 취소 or 종료
}

UCLASH_CombatComponent* ACLASH_PlayerCharacter::GetCombatComponent() const
{
	return PlayerCombatComponent ? PlayerCombatComponent : nullptr;
}

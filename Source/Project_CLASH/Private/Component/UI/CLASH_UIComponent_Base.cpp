#include "Component/UI/CLASH_UIComponent_Base.h"

#include "Blueprint/UserWidget.h"

#include "UI/HUD/CLASH_HUD_Base.h"
#include "GAS/AttributeSet/CLASH_AttributeSet_Basic.h"
#include "Character/CLASH_BaseCharacter.h"

#include "DebugHelper.h"


UCLASH_UIComponent_Base::UCLASH_UIComponent_Base()
{
}

void UCLASH_UIComponent_Base::BeginPlay()
{
	Super::BeginPlay();
}

void UCLASH_UIComponent_Base::OnCurrentFocusChanged(const FOnAttributeChangeData& Data)
{
    if (!HUD || !ASC) { return; }

    const UCLASH_AttributeSet_Basic* CLASHAttribute_Base = ASC->GetSet<UCLASH_AttributeSet_Basic>();
    float Percent = CLASHAttribute_Base->GetFocus() / CLASHAttribute_Base->GetMaxFocus();
    HUD->UpdateFoucsBar(CLASHAttribute_Base->GetFocus() / CLASHAttribute_Base->GetMaxFocus());
}

void UCLASH_UIComponent_Base::SettingInitValue()
{
    if (!HUD || !ASC) { return; }

    // 집중력 게이지 초기값 부여//
    FOnAttributeChangeData InitFocusData;
    InitFocusData.NewValue = ASC->GetNumericAttribute(UCLASH_AttributeSet_Basic::GetFocusAttribute());
    OnCurrentFocusChanged(InitFocusData);
}

void UCLASH_UIComponent_Base::InitUIComponent(ACLASH_BaseCharacter* ClashCharacter)
{
	if (!ClashCharacter) { return; }

    APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
    HUD = Cast< UCLASH_HUD_Base>(CreateWidget<UUserWidget>(PC, HUDClass));
    HUD->AddToViewport();

    if (!HUD) { return; }

    if (IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(ClashCharacter))
    {
        ASC = ASInterface->GetAbilitySystemComponent();
        if (ASC)
        {
            ASC->GetGameplayAttributeValueChangeDelegate(UCLASH_AttributeSet_Basic::GetFocusAttribute()).AddUObject(this, &UCLASH_UIComponent_Base::OnCurrentFocusChanged);
        }
    }

    SettingInitValue();
}

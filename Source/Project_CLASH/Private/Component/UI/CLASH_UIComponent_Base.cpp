#include "Component/UI/CLASH_UIComponent_Base.h"

#include "Blueprint/UserWidget.h"

#include "UI/HUD/CLASH_HUD_Base.h"
#include "GAS/AttributeSet/CLASH_AttributeSet_Basic.h"
#include "Character/CLASH_BaseCharacter.h"


UCLASH_UIComponent_Base::UCLASH_UIComponent_Base()
{
}

void UCLASH_UIComponent_Base::BeginPlay()
{
	Super::BeginPlay();
}

void UCLASH_UIComponent_Base::OnCurrentFocusChanged(const FOnAttributeChangeData& Data)
{
    if (!ASC) { return; }

    const UCLASH_AttributeSet_Basic* CLASHAttribute_Base = ASC->GetSet<UCLASH_AttributeSet_Basic>();
    float Max = CLASHAttribute_Base->GetMaxFocus();
    float Current = Data.NewValue;

    if (Max <= 0) { return; }

    const float Percent = Current / Max;
    OnFoucsBarChanged.Broadcast(Percent);
}

void UCLASH_UIComponent_Base::CreateHUD()
{
}

void UCLASH_UIComponent_Base::SettingInitValue()
{
    FOnAttributeChangeData InitFocusData;
    InitFocusData.NewValue = ASC->GetNumericAttribute(UCLASH_AttributeSet_Basic::GetFocusAttribute());
    OnCurrentFocusChanged(InitFocusData);

    float WillCount = ASC->GetNumericAttribute(UCLASH_AttributeSet_Basic::GetMaxWillCountAttribute());
    OnWiilCountCreated.Broadcast(WillCount);
}

void UCLASH_UIComponent_Base::BindUpdage(UAbilitySystemComponent* InASC)
{
    if (!InASC) { return; }
    InASC->GetGameplayAttributeValueChangeDelegate(UCLASH_AttributeSet_Basic::GetFocusAttribute()).AddUObject(this, &UCLASH_UIComponent_Base::OnCurrentFocusChanged);
}

void UCLASH_UIComponent_Base::InitUIComponent(ACLASH_BaseCharacter* ClashCharacter)
{
	if (!ClashCharacter) { return; }

    CreateHUD();

    if (IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(ClashCharacter))
    {
        ASC = ASInterface->GetAbilitySystemComponent();
        BindUpdage(ASC);
    }
    SettingInitValue();
}
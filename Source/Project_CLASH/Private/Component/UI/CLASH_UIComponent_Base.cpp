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
    if (!HUD || !ASC) { return; }

    const UCLASH_AttributeSet_Basic* CLASHAttribute_Base = ASC->GetSet<UCLASH_AttributeSet_Basic>();
    float Percent = CLASHAttribute_Base->GetFocus() / CLASHAttribute_Base->GetMaxFocus();
    HUD->UpdateFoucsBar(Percent);
}

void UCLASH_UIComponent_Base::CreateHUD()
{
    
}

void UCLASH_UIComponent_Base::SettingInitValue()
{
    if (!HUD || !ASC) { return; }

    FOnAttributeChangeData InitFocusData;
    InitFocusData.NewValue = ASC->GetNumericAttribute(UCLASH_AttributeSet_Basic::GetFocusAttribute());
    OnCurrentFocusChanged(InitFocusData);

    float WillCount = ASC->GetNumericAttribute(UCLASH_AttributeSet_Basic::GetMaxWillCountAttribute());
    HUD->CreateWillBeads(WillCount);
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

    if (!HUD) { return; }

    if (IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(ClashCharacter))
    {
        ASC = ASInterface->GetAbilitySystemComponent();
        BindUpdage(ASC);
    }
    SettingInitValue();
}

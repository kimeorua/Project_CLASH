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

void UCLASH_UIComponent_Base::OnCurrentFocusChanged(float Percent)
{
    OnFoucsBarChanged.Broadcast(Percent);
}

void UCLASH_UIComponent_Base::CreateHUD()
{
}

void UCLASH_UIComponent_Base::SettingInitValue()
{
    const UCLASH_AttributeSet_Basic* CLASHAttribute_Base = ASC->GetSet<UCLASH_AttributeSet_Basic>();
    float Max = CLASHAttribute_Base->GetMaxFocus();
    float Current = CLASHAttribute_Base->GetFocus();

    OnCurrentFocusChanged(Current / Max);

    float WillCount = ASC->GetNumericAttribute(UCLASH_AttributeSet_Basic::GetMaxWillCountAttribute());
    OnWiilCountCreated.Broadcast(WillCount);
}

void UCLASH_UIComponent_Base::BindUpdage(UAbilitySystemComponent* InASC)
{
    if (!InASC) { return; }
    UCLASH_AttributeSet_Basic* CLASHAttribute_Base = const_cast<UCLASH_AttributeSet_Basic*>(InASC->GetSet<UCLASH_AttributeSet_Basic>());
    CLASHAttribute_Base->OnUpdateFoucsUI.AddDynamic(this, &UCLASH_UIComponent_Base::OnCurrentFocusChanged);
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
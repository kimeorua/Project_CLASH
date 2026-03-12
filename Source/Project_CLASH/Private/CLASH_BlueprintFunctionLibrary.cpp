#include "CLASH_BlueprintFunctionLibrary.h"
#include "Character/CLASH_BaseCharacter.h"
#include "Component/Interface/CLASH_OwnerInterface.h"

ACLASH_BaseCharacter* UCLASH_BlueprintFunctionLibrary::GetComponentOwner(const UActorComponent* Comp)
{
    if (Comp && Comp->GetClass()->ImplementsInterface(UCLASH_OwnerInterface::StaticClass()))
    {
        return ICLASH_OwnerInterface::Execute_GetOwnerCharacter(Comp);
    }
    return nullptr;
}
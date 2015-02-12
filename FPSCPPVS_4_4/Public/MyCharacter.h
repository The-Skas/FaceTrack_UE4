

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

/**
 * 
 */
UCLASS(config=Game)
class FPSCPPVS_4_4_API AMyCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	TSubobjectPtr<class USkeletalMeshComponent> MyMesh;
	
};

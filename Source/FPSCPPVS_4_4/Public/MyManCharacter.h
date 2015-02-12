

#pragma once

#include "GameFramework/Character.h"
#include "MyManCharacter.generated.h"

/**
 * 
 */
UCLASS(config = Game)
class FPSCPPVS_4_4_API AMyManCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()
		

	//UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	//TSubobjectPtr<class USkeletalMeshComponent> MyMesh;
	
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<class UCameraComponent> FirstPersonCameraComponent;
};

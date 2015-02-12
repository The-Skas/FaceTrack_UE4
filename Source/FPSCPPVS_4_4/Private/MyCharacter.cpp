

#include "FPSCPPVS_4_4.h"
#include "MyCharacter.h"


AMyCharacter::AMyCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	this->MyMesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("CharacterMesh1P"));
	this->MyMesh->AttachParent = CapsuleComponent;
}



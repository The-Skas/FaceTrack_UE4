

#include "FPSCPPVS_4_4.h"
#include "MyManCharacter.h"
#include <iostream>

AMyManCharacter::AMyManCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);


	
	// Create a CameraComponent	
	FirstPersonCameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = CapsuleComponent;
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera

	this->Mesh->SetMorphTarget(TEXT("Jaw_Down"), 1.0f);
	
	
}



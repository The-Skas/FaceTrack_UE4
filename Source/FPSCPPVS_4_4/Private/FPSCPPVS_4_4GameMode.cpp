// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "FPSCPPVS_4_4.h"
#include "FPSCPPVS_4_4GameMode.h"
#include "FPSCPPVS_4_4HUD.h"
#include "FPSCPPVS_4_4Character.h"

AFPSCPPVS_4_4GameMode::AFPSCPPVS_4_4GameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/MyCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSCPPVS_4_4HUD::StaticClass();
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyProject7.h"
/**
 * 
 */
USTRUCT()
struct FMorphTargetStruct
{
  GENERATED_USTRUCT_BODY()
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Morph Target");
  FString morphTarget;
  
  UPROPERT(EditAnywhere, BlueprintReadWrite, Category="Morph Target");
  float value;

};

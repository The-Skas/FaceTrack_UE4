// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "MorphTargetStruct.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYPROJECT7_API UMorphTargetStruct : public UUserDefinedStruct
{
	GENERATED_UCLASS_BODY()
  UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = morphTarget)
  FName morphTarget;
  
  UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = morphTarget)
  float value;
  
	
	
};

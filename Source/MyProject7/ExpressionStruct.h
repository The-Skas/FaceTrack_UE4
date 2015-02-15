// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MorphTargetStruct.h"
#include "Engine/UserDefinedStruct.h"
#include "ExpressionStruct.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYPROJECT7_API UExpressionStruct : public UUserDefinedStruct
{
	GENERATED_UCLASS_BODY()
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Facial Expression")
  TArray<UMorphTargetStruct*> morphTargets;
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Facial Expression")
  FString expressionName;
	
	
};
FRotator
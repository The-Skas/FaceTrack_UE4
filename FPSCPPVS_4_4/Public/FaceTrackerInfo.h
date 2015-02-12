#pragma once

#include "Vector2D.h"
#include "Vector.h"
#include "ObjectBase.h"
#include "FaceTrackerInfo.generated.h"
/**
USTRUCT can be constructed with different arguements.

For details refer to this link: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/Reference/Structs/index.html
*/

USTRUCT(BlueprintType)
struct FFaceTrackerInfo
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = FaceTrackerInfo)
	bool faceFound;
	
	/* Stores the x,y co-ordinate*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = FaceTrackerInfo)
	FVector2D facePosition2D;

	/*UFUNCTION(BlueprintCallable)
	void SetFaceFound(bool found)
	{
		faceFound = found;
	}

	UFUNCTION(BlueprintCallable)
	void SetFacePosition2D(FVector facePositionVec)
	{
		facePosition2D.X = facePositionVec.X;
		facePosition2D.Y = facePositionVec.Y;
	}
*/
};


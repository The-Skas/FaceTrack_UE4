#pragma once

#include "ObjectBase.h"
#include "OscDataElemStruct.h"
#include "OscDataStruct.generated.h"

/**
	USTRUCT can be constructed with different arguements.
	
	For details refer to this link: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/Reference/Structs/index.html
 */
USTRUCT(BlueprintType)
struct FOscDataStruct
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY()
    int32 Index;

    UPROPERTY()
    TArray<FOscDataElemStruct> Queue;

    FOscDataStruct() : Index(0)
    { }

    FOscDataElemStruct Pop()
    {
        const auto idx = std::max(Index, 0);
        if(idx < Queue.Num())
        {
            ++Index;
            return Queue[idx];
        }
        return FOscDataElemStruct();
    }
};

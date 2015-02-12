#pragma once

#include "GameFramework/Actor.h"
#include "OscReceiverInterface.h"
#include "OscDataStruct.h"
#include "OscReceiverActor.generated.h"


UCLASS()
class AOscReceiverActor : public AActor, public IOscReceiverInterface
{
    GENERATED_UCLASS_BODY()

    UPROPERTY(EditAnywhere, Category=OSC)
    FString AddressFilter;

    UFUNCTION(BlueprintImplementableEvent, Category=OSC)
    void OnOscReceived(const FName & Address, const FOscDataStruct & Data);

protected:

    virtual void BeginDestroy() override;
    
    virtual const FString & GetAddressFilter() override
    {
        return AddressFilter;
    }

    virtual void SendEvent(const FName & Address, const FOscDataStruct & Data) override
    {
        OnOscReceived(Address, Data);
    }
};

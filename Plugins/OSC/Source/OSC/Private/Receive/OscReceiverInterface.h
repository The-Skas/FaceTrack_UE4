#pragma once

#include "OscDataStruct.h"
#include "OscReceiverInterface.generated.h"


UINTERFACE(MinimalAPI)
class UOscReceiverInterface : public UInterface
{
    GENERATED_UINTERFACE_BODY()
};

class IOscReceiverInterface
{
    GENERATED_IINTERFACE_BODY()

    virtual const FString & GetAddressFilter();
    virtual void SendEvent(const FName & Address, const FOscDataStruct & Data);
};

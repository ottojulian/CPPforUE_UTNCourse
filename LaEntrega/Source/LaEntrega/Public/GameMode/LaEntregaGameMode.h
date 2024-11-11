// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Candado/CandadoBase.h"
#include "LlaveBase/LlaveBase.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LaEntregaGameMode.generated.h"

UCLASS(minimalapi)
class ALaEntregaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALaEntregaGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Candado Functions")
	ACandadoBase* CurrentLock;

	UFUNCTION(BlueprintImplementableEvent, Category = "Candado Functions")
	void AddItem(UTexture2D* image, E_Key keyType);
};




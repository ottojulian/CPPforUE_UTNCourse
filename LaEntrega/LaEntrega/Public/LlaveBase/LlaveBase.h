// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LlaveBase.generated.h"

UENUM(BlueprintType)
enum class E_Key : uint8 {
	Liberado UMETA(DisplayName = "Liberado"),
	Amuleto UMETA(DisplayName = "Amuleto"),
	Libro UMETA(DisplayName = "Libro"),
};

UCLASS()
class LAENTREGA_API ALlaveBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALlaveBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item")
	E_Key KeyType{ E_Key::Liberado };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item")
	UTexture2D* ItemImage;

};

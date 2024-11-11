// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "LlaveBase/LlaveBase.h"
#include "CandadoBase.generated.h"

UCLASS()
class LAENTREGA_API ACandadoBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACandadoBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Root Component")
	USceneComponent* CustomRootComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Candado Functions")
	bool interactionEnable;

	UFUNCTION(BlueprintCallable, Category = "Candado Functions")
	bool TryLlave(E_Key llave);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Candado Functions")
	E_Key llaveCorrecta;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Candado Functions")
	void OpenLock();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Candado Functions")
	UBoxComponent* BoxCollider;

	UFUNCTION()
	void OnBoxColliderBeginOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxColliderEndinOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

};

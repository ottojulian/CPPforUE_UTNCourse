// Fill out your copyright notice in the Description page of Project Settings.

#include "Candado/CandadoBase.h"
#include "LaEntrega/LaEntregaCharacter.h"
#include <GameMode/LaEntregaGameMode.h>

// Sets default values
ACandadoBase::ACandadoBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRootComponent"));
	RootComponent = CustomRootComponent;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));

	BoxCollider->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	BoxCollider->SetGenerateOverlapEvents(true);

	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ACandadoBase::OnBoxColliderBeginOverlap);
	BoxCollider->OnComponentEndOverlap.AddDynamic(this, &ACandadoBase::OnBoxColliderEndinOverlap);



}

// Called when the game starts or when spawned
void ACandadoBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACandadoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACandadoBase::OnBoxColliderBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor && (OtherActor != this)) {
		if (Cast <ALaEntregaCharacter>(OtherActor)) {
			interactionEnable = true;
			UE_LOG(LogTemp, Warning, TEXT("Overlap con %s"), *OtherActor->GetName());
			ALaEntregaGameMode* GM = Cast<ALaEntregaGameMode>(GetWorld()->GetAuthGameMode());
			if (GM) {
				GM->CurrentLock = this;
			}
		}
	}
}

void ACandadoBase::OnBoxColliderEndinOverlap(UPrimitiveComponent* OverlappedComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex){
	if (OtherActor && (OtherActor != this)) {
		if (Cast <ALaEntregaCharacter>(OtherActor)) {
			interactionEnable = false;
			UE_LOG(LogTemp, Warning, TEXT("End Overlap con %s"), *OtherActor->GetName());
			ALaEntregaGameMode* GM = Cast<ALaEntregaGameMode>(GetWorld()->GetAuthGameMode());
			if (GM) {
				GM->CurrentLock = nullptr;
			}
		}
	}
}

bool ACandadoBase::TryLlave(E_Key llave) {
	bool success = false;
	if (llaveCorrecta == llave) {
		OpenLock();
		success = true;
	}
	else {
		success = false;
		//Acá puede ir un mensaje que salga cuando se trata de usar una llave incorrecta
		

	}
	return success;
}
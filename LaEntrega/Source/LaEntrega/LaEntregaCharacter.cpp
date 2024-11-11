// Copyright Epic Games, Inc. All Rights Reserved.

#include "LaEntregaCharacter.h"
#include "LaEntregaProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <LlaveBase/LlaveBase.h>
#include <Candado/CandadoBase.h>
#include "GameMode/LaEntregaGameMode.h"



//////////////////////////////////////////////////////////////////////////


ALaEntregaCharacter::ALaEntregaCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	interactionDistance = 1000;
	enableCharacterControls = true;  
}

void ALaEntregaCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	FuncionCPP();
}


//////////////////////////////////////////////////////////////////////////// Input

void ALaEntregaCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		/* Lo de abajo está comentado para hacer que no se pueda saltar y la cámara esté fija, pero se pueda mirar a los alrededores*/

		//Jumping
		/*EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);*/

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ALaEntregaCharacter::Move);
		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ALaEntregaCharacter::Look);

		//Pickup
		EnhancedInputComponent->BindAction(PickUp, ETriggerEvent::Started, this, &ALaEntregaCharacter::PickUpObject);

		//Inventario
		EnhancedInputComponent->BindAction(Inventario, ETriggerEvent::Started, this, &ALaEntregaCharacter::OpenCloseInventario);

	}
}


//void ALaEntregaCharacter::OpenCloseInventario()
//{
//}

void ALaEntregaCharacter::Move(const FInputActionValue& Value)
{
	if (enableCharacterControls) {
		// input is a Vector2D
		FVector2D MovementVector = Value.Get<FVector2D>();

		if (Controller != nullptr)
		{
			// add movement 
			AddMovementInput(GetActorForwardVector(), MovementVector.Y);
			AddMovementInput(GetActorRightVector(), MovementVector.X);
		}
	}
}

void ALaEntregaCharacter::Look(const FInputActionValue& Value)
{

	if (enableCharacterControls) {

		// input is a Vector2D
		FVector2D LookAxisVector = Value.Get<FVector2D>();

		if (Controller != nullptr)
		{
			// add yaw and pitch input to controller
			AddControllerYawInput(LookAxisVector.X);
			AddControllerPitchInput(LookAxisVector.Y);
		}
	}
}

void ALaEntregaCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool ALaEntregaCharacter::GetHasRifle()
{
	return bHasRifle;
}

void ALaEntregaCharacter::FuncionCPP()									//Función que imprime por consola el texto entre comillas. Aparece en el OutputLog
{																		//en el engine
	UE_LOG(LogTemp, Warning, TEXT("ESTA ES LA FUNCION"));
}

void ALaEntregaCharacter::PickUpObject() {
	
	APlayerController* PC = Cast<APlayerController>(GetController());	//Variable creada para almacenar un objeto de tipo PlayerController, pero casteado
																		//con un template para cambiarlo de tipo Controller a PlayerController. Al almace
																		// narla así, puedo acceder a sus métodos a través de la variable que la contiene+

	if (PC) {	//PC es una variable que puede devolver nullPointer. El if interpreta ese tipo de valor como valor de verdad

		FVector CameraLocation;	//Vector de tres dimensiones con la ubicación de la cámara
		FRotator CameraRotator; //Vector rotador de tres dimensiones
		PC->GetPlayerViewPoint(CameraLocation, CameraRotator);	//Obtengo la referencia al centro donde está la cámara accediendo 
																//al método GetPlayerViewPoint

		FVector TraceStart = CameraLocation;
		FVector TraceEnd = TraceStart + CameraRotator.Vector() * interactionDistance;

		FHitResult HitResult;	//Crea el espacio de memoria de la variable para guardar los datos de un eventual hit result
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);

		bool seCreo = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
		if (seCreo) {

			DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 20.0f); //clases static, permite usar clases sin crear objetos?
			AActor* HitActor = HitResult.GetActor();
			//UE_LOG(LogTemp, Warning, TEXT("LineTraced"));
			UE_LOG(LogTemp, Warning, TEXT("%s"), *HitActor->GetName());
			ALlaveBase* llave = Cast<ALlaveBase>(HitActor);

			if (llave) {
				UE_LOG(LogTemp, Warning, TEXT("Es una llave"));
				ALaEntregaGameMode* GM = Cast <ALaEntregaGameMode>(GetWorld()->GetAuthGameMode());
				if (GM) {
					GM->AddItem(llave->ItemImage, llave->KeyType);
					UE_LOG(LogTemp, Warning, TEXT("Llave agregada: %s"), *llave->GetName());
					HitActor->Destroy();
					
				}

			}
			else {
				ACandadoBase* candado = Cast<ACandadoBase>(HitActor);
				if (candado) {
					if (candado->interactionEnable) {
						candado->TryLlave(E_Key::Liberado);
					}
					else {
						//UE_LOG(LogTemp,Warning,TEXT("falta la llave de %s"), *HitActor->GetName())
					}

				}
			}
		}

			//if (HitActor && HitActor->IsA(ObjetoAgarrableClass)) {

			//	UE_LOG(LogTemp, Warning, TEXT("Interactuable detectado"));
			//	AGM_LaEntregaBase* GM = Cast<AGM_LaEntregaBase>(GetWorld()->GetAuthGameMode());

			//	if (GM) {	
			//		
			//		UE_LOG(LogTemp, Warning, TEXT("GM Reference Casted"));
			//		GM->PruebaGM();
			//	}

			//	HitActor->Destroy();
			//}
	}


}
	



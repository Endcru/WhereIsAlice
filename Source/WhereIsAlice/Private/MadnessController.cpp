// Fill out your copyright notice in the Description page of Project Settings.


#include "MadnessController.h"
#include "MadnessEffect.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"

// Sets default values
AMadnessController::AMadnessController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMadnessController::BeginPlay()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		MainCharacter = PlayerController->GetPawn();
		if (MainCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player's Character Name: %s"), *MainCharacter->GetName());
		}
	}
	UMaterialParameterCollection* MPC = LoadObject<UMaterialParameterCollection>(nullptr, TEXT("/Game/Magic/PC_PostProcessData.PC_PostProcessData"));
	if (IsValid(MPC) && GetWorld())
	{
		MPCInstance = GetWorld()->GetParameterCollectionInstance(MPC);
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("MPC is not loaded or the world is unavailable"));
	}
	Super::BeginPlay();
	
}

// Called every frame
void AMadnessController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMadnessController::Madness(float MadnessLevel)
{
	// Activate  MadnessWorld
	if ((MadnessLevel >= MadnessWorldMadnessLevel) and (not MadnessWorldActive)) {
		MadnessWorldActive = true;
		if (IsValid(MainCharacter) and (MainCharacter->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_E_MadnessEffect(MainCharacter, MadnessLevel, MadnessWorldActive);
		}
		if (IsValid(SkyShub) and (SkyShub->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_ActivateSky(SkyShub);
		}
		if (IsValid(Sky) and (Sky->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_DeactivateSky(Sky);
		}
		if (IsValid(SkyLight) and (SkyLight->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_ChangeSkyType(SkyLight, MadnessWorldActive);
		}
	}
	// Deactivate  MadnessWorld
	else if ((MadnessLevel <= NormalWorldMadnessLevel) and (MadnessWorldActive)){
		MadnessWorldActive = false;
		if (IsValid(SkyShub) and (SkyShub->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_DeactivateSky(SkyShub);
		}
		if (IsValid(Sky) and (Sky->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_ActivateSky(Sky);
		}
		if (IsValid(SkyLight) and (SkyLight->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_ChangeSkyType(SkyLight, MadnessWorldActive);
		}
	}
	// Changing the color and power of the light
	if (IsValid(SkyLight) and (SkyLight->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
	{
		IMadnessEffect::Execute_ChangeSkyMadness(SkyLight, MadnessLevel);
	}
	// Madness Effect on Madness Items
	for (AActor* MadnessItem : MadnessItems)
	{
		if ((IsValid(MadnessItem) and MadnessItem->GetClass()->ImplementsInterface(UMadnessEffect::StaticClass())))
		{
			IMadnessEffect::Execute_E_MadnessEffect(MadnessItem, MadnessLevel, MadnessWorldActive);
		}
		else
		{
			const FString ItemName = IsValid(MadnessItem) ? MadnessItem->GetName() : TEXT("nullptr");
			UE_LOG(LogTemp, Warning, TEXT("MadnessItem '%s' does not implement the UMadnessEffect interface or is invalid"), *ItemName);
		}
	}
	// Madness World Effect Use
	if (IsValid(MPCInstance))
	{
		if (MadnessLevel >= MadnesEffectMadnessLevel) {
			MPCInstance->SetScalarParameterValue(FName("MadnessWorldEffect"), 1.0f);
		}
		else {
			MPCInstance->SetScalarParameterValue(FName("MadnessWorldEffect"), 0.0f);
		}
	}	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't get MPCInstance"));
	}
}

void AMadnessController::AddMadnessItem(AActor* MadnessItem)
{
	if (IsValid(MadnessItem))
	{
		MadnessItems.Add(MadnessItem);
	}
}
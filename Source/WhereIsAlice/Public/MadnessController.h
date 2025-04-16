// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MadnessController.generated.h"

UCLASS()
class WHEREISALICE_API AMadnessController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMadnessController();

	// DefaultSceneRoot
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// Level of Madness when Madness Effect apear
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	double MadnesEffectMadnessLevel = 80;

	// HDRIBackdrop with Shub-Niggurat Sky image
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	TObjectPtr<AActor> SkyShub;

	// HDRIBackdrop with Normal Sky image
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	TObjectPtr<AActor> Sky;

	// Madness World Activation Check
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	bool MadnessWorldActive = false;

	// Level of Madness when World Go to Madness
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	double MadnessWorldMadnessLevel = 70.0;

	// BP_Sky with skylight
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	TObjectPtr<AActor> SkyLight;

	// Array of Madness Objects
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	TArray<AActor*> MadnessItems;

	// Level of Madness when World Go to Normal World
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	double NormalWorldMadnessLevel = 20.0;

	// Main Character that player use
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	TObjectPtr<AActor> MainCharacter;
private:

	UMaterialParameterCollectionInstance* MPCInstance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Add madness item to array of madness items
	UFUNCTION(BlueprintCallable, CallInEditor)
	virtual void AddMadnessItem(AActor* MadnessItem);

	// Main function, changes world on madness level
	UFUNCTION(BlueprintCallable, CallInEditor)
	virtual void Madness(float MadnessLevel);
};





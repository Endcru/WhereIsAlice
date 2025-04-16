// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MadnessEffect.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMadnessEffect : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WHEREISALICE_API IMadnessEffect
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	/** Madness logic */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "По умолчанию")
	void E_MadnessEffect(double MadnessLevel, bool MadnessWorldActivated);
	virtual void E_MadnessEffect_Implementation(double MadnessLevel, bool MadnessWorldActivated) = 0;

	/** Activate madness sky */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ActivateSky();
	virtual void ActivateSky_Implementation() = 0;

	/** Deactivate madness sky */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DeactivateSky();
	virtual void DeactivateSky_Implementation() = 0;

	/** Change sky visual type */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ChangeSkyType(bool ShubSky);
	virtual void ChangeSkyType_Implementation(bool ShubSky) = 0;

	/** Change sky based on madness */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ChangeSkyMadness(double MadnessLevel);
	virtual void ChangeSkyMadness_Implementation(double MadnessLevel) = 0;
};


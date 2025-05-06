// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NeroAiCommands.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNeroAiCommands : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WHEREISALICE_API INeroAiCommands
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Madness logic */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Ai")
	bool GoForward();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Ai")
	bool RotateMonster(float zRotation);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Ai")
	bool AttackCheck();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Ai")
	bool UseFirstAbility();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Ai")
	float GetNoiseLevel();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Pawn")
	FVector GetPawnLocation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Pawn")
	float GetPawnRotation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Player")
	float GetMadness();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, CallInEditor, Category = "Player")
	float GetHealth();
};

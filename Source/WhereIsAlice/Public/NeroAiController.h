// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NeroAiController.generated.h"

UCLASS(Blueprintable)
class WHEREISALICE_API ANeroAiController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANeroAiController();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	float PlayerHP = 100.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	float PlayerMadness = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	float PlayerLocationX = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	float PlayerLocationY = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player")
	float PlayerRotationZ = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	bool AstralM1Block = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	float AstralM1LocationX = 0.0;
  
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	float AstralM1LocationY = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	float AstralM1RotationZ = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	bool AstralM2Block = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	float AstralM2LocationX = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	float AstralM2LocationY = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	float AstralM2RotationZ = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	bool Cultist1Block = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist1LocationX = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist1LocationY = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist1RotationZ = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist1NoisePoints = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Astral")
	bool Cultist2Block = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist2LocationX = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist2LocationY = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist2RotationZ = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cultist")
	float Cultist2NoisePoints = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Monsters")
	TArray<int> MonstersActions;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, CallInEditor)
	virtual void GetGameInf();
};

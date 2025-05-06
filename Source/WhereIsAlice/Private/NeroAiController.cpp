// Fill out your copyright notice in the Description page of Project Settings.


#include "NeroAiController.h"
#include "NeroAiCommands.h"

ANeroAiController::ANeroAiController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeroAiController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeroAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called every frame
void ANeroAiController::GetGameInf()
{

}

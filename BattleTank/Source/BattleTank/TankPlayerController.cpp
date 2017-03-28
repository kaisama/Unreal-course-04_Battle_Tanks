// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();

	if (!controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found player tank: %s"), *(controlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}




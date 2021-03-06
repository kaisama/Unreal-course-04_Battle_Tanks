// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

public:
	virtual float TakeDamage(float damageAmount, FDamageEvent const &damageEvent, AController *eventInstigator, AActor *damageCauser) override;

private:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealthPercent() const;

	FTankDelegate OnDeath;

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int32 MaxHealth = 100;
	
	UPROPERTY(VisibleAnywhere, Category = Setup)
	int32 CurrentHealth;

};

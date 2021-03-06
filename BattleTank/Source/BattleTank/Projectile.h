// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent *hitComponent, AActor *otherActor, UPrimitiveComponent *otherComponent, FVector normalImpulse, const FHitResult &hit);

	void OnTimerExpire();

public:
	void LaunchProjectile(float speed);

private:
	UProjectileMovementComponent *ProjectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UStaticMeshComponent *CollisionMesh = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = Components)
	UParticleSystemComponent *LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UParticleSystemComponent *ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
	URadialForceComponent *ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float DestroyDelay = 10;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float DamageAmount = 20;
};

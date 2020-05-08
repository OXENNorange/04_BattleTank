// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true; //TODO Should this really tick

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	
	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); ///dont worry about the error UE4 knows who "Barrel" is

	//calc the outlaunchvel
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace));

	if (bHaveAimSolution)
	{
		//auto TankName = GetOwner()->GetName().ToString();
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
	}
	//do nothing 

}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotation - BarrelRotation;

	Barrel->Elevate(DeltaRotator.Pitch); //setting this to DeltaRotator.Pitch make it not move, but numbers does make it move //video 151
	Turret->Rotate(DeltaRotator.Yaw); //setting this to DeltaRotator.Yaw make it not move //video 153
}



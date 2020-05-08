// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/Rotator.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Vector.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetTimeSeconds();

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds; 
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange; 
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationPerSecond, MaxElevationPerSecond); //stops the Turret from going past these parameters

	SetRelativeRotation(FRotator(Elevation, 0, 0));


}
// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetTimeSeconds();

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	auto Rotation = FMath::Clamp<float>(RawNewRotation, 0, 0); //stops the Turret from going past these parameters

	SetRelativeRotation(FRotator(0, Rotation, 0));


}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Rotator.h"
#include "Math/UnrealMathUtility.h"
#include "TankBarrel.generated.h"

/**
 * 
 */


UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed); //-1 max downward movement and +1 is max up movement


private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 5; 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationPerSecond = 40; //TODO

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationPerSecond = 0; //TODO
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //last include

/**
 * 
 */

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


private:
		ATank* GetControlledTank() const;

		virtual void BeginPlay() override;

		virtual void Tick(float DeltaTime) override;

		void AimTowardsCrosshair();

		//Return Out Parameter, true if hit landscape
		bool GetSightRayHitLocation(FVector& OutHitLocation) const;

		UPROPERTY(EditAnywhere)
			float CrosshairXLocation = 0.5;

		UPROPERTY(EditAnywhere)
			float CrosshairYLocation = 0.3333;

		UPROPERTY(EditAnywhere)
			float LineTraceRange = 1000000;

		bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};

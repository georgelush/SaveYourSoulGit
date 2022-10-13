// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SAVEYOURSOUL_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetShouldMove(bool ShouldMove);
	void SetRotationMove(bool DoingRotation);
		
private:
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotationSpeed;

	UPROPERTY(EditAnywhere)
	float MoveTime = 4;

	bool ShouldMove = false;
	bool DoingRotation = false;

	FVector OriginalLocation;

};
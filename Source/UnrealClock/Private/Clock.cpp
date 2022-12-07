// Fill out your copyright notice in the Description page of Project Settings.


#include "Clock.h"

const float AClock::secondsToDegrees = 6.0f, AClock::minutesToDegrees = 6.0f, AClock::hoursToDegrees = 30.0f;

// Sets default values
AClock::AClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FDateTime time = FDateTime::Now();

	float seconds = static_cast<float>(time.GetSecond());
	float minutes = static_cast<float>(time.GetMinute()) + seconds * 0.0166667f;
	float hours = static_cast<float>(time.GetHour12()) + minutes * 0.0166667f;

	HoursArm->SetActorRotation(FQuat(FRotator(0.0f, hours * hoursToDegrees, 0.0f)));
	MinutesArm->SetActorRotation(FQuat(FRotator(0.0f, minutes * minutesToDegrees, 0.0f)));
	SecondsArm->SetActorRotation(FQuat(FRotator(0.0f, seconds * secondsToDegrees, 0.0f)));
}


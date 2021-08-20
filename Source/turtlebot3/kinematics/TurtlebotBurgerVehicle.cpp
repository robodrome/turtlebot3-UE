// Copyright (C) Rapyuta Robotics


#include "TurtlebotBurgerVehicle.h"
#include "KinematicsMovementComponent.h"

#include "ROS2Node.h"
#include "Msgs/ROS2TFMsg.h"

ATurtlebotBurgerVehicle::ATurtlebotBurgerVehicle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MoveComponent = CreateDefaultSubobject<UKinematicsMovementComponent>(TEXT("MoveComponent"));
}


void ATurtlebotBurgerVehicle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void ATurtlebotBurgerVehicle::SetLinearVel(FVector Velocity)
{
	// We're assuming input is in meters, so convert to centimeters.
	GetMovementComponent()->Velocity = Velocity;
}


void ATurtlebotBurgerVehicle::SetAngularVel(FVector Velocity)
{
	UKinematicsMovementComponent *KinematicsMovementComponent = Cast<UKinematicsMovementComponent>(GetMovementComponent());

	if (KinematicsMovementComponent)
	{
		KinematicsMovementComponent->AngularVelocity = Velocity;
	}
}


void ATurtlebotBurgerVehicle::BeginPlay()
{
	Super::BeginPlay();

/*
	for (TFieldIterator<FProperty> PropIt(FTestData::StaticStruct()); PropIt; ++PropIt)
	{
		FProperty *Property = *PropIt;
		
		FString Name = Property->GetName();
		FString Type = Property->GetCPPType();

		UE_LOG(LogTemp, Warning, TEXT("*** Prop: %s (%s)"), *Name, *Type);
	}
*/
}


void ATurtlebotBurgerVehicle::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

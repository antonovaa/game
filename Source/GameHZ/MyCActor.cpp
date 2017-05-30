// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHZ.h"
#include "MyCActor.h"


// Sets default values
AMyCActor::AMyCActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMyCActor::GetWaivesConfiguration()
{
	int i = 0;
	for (TActorIterator<ACharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		FString asd = ActorItr->GetFullName();
		FVector2D d(2, 2);
		GEngine->AddOnScreenDebugMessage(-1, 55.f, FColor::White, asd,false,d);
		i++;
	}
	return int32(i);
}

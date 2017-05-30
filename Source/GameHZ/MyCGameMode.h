// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MyCGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GAMEHZ_API AMyCGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:	

	UFUNCTION(BlueprintCallable)
		void StartServ(int port);
};

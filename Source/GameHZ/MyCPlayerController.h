// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Runtime/Online/HTTP/Public/Http.h"

#include "Runtime/Online/HTTP/Public/Http.h"
#include "GameFramework/PlayerController.h"
#include "MyCPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class GAMEHZ_API AMyCPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite)
		int32 result;

	UPROPERTY(BlueprintReadWrite)
		int32 level;

	UPROPERTY(BlueprintReadWrite)
		FString id;

		void OnYourFunctionCompleted(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
		void LogginInGame_Or_Registration(FString login, FString password, bool RA, FString url);

	UFUNCTION(BlueprintCallable)
		FString get_id();

	UFUNCTION(BlueprintCallable)
		int32 get_result();
	
};

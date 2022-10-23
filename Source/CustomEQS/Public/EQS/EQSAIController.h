// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EQSAIController.generated.h"

class UEnvQuery;

/**
 * 
 */
UCLASS()
class CUSTOMEQS_API AEQSAIController : public AAIController
{
	GENERATED_BODY()
	
  UPROPERTY(EditAnywhere, Category = "AI")
  UEnvQuery* FindHidingSpotEQS;

  UFUNCTION(BlueprintCallable)
  void FindHidingSpot();

  void MoveToQueryResult(TSharedPtr<FEnvQueryResult> result);
};

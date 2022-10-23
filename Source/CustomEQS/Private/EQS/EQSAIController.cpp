// Fill out your copyright notice in the Description page of Project Settings.


#include "EQS/EQSAIController.h"

#include "EnvironmentQuery/EnvQueryManager.h"

void AEQSAIController::FindHidingSpot()
{
    FEnvQueryRequest HidingSpotQueryRequest = FEnvQueryRequest(FindHidingSpotEQS, GetPawn());
    HidingSpotQueryRequest.Execute(EEnvQueryRunMode::SingleResult, this, &AEQSAIController::MoveToQueryResult);
}

void AEQSAIController::MoveToQueryResult(TSharedPtr<FEnvQueryResult> result)
{
    if (result->IsSuccsessful()) {
        MoveToLocation(result->GetItemAsLocation(0));
    }
}


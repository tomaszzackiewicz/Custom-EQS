// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_SurfaceDetector.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMEQS_API UEnvQueryTest_SurfaceDetector : public UEnvQueryTest
{
	GENERATED_BODY()

public:

	UEnvQueryTest_SurfaceDetector();
	
	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

	virtual FText GetDescriptionDetails() const override;

private:
	float WaterLevel = 95.f;
};

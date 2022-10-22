// Fill out your copyright notice in the Description page of Project Settings.


#include "EQS/EnvQueryTest_SurfaceDetector.h"

#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "Kismet/KismetMathLibrary.h"

UEnvQueryTest_SurfaceDetector::UEnvQueryTest_SurfaceDetector()
{
	Cost = EEnvTestCost::High;
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
	SetWorkOnFloatValues(false);
}

void UEnvQueryTest_SurfaceDetector::RunTest(FEnvQueryInstance& QueryInstance) const
{
	BoolValue.BindData(QueryInstance.Owner.Get(), QueryInstance.QueryID);
	const bool bWantsInside = BoolValue.GetValue();


	for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
	{
		const FVector ItemLocation = GetItemLocation(QueryInstance, It.GetIndex());

		bool bInside = false;

		FHitResult RV_Hit(ForceInit);

		FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true);
		RV_TraceParams.bTraceComplex = true;
		RV_TraceParams.bReturnPhysicalMaterial = false;

		bool hit = GetWorld()->LineTraceSingleByChannel(
			RV_Hit,     //result
			ItemLocation,  //start
			ItemLocation - FVector(0, 0, 10000), //end
			ECC_Visibility, //collision channel
			RV_TraceParams
		);

		if (hit)
		{
			bInside = RV_Hit.Location.Z < WaterLevel;
		}

		It.SetScore(TestPurpose, FilterType, bInside, bWantsInside);
	}

}

FText UEnvQueryTest_SurfaceDetector::GetDescriptionDetails() const
{
	return DescribeBoolTestParams("inside water body");
}
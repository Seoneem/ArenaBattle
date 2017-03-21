// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABMyGameInstance.h"

UABMyGameInstance::UABMyGameInstance()
{
	//Super::Init();
	//UE_LOG(LogClass, Warning, TEXT("Game Instance Constructor Call!"));
	AB_LOG(Warning, TEXT("Constructor Call Start"));
	WebConnect = CreateDefaultSubobject<UWebConnect>(TEXT("WebConnect"));
	AB_LOG(Warning, TEXT("Constructor Call End"));
}

void UABMyGameInstance::Init()
{
	Super::Init();
	AB_LOG_CALLONLY(Warning);

	UClass* ClassInfo1 = WebConnect->GetClass();
	UClass* ClassInfo2 = UWebConnect::StaticClass();

	if (ClassInfo1 == ClassInfo2)
	{
		AB_LOG(Warning, TEXT("ClassInfo1 is same with ClassInfo2"));
	}

	for (TFieldIterator<UProperty> It(ClassInfo1); It; ++It)
	{
		AB_LOG(Warning, TEXT("Fied : %s, Type : %s"), *It->GetName(), *It->GetClass()->GetName());
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());

		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnect));
		}
	}
}

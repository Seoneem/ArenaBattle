// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "ABMyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	
	
};

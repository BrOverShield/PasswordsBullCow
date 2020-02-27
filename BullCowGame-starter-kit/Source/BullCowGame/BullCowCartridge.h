// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void PrintPreviousGuesses();
	void SetupGame();

	const std::vector<FString> Passwords = 
	{
		TEXT("123456"),
		TEXT("12345"),
		TEXT("123456789"),
		TEXT("password"),
		TEXT("iloveyou"),
		TEXT("1234567"),
		TEXT("princess"),
		TEXT("rockyou"),
		TEXT("12345678"),
		TEXT("abc123"),
		TEXT("nicole"),
		TEXT("daniel"),
		TEXT("babygirl"),
		TEXT("monkey")
	};

	// Your declarations go below!
	private:
		FString HiddenWord;
		int32 Lives;
	
};

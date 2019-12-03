// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Thank you for playing Bull Cows"));
    PrintLine(TEXT("Guess the 4 letter word")); // Magic number REMOVE!

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("cake"); // Move outside this function
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You won!"));
    }
    else
    {
        PrintLine(TEXT("You lost"));
    }
    
    
    FString Isogram = TEXT("oilpce");
    PrintLine(Input);
}
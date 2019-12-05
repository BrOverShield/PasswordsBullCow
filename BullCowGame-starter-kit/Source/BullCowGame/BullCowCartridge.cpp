// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Thank you for playing Bull Cows"));
    PrintLine(TEXT("Guess the 4 letter word")); // Magic number REMOVE!
    HiddenWord = TEXT("cake");

    // Set lives

    // Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    // Check if right number of characters
    // Check if isogram
    // 
    
    ClearScreen();
    FString HiddenWord = TEXT("cake"); // Move outside this function
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You won!"));
    }
    else
    {
        // Remove a life
        // if still alive
        PrintLine(TEXT("You lost"));
        PrintLine(TEXT("The hidden word was : "));
    }
    
    
    FString Isogram = TEXT("oilpce");
    PrintLine(Input);
}
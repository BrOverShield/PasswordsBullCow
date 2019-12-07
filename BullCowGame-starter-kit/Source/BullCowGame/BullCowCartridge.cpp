// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(FString::Printf(TEXT("The Hidden Word is : %s"), *HiddenWord)); //Debug Line

    PrintLine(TEXT("Thank you for playing Bull Cows"));
    PrintLine(TEXT("Guess the 4 letter word")); // Magic number REMOVE!
    

    
    // Set lives

    // Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    if (Input.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Wrong number of letters entered. Make sure you have 4 letters")); // Magic Number
    }
    // Check if isogram
    // 
    
    
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
        PrintLine(TEXT("The hidden word was : cake")); // Magic Word
    }
    
    
    FString Isogram = TEXT("oilpce");
    PrintLine(Input);
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cake");
    Lives = 4;
}
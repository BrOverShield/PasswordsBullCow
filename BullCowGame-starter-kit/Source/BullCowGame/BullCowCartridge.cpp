// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

FString HiddenWord;
bool bGameOver;
int Lives;
FString Isogram;

void UBullCowCartridge::BeginPlay() // When the game starts
{
    bGameOver = false;
    Lives = 4;
    Super::BeginPlay();
    SetupGame();
    PrintLine(FString::Printf(TEXT("The Hidden Word is : %s"), *HiddenWord)); //Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (bGameOver == true)
    {
        bGameOver = false;
        SetupGame();
    }
    else //Not Game Over
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("Wrong number of letters entered. Make sure you have 4 letters")); // Magic Number
        }
        else //Right number of letters
        {
            if (Input == HiddenWord)
            {
                PrintLine(TEXT("You won!"));
                bGameOver = true;
            }
            else // Not the right word
            {
                // Remove a life
                Lives --;
                // if still alive
                if (Lives == 0)
                {
                    PrintLine(TEXT("You lost"));
                    PrintLine(TEXT("The hidden word was : " + HiddenWord));
                }
                else //if still has lives left
                {
                    PrintLine(TEXT("WRONG! %i lives left!"), Lives);
                }
                PrintLine(TEXT("You wrote : " + Input));
            }
        }
    }
    
    
    
    
    
    
    
    
    
}

void UBullCowCartridge::SetupGame()
{
    // Prompt player for guess
    PrintLine(TEXT("Thank you for playing Bull Cows"));
    HiddenWord = TEXT("cake");
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
}
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include <vector>
#include <stdlib.h> 

FString HiddenWord;
bool bGameOver;
int Lives;
FString Isogram;
std::vector<FString> Guesses;

void UBullCowCartridge::BeginPlay() // When the game starts
{
    bGameOver = false;
    Guesses = {};
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
            PrintPreviousGuesses();
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
                // if lost
                if (Lives == 0)
                {
                    bGameOver = true;
                    PrintLine(TEXT("You lost"));
                    PrintLine(TEXT("The hidden word was : " + HiddenWord));
                }
                else //if still has lives left
                {
                    Guesses.push_back(Input);
                    PrintLine(TEXT("WRONG! %i lives left!"), Lives);
                    PrintPreviousGuesses();
                }
            }
        }
    }
}

void UBullCowCartridge::PrintPreviousGuesses()
{
    if (Guesses.size() != 0)
    {
        PrintLine(TEXT("You guessed : "));
        for (int i = 0; i < Guesses.size(); i++)
        {
            PrintLine(Guesses[i]);
        }
    }
}

void UBullCowCartridge::SetupGame()
{
    // Prompt player for guess
    PrintLine(TEXT("Thank you for playing Bull Cows"));
    int randomNumber = rand () % Passwords.size();
    HiddenWord = Passwords[randomNumber];
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    Lives = 4;
}
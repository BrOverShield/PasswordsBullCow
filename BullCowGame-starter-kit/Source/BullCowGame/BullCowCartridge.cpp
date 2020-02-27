// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include <vector>
#include <stdlib.h> 

FString HiddenWord;
bool bGameOver;
int32 Lives;
FString Isogram;
std::vector<FString> Guesses;

void UBullCowCartridge::BeginPlay() // When the game starts
{
    bGameOver = false;
    Guesses = {};
    Super::BeginPlay();
    SetupGame();
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
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::PrintPreviousGuesses()
{
    if (Guesses.size() != 0)
    {
        PrintLine(TEXT("You guessed : "));
        for (int32 i = 0; i < Guesses.size(); i++)
        {
            PrintLine(Guesses[i]);
        }
    }
}

void UBullCowCartridge::SetupGame()
{
    // Prompt player for guess
    PrintLine(TEXT("Thank you for playing Bull Cows"));
    
    do
    {
        int32 randomNumber = rand () % Passwords.size();
        HiddenWord = Passwords[randomNumber];
    }
    while(!IsIsogram(HiddenWord));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    Lives = HiddenWord.Len();
    PrintLine(TEXT("You have %i lives."), HiddenWord.Len());
    PrintLine(FString::Printf(TEXT("The Hidden Word is : %s"), *HiddenWord)); //Debug Line
    Guesses = {};
}

void UBullCowCartridge::EndGame()
{
    PrintLine(TEXT("You won!"));
    PrintLine(TEXT("The Password is : ") + HiddenWord);
    PrintLine(TEXT("Press any key to play again"));
    bGameOver = true;
}

int32 UBullCowCartridge::CheckForBulls(FString Guess)
{
    int32 bulls = 0;
    for (int32 i = 0; i < Guess.Len(); i++)
    {
        if (Guess[i] == HiddenWord[i])
        {
            bulls++;
        }
    }
    return bulls;
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Wrong number of letters entered. Make sure you have %i letters"), HiddenWord.Len()); // Magic Number
        PrintPreviousGuesses();
    }
    else //Right number of letters
    {
        if (Guess == HiddenWord)
        {
            EndGame();
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
                
                PrintLine(TEXT("Press any key to play again"));
            }
            else //if still has lives left
            {
                int32 bulls = CheckForBulls(Guess);
                FString Concatenation = TEXT("   ") + Guess + TEXT("(") + FString::FromInt(bulls) + TEXT(" bulls)");
                Guesses.push_back(Concatenation);
                PrintLine(TEXT("WRONG! %i lives left!"), Lives);
                PrintPreviousGuesses();
            }
        }
    }
}

bool UBullCowCartridge::IsIsogram(FString word)
{
    for (int32 i = 0; i < word.Len(); i++)
    {
        for (int32 j = i+1; j < word.Len(); j++)
        {
            if (word[i] == word[j])
            {
                return false;
            }
        }
    }
    return true;
}
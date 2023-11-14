//===================================================================================================
// Author: Tristan Mann
// Date: 10-06-2023
// Desc: Remaking the hangman application to work with any length of word using loops and functions.
//===================================================================================================

#include <iostream>
#include <string>

using namespace std;

string setWord()
{
	string wordToGuess;
	int length;

	cout << "Enter a word for the other player to guess: ";
	cin >> wordToGuess;
	length = wordToGuess.length();

	for (int let = 0; let < length; let++)
	{
		wordToGuess.at(let) = tolower(wordToGuess.at(let));
	}
	cout << "Your word is: " << wordToGuess << " It is " << length << " characters long." << endl;

	return wordToGuess;
}

int main()
{
	string word = setWord();
	string dashes = "";
	string wordGuess;
	string letGuess;

	bool wordGuessed = false;
	bool letterGuessed = false;

	int length = word.length();
	int guesslength;
	int turnsLeft = length;
	int numOfLets = 0;


	for (int turn = length; turn > 0; turn--)
	{
		dashes = dashes + "-";
	}

	while (wordGuessed == false)
	{


		cout << "You have " << turnsLeft << " turns left. Guess a letter: " << endl;
		cin >> letGuess;

		if (letGuess.length() == 1)
		{
			//Set guess to lowercase
			letGuess.at(0) = tolower(letGuess.at(0));

			for (int check = length - 1; check > -1; check--)
			{

				if (letGuess.at(0) == word.at(check))
				{
					letterGuessed = true;
					numOfLets++;

					if (letterGuessed = true)
					{

						cout << "You guessed the letter in the " << check << " position correct" << endl << endl;
						dashes.at(check) = letGuess.at(0);
						cout << dashes << endl;
					}

				}

			}
			if (numOfLets == 0)
			{
				cout << "You did not guess any letter correct." << endl << endl;
			}
		}
		else
		{
			cout << "You did not input a letter try again next turn." << endl << endl;
		}

		//cycle to the next turn in the order and reset numOfLets to keep track of letters guessed correctly.
		turnsLeft--;
		numOfLets = 0;

		cout << "Now take a guess at the word." << endl;
		cin >> wordGuess;
		guesslength = wordGuess.length();
		//Sets word guessed to lowercase
		for (int let = 0; let < guesslength; let++)
		{
			wordGuess.at(let) = tolower(wordGuess.at(let));
		}

		if (wordGuess == word)
		{
			cout << "You Guessed the word correctly with " << turnsLeft << " turns left. Congratulations!" << endl;
			wordGuessed = true;
		}
		else
		{
			cout << "You did not guess the word correctly." << endl << endl;
		}
	}
	return true;
}

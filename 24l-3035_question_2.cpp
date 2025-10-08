#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

const int MAX_TRIES = 7;

string selectRandomWord(const string& filename)
{
    ifstream fin(filename.c_str());
    if (!fin)
    {
        cout << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    int total = 0;
    string temp;
    while (fin >> temp)
    {
        total++;
    }
    fin.close();

    if (total == 0)
    {
        cout << "Error: The file is empty!" << endl;
        exit(1);
    }

    ifstream fin2(filename.c_str());
    string* words = new string[total];
    for (int i = 0; i < total; i++)
    {
        fin2 >> words[i];
    }
    fin2.close();

    srand(time(0));
    int randomIndex = rand() % total;
    string chosenWord = words[randomIndex];

    delete[] words;
    return chosenWord;
}

bool letterExists(const string& text, char ch)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ch)
        {
            return true;
        }
    }
    return false;
}

void displayProgress(const string& wordToGuess, const string& guessedChars)
{
    cout << "Word: ";
    for (int i = 0; i < wordToGuess.length(); i++)
    {
        char ch = tolower(wordToGuess[i]);
        if (letterExists(guessedChars, ch))
        {
            cout << ch << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordFound(const string& wordToGuess, const string& guessedChars)
{
    for (int i = 0; i < wordToGuess.length(); i++)
    {
        char ch = tolower(wordToGuess[i]);
        if (!letterExists(guessedChars, ch))
        {
            return false;
        }
    }
    return true;
}

void startGame(const string& secretWord)
{
    string guessedLetters = "";
    int chancesLeft = MAX_TRIES;
    char inputChar;

    cout << endl;
    cout << "Game Started!" << endl;
    cout << "You can make " << MAX_TRIES << " wrong guesses." << endl << endl;

    while (true)
    {
        displayProgress(secretWord, guessedLetters);
        cout << "Chances left: " << chancesLeft << endl;
        cout << "Enter a letter: ";
        cin >> inputChar;
        cout << endl;

        inputChar = tolower(inputChar);

        if (!isalpha(inputChar))
        {
            cout << "Invalid input. Please enter a letter only." << endl << endl;
            continue;
        }

        if (letterExists(guessedLetters, inputChar))
        {
            cout << "You already guessed that letter." << endl << endl;
            continue;
        }

        guessedLetters += inputChar;

        if (letterExists(secretWord, inputChar) || letterExists(secretWord, toupper(inputChar)))
        {
            cout << "Good guess!" << endl << endl;
        }
        else
        {
            chancesLeft--;
            cout << "Incorrect! Remaining chances: " << chancesLeft << endl << endl;
        }

        if (isWordFound(secretWord, guessedLetters))
        {
            cout << "You won! The word was: " << secretWord << endl;
            break;
        }

        if (chancesLeft == 0)
        {
            cout << "You lost! The correct word was: " << secretWord << endl;
            break;
        }
    }
}

int main()
{
    cout << "======== HANGMAN GAME ========" << endl;
    cout << "Category: Tech Companies" << endl;
    cout << "Guess the company name letter by letter!" << endl << endl;

    char playAgain = 'y';
    while (tolower(playAgain) == 'y')
    {
        string randomWord = selectRandomWord("tech_companies.txt");
        startGame(randomWord);

        cout << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    }

    cout << "Thanks for playing Hangman!" << endl;
    return 0;
}

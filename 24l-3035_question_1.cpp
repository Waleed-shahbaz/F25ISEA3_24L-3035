#include <iostream>
#include <string>
#include <conio.h>
#include <cctype>
using namespace std;

bool checkIfPalindrome(string text)
{
    int left = 0;
    int right = text.length() - 1;

    while (left < right)
    {
        while (left < right && !isalnum(text[left]))
        {
            left++;
        }

        while (left < right && !isalnum(text[right]))
        {
            right--;
        }

        if (tolower(text[left]) != tolower(text[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

void runPalindromeChecker()
{
    string userInput;
    char key;

    cout << "----------- PALINDROME CHECKER -----------" << endl;
    cout << "Press ESC key anytime to exit." << endl << endl;

    while (true)
    {
        userInput = "";
        cout << "Enter a word or phrase: ";

        while (true)
        {
            key = _getch();

            if (key == 27)
            {
                cout << endl << "Program terminated." << endl;
                return;
            }

            if (key == 13)
            {
                cout << endl;
                break;
            }

            userInput += key;
            cout << key;
        }

        if (checkIfPalindrome(userInput))
        {
            cout << "Result: It is a palindrome." << endl << endl;
        }
        else
        {
            cout << "Result: Not a palindrome." << endl << endl;
        }
    }
}
//
//int main1()
//{
//    runPalindromeChecker();
//    return 0;
//}

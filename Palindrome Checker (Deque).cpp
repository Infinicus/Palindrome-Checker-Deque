//Palindrome Checker using Deque, not case-sensitive.
#include <iostream>
#include <string.h>
#include <deque>

using namespace std;

void print_deque(deque<char> word_deque)                        //Prints members of deque
{
    deque<char>::iterator iteration;
    cout << "Deque: ";
    for (iteration = word_deque.begin(); iteration != word_deque.end(); ++iteration)
        cout << *iteration;
    cout << endl;
}

bool isPalindrome(deque<char> word_deque)                       //Function to check palindrome
{
    while(!word_deque.empty())
    {
        if(word_deque.size() == 1)                              //Middle character
            return true;
        if(word_deque.front() == word_deque.back())             //If front and back the same character
        {                                                       //Pops front and back
            word_deque.pop_back();
            word_deque.pop_front();
        }
        else                                                    //If not the same return false
            return false;
    }

    return true;                                                //If deque is empty then it is palindrome
}

char convertToUppercase(char character)                         //Function to convert to uppercase
{
    if(islower(character))
        return toupper(character);
}

int main()
{
    deque<char> word_deque;
    string word;

    cout << "Input your word: ";
    cin >> word;

    for(int i = 0; i < word.size(); i++)                        //Loops through the string length
    {
        if(word[i] != ' ')                                      //Ignore spaces
        {
            convertToUppercase(word[i]);                        //Converts character to uppercase
            word_deque.push_back(word[i]);                      //Pushes character to the back of deque
        }
    }

    print_deque(word_deque);                                    //Prints deque

    if(isPalindrome(word_deque))                                //Final checking
        cout << "\nWord is palindrome!" << endl;
    else
        cout << "\nWord is not palindrome!" << endl;
}

//Giga Hidjrika Aura Adkhy
//17/03/2022

#include <iostream>
#include <ctime>

using namespace std;

string generatePassword(int length) 
{
    const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charsLength = sizeof(chars) - 1;

    string password;
    for (int i = 0; i < length; i++) 
    {
        password += chars[rand() % charsLength];
    }

    return password;
}

int countWordOccurrences(const char* text, const char* word) 
{
    int count = 0;
    int textLength = strlen(text);
    int wordLength = strlen(word);

    for (int i = 0; i <= textLength - wordLength; i++) 
    {
        bool match = true;

        for (int j = 0; j < wordLength; j++)
        {
            if (text[i + j] != word[j]) 
            {
                match = false;
                break;
            }
        }
        if (match) 
        {
            count++;
        }
    }

    return count;
}

bool isValidEmail(const std::string& email) {
    int atPos = email.find('@');
    int dotPos = email.rfind('.');

    return atPos >= 0 and dotPos >= 0 and dotPos > atPos;
}

int main() 
{
    srand(time(0));

    // задача №1
    int passwordLength;
    cout << "Enter the length of the password: ";
    cin >> passwordLength;

    string password = generatePassword(passwordLength);

    cout << "Generated Password: " << password << "\n";

    //задача №3

    char inputText[1000];  
    char searchWord[100]; 

    cout << "Enter a text string: ";
    gets_s(inputText, sizeof(inputText));

    cout << "Enter a word to count: ";
    gets_s(searchWord, sizeof(searchWord));

    int occurrences = countWordOccurrences(inputText, searchWord);

    cout << "The word \"" << searchWord << "\" appears " << occurrences << " times in the text.\n";

    //задача №2

    string email;

    cout << "Enter an email address: ";
    cin >> email;

    if (isValidEmail(email)) 
    {
        cout << "The email is valid.\n";
    }
    else 
    {
        cout << "Invalid email format.\n";
    }

    return 0;
}

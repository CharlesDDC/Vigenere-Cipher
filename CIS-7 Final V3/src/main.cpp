#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encryption(string, string);
string decryption(string, string);

int main()
{
    char input;
    string text;
    string key;

    cout << "Enter 'E' if you want to Encrypt a message." << endl;
    cout << "Enter 'D' if you want to Decrypt a message." << endl;
    cout << "Enter anything else to quit." << endl;
    cin >> input;

    // clear leftover newline so getline works
    cin.ignore(10000, '\n');
    if (input == 'e' || input == 'E')
    {
        cout << "Enter any text you would like to encrypt (Alphabet Characters only): ";
        getline(cin, text);

        cout << "\nEnter any text that you would like to use as the key: ";
        getline(cin, key);

        cout << encryption(text, key);
    }
    else if (input == 'd' || input ==  'D')
    {
        cout << "Enter any text you would like to decrypt (Alphabet Characters only): ";
        getline(cin, text);

        cout << "\nEnter any text that you would like to use as the key: ";
        getline(cin, key);

        cout << decryption(text, key);
    }
    else
    {
        return 0;
    }
}

string encryption(string text, string key)
{
    if (key.size() == 0) return text;

    int keyIndex = 0;

    for (int i = 0; i < (int)text.size(); i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            char t = toupper((unsigned char)text[i]);

            // find next key character that is a letter
            while (keyIndex < (int)key.size() && !isalpha((unsigned char)key[keyIndex]))
            {
                keyIndex++;
                if (keyIndex >= (int)key.size()) keyIndex = 0;
            }

            char k = toupper((unsigned char)key[keyIndex]);

            text[i] = char('A' + ((t - 'A') + (k - 'A')) % 26);

            keyIndex++;
            if (keyIndex >= (int)key.size()) keyIndex = 0;
        }
        // else: keep spaces (and any non-letters) exactly the same
    }
    return text;
}

string decryption(string text, string key)
{
    if (key.size() == 0) return text;

    int keyIndex = 0;

    for (int i = 0; i < (int)text.size(); i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            char t = toupper((unsigned char)text[i]);

            // find next key character that is a letter
            while (keyIndex < (int)key.size() && !isalpha((unsigned char)key[keyIndex]))
            {
                keyIndex++;
                if (keyIndex >= (int)key.size()) keyIndex = 0;
            }

            char k = toupper((unsigned char)key[keyIndex]);

            int shift = (t - 'A') - (k - 'A');
            if (shift < 0) shift += 26;

            text[i] = char('A' + shift);

            keyIndex++;
            if (keyIndex >= (int)key.size()) keyIndex = 0;
        }
        // else: keep spaces (and any non-letters) exactly the same
    }
    return text;
}

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string ciphering(string text, string key);

int main(int argc, string argv[])
{   
    string key = argv[1];
    //check if we only get one key.
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    //check if the key contains only 26 characters.
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //check if the key contains only alphabetic characters.
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    //check if the key does not contain repeated characters.
    for (int i = 0; i < strlen(key); i++)
    {
        for (int n = i + 1 ; n < strlen(key); n++)
        {
            if (key[i] == key[n])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }
    
    string text = get_string("plaintext: ");
    string cipher_text = ciphering(text, key);
    printf("ciphertext: %s\n",cipher_text);
}

string ciphering(string text, string key)
{
     for (int i = 0; i < strlen(key); i++)
    {
        //making all the characters lowercase.
        if (isupper(key[i]) != 0) 
        {
            key[i] += 32;
        }
    }
    for (int i = 0; i < strlen(text); i++)
    {
        int key_num = 0;
        if (isupper(text[i]) != 0)
        {
            key_num = text[i];
            text[i] = key[key_num - 65] - 32;
            //-32 because all characters were converted to lowercase earlier.
        }
        else if (islower(text[i]) != 0) 
        {
            key_num = text[i];
            text[i] = key[key_num - 97];
        }
    }
    return text;
}

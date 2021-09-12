#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string encipher(int key_int, string text);

int main(int argc, string argv[])
{
    string key = argv[1];
    int key_int = atoi(argv[1]);
    
    //check if we only get one key.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //check if the key contains digits only.
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    
    string text = get_string("plaintext: ");       
    string cipher_text = encipher(key_int,text);
    printf("ciphertext: %s\n",cipher_text);
}

string encipher(int key_int, string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            float temporary_float = 0;
            if (isupper(text[i]) != 0)
            {
                //making the character value range from 0 to 25 rather than 65 to 90 to use the modulo.
                temporary_float = (text[i] + key_int - 65) % 26; //65 is A is ascii.
                //convert back to its value from 65 to 90.
                text[i] = temporary_float + 65; 
            }
            else if (islower(text[i]) != 0)
            {
                temporary_float = (text[i] + key_int - 97) % 26;
                text[i] = temporary_float + 97;
            }
        }

    }
    return text;
}

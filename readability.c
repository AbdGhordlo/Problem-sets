#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int Letters(string text);
int Words(string text);
int Sentences(string text);
float Grade(float letters, float words, float sentences);

int main(void)
{
    string text = get_string("Text: ");
    float letters = Letters(text);
    float words = Words(text);
    float sentences = Sentences(text);
    float grade = Grade(letters, words, sentences);
    
    if (grade > 16)
    {
        printf("\nGrade 16+\n");
    }
    else if (grade < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else
    {   
        printf("\nGrade %.0f\n",round(grade));        
    }
}
//How can i return muliple values with a single function?
//Get amount of letters
int Letters(string text)
{
    int total_letters = 0, total_sentences = 0, total_words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            total_letters ++;
        }
    }
    return total_letters;
}
//Get amount of sentences
int Sentences(string text)
{
    int total_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            total_sentences ++;
        }
    }
    return total_sentences;
}
//Get amount of words
int Words(string text)
{
    int total_words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            total_words ++;
        }
    }
    return total_words +=1;
}
//Coleman-Liau index
float Grade(float letters, float words, float sentences)
{
    //L is the average number of letters per 100 words in the text
    //S is the average number of sentences per 100 words in the text.
    float index = 0, L = 0, S = 0;
    L = letters / words * 100;
    S = sentences / words * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

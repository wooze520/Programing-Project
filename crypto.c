#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "crypto.h"

void encrypt(char *text, int shift) 
{
    for (int i = 0; text[i] != '\0'; i++) 
    {
        char c = text[i];
        if (isupper(c))
        {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        } 
        else if (islower(c)) 
        {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) 
    {
        char c = text[i];
        if (isupper(c)) 
        {
            text[i] = (c - 'A' - shift + 26) % 26 + 'A';
        } 
        else if (islower(c)) 
        {
            text[i] = (c - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

void saveToFile(const char *filename, char *text) 
{
    FILE *fp = fopen(filename, "w");
    if (!fp) 
    {
        printf("파일 저장 실패!\n");
        return;
    }
    fprintf(fp, "%s", text);
    fclose(fp);
    printf("파일 저장 완료!\n");
}

void loadFromFile(const char *filename, char *buffer) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) 
    {
        printf("파일 불러오기 실패!\n");
        return;
    }
    fgets(buffer, MAX_TEXT, fp);
    fclose(fp);
    printf("파일 불러오기 완료!\n");
}

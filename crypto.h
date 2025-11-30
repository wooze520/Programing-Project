#ifndef CRYPTO_H
#define CRYPTO_H

#define MAX_TEXT 1024

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void saveToFile(const char *filename, char *text);
void loadFromFile(const char *filename, char *buffer);

#endif

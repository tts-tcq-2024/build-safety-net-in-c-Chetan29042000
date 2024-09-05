#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Function to return the Soundex code for a given character (CCN = 1)
char getSoundexCode(char c) {
    c = toupper(c);
    if (strchr("BFPV", c)) return '1';
    if (strchr("CGJKQSXZ", c)) return '2';
    if (strchr("DT", c)) return '3';
    if (c == 'L') return '4';
    if (strchr("MN", c)) return '5';
    if (c == 'R') return '6';
    return '0'; // For A, E, I, O, U, H, W, Y
}

// Function to initialize the Soundex array and set the first letter (CCN = 1)
void initializeSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]); // First letter of the name in uppercase
}

// Function to check if a new code should be added to the Soundex string (CCN = 1)
int shouldAddCode(char code, char lastCode) {
    return (code != '0' && code != lastCode); // Avoid '0' and duplicates
}

// Helper function to handle adding characters to the Soundex code (CCN = 2)
void addSoundexCode(char *soundex, int *sIndex, char code) {
    soundex[(*sIndex)++] = code;
}

// Function to process the remaining characters in the name (CCN = 3)
void processName(const char *name, char *soundex, int len) {
    int sIndex = 1;
    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (shouldAddCode(code, soundex[sIndex - 1])) {
            addSoundexCode(soundex, &sIndex, code);
        }
    }
    soundex[sIndex] = '\0'; // Terminate string at current index (for safety)
}

// Function to fill remaining positions with '0' to meet the 4-character Soundex format (CCN = 1)
void fillWithZeros(char *soundex) {
    int sIndex = strlen(soundex);
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0'; // Ensure string is properly terminated
}

// Main function that uses the helper functions to generate the complete Soundex code (CCN = 2)
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    initializeSoundex(name, soundex);
    processName(name, soundex, len);
    fillWithZeros(soundex);
}

#endif // SOUNDEX_H

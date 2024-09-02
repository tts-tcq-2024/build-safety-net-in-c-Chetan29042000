#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

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

int shouldAddCode(char code, char previousCode) {
    return code != '0' && code != previousCode;
}

void fillRemainingWithZeros(char *soundex, int *sIndex) {
    while (*sIndex < 4) {
        soundex[(*sIndex)++] = '0';
    }
    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    int len = strlen(name);

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (shouldAddCode(code, soundex[sIndex - 1])) {
            soundex[sIndex++] = code;
        }
    }

    fillRemainingWithZeros(soundex, &sIndex);
}

#endif // SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Define the mapping for Soundex codes
const char soundexMapping[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A-J 
    '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K-T
    '0', '1', '0', '2', '0', '2'  // U-Z
};

// Function to get the Soundex code for a character
char getSoundexCode(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexMapping[c - 'A']; // Map letter to code
    }
    return '0'; // For non-alphabet characters
}

void fillRemainingWithZeros(char *soundex, int *sIndex) {
    while (*sIndex < 4) {
        soundex[(*sIndex)++] = '0'; // Fill remaining with zeros
    }
    soundex[4] = '\0'; // Null terminate the string
}

void addCharacterIfValid(char code, char previousCode, char *soundex, int *sIndex) {
    if (shouldAddCode(code, previousCode)) {
        soundex[(*sIndex)++] = code;
    }
}

void processCharacter(const char *name, char *soundex, int *sIndex, int len) {
    for (int i = 1; i < len && *sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        addCharacterIfValid(code, soundex[*sIndex - 1], soundex, sIndex);
    }
}


void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]); // Set the first letter
    int sIndex = 1;
    int len = strlen(name);

    processNameCharacters(name, soundex, &sIndex, len);
    fillRemainingWithZeros(soundex, &sIndex);
}

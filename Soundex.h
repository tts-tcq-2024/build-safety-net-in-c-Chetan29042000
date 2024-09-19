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

// Function to fill the remaining Soundex string with zeros
void fillRemainingWithZeros(char *soundex, int *sIndex) {
    while (*sIndex < 4) {
        soundex[(*sIndex)++] = '0'; // Fill remaining positions with zeros
    }
    soundex[4] = '\0'; // Null-terminate the Soundex string
}

// Function to add a character to the Soundex code if it's valid
void addCharacterIfValid(char code, char previousCode, char *soundex, int *sIndex) {
    if (code != '0' && code != previousCode) { // Check if the code should be added
        soundex[(*sIndex)++] = code;
    }
}

// Function to process the remaining characters in the name
void processCharacter(const char *name, char *soundex, int *sIndex, int len) {
    for (int i = 1; i < len && *sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        addCharacterIfValid(code, soundex[*sIndex - 1], soundex, sIndex);
    }
}

// Function to generate the Soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]); // Set the first letter of the Soundex code
    int sIndex = 1; // Start index for the Soundex code
    int len = strlen(name); // Length of the input name

    processCharacter(name, soundex, &sIndex, len); // Process the remaining characters in the name
    fillRemainingWithZeros(soundex, &sIndex); // Ensure the Soundex code has 4 characters
}

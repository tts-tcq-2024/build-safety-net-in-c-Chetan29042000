#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "Soundex.h"

// Function to compare expected and actual Soundex codes
void verifySoundex(const char *input, const char *expected) {
    char soundex[5];
    generateSoundex(input, soundex);
    assert(strcmp(soundex, expected) == 0);
    printf("Test passed for input: %s -> %s\n", input, soundex);
}

// Test case function for typical names
void test_typicalNames() {
    verifySoundex("Robert", "R163");
    verifySoundex("Ashcraft", "A261");
    verifySoundex("Tymczak", "T520");
}

// Test case function for edge cases
void test_edgeCases() {
    verifySoundex("A", "A000");     // Single character name
    verifySoundex("", "0000");      // Empty string
    verifySoundex("Euler", "E460"); // Starts with a vowel
}

// Test case function for names with non-alphabetic characters
void test_specialCharacters() {
    verifySoundex("B@rton", "B635");    // Name with special character '@'
    verifySoundex("O'Connor", "O256");  // Name with apostrophe
}

// Main function to run all test cases
void test_generateSoundex() {
    test_typicalNames();
    test_edgeCases();
    test_specialCharacters();
    printf("All tests for generateSoundex passed!\n");
}

int main() {
    test_generateSoundex();
    return 0;
}

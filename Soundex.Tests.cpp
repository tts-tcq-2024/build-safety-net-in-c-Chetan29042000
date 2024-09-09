#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
// //AAA
//   char soundex[5];
//   generateSoundex("AX", soundex);
//   ASSERT_STREQ(soundex,"A200");
 
// generateSoundex("Ashcraft", soundex);
//   ASSERT_STREQ(soundex,"A261");
 
// generateSoundex("Rupert", soundex);
//   ASSERT_STREQ(soundex,"R163");
 
// }


void verifySoundex(const char *input, const char *expected) {
    char soundex[5];
    generateSoundex(input, soundex);
    assert(strcmp(soundex, expected) == 0);
    printf("Test passed for input: %s -> %s\n", input, soundex);
}

// Test typical names
void test_typicalNames() {
    verifySoundex("Robert", "R163");    // Common name
    verifySoundex("Ashcraft", "A261");  // Name with different consonants
    verifySoundex("Tymczak", "T522");   // Name with similar consonants
    verifySoundex("Washington", "W252");// Common surname
}

// Test edge cases
void test_edgeCases() {
    verifySoundex("A", "A000");         // Single character
    verifySoundex("", "0000");          // Empty string
    verifySoundex("Euler", "E460");     // Starts with vowel
    verifySoundex("Lee", "L000");       // Short name with no changes
    verifySoundex("Pneumonia", "P555"); // Starts with silent letters
}

// Test names with non-alphabet characters
void test_specialCharacters() {
    verifySoundex("B@rton", "B635");    // Name with special character '@'
    verifySoundex("O'Connor", "O256");  // Name with apostrophe
    verifySoundex("D'Artagnan", "D632");// Name with apostrophe and multiple names
}

// Test names with repeating characters
void test_repeatingCharacters() {
    verifySoundex("Lloyd", "L300");     // Name with repeating 'L'
    verifySoundex("Addams", "A352");    // Name with repeating 'D'
}

int main() {
    test_typicalNames();
    test_edgeCases();
    test_specialCharacters();
    test_repeatingCharacters();
    return 0;
}

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

void generateSoundex(const char *name, char *soundex);
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

int main() {
    test_typicalNames();
    return 0;
}

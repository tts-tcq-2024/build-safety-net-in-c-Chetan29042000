#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Testcase 1: Common Name Soundex Conversion
TEST(SoundexTestsuite, HandleCommonName) {
    char soundex[5];
    generateSoundex("Robert", soundex);
    ASSERT_STREQ(soundex, "R163");
}

// Testcase 2: Name with Different Consonants Soundex Conversion
TEST(SoundexTestsuite, HandleNameWithDifferentConsonants) {
    char soundex[5];
    generateSoundex("Ashcraft", soundex);
    ASSERT_STREQ(soundex, "A261");
}

// Testcase 3: Single Character Name Soundex Conversion
TEST(SoundexTestsuite, HandleSingleCharacterName) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}

// Testcase 4: Name Starting with a Vowel Soundex Conversion
TEST(SoundexTestsuite, HandleNameStartingWithVowel) {
    char soundex[5];
    generateSoundex("Euler", soundex);
    ASSERT_STREQ(soundex, "E460");
}

// Testcase 5: Short Name with No Changes Soundex Conversion
TEST(SoundexTestsuite, HandleShortNameWithNoChanges) {
    char soundex[5];
    generateSoundex("Lee", soundex);
    ASSERT_STREQ(soundex, "L000");
}

// Testcase 6: Name with Special Character '@' in Soundex Conversion
TEST(SoundexTestsuite, HandleNameWithSpecialCharacter) {
    char soundex[5];
    generateSoundex("B@rton", soundex);
    ASSERT_STREQ(soundex, "B635");
}

// Testcase 7: Name with Repeating Letters Soundex Conversion
TEST(SoundexTestsuite, HandleNameWithRepeatingLetters) {
    char soundex[5];
    generateSoundex("Addams", soundex);
    ASSERT_STREQ(soundex, "A352");
}

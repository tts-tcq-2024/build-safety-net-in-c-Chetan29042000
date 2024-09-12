#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 char soundex[5];
 // Testcase 1: Common name
 generateSoundex("Robert", soundex); 
 ASSERT_STREQ(soundex,"R163");
 
 // Testcase 2: Name with different consonants
 generateSoundex("Ashcraft", soundex);
 ASSERT_STREQ(soundex,"A261");
 
 // Testcase 3: Single character
 generateSoundex("A", soundex);
 ASSERT_STREQ(soundex,"A000");

 // Testcase 4: name Starts with vowel
 generateSoundex("Euler", soundex);
 ASSERT_STREQ(soundex,"E460");
 
// Testcase 5: Short name with no changes
 generateSoundex("Lee", soundex);
 ASSERT_STREQ(soundex,"L000");

 // Testcase 6: Name with special character '@'
 generateSoundex("B@rton", soundex);
 ASSERT_STREQ(soundex,"B635");

 // Testcase 7: Name with apostrophe
 generateSoundex("O'Connor", soundex);
 ASSERT_STREQ(soundex,"O256");

 // Testcase 8: Name with apostrophe and multiple name
 generateSoundex("D'Artagnan", soundex);
 ASSERT_STREQ(soundex,"D632");


 // Testcase 9: Name with repeating character
 generateSoundex("Addams", soundex);
 ASSERT_STREQ(soundex,"A352");
 
}

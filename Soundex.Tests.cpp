#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 char soundex[5];
 // Common name
 generateSoundex("Robert", soundex); 
 ASSERT_STREQ(soundex,"R163");
 
 // Name with different consonants
 generateSoundex("Ashcraft", soundex);
 ASSERT_STREQ(soundex,"A261");
 
 // Single character
 generateSoundex("A", soundex);
 ASSERT_STREQ(soundex,"A000");

 // Starts with vowel
 generateSoundex("Euler", soundex);
 ASSERT_STREQ(soundex,"E460");
 
// Short name with no changes
 generateSoundex("Lee", soundex);
 ASSERT_STREQ(soundex,"L000");

 // Name with special character '@'
 generateSoundex("B@rton", soundex);
 ASSERT_STREQ(soundex,"B635");

 // Name with apostrophe
 generateSoundex("O'Connor", soundex);
 ASSERT_STREQ(soundex,"O256");

 // Name with apostrophe and multiple names
 generateSoundex("D'Artagnan", soundex);
 ASSERT_STREQ(soundex,"D632");


 // Name with repeating 'D'
 generateSoundex("Addams", soundex);
 ASSERT_STREQ(soundex,"A352");
 
}

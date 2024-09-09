#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
 
generateSoundex("Ashcraft", soundex);
  ASSERT_STREQ(soundex,"A261");
 
generateSoundex("Rupert", soundex);
  ASSERT_STREQ(soundex,"R163");
 
}

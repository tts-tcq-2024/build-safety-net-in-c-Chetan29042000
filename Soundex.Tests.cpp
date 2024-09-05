#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_generateSoundex() {
    char soundex[5];

    // Test case 1: Simple name
    generateSoundex("Robert", soundex);
    assert(strcmp(soundex, "R163") == 0);

    // Test case 2: Another name
    generateSoundex("Ashcraft", soundex);
    assert(strcmp(soundex, "A261") == 0);

    // Test case 3: Name with similar sounding characters
    generateSoundex("Tymczak", soundex);
    assert(strcmp(soundex, "T520") == 0);

    // Test case 4: Single character name
    generateSoundex("A", soundex);
    assert(strcmp(soundex, "A000") == 0);

    // Test case 5: Empty string (should just return "0000")
    generateSoundex("", soundex);
    assert(strcmp(soundex, "0000") == 0);

    printf("All tests for generateSoundex passed!\n");
}

int main() {
    test_generateSoundex();
    return 0;
}

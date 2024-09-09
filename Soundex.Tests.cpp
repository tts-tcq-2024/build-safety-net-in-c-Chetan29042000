#include <stdio.h>
#include <string.h>
#include <assert.h>

void testSoundex(const char *name, const char *expected) {
    char soundex[5];
    generateSoundex(name, soundex);
    assert(strcmp(soundex, expected) == 0);
    printf("Test passed: %s -> %s\n", name, soundex);
}

void runTests() {
    // Test cases with common names
    testSoundex("Robert", "R163");  // R:1, B:1 (skip), T:3, Filler: 000
    testSoundex("Rupert", "R163");  // R:1, P:1 (skip), T:3, Filler: 000
    testSoundex("Rubin", "R150");   // R:1, B:1 (skip), N:5, Filler: 000
    testSoundex("Ashcraft", "A261"); // A:0, S:2, C:2 (skip), R:6, T:3, Filler: 0
    testSoundex("Tymczak", "T522"); // T:3, M:5, C:2, Z:2, Filler: 0

    // Edge cases
    testSoundex("Pfister", "P236"); // P:1, F:1 (skip), S:2, T:3, R:6
    testSoundex("Honeyman", "H555"); // H:0 (skip), N:5, M:5, Filler: 00
    testSoundex("Jackson", "J250"); // J:2, C:2, K:2, N:5, Filler: 0
    testSoundex("T", "T000");       // Single character, filler: 000

    // Test cases with different character cases
    testSoundex("Washington", "W252"); // W:0 (skip), S:2, H:0 (skip), N:5, G:2, T:3
    testSoundex("Lee", "L000");        // L:4, E:0 (skip), Filler: 000
    testSoundex("O'Conner", "O256");   // O:0 (skip), C:2, N:5, R:6, Filler: 0

    printf("All tests passed!\n");
}

int main() {
    runTests();
    return 0;
}

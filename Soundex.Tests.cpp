#include "Soundex.h"
#include <stdio.h>
#include <string.h>

// Declaration of the function under test
void generateSoundex(const char *name, char *soundex);

// Helper function to run a test and display result
void runTest(const char *name, const char *expected) {
    char soundex[5];  // To store the generated Soundex code
    generateSoundex(name, soundex);  // Generate the Soundex for the name
    
    // Check if the generated Soundex matches the expected result
    if (strcmp(soundex, expected) == 0) {
        printf("Test Passed: %s -> %s\n", name, soundex);
    } else {
        printf("Test Failed: %s -> %s (Expected: %s)\n", name, soundex, expected);
    }
}

// Main function with individual test cases
int main() {
    // Test case 1: Common name "Robert"
    runTest("Robert", "R163");

    // Test case 2: Similar name "Rupert"
    runTest("Rupert", "R163");

    // Test case 3: Name with a single letter "A"
    runTest("A", "A000");

    // Test case 4: Name with only vowels "Eioau"
    runTest("Eioau", "E000");

    // Test case 5: Name with repetitive consonants "Ashcraft"
    runTest("Ashcraft", "A261");

    // Test case 6: A longer name "Jackson"
    runTest("Jackson", "J250");

    // Test case 7: Complex name "Tymczak"
    runTest("Tymczak", "T522");

    // Test case 8: Name with many vowels and few consonants "Euler"
    runTest("Euler", "E460");

    // Test case 9: Name with varying consonants "Pfister"
    runTest("Pfister", "P236");

    // Test case 10: Short name "B"
    runTest("B", "B000");

    return 0;
}

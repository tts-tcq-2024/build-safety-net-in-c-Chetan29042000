#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Soundex.h"

// Declaration of the function under test
void generateSoundex(const char *name, char *soundex);

// Test case 1: Simple name
void test_case_1() {
    char soundex[5];
    generateSoundex("Robert", soundex);
    assert(strcmp(soundex, "R163") == 0);
    printf("Test Case 1 Passed!\n");
}

// Test case 2: Name with silent letters
void test_case_2() {
    char soundex[5];
    generateSoundex("Rupert", soundex);
    assert(strcmp(soundex, "R163") == 0);
    printf("Test Case 2 Passed!\n");
}

// Test case 3: Single letter name
void test_case_3() {
    char soundex[5];
    generateSoundex("A", soundex);
    assert(strcmp(soundex, "A000") == 0);
    printf("Test Case 3 Passed!\n");
}

// Test case 4: Name with all vowels
void test_case_4() {
    char soundex[5];
    generateSoundex("Eioau", soundex);
    assert(strcmp(soundex, "E000") == 0);
    printf("Test Case 4 Passed!\n");
}

// Test case 5: Short name with repetitive consonants
void test_case_5() {
    char soundex[5];
    generateSoundex("Ashcraft", soundex);
    assert(strcmp(soundex, "A261") == 0);
    printf("Test Case 5 Passed!\n");
}

// Test case 6: Long name
void test_case_6() {
    char soundex[5];
    generateSoundex("Jackson", soundex);
    assert(strcmp(soundex, "J250") == 0);
    printf("Test Case 6 Passed!\n");
}

// Test case 7: Handling name with similar consonants
void test_case_7() {
    char soundex[5];
    generateSoundex("Tymczak", soundex);
    assert(strcmp(soundex, "T522") == 0);
    printf("Test Case 7 Passed!\n");
}

// Main function to run all test cases
int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();
    test_case_7();

    printf("All Test Cases Passed!\n");
    return 0;
}

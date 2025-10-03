#!/bin/bash

# Compile the program
gcc -o permutations main.c

echo "=== 10 TEST CASES FOR PERMUTATIONS ==="
echo

# Test Case 1: Already sorted
echo "Test 1: Already sorted (abc)"
echo "Input: abc"
echo "Output:"
./permutations abc
echo "Expected:"
echo "abc"
echo "acb"
echo "bac"
echo "bca"
echo "cab"
echo "cba"
echo

# Test Case 2: Reverse sorted
echo "Test 2: Reverse sorted (cba)"
echo "Input: cba"
echo "Output:"
./permutations cba
echo "Expected:"
echo "abc"
echo "acb"
echo "bac"
echo "bca"
echo "cab"
echo "cba"
echo

# Test Case 3: Single character
echo "Test 3: Single character (a)"
echo "Input: a"
echo "Output:"
./permutations a
echo "Expected:"
echo "a"
echo

# Test Case 4: Two characters - sorted
echo "Test 4: Two characters sorted (ab)"
echo "Input: ab"
echo "Output:"
./permutations ab
echo "Expected:"
echo "ab"
echo "ba"
echo

# Test Case 5: Two characters - reverse
echo "Test 5: Two characters reverse (ba)"
echo "Input: ba"
echo "Output:"
./permutations ba
echo "Expected:"
echo "ab"
echo "ba"
echo

# Test Case 6: Random order 3 chars
echo "Test 6: Random order (bac)"
echo "Input: bac"
echo "Output:"
./permutations bac
echo "Expected:"
echo "abc"
echo "acb"
echo "bac"
echo "bca"
echo "cab"
echo "cba"
echo

# Test Case 7: Random order 3 chars
echo "Test 7: Random order (acb)"
echo "Input: acb"
echo "Output:"
./permutations acb
echo "Expected:"
echo "abc"
echo "acb"
echo "bac"
echo "bca"
echo "cab"
echo "cba"
echo

# Test Case 8: 2 characters different
echo "Test 8: Two characters (xy)"
echo "Input: xy"
echo "Output:"
./permutations xy
echo "Expected:"
echo "xy"
echo "yx"
echo

# Test Case 10: Empty argument test
echo "Test 10: No arguments"
echo "Input: (no arguments)"
echo "Output:"
./permutations
echo "Expected:"
echo "(just newline)"
echo

echo "=== END OF TESTS ==="
#!/bin/bash

# Compile the program
gcc -o permutations main.c

echo "=== 10 TEST CASES FOR SORTING ==="
echo

# Test Case 1: Already sorted
echo "Test 1: Already sorted (abc)"
echo "Input: abc"
echo -n "Output: "
./permutations abc
echo "Expected: abc"
echo

# Test Case 2: Reverse sorted
echo "Test 2: Reverse sorted (cba)"
echo "Input: cba"
echo -n "Output: "
./permutations cba
echo "Expected: abc"
echo

# Test Case 3: Single character
echo "Test 3: Single character (a)"
echo "Input: a"
echo -n "Output: "
./permutations a
echo "Expected: a"
echo

# Test Case 4: Two characters - sorted
echo "Test 4: Two characters sorted (ab)"
echo "Input: ab"
echo -n "Output: "
./permutations ab
echo "Expected: ab"
echo

# Test Case 5: Two characters - reverse
echo "Test 5: Two characters reverse (ba)"
echo "Input: ba"
echo -n "Output: "
./permutations ba
echo "Expected: ab"
echo

# Test Case 6: Random order 3 chars
echo "Test 6: Random order (bac)"
echo "Input: bac"
echo -n "Output: "
./permutations bac
echo "Expected: abc"
echo

# Test Case 7: Random order 3 chars
echo "Test 7: Random order (acb)"
echo "Input: acb"
echo -n "Output: "
./permutations acb
echo "Expected: abc"
echo

# Test Case 8: 4 characters reverse
echo "Test 8: Four characters reverse (dcba)"
echo "Input: dcba"
echo -n "Output: "
./permutations dcba
echo "Expected: abcd"
echo

# Test Case 9: 4 characters mixed
echo "Test 9: Four characters mixed (bdac)"
echo "Input: bdac"
echo -n "Output: "
./permutations bdac
echo "Expected: abcd"
echo

# Test Case 10: 5 characters random
echo "Test 10: Five characters random (edcba)"
echo "Input: edcba"
echo -n "Output: "
./permutations edcba
echo "Expected: abcde"
echo

echo "=== END OF TESTS ==="
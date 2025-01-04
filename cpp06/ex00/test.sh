#!/bin/bash
GREEN='\033[32m'
RE='\033[0m'

INT_MIN=$(getconf INT_MIN)
INT_MAX=$(getconf INT_MAX)

# Array of test cases
tests=(
    # Usual tests
    "42"               # Integer
    "-42"              # Negative Integer
    "42.0f"            # Float
    "3.14"             # Double
    "a"                # Char
    "0.0"              # Double with zero
    "0.5"              # Small fractional number
    "'\\n'"            # Newline character

    # Specific conversions
    "nan"              # Not a Number
    "+inf"              # Positive infinity
    "-inff"             # Negative infinity

    # Edge cases for range limits
    "$(echo $((INT_MIN)))"    # INT_MIN
    "$(echo $((INT_MIN - 1)))" # Below INT_MIN
    "$(echo $((INT_MAX)))"    # INT_MAX
    "$(echo $((INT_MAX + 1)))" # Above INT_MAX

    # Float and double edge cases
    "3.4e+38"               # Maximum positive float
    "1.79769e+308"          # Maximum double
)

# Loop through the test cases
for test in "${tests[@]}"; do
    echo -e "${GREEN}CONVERT: $test${RE}"
    ./converter "$test"
    echo -e "${GREEN}_____________________${RE}\n"
done

#echo -e (-e allowes to use escape sequences in scripts)

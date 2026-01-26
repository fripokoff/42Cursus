#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Counters
TOTAL=0
PASSED=0
FAILED=0

# Program
PROG="./a.out"

# Test function
run_test() {
    local input="$1"
    local expected_output="$2"
    local description="$3"
    
    TOTAL=$((TOTAL + 1))
    
    # Run program and capture output
    OUTPUT=$($PROG "$input" 2>&1)
    
    # Check if output matches (allowing for minor whitespace differences)
    if [ "$OUTPUT" = "$expected_output" ]; then
        echo -e "${GREEN}✅ Test $TOTAL: $description${NC}"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}❌ Test $TOTAL: $description${NC}"
        echo -e "${YELLOW}   Input: '$input'${NC}"
        echo -e "   Expected:"
        echo "$expected_output" | sed 's/^/     /'
        echo -e "   Got:"
        echo "$OUTPUT" | sed 's/^/     /'
        FAILED=$((FAILED + 1))
    fi
}

# Run tests
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   SCALAR CONVERTER TESTER${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""

# ==================== BASIC TESTS ====================
echo -e "${BLUE}[BASIC TESTS]${NC}"
run_test "42" "char: '*'
int: 42
float: 42.0f
double: 42.0" "Simple int"

run_test "42.0f" "char: '*'
int: 42
float: 42.0f
double: 42.0" "Float with .0f"

run_test "42.5f" "char: '*'
int: 42
float: 42.5f
double: 42.5" "Float decimal"

run_test "a" "char: 'a'
int: 97
float: 97.0f
double: 97.0" "Char literal"

run_test "0" "char: '0'
int: 48
float: 48.0f
double: 48.0" "Char '0' (ASCII 48)"

# ==================== PSEUDO LITERALS ====================
echo ""
echo -e "${BLUE}[PSEUDO LITERALS]${NC}"
run_test "nan" "char: impossible
int: impossible
float: nanf
double: nan" "NaN"

run_test "nanf" "char: impossible
int: impossible
float: nanf
double: nan" "NaN float"

run_test "+inf" "char: impossible
int: impossible
float: +inff
double: +inf" "Positive infinity"

run_test "+inff" "char: impossible
int: impossible
float: +inff
double: +inf" "Positive infinity float"

run_test "-inf" "char: impossible
int: impossible
float: -inff
double: -inf" "Negative infinity"

run_test "-inff" "char: impossible
int: impossible
float: -inff
double: -inf" "Negative infinity float"

# ==================== CHAR LIMITS ====================
echo ""
echo -e "${BLUE}[CHAR LIMITS]${NC}"
run_test "127" "char: Non displayable
int: 127
float: 127.0f
double: 127.0" "CHAR_MAX"

run_test "128" "char: impossible
int: 128
float: 128.0f
double: 128.0" "CHAR_MAX + 1"

run_test "32" "char: ' '
int: 32
float: 32.0f
double: 32.0" "First printable (space)"

run_test "31" "char: Non displayable
int: 31
float: 31.0f
double: 31.0" "Last non-printable"

run_test "126" "char: '~'
int: 126
float: 126.0f
double: 126.0" "Last printable"

# ==================== INT LIMITS ====================
echo ""
echo -e "${BLUE}[INT LIMITS]${NC}"
run_test "2147483647" "char: impossible
int: 2147483647
float: 2.14748e+09f
double: 2.14748e+09" "INT_MAX"

run_test "2147483648" "Int overflow." "INT_MAX + 1 (overflow)"

# ==================== INVALID FORMATS ====================
echo ""
echo -e "${BLUE}[INVALID FORMATS]${NC}"
run_test "invalid" "Literal incorrect." "Invalid text"

run_test "0x42" "Literal incorrect." "Hexadecimal"

run_test "1e10" "Literal incorrect." "Scientific notation"

run_test "42ff" "Literal incorrect." "Double f"

run_test "42.42.42" "Literal incorrect." "Multiple dots"

run_test "." "char: '.'
int: 46
float: 46.0f
double: 46.0" "Just a dot (char)"

run_test "+" "char: '+'
int: 43
float: 43.0f
double: 43.0" "Just plus sign (char)"

run_test "-" "char: '-'
int: 45
float: 45.0f
double: 45.0" "Just minus sign (char)"

run_test "" "char: Non displayable
int: 0
float: 0.0f
double: 0.0" "Empty string (edge case)"

# ==================== SPECIAL CHARS ====================
echo ""
echo -e "${BLUE}[SPECIAL CHARACTERS]${NC}"
run_test " " "char: ' '
int: 32
float: 32.0f
double: 32.0" "Space character"

run_test "!" "char: '!'
int: 33
float: 33.0f
double: 33.0" "Exclamation mark"

run_test "~" "char: '~'
int: 126
float: 126.0f
double: 126.0" "Tilde (last printable)"

# ==================== PRECISION TESTS ====================
echo ""
echo -e "${BLUE}[PRECISION TESTS]${NC}"
run_test "4.2f" "char: Non displayable
int: 4
float: 4.2f
double: 4.2" "Simple float"

run_test "42.42f" "char: '*'
int: 42
float: 42.42f
double: 42.42" "Float with decimals"

run_test "123.456" "char: '{'
int: 123
float: 123.456f
double: 123.456" "Double precision"

run_test "0.5" "char: Non displayable
int: 0
float: 0.5f
double: 0.5" "Half"

run_test "999.999f" "char: impossible
int: 999
float: 999.999f
double: 999.999" "High precision float"

# ==================== EDGE CASES ====================
echo ""
echo -e "${BLUE}[EDGE CASES]${NC}"
run_test "42." "char: '*'
int: 42
float: 42.0f
double: 42.0" "Trailing dot (treated as double)"

run_test ".42" "char: Non displayable
int: 0
float: 0.42f
double: 0.42" "Leading dot"

run_test "0.0" "char: Non displayable
int: 0
float: impossible
double: 0.0" "Zero float (min detection issue)"

run_test "00000042" "char: '*'
int: 42
float: 42.0f
double: 42.0" "Leading zeros"

# ==================== SUMMARY ====================
echo ""
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}              SUMMARY${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total tests: ${YELLOW}$TOTAL${NC}"
echo -e "${GREEN}Passed: $PASSED ✅${NC}"
echo -e "${RED}Failed: $FAILED ❌${NC}"

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed! 🎉${NC}"
    exit 0
else
    PERCENTAGE=$((PASSED * 100 / TOTAL))
    echo -e "${YELLOW}Success rate: $PERCENTAGE%${NC}"
    exit 1
fi

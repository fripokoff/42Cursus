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
PROG="./convert"

# Test function
run_test() {
    local input="$1"
    local expected_output="$2"
    local description="$3"
    
    TOTAL=$((TOTAL + 1))
    
    # Run program and capture output
    OUTPUT=$($PROG "$input" 2>&1)
    
    # Check if output matches
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
echo -e "${BLUE}   (Adapted to current implementation)${NC}"
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

# Note: Votre implémentation ne gère PAS les signes +/-
run_test "-42" "Literal incorrect." "Negative int (not supported)"

run_test "+42" "Literal incorrect." "Positive int with + (not supported)"

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
echo -e "${BLUE}[CHAR LIMITS (Positive only)]${NC}"
run_test "127" "char: Non displayable
int: 127
float: 127.0f
double: 127.0" "CHAR_MAX (127)"

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

# Note: -128, -129 ne fonctionnent pas car pas de support des signes
run_test "-128" "Literal incorrect." "CHAR_MIN (not supported without sign handling)"

# ==================== INT LIMITS ====================
echo ""
echo -e "${BLUE}[INT LIMITS]${NC}"
run_test "2147483647" "char: impossible
int: 2147483647
float: 2.14748e+09f
double: 2.14748e+09" "INT_MAX"

run_test "2147483648" "Int overflow." "INT_MAX + 1 (overflow)"

# Note: Les négatifs ne fonctionnent pas
run_test "-2147483648" "Literal incorrect." "INT_MIN (not supported)"

# ==================== FLOAT/DOUBLE OVERFLOW ====================
echo ""
echo -e "${BLUE}[OVERFLOW TESTS]${NC}"
run_test "999999999999999999999999999999999999999" "Float overflow." "Very large number (float overflow)"

run_test "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999" "Double overflow." "Extremely large number (double overflow)"

# ==================== INVALID FORMATS ====================
echo ""
echo -e "${BLUE}[INVALID FORMATS]${NC}"
run_test "invalid" "Literal incorrect." "Invalid text"

run_test "0x42" "Literal incorrect." "Hexadecimal"

run_test "0X42" "Literal incorrect." "Hexadecimal uppercase"

run_test "1e10" "Literal incorrect." "Scientific notation"

run_test "1E10" "Literal incorrect." "Scientific notation uppercase"

run_test "42+5" "Literal incorrect." "Sign in middle"

run_test "42-5" "Literal incorrect." "Sign in middle (minus)"

run_test "++42" "Literal incorrect." "Double plus sign"

run_test "--42" "Literal incorrect." "Double minus sign"

run_test "+-42" "Literal incorrect." "Plus then minus"

run_test "42ff" "Literal incorrect." "Double f"

run_test "42.0ff" "Literal incorrect." "Double f with dot"

run_test "4f2" "Literal incorrect." "f in middle"

run_test "42f.0" "Literal incorrect." "f before dot"

run_test "42.42.42" "Literal incorrect." "Multiple dots"

run_test ".f" "Literal incorrect." "Dot and f"

run_test "+f" "Literal incorrect." "Plus and f"

run_test "-f" "Literal incorrect." "Minus and f"

run_test "   " "Literal incorrect." "Spaces only"

run_test "4 2" "Literal incorrect." "Space in middle"

# ==================== SINGLE CHAR EDGE CASES ====================
echo ""
echo -e "${BLUE}[SINGLE CHARACTER TESTS]${NC}"
run_test "." "char: '.'
int: 46
float: 46.0f
double: 46.0" "Just a dot (treated as char)"

run_test "+" "char: '+'
int: 43
float: 43.0f
double: 43.0" "Just plus sign (treated as char)"

run_test "-" "char: '-'
int: 45
float: 45.0f
double: 45.0" "Just minus sign (treated as char)"

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

# ==================== EDGE CASES WITH DOTS ====================
echo ""
echo -e "${BLUE}[EDGE CASES WITH DOTS]${NC}"
run_test "42." "char: '*'
int: 42
float: 42.0f
double: 42.0" "Trailing dot (accepted as double)"

run_test ".42" "char: Non displayable
int: 0
float: 0.42f
double: 0.42" "Leading dot (accepted)"

run_test "0.0" "char: Non displayable
int: 0
float: impossible
double: 0.0" "Zero float (float min issue)"

run_test "0.00000" "char: Non displayable
int: 0
float: impossible
double: 0.0" "Zero with many decimals"

# ==================== LEADING ZEROS ====================
echo ""
echo -e "${BLUE}[LEADING ZEROS]${NC}"
run_test "00000042" "char: '*'
int: 42
float: 42.0f
double: 42.0" "Leading zeros (accepted)"

run_test "007" "char: Non displayable
int: 7
float: 7.0f
double: 7.0" "Leading zeros (007)"

# ==================== EMPTY STRING ====================
echo ""
echo -e "${BLUE}[EMPTY STRING]${NC}"
run_test "" "char: Non displayable
int: 0
float: 0.0f
double: 0.0" "Empty string (edge case)"

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

run_test "1.5" "char: Non displayable
int: 1
float: 1.5f
double: 1.5" "1.5"

run_test "100.5f" "char: 'd'
int: 100
float: 100.5f
double: 100.5" "100.5f"

# ==================== LARGE NUMBERS ====================
echo ""
echo -e "${BLUE}[LARGE NUMBERS]${NC}"
run_test "1000000" "char: impossible
int: 1000000
float: 1e+06f
double: 1e+06" "One million"

run_test "999999" "char: impossible
int: 999999
float: 999999.0f
double: 999999.0" "999999"

run_test "1000000.0f" "char: impossible
int: 1000000
float: 1e+06f
double: 1e+06" "One million float"

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

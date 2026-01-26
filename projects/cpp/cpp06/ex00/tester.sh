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
    local expected_char="$2"
    local expected_int="$3"
    local expected_float="$4"
    local expected_double="$5"
    local description="$6"
    
    TOTAL=$((TOTAL + 1))
    
    # Run program and capture output
    OUTPUT=$($PROG "$input" 2>&1)
    
    # Extract lines
    CHAR_LINE=$(echo "$OUTPUT" | grep "^char:" | sed 's/char: //')
    INT_LINE=$(echo "$OUTPUT" | grep "^int:" | sed 's/int: //')
    FLOAT_LINE=$(echo "$OUTPUT" | grep "^float:" | sed 's/float: //')
    DOUBLE_LINE=$(echo "$OUTPUT" | grep "^double:" | sed 's/double: //')
    
    # Check results
    SUCCESS=1
    
    if [ "$CHAR_LINE" != "$expected_char" ]; then
        SUCCESS=0
    fi
    if [ "$INT_LINE" != "$expected_int" ]; then
        SUCCESS=0
    fi
    if [ "$FLOAT_LINE" != "$expected_float" ]; then
        SUCCESS=0
    fi
    if [ "$DOUBLE_LINE" != "$expected_double" ]; then
        SUCCESS=0
    fi
    
    # Display result
    if [ $SUCCESS -eq 1 ]; then
        echo -e "${GREEN}✅ Test $TOTAL: $description${NC}"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}❌ Test $TOTAL: $description${NC}"
        echo -e "${YELLOW}   Input: '$input'${NC}"
        echo -e "   Expected char: $expected_char | Got: $CHAR_LINE"
        echo -e "   Expected int: $expected_int | Got: $INT_LINE"
        echo -e "   Expected float: $expected_float | Got: $FLOAT_LINE"
        echo -e "   Expected double: $expected_double | Got: $DOUBLE_LINE"
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
run_test "0" "Non displayable" "0" "0.0f" "0.0" "Zero"
run_test "42" "'*'" "42" "42.0f" "42.0" "Simple int"
run_test "42.0f" "'*'" "42" "42.0f" "42.0" "Float with .0f"
run_test "42.5" "'*'" "42" "42.5f" "42.5" "Float decimal"
run_test "a" "'a'" "97" "97.0f" "97.0" "Char literal"
run_test "-42" "Non displayable" "-42" "-42.0f" "-42.0" "Negative int"

# ==================== PSEUDO LITERALS ====================
echo ""
echo -e "${BLUE}[PSEUDO LITERALS]${NC}"
run_test "nan" "impossible" "impossible" "nanf" "nan" "NaN"
run_test "nanf" "impossible" "impossible" "nanf" "nan" "NaN float"
run_test "+inf" "impossible" "impossible" "+inff" "+inf" "Positive infinity"
run_test "+inff" "impossible" "impossible" "+inff" "+inf" "Positive infinity float"
run_test "-inf" "impossible" "impossible" "-inff" "-inf" "Negative infinity"
run_test "-inff" "impossible" "impossible" "-inff" "-inf" "Negative infinity float"

# ==================== CHAR LIMITS ====================
echo ""
echo -e "${BLUE}[CHAR LIMITS]${NC}"
run_test "127" "Non displayable" "127" "127.0f" "127.0" "CHAR_MAX"
run_test "128" "impossible" "128" "128.0f" "128.0" "CHAR_MAX + 1"
run_test "-128" "Non displayable" "-128" "-128.0f" "-128.0" "CHAR_MIN"
run_test "-129" "impossible" "-129" "-129.0f" "-129.0" "CHAR_MIN - 1"
run_test "32" "' '" "32" "32.0f" "32.0" "First printable (space)"
run_test "31" "Non displayable" "31" "31.0f" "31.0" "Last non-printable"
run_test "126" "'~'" "126" "126.0f" "126.0" "Last printable"

# ==================== INT LIMITS ====================
echo ""
echo -e "${BLUE}[INT LIMITS]${NC}"
run_test "2147483647" "impossible" "2147483647" "2.14748e+09f" "2.14748e+09.0" "INT_MAX"
run_test "2147483648" "impossible" "impossible" "2.14748e+09f" "2.14748e+09.0" "INT_MAX + 1"
run_test "-2147483648" "impossible" "-2147483648" "-2.14748e+09.0f" "-2.14748e+09.0" "INT_MIN"
run_test "-2147483649" "impossible" "impossible" "-2.14748e+09.0f" "-2.14748e+09.0" "INT_MIN - 1"

# ==================== FLOAT OVERFLOW ====================
echo ""
echo -e "${BLUE}[FLOAT OVERFLOW]${NC}"
run_test "999999999999999999999999999999999999999" "impossible" "impossible" "impossible" "1e+39" "Float overflow (positive)"
run_test "-999999999999999999999999999999999999999" "impossible" "impossible" "impossible" "-1e+39" "Float overflow (negative)"

# ==================== DOUBLE OVERFLOW ====================
echo ""
echo -e "${BLUE}[DOUBLE OVERFLOW]${NC}"
run_test "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999" "impossible" "impossible" "impossible" "impossible" "Double overflow (huge positive)"
run_test "-99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999" "impossible" "impossible" "impossible" "impossible" "Double overflow (huge negative)"

# ==================== INVALID FORMATS ====================
echo ""
echo -e "${BLUE}[INVALID FORMATS]${NC}"
run_test "0x42" "impossible" "impossible" "impossible" "impossible" "Hexadecimal"
run_test "0X42" "impossible" "impossible" "impossible" "impossible" "Hexadecimal uppercase"
run_test "1e10" "impossible" "impossible" "impossible" "impossible" "Scientific notation"
run_test "1E10" "impossible" "impossible" "impossible" "impossible" "Scientific notation uppercase"
run_test "42+5" "impossible" "impossible" "impossible" "impossible" "Sign in middle"
run_test "42-5" "impossible" "impossible" "impossible" "impossible" "Sign in middle (minus)"
run_test "++42" "impossible" "impossible" "impossible" "impossible" "Double plus sign"
run_test "--42" "impossible" "impossible" "impossible" "impossible" "Double minus sign"
run_test "+-42" "impossible" "impossible" "impossible" "impossible" "Plus then minus"
run_test "42ff" "impossible" "impossible" "impossible" "impossible" "Double f"
run_test "42.0ff" "impossible" "impossible" "impossible" "impossible" "Double f with dot"
run_test "4f2" "impossible" "impossible" "impossible" "impossible" "f in middle"
run_test "42f.0" "impossible" "impossible" "impossible" "impossible" "f before dot"
run_test "42.42.42" "impossible" "impossible" "impossible" "impossible" "Multiple dots"
run_test "." "impossible" "impossible" "impossible" "impossible" "Just a dot"
run_test ".f" "impossible" "impossible" "impossible" "impossible" "Dot and f"
run_test "42." "impossible" "impossible" "impossible" "impossible" "Number with trailing dot"
run_test ".42" "impossible" "impossible" "impossible" "impossible" "Number with leading dot"
run_test "+" "impossible" "impossible" "impossible" "impossible" "Just plus sign"
run_test "-" "impossible" "impossible" "impossible" "impossible" "Just minus sign"
run_test "+f" "impossible" "impossible" "impossible" "impossible" "Plus and f"
run_test "-f" "impossible" "impossible" "impossible" "impossible" "Minus and f"
run_test "" "impossible" "impossible" "impossible" "impossible" "Empty string"
run_test "   " "impossible" "impossible" "impossible" "impossible" "Spaces"
run_test "4 2" "impossible" "impossible" "impossible" "impossible" "Space in middle"

# ==================== EDGE CASES ====================
echo ""
echo -e "${BLUE}[EDGE CASES]${NC}"
run_test "-0" "Non displayable" "0" "-0.0f" "-0.0" "Negative zero"
run_test "+0" "Non displayable" "0" "0.0f" "0.0" "Positive zero"
run_test "-0.0" "Non displayable" "0" "-0.0f" "-0.0" "Negative zero float"
run_test "+0.0" "Non displayable" "0" "0.0f" "0.0" "Positive zero float"
run_test "00000042" "impossible" "impossible" "impossible" "impossible" "Leading zeros"
run_test "0.0" "Non displayable" "0" "0.0f" "0.0" "Zero float"
run_test "0.00000" "Non displayable" "0" "0.0f" "0.0" "Zero with many decimals"

# ==================== SPECIAL CHARS ====================
echo ""
echo -e "${BLUE}[SPECIAL CHARACTERS]${NC}"
run_test " " "' '" "32" "32.0f" "32.0" "Space character"
run_test "!" "'!'" "33" "33.0f" "33.0" "Exclamation mark"
run_test "~" "'~'" "126" "126.0f" "126.0" "Tilde (last printable)"

# ==================== PRECISION TESTS ====================
echo ""
echo -e "${BLUE}[PRECISION TESTS]${NC}"
run_test "4.2f" "Non displayable" "4" "4.2f" "4.2" "Simple float"
run_test "42.42f" "'*'" "42" "42.42f" "42.42" "Float with decimals"
run_test "123.456" "'{'" "123" "123.456f" "123.456" "Double precision"
run_test "0.5" "Non displayable" "0" "0.5f" "0.5" "Half"
run_test "999.999f" "impossible" "999" "999.999f" "999.999" "High precision float"

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

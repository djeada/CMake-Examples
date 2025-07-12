#!/bin/bash
# Script to test compilation of all CMake-based projects in src/
set -e

SRC_DIR="$(dirname "$0")/../src"
FAILURES=()

echo "===================="
echo "CMake Example Compilation Test"
echo "===================="
TOTAL=0
SUCCESS=0
FAIL=0

for EXAMPLE in "$SRC_DIR"/*; do
    if [ -d "$EXAMPLE" ] && [ -f "$EXAMPLE/CMakeLists.txt" ]; then
        TOTAL=$((TOTAL+1))
        echo "\n>>> Attempting to compile: $EXAMPLE"
        echo -e "\n>>> Attempting to compile: $EXAMPLE"
        BUILD_DIR="$EXAMPLE/build_test"
        rm -rf "$BUILD_DIR"
        mkdir "$BUILD_DIR"
        pushd "$BUILD_DIR" > /dev/null
        if cmake .. && cmake --build .; then
            echo "[SUCCESS] $EXAMPLE compiled successfully."
            echo -e "[SUCCESS] $EXAMPLE compiled successfully."
            SUCCESS=$((SUCCESS+1))
        else
            echo "[FAIL] $EXAMPLE failed to compile."
            echo -e "[FAIL] $EXAMPLE failed to compile."
            FAILURES+=("$EXAMPLE")
            FAIL=$((FAIL+1))
        fi
        popd > /dev/null
        rm -rf "$BUILD_DIR"
    fi
    # Also check subdirectories for CMakeLists.txt
    for SUB in "$EXAMPLE"/*; do
        if [ -d "$SUB" ] && [ -f "$SUB/CMakeLists.txt" ]; then
            TOTAL=$((TOTAL+1))
            echo "\n>>> Attempting to compile: $SUB"
        echo -e "\n>>> Attempting to compile: $SUB"
            BUILD_DIR="$SUB/build_test"
            rm -rf "$BUILD_DIR"
            mkdir "$BUILD_DIR"
            pushd "$BUILD_DIR" > /dev/null
            if cmake .. && cmake --build .; then
                echo "[SUCCESS] $SUB compiled successfully."
                echo -e "[SUCCESS] $SUB compiled successfully."
                SUCCESS=$((SUCCESS+1))
            else
                echo "[FAIL] $SUB failed to compile."
                echo -e "[FAIL] $SUB failed to compile."
                FAILURES+=("$SUB")
                FAIL=$((FAIL+1))
            fi
            popd > /dev/null
            rm -rf "$BUILD_DIR"
        fi
    done

done

echo "Compilation Summary"
echo "===================="
echo "Total projects attempted: $TOTAL"
echo "Successful compilations: $SUCCESS"
echo "Failed compilations: $FAIL"
echo -e "\n===================="

if [ ${#FAILURES[@]} -eq 0 ]; then
    echo "\nAll examples compiled successfully."
    echo -e "\nAll examples compiled successfully."
    exit 0
else
    echo "\nSome examples failed to compile:"
    echo -e "\nSome examples failed to compile:"
    for FAIL in "${FAILURES[@]}"; do
        echo "  $FAIL"
    done
    exit 1
fi

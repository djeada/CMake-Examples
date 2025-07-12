#!/bin/bash
set -e

# Check if clang-format is installed
if ! command -v clang-format &> /dev/null; then
    echo "Error: clang-format is not installed."
    exit 1
fi

echo "===================="
echo "C++ Code Formatting Check"
echo "===================="

# Variables for tracking
failed_count=0
total_files=0

# Find all .cpp and .h files excluding build directories and third-party code
while IFS= read -r file; do
    total_files=$((total_files + 1))
    echo "Checking: $file"
    
    # Check if file matches clang-format output
    if ! clang-format --dry-run --Werror "$file" &> /dev/null; then
        echo "[FAIL] File not properly formatted: $file"
        failed_count=$((failed_count + 1))
    else
        echo "[PASS] File is properly formatted: $file"
    fi
done < <(find "$(dirname "$0")/../src" -type f \( -name "*.cpp" -o -name "*.h" \) \
    ! -path "*/build*/*" \
    ! -path "*/googletest*/*" \
    ! -path "*/CMakeFiles/*")

echo ""
echo "===================="
echo "Formatting Summary"
echo "===================="
echo "Total source files checked: $total_files"
echo "Files needing formatting: $failed_count"
echo "Files properly formatted: $((total_files - failed_count))"

if [ $failed_count -eq 0 ]; then
    echo "✅ All source files are properly formatted!"
    exit 0
else
    echo "❌ Some files need formatting fixes."
    echo ""
    echo "To fix all formatting issues, run:"
    echo "  find \"$(dirname "$0")/../src\" -type f \\( -name \"*.cpp\" -o -name \"*.h\" \\) ! -path \"*/build*/*\" ! -path \"*/googletest*/*\" ! -path \"*/CMakeFiles/*\" -exec clang-format -i {} +"
    exit 1
fi

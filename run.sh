#!/bin/bash

echo "Dir $1"
echo "Filename: $2"

GREEN='\033[0;32m' # Green text
RED='\033[0;31m' # Red text
NC='\033[0m'       # No color

echo $1

file_to_modify="CMakeLists.txt"
line_number=5

# The new content to replace the old line with.
new_content="add_executable(dsa $1$2)"

echo $new_content
# Use sed to replace the specified line.
sed -i "${line_number}s|.*|${new_content}|" "$file_to_modify"

echo -e "${RED}Build program${NC}"
cmake --build build
echo -e "${GREEN}Run program"
echo -e "----------------------------------------------------${NC}"
./build/dsa
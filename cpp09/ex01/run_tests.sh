#!/bin/bash

INPUT_FILE="rpn_tests.txt"

if [[ ! -f "$INPUT_FILE" ]]; then
  echo "file '$INPUT_FILE' not found..."
  exit 1
fi

while IFS= read -r expr || [[ -n "$expr" ]]; do
  # Skip blank lines between cases
  [[ -z "$expr" ]] && continue

  # Next line must be the expected-result line
  if ! IFS= read -r expected; then
    echo "Malformed test file: missing expected result for: $expr" >&2
    exit 1
  fi

  # Run and print
  echo -e "\033[1;32m>>> ./RPN \"$expr\"\033[0m"
  ./RPN "$expr"
  echo -e "\e[1;35m$expected\e[0m"
  sleep 1
  echo

done < "$INPUT_FILE"

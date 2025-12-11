#!/bin/bash

INPUT_FILE="test_cases.txt"

ERR_FILE="invalid_cases.txt"

ULINE="\e[4m"
BLINK="\e[5m"
BLACK="\e[1;30m"
RED="\e[1;31m"
GREEN="\e[1;32m"
YELLOW="\e[1;33m"
BLUE="\e[1;34m"
PURPLE="\e[1;35m"
CYAN="\e[1;36m"
WHITE="\e[1;37m"
RESET="\e[0m"

run (){
	local file="$1"
	local mode="$2"
	if [[ ! -f "$file" ]]; then
		echo -e "$RED $BLINK file '$file' not found...$RESET"
		exit 1
	fi

	while IFS= read -r test; do
		[[ -z "$test" ]] && continue

		if ! IFS= read -r case; then
			echo -e "$RED $BLINK Missing test case expression...$RESET" >&2
			exit 1
		fi

		echo -e "$PURPLE Running following test: $test$RESET"

		if [[ "$mode"=="valid" ]]; then
			ARG="$(eval "$case")"
			RES="$(./PmergeMe "$ARG")"
			./checker "$RES"
		else
			./PmergeMe "$case"
		fi
#		sleep 1
		echo
	done < "$file"
}

run "$INPUT_FILE" "valid"
run "$ERR_FILE" "invalid"

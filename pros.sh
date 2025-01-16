#!/bin/bash

# File paths
variablesFile="./src/autonomous.cpp"
projectFile="./project.pros"

# Configurable auton selector line
# Change this to match your project's auton line format.
autonSelectorLine="std::string auton ="

# Project names with optional custom slots
declare -A projectNames=(
    [1]="53C/Red/Ring"
    [2]="53C/Red/Mogo"
    [3]="53C/Red/Elim"
    [4]="53C/Blue/Ring"
    [5]="53C/Blue/Mogo"
    [6]="53C/Blue/Elim"
    [7]="53C/Skills"
    [8]="53C/NoAuton"
)

declare -A customSlots=(
    [red-ring]=1
    [red-mogo]=2
    [red-elim]=3
    [blue-ring]=4
    [blue-mogo]=5
    [blue-elim]=6
    [skills]=7
    [testing]=8
)

# Predefined auton groups
declare -A autonKeywords=(
    [name]="1 test"
)

# ---------End of configuration (DO NOT CHANGE UNLESS YOU KNOW WHAT YOU'RE DOING)---------- #

# Function to update variables.cpp
update_variables_file() {
    local autonValue=$1
    sed -i "s|${autonSelectorLine}.*;|${autonSelectorLine} \"${autonValue}\";|" "$variablesFile"
    echo "Updated variables.cpp: Set auton to $autonValue"
}

# Function to update project.pros
update_project_file() {
    local projectName=$1
    local slot=$2
    sed -i "s|\"project_name\": \".*\",|\"project_name\": \"${projectName}\",|" "$projectFile"
    sed -i "s|slot = [0-9]*|slot = ${slot}|" "$projectFile"
    echo "Updated project.pros: Set slot to $slot and project_name to '$projectName'"
}

# Function to upload auton code
upload_code() {
    local slot=$1
    local autonValue=$2
    local projectName=$3

    # Cap the slot at 8
    if (( slot > 8 )); then
        slot=8
    fi

    # Update the files
    update_variables_file "$autonValue"
    update_project_file "$projectName" "$slot"

    # Upload the code
    echo "Uploading code to slot $slot..."
    pros mu --slot "$slot"
}

# Check for arguments
if [[ $# -eq 0 ]]; then
    echo "Error: No input provided. Please enter a number, keyword, or auton name."
    exit 1
fi

# Main logic
input=$1
specifiedSlot=""
for (( i=2; i<=$#; i++ )); do
    if [[ ${!i} == "--slot" ]]; then
        (( i++ ))
        specifiedSlot=${!i}
        break
    fi
done

if [[ -n ${projectNames[$input]} ]]; then
    # String-based auton
    projectName=${projectNames[$input]}
    autonValue=$input
    uploadSlot=${specifiedSlot:-${customSlots[$input]:-1}}
    upload_code "$uploadSlot" "$autonValue" "$projectName"
elif [[ $input =~ ^[0-9]+$ ]]; then
    # Number-based auton
    autonValue=$input
    if [[ -z ${projectNames[$autonValue]} ]]; then
        echo "Error: Invalid auton number '$autonValue'. Please enter a valid auton number."
        exit 1
    fi
    projectName=${projectNames[$autonValue]}
    uploadSlot=${specifiedSlot:-${customSlots[$autonValue]:-$autonValue}}
    upload_code "$uploadSlot" "$autonValue" "$projectName"
elif [[ -n ${autonKeywords[$input]} ]]; then
    # Group-based auton
    autonList=${autonKeywords[$input]}
    uploadSlot=1
    for auton in $autonList; do
        if [[ -n ${projectNames[$auton]} ]]; then
            projectName=${projectNames[$auton]}
            upload_code "$uploadSlot" "$auton" "$projectName"
            ((uploadSlot++))
        fi
    done

    # Fill remaining slots with empty values
    while ((uploadSlot <= 8)); do
        upload_code "$uploadSlot" "-1" "Empty Slot"
        ((uploadSlot++))
    done
else
    echo "Error: Invalid input '$input'. Please enter a valid number, auton name, or keyword."
    exit 1
fi

echo "Done!"

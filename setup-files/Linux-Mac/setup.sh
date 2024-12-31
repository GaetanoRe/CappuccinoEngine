#!/bin/bash

# Path to vcpkg
VCPKG_DIR="$HOME/vcpkg"

# Check if vcpkg exists
if [ ! -d "$VCPKG_DIR" ]; then
    echo "vcpkg not found. Please install it first."
    exit 1
fi

# Add vcpkg to PATH
export PATH="$VCPKG_DIR:$PATH"

# Path to the libraries list file
LIBRARIES_FILE="../../libraries.txt"

# Check if libraries file exists
if [ ! -f "$LIBRARIES_FILE" ]; then
    echo "libraries.txt not found in the project root. Please create it and list the libraries to install."
    exit 1
fi

# Read libraries from file
LIBRARIES=$(cat "$LIBRARIES_FILE")

# Install libraries
for LIB in $LIBRARIES; do
    echo "Installing $LIB..."
    if ! vcpkg install $LIB --triplet x64-linux; then
        echo "Error installing $LIB. Check the logs for details."
        exit 1
    fi
done

echo "All libraries installed successfully!"

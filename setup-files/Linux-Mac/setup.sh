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

# List of libraries to install
LIBRARIES=(
    "glfw3"
    "glew"
    "soil"
    "freetype"
    "glm"
    "bullet3"
    "openal-soft"
)

# Install libraries
for LIB in "${LIBRARIES[@]}"; do
    echo "Installing $LIB..."
    vcpkg install $LIB --triplet x64-linux || exit 1
done

echo "All libraries installed successfully!"
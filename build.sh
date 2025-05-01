#!/bin/bash

# Set the output binary name
OUTPUT="SecureLoginSystem"

# Set the source files
SOURCES="src/main.cpp src/LoginManager.cpp src/Encryption.cpp src/Database.cpp src/OTPGenerator.cpp src/SendMail.cpp"

# Set the include directory
INCLUDE_DIR="-Iinclude"

# Set the required libraries
LIBRARIES="-lcurl"

# Compile the project
echo "Compiling the project..."
g++ $SOURCES $INCLUDE_DIR -o $OUTPUT $LIBRARIES

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Executable created: $OUTPUT"
else
    echo "Compilation failed!"
fi
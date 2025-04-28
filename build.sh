#!/bin/bash
g++ src/main.cpp src/LoginManager.cpp src/Encryption.cpp src/Database.cpp src/OTPGenerator.cpp -Iinclude -o SecureLoginSystem

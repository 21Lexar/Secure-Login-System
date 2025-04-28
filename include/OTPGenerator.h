#ifndef OTPGENERATOR_H

#define OTPGENERATOR_H
#pragma once
#include <time.h>
#include <iostream>
using namespace std;

class OTPGenerator {
    int otp;
    public:
        OTPGenerator();
        int getOTP() const;
        bool verifyOTP(int userOTP) const;
};

#endif
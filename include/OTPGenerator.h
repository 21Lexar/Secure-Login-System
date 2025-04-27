#ifndef OTPGENERATOR_H

#define OTPGENERATOR_H
#pragma once
#include <time.h>
#include <iostream>
using namespace std;

class OTPGenerator {
    unsigned int otp;
    public:
        OTPGenerator();
        bool verifyOTP(unsigned int userOTP) const;
};

#endif
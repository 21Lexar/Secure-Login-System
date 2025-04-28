#include "../include/OTPGenerator.h"

OTPGenerator::OTPGenerator(){
    int iseed = (unsigned int)time(NULL);
    srand (iseed);
    bool da=false;
    while (da==false) {
        if (rand ()%1000000<=999999){
        otp = rand ()%1000000;
        da=true;
        }
        else da=false;
    }
}

int OTPGenerator::getOTP() const {
    return otp;
}

bool OTPGenerator::verifyOTP(int userOTP) const {
    return otp == userOTP;
}

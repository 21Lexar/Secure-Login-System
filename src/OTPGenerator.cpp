#include "../include/OTPGenerator.h"

OTPGenerator::OTPGenerator(){
unsigned int iseed = (unsigned int)time(NULL);
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

bool OTPGenerator::verifyOTP(unsigned int userOTP) const {
    return otp == userOTP;
}

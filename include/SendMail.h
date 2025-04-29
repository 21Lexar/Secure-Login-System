#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <string>

// Function to send an email with the provided receiver email and OTP
void sendEmail(const std::string& receiver_email, const int& otp);

#endif // SENDMAIL_H
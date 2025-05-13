#include <iostream>
#include <string>
#include <curl/curl.h>
#include <stdlib.h>
#include "../include/SendMail.h"
using namespace std;

void sendEmail(const string& receiver_email, const int& otp) {
    const string api_key = ""; // Enter your SMTP2GO API key here
    const string sender_email = ""; // Enter your verified sender email here
    const string sender_name = "Secure Login System";
    const std::string api_url = "https://api.smtp2go.com/v3/email/send";

    string json_payload = R"({
        "api_key": ")" + api_key + R"(",
        "to": [")" + receiver_email + R"("],
        "sender": ")" + sender_email + R"(",
        "subject": "Secure Login System OTP Code",
        "text_body": "Your OTP is: )" + to_string(otp) + R"(",
        "from": ")" + sender_name + R"( <)" + sender_email + R"(>"
    })";

    CURL *curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL" << std::endl;
        return;
    }

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_DNS_SERVERS, "8.8.8.8,8.8.4.4");

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "Email sending failed: " << curl_easy_strerror(res) << endl;
    } else {
        cout << "Email sent successfully to " << receiver_email << endl;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
}


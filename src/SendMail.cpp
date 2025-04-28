#include <iostream>
#include <string>
#include <cstring>
#include <curl/curl.h>
#include <cstdlib> // For getenv()

void send_email(const std::string& receiver_email, const std::string& otp) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *recipients = NULL;

    // Email content
    std::string payload_text =
        "To: " + receiver_email + "\r\n"
        "From: Secure-Login-System mirza.khizar.502@gmail.com\r\n"
        "Subject: Your OTP Code\r\n"
        "\r\n"
        "Your OTP code is: " + otp + "\r\n";

    struct upload_status {
        size_t bytes_read;
        const std::string *payload;
    };

    auto payload_source = [](char *ptr, size_t size, size_t nmemb, void *userp) -> size_t {
        upload_status *upload_ctx = (upload_status *)userp;
        const char *data = upload_ctx->payload->c_str() + upload_ctx->bytes_read;
        size_t room = size * nmemb;
        size_t len = strlen(data);

        if (len > room)
            len = room;

        if (len) {
            memcpy(ptr, data, len);
            upload_ctx->bytes_read += len;
            return len;
        }
        return 0;
    };

    struct upload_status upload_ctx = { 0, &payload_text };

    curl = curl_easy_init();
    if (curl) {
        const char *smtp_username = std::getenv("SMTP_USERNAME");
        const char *smtp_password = std::getenv("SMTP_PASSWORD");

        if (!smtp_username || !smtp_password) {
            std::cerr << "Error: SMTP credentials not set in environment variables." << std::endl;
            curl_easy_cleanup(curl);
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_USERNAME, smtp_username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtp_password);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, smtp_username);

        recipients = curl_slist_append(recipients, ("<" + receiver_email + ">").c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // Enable verbose for debugging
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        else
            std::cout << "Email sent successfully to " << receiver_email << std::endl;

        if (recipients)
            curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Error: Failed to initialize CURL." << std::endl;
    }
}

int main() {
    // Set environment variables for testing (remove in production)
    setenv("SMTP_USERNAME", "mirza.khizar.502@gmail.com", 1);
    setenv("SMTP_PASSWORD", "lrtj clsf jtza didm", 1);

    send_email("gigglesafari@gmail.com", "123456");
    return 0;
}


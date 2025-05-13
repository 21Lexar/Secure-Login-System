# Secure Login System
## **Description**

A terminal-based secure login system developed in C++ that allows users to register a new account or log in to an existing account. Both features use Two-Factor Authentication. The system checks if the email has been already registered or not. The passwords are saved in a file being encrypted.

## **Preview**

**Options Menu**
</br>
![Options Menu Entry Point](/img/IntroSLS.png)

**Login Page**
</br>
![Login Menu](/img/LoginSLS.png)

**Signup Page**
</br>
![Register Menu](/img/RegisterSLS.png)

## **Key Features:**

**Secure Data Encryption:** The system provides login and register options for the user, protected by an encrypted password.

**Two-Factor Authentication:** The user will receive an OTP via email, which will be keyed in the OTP section to authenticate the system to register a new account for the user or allow the login of an existing account.

## **Available Options**

**Registration**: Register a new account with your email and a password;

**Login:** login into an existing account and verify if the email is already registered;

**Encryption:** Users’ password are encrypted into cipher text;

**Verification:** Matches the email with the same stored password;

**OTP:** Auto-generated OTP is received in the email to authenticate the use;

**OTP Checker:** Ask the user if they have received the OTP or if there is a need to send another OTP.

## **Installation**
NOTE: The Code is only available for Linux;
1. Clone the repo using;
```bash
git clone https://github.com/21Lexar/Secure-Login-System.git
cd Secure-Login-System/src
code SendMail.cpp
```
2. Create an accout on SMTP2GO;
3. Create your API Key;
4. Verify your sender email;
5. Paste the your API Key and verified email in the highlighted sections;
![Code Chunk Screenshot](/img/2025-05-13_14-38.png)
6. Run the code;
```bash
bash build.sh
./SecureLoginSystem
```

## **Contact**

[u2024294@giki.edu.pk](mailto:u2024294@giki.edu.pk)

[u2024595@giki.edu.pk](mailto:u2024595@giki.edu.pk)

[u2024610@giki.edu.pk](mailto:u2024610@giki.edu.pk)

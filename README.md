# Vigenère Cipher Encryption & Decryption Program

## Description
This project is a C++ console application that implements the Vigenère cipher for both encryption and decryption of text. The program allows the user to choose whether to encrypt or decrypt a message using a keyword. All alphabetic characters are processed using the Vigenère cipher, while spaces and non-letter characters are preserved exactly as entered.

## Programming Approach
The program is written in C++ using a procedural programming approach. It utilizes:
- Functions to separate encryption and decryption logic
- The C++ Standard Library (`<iostream>`, `<string>`, `<cctype>`)
- Character manipulation with `toupper()` to ensure consistent letter handling
- Modular arithmetic to correctly shift characters within the alphabet

The cipher operates only on alphabetic characters. Any spaces or non-alphabetic characters remain unchanged, which improves readability of the output.

## Author
- **Charles Dela Cruz:** 
- **Role:** Sole Developer

## Date Published
- **Date:** [12/17/2025]

## Basic Instructions
1. Open a terminal or command prompt.
2. Compile the program using a C++ compiler (such as `g++`).
3. Run the compiled executable.
4. Choose whether to encrypt or decrypt by entering the prompted option.
5. Enter the message you want to process.
6. Enter the keyword for the Vigenère cipher.
7. View the encrypted or decrypted output displayed in the terminal.

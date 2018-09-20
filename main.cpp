// Section 10
// Challenge - 
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet 
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>
#include <string>

using namespace std;
int main() {
    
	// Set the cipher of each alphabet
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
	
	// String storage for user input, encrypted_message, decrypted_message
    string message_input;
	string encrypted_message;
	string decrypted_message;
	
	// Variables to store the index of key and relavant alphabet
	uint8_t encode_idx {};
	uint8_t decode_idx {};
	
	cout << "Enter your message: ";
	getline(cin,message_input);
	cout << "\n==== Encrypting the message... ====" << endl;
	
	// Parse a letter from the first to the end, and store encrypted letter
	for (char c:message_input) {
		if (isalpha(c)) {	// if input char is alphabet, encrypt it.
			encode_idx = alphabet.find(c);	// Find the index for the char
			encrypted_message += key.at(encode_idx);	// Replace it with the cipher
		} else {
			encrypted_message += c;
		}
	}
	
    cout << "User message input: " << message_input << endl;
	cout << "Encrypted message: " << encrypted_message << endl;
	cout << "\n==== Decrypting the message... ====" << endl;
	
	for (char c:encrypted_message) {
		if (isalpha(c)) {	// if input char is alphabet, encrypt it.
			decode_idx = key.find(c);	// Find the index of key
			decrypted_message += alphabet.at(decode_idx);	// Replace it with the cipher
		} else {
			decrypted_message += c;
		}
	}
	
	cout << "Encrypted message: " << encrypted_message << endl;
	cout << "Decrypted message: " << decrypted_message << endl;
	
    cout << "\nPress Enter to finish the task" << endl;
	getchar();
	
    return 0;
}


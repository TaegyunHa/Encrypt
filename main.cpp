// T Ha

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


//
// Created by yusufc on 23.04.2019.
//

#include <stdio.h>


char* ceaser_encrypt(char* message_to_encrypt, int shift){
	int i; 
	char* encrypted_message; 
	int len_mess = get_string_length(message_to_encrypt);
	
	if (len_mess == 0) return NULL;

	encrypted_message = (char*) malloc(sizeof(char));

	for( i = 0; i < len_mess; i ++){
		if (i == 0){
			encrypted_message[i] = message_to_encrypt[i];
		}
		encrypted_message = (char*) realloc(encrypted_message, size_of(char) * i + 1);
		encrypted_message[i] = message_to_encrypt[i];
	}
	return message_to_encrypt;
} 

int main() {

	/* you can try all of your implementations here */
	char *c = "I have an apple.";
	int shift = 2, i;
	int lengo = get_string_length(c);
	char *d = ceaser_encrypt(*c, shift);

	for(i = 0; i<lengo; i++){
		printf("%c", *d[i]);
	}



	return 0;
}
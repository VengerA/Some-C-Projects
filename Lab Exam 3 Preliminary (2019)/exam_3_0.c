//
// Created by yusufc on 23.04.2019.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	returns number of characters in a string
	returns 0 if string is NULL
*/
int get_string_length(char *string) {
    int i = 0;
    if (string != NULL) {
        while (string[i] != '\0') i++;
    }
    return i;
}

/*
	returns the longest string length
	returns 0 if string array is NULL
*/
int get_longest_string_length(char **s, int n_string) {
    int maxLength = 0, tempLength = 0;
    int i;

    if (s == NULL) {
        return 0;
    }

    for (i = 0; i < n_string; i++) {
        if (s[i] != NULL) {
            tempLength = get_string_length(s[i]);
            if (tempLength > maxLength) {
                maxLength = tempLength;
            }
        }
    }
    return maxLength;
}

/*
 *  returns nothing
 *	prints combined strings one line for each.
 */
void print_combined_strings(char **s, int n_string) {
    int i;
    for (i = 0; i < n_string; i++) {
        if (s[i] != NULL) {
            printf("%s\n", s[i]);
        }
    }
}


/*
 *  returns whether given char is a letter
 */
int is_letter(char c) {
    return (c < 91 && c > 64) || (c < 123 && c > 96);
}

/*
 *  returns the order of the letter in the alphabet
 *  if given char is not a letter, returns -1
 */
int letter_to_shift(char c) {
    if (c < 91 && c > 64) {
        return c - 64;
    } else if (c < 123 && c > 96) {
        return c - 96;
    }

    return -1;
}



/* DON'T TOUCH THE CODE ABOVE, INCLUDING THIS LINE. YOUR IMPLEMENTATIONS MAY START BELOW THIS LINE. */


char* ceaser_encrypt(char* message_to_encrypt, int shift){
	int i; 
	char* encrypted_message; 
	int len_mess = get_string_length(message_to_encrypt);
	
	if (len_mess == 0) return NULL;

	encrypted_message = (char*) malloc(sizeof(char));

	for( i = 0; i < len_mess; i ++){
		if (i == 0){
			encrypted_message[i] = message_to_encrypt[i] + shift;
		}
        if (is_letter(message_to_encrypt[i])){
            encrypted_message = (char*) realloc(encrypted_message, sizeof(char) * i + 1);
		    encrypted_message[i] = (message_to_encrypt[i] + shift)%255;
        }
        else {
            encrypted_message = (char*) realloc(encrypted_message, sizeof(char) * i + 1);
            encrypted_message[i] = message_to_encrypt[i];
        }
        
	}
	return encrypted_message;
} 

char* polyalphabetic_encrypt(char* message_to_encrypt, char* key_string){
    int i, j, len_message, len_key; 
    char* encrypted_message;
    

    len_key = get_string_length(key_string);
    len_message = get_string_length(message_to_encrypt);
    if(message_to_encrypt == NULL){
        return NULL;
    }
    encrypted_message = (char*) malloc(sizeof(char));
    for(i=0, j=0; i < len_message; i++, j++){
        if ( j == len_key){
            j = 0;
        }
        if (i == 0){
            encrypted_message[i] = message_to_encrypt[i] + letter_to_shift(key_string[j]);
        }
        else {
            if (is_letter(message_to_encrypt[i])){
                if (!is_letter(message_to_encrypt[i] + letter_to_shift(key_string[j]))){
                    encrypted_message = (char*) realloc(encrypted_message, sizeof(char) * (i+1));
                    encrypted_message[i] = message_to_encrypt[i] + (letter_to_shift(key_string[j]) - 26);
                }
                else {
                    encrypted_message = (char*) realloc(encrypted_message, sizeof(char) * (i+1));
                    encrypted_message[i] = message_to_encrypt[i] + letter_to_shift(key_string[j]);
                }
            }
            else {
                encrypted_message = (char*) realloc(encrypted_message, sizeof(char) * (i+1));
                encrypted_message[i] = message_to_encrypt[i];
                j -=1;
            }
        }
    }
    return encrypted_message;
}

char** combine_strings(char** messages, int n_messages, int grouping, char* salt){
    char **temp, *temp2;
    int i, j, k,  divide_num, len_message;
    
    divide_num = grouping * n_messages;

    for(i=0; i< n_messages; i++){
        len_message = get_string_length(messages[i]);
        if (len_message % divide_num != 0){
                temp[i] = (char*) malloc(sizeof(char));
                for(j=len_message, k = 0; j < len_message + (12 - len_message % 12 ); j++){
                    if (j<len_message){
                        if (j == 0){
                            temp[i][j] = messages[i][j];
                        }
                        else{
                            temp[i] =  (char*) realloc(sizeof(char) * (j+1));
                            temp[i][j] == messages[j];
                        }
                    }
                    else {
                        if (k == grouping){
                            k = 0;
                        }
                        temp[i] =  (char*) realloc(sizeof(char) * (j+1));
                        temp[i]][j] = salt[k];
                        k++;
                    }
                }      
        }   
    }
    for(i = 0; i < n_messages; i++){
        temp2 = (char*) malloc(sizeof(char) * grouping);
        for(j=0; j< get_string_length; j++){
            temp2[j] = temp[i][j+grouping];
        }
        if(i+1 < n_messages){
            temp[i][j+grouping] = temp[i+1][j+grouping];

        }
    }
}


int main(){
    char  *c = "Nothing is true. Everything is permitted.";
	int shift = 3, i;
	
	char *d = ceaser_encrypt(c, shift);
    int lengo = get_string_length(d);
    char *message_to_encrypt = "Nothing is true. Everything is permitted.";
    char *key = "Ceng";
    char *e = polyalphabetic_encrypt(message_to_encrypt, key);


	for(i = 0; i<lengo; i++){
		printf("%c", *(e+i));
	}
    printf("\n");




    return 0;
}


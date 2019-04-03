/*
 Title: Rotation Cipher
 Description: this program takes in a plain text and produces a cipher of that text using the rotation cipher
 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define function for the rotation cipher (also known as caeser cipher)

// ask the user for the plain text to encrypt
int main() {
    char message[100], ch; //what does 'ch' mean?
    int key, i;
    /* printf("enter a message to encrypt: ")
    get(message)
    printf("enter key: ") */
    printf("Enter a message to encrypt: "); //implementation of above comment --> purpose: encryption of a cipher
    get(messgage);
    printf("Enter key: ");
    scanf("%d", &key); // scanf statement is reading the value entered into the printf statement on line22 and stroing it into 'key'
    
    for(i=0; message[i] != '\0'; ++i) { //not sure what 'i' represents in this code at the moment --> need to work out or replace
        ch=message[i];
        
        if(ch >= 'a' && ch <= 'z') { //given chracters --> plain text?? must be between a and z, needs to be uppercase??
            ch=ch + key;
            
            if(ch > 'z') {
                ch=ch-'z' + 'a' -1;
            } // bracket to end second if statement
            message[i] = ch;
        } // bracket to end first if statement
    } // bracket to end the for statement
    // need an elseif statement for upper case A and Z + another if statement within the elseif statement
    printf(encyrpted message: %s", message); 
    // printf statement to give the output --> the encrypted cipher of the given plain text
    // majority of the current code right now has been sourced from internet, need to gain an understanding and rewrite the code 
    // Try hard coding the variables next time rather than trying to use a string, then return back to the string once there's a better understanding

  return 0;
}

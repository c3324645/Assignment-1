/* 
 The rotational cipher (caesar cipher) takes text and shifts the letters according
 to the key to encrypt or decrypt the text
 */

#include<stdio.h> 
#include<stdlib.h> 

char data[50], temp; //intialising variables, temp is temporary variables
int key, count;

void getmessage() //function to read the message to be encrypted or decrypted
{	
      printf("Please Enter a Message:\t"); //printf statement for user input, \t provides a tab space
      scanf("%[^\n]s", data); //scanf statement to read user input
}

void key_input() //function that allows the user to input the key (the amount the letters are shifted) for the cipher
{
      printf("Please Enter a Key:\t");
      scanf("%d", &key);
}

void caesar_cipher_encryption() //function to encyrpt text
{
      for(count = 0; data[count] != '\0'; count++) // the for statement allows the text to continue to be 'shifted' per the key
      {
            temp = data[count];
            if(temp >= 'a' && temp <= 'z')
            {
                  temp = temp + key; //temp becomes equivalent to the last value of temp plus the key that was input by the user
                  if(temp > 'z')
                  {
                        temp = temp - 'z' + 'a' - 1;
                  }
                  data[count] = temp;
            }
            else if(temp >= 'A' && temp <= 'Z') // else if statement for uppercase letters
            {
                  temp = temp + key;
                  if(temp > 'Z')
                  {
                        temp = temp - 'Z' + 'A' - 1;
                  }
                  data[count] = temp;
            }
      }
      printf("\nEncrypted Message:\t%s\n", data); //the printf statement prints the encrypted message
}

void caesar_cipher_decryption() //function to decrypt text
{
      for(count = 0; data[count] != '\0'; count++)
      {
            temp = data[count];
            if(temp >= 'a' && temp <= 'z')
            {
                  temp = temp - key; //the temp becomes the last value of temp minus the key to decrypt the text 
                  if(temp < 'a')
                  {
                        temp = temp + 'z' - 'a' + 1;
                  } //ending bracket for the if statement for temp < 'a'
                  data[count] = temp;
            }
            else if(temp >= 'A' && temp <= 'Z') //elseif statement to decrypt uppercase letters
            {
                  temp = temp - key; 
                  if(temp < 'A')
                  {
                        temp = temp + 'Z' - 'A' + 1;
                  }
                  data[count] = temp; //data becomes the value for temp
            }
      }
      printf("\nDecrypted Message:\t%s\n", data);//printf statement to print the decrypted message, the output comes from the data on line 72
}

int main()
{
      int choice; // initialising variables
      getmessage(); // calls for the getmessage function which takes the users input
      key_input(); // calls for the key input function
      while(1)
      { //opening bracket for the while loop
            printf("\n1. Encryption\n2. Decryption\n3. Exit\n");
            printf("\nEnter You Choice:\t");
            scanf("%d", &choice); //scanf statement reads the users decision and stores that in choice
            switch(choice) //switch statement which based on the user's input will encrypt, decrypt, exit the program or print an error message
            { //opening bracket for switch statement
                  case 1: caesar_cipher_encryption();
                          break; //break to break the switch statement if condition is met
                  case 2: caesar_cipher_decryption();
                          break;
                  case 3: exit(0);
                  default: printf("\nPlease select a correct option:\n"); //defult case for if the user fails to input one of the given options to encrypt, decrypt or exit the program
            } //closing bracket for switch statement
      } //closing bracket for the while loop
      printf("\n"); //print the output on a new line
      return 0;
}

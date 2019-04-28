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
      printf("Enter a String:\t"); //printf statement for user input
      scanf("%[^\n]s", data); //scanf statement to read user input
}

void key_input() //function that allows the user to input the key (the amount the letters are shifted) for the cipher
{
      printf("Enter a Key:\t");
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
            else if(temp >= 'A' && temp <= 'Z')
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
                  temp = temp - key;
                  if(temp < 'a')
                  {
                        temp = temp + 'z' - 'a' + 1;
                  }
                  data[count] = temp;
            }
            else if(temp >= 'A' && temp <= 'Z')
            {
                  temp = temp - key;
                  if(temp < 'A')
                  {
                        temp = temp + 'Z' - 'A' + 1;
                  }
                  data[count] = temp;
            }
      }
      printf("\nDecrypted Message:\t%s\n", data);
}

int main()
{
      int choice; // initialising variables
      getmessage(); // calls for the getmessage function which takes the users input
      key_input(); // calls for the key input function
      while(1)
      {
            printf("\n1. Encryption\n2. Decryption\n3. Exit\n");
            printf("\nEnter You Choice:\t");
            scanf("%d", &choice); //scanf statement reads the users decision and makes that the value of choice
            switch(choice) //switch statement which based on the user's input will encrypt, decrypt, exit the program or print an error message
            {
                  case 1: caesar_cipher_encryption();
                          break; 
                  case 2: caesar_cipher_decryption();
                          break;
                  case 3: exit(0);
                  default: printf("\nPlease select a correct option:\n");
            }
      }
      printf("\n"); //print the output on a new line
      return 0;
}


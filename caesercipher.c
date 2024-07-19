#include<stdio.h>
#include<ctype.h> // library that lets u classify and transform the sequence of characters.. if it is not integer it typecasts internally in function
void main(){
    char text[500], ch;
    int key;
    printf("Enter the text:");
    scanf("%s", text);
    printf("Enter the Key:");
    scanf("%d",&key); 
    // code for encryption of the given text
   for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalnum(ch)) { // check for teh valid character
            if (islower(ch)) { // if the character is lowercase
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            if (isupper(ch)) { // if the character is uppercase
                ch = (ch - 'A' + key) % 26 + 'A';
            }
            if (isdigit(ch)) { // if given character is a digit
                ch = (ch - '0' + key) % 10 + '0';
            }
        }
        else {
            printf("Invalid Message");
        }
        text[i] = ch; // move the encrypted text to the text[]

    }
    printf("Encrypted message: %s\n", text);
    
    // code for decoding the encrypted text
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalnum(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' - key + 26) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            }
            if (isdigit(ch)) {
                ch = (ch - '0' - key + 10) % 10 + '0';
            }
        }
        else {
            printf("Invalid Message");
        }
        text[i] = ch;
    } 
    printf("Decrypted Text: %s\n",text);
    return ;
}

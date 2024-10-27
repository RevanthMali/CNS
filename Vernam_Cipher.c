#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(const char* message, const char* key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    char extendedKey[100];
    
    // Extend the key to match the length of the message
    for (int i = 0; i < messageLen; i++) {
        extendedKey[i] = key[i % keyLen];
    }
    extendedKey[messageLen] = '\0';  // Null-terminate the extended key

    char encryptedMessage[100];
    for (int i = 0; i < messageLen; i++) {
        encryptedMessage[i] = (message[i] - 'A' + extendedKey[i] - 'A') % 26 + 'A';
    }
    encryptedMessage[messageLen] = '\0';  // Null-terminate the encrypted message

    printf("Encrypted message: %s\n", encryptedMessage);
}

void decrypt(const char* message, const char* key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    char extendedKey[100];
    
    // Extend the key to match the length of the message
    for (int i = 0; i < messageLen; i++) {
        extendedKey[i] = key[i % keyLen];
    }
    extendedKey[messageLen] = '\0';  // Null-terminate the extended key

    char decryptedMessage[100];
    for (int i = 0; i < messageLen; i++) {
        decryptedMessage[i] = (message[i] - extendedKey[i] + 26) % 26 + 'A';
    }
    decryptedMessage[messageLen] = '\0';  // Null-terminate the decrypted message

    printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {
    int choice;
    char message[100], key[100];

    printf("Choose operation (1 for Encrypt, 2 for Decrypt): ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%s", key);

    // Convert input to uppercase
    for (int i = 0; message[i]; i++) {
        message[i] = toupper(message[i]);
    }
    for (int i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
    }

    if (choice == 1) {
        encrypt(message, key);
    } else if (choice == 2) {
        decrypt(message, key);
    } else {
        printf("Invalid choice! Please choose 1 or 2.\n");
    }

    return 0;
}

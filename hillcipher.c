#include <stdio.h>
#include <string.h>
// Function to create a matrix from the key
void createMatrixFromKey(int matrix[][20], char key[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = key[k] - 'A'; // Convert char to 0-25 integer
            k++;
        }
    }
}
// Function to multiply matrix with vector
void matrixVectorMultiply(int matrix[][20], int vector[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
        result[i] = result[i] % 26;
    }
}

int main() {
    int n;
    char msg[20];
    int keyMatrix[20][20];
    int plainTextVector[20], cipherTextVector[20];

    printf("Enter the plain text (only alphabetic characters, max 20): ");
    scanf("%s", msg);
    
    int msgLength = strlen(msg);
    if (msgLength > 20) {
        printf("Plain text too long! Maximum length is 20 characters.\n");
        return 1;
    }

    printf("\nEnter the order of Matrix (n x n): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Invalid matrix order! Please enter a value between 1 and 20.\n");
        return 1;
    }

    char key[n * n + 1];
    printf("Enter the Key (must be %d characters long): ", n * n);
    scanf("%s", key);

    if (strlen(key) != n * n) {
        printf("Key length does not match matrix order!\n");
        return 1;
    }

    createMatrixFromKey(keyMatrix, key, n);

    // Pad message to fit the matrix size
    int paddedLength = ((msgLength + n - 1) / n) * n;
    for (int i = msgLength; i < paddedLength; i++) {
        msg[i] = 'X'; // Padding character
    }
    msg[paddedLength] = '\0';

    printf("\nMatrix Key:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", keyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEncrypted Text: ");
    for (int i = 0; i < paddedLength; i += n) {
        // Create vector from message segment
        for (int j = 0; j < n; j++) {
            plainTextVector[j] = msg[i + j] - 'A';
        }

        matrixVectorMultiply(keyMatrix, plainTextVector, cipherTextVector, n);

        for (int j = 0; j < n; j++) {
            printf("%c", cipherTextVector[j] + 'A');
        }
    }
    printf("\n");

    return 0;
}


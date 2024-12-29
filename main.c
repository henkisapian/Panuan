#include <stdio.h>
#include <string.h>
#include "blake2b.h"

// Contoh penggunaan BLAKE2b untuk menghasilkan hash
void example_blake2b() {
    const char *data = "Hello, BLAKE2b!";
    uint8_t hash[32];  // Hasil hash 256-bit (32 bytes)

    // Hashing data menggunakan BLAKE2b
    blake2b_hash(hash, data, strlen(data));

    printf("BLAKE2b Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Contoh penggunaan HMAC-BLAKE2b
void example_hmac_blake2b() {
    const char *key = "secretkey";
    const char *data = "message to be hashed";
    uint8_t hmac_result[32];  // HMAC-BLAKE2b 256-bit output

    // HMAC-BLAKE2b hash
    hmac_blake2b_hash(hmac_result, key, strlen(key), data, strlen(data));

    printf("HMAC-BLAKE2b: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hmac_result[i]);
    }
    printf("\n");
}

// Contoh penggunaan PBKDF2-BLAKE2b
void example_pbkdf2_blake2b() {
    const char *password = "password";
    const char *salt = "salt";
    uint8_t derived_key[32];  // Hasil kunci derivasi
    size_t dkLen = 32;  // Ukuran kunci derivasi

    // PBKDF2-BLAKE2b
    pbkdf2_blake2b((const uint8_t *)password, strlen(password), 
                   (const uint8_t *)salt, strlen(salt), 1000, 
                   derived_key, dkLen);

    printf("PBKDF2-BLAKE2b Derived Key: ");
    for (int i = 0; i < dkLen; i++) {
        printf("%02x", derived_key[i]);
    }
    printf("\n");
}

int main() {
    // Menampilkan contoh BLAKE2b
    example_blake2b();

    // Menampilkan contoh HMAC-BLAKE2b
    example_hmac_blake2b();

    // Menampilkan contoh PBKDF2-BLAKE2b
    example_pbkdf2_blake2b();

    return 0;
}

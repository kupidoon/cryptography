#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "crypto.h"

 int main ()
 {
	bool bits1[8];
encode_char('A', bits1);
for(int i = 0; i < 8; i++){
    printf("%d", bits1[i]);
}
printf("\n");
// prints: 01000001

	bool bits2[8] = {0,1,0,0,0,0,0,1};
printf("%c\n", decode_char(bits2));
// prints: A


char* text = "Hello, how are you?";
const int len = strlen(text);
bool bytes1[len+1][8];
encode_string(text, bytes1);
for(int j = 0; j <= len; j++){
    printf("%c: ", text[j]);
    for(int i = 0; i < 8; i++){
        printf("%d", bytes1[j][i]);
    }
    printf("\n");
}
// prints:
// H: 01001000
// e: 01100101
// l: 01101100
// l: 01101100
// o: 01101111
// ,: 00101100
//  : 00100000
// h: 01101000
// o: 01101111
// w: 01110111
//  : 00100000
// a: 01100001
// r: 01110010
// e: 01100101
//  : 00100000
// y: 01111001
// o: 01101111
// u: 01110101
// ?: 00111111
// : 00000000

// bool bytes2[7][8] = {
//     {0,1,0,0,1,0,0,0},
//     {0,1,1,0,0,1,0,1},
//     {0,1,1,0,1,1,0,0},
//     {0,1,1,0,1,1,0,0},
//     {0,1,1,0,1,1,1,1},
//     {0,0,1,0,0,0,0,1},
//     {0,0,0,0,0,0,0,0}
// };
char string[7];
decode_string(7, bytes1, string);
printf("%s\n", string);
// prints: Hello!


	char reversed[255];
reverse("Hello world!", reversed);
printf("%s\n", reversed);
// "!DLROW OLLEH"

	char encrypted[255];
char decrypted[255];

// basic test with long text
vigenere_encrypt("CoMPuTeR", "Hello world!", encrypted);
printf("%s\n", encrypted);
// "JSXAI PSINR!"
vigenere_decrypt("CoMPuTeR", encrypted, decrypted);
printf("%s\n", decrypted);
// "HELLO WORLD!"

unsigned char encryptedd[100];

// basic test with long text
bit_encrypt("Hello world!", encryptedd);
for(int i=0; i < 12;i++) {
    printf("%02x ", (unsigned char)encryptedd[i]);
    //80 9c 95 95 96 11 bc 96 b9 95 9d 10
}
unsigned char decrypted1[100];
bit_decrypt(encryptedd, decrypted1);
printf("%s\n", decrypted1);



	
    
    
    
    
    
    
    return 0;
}
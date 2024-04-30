#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//
void encode_char(const unsigned char character, bool bits[8]){
    int bit_valuels[8] = {128, 64 ,32 ,16 ,8 ,4 ,2 ,1};
    int CharValue = (int)character;
    for(int i=0;i<8;i++){
       bits[i]=0;
       if(bit_valuels[i]<= CharValue){
        bits[i]=1;
        CharValue -=bit_valuels[i];
        }
    
    }

}
//
unsigned char decode_char(const bool bits[8]){
    int Value=0;
    int bit_values[8] = {128, 64 ,32 ,16 ,8 ,4 ,2 ,1};
    for(int i=0;i<8;i++){
        if(bits[i]>0){
            Value+=bit_values[i];
        
        }
    }
    return Value;
}
//
void encode_string( char string[], bool bytes[][8]) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        encode_char(string[i], bytes[i]);
    }
}
//
// void decode_string( int rows,  bool bytes[][8], unsigned char string[]) {
//     int bit_values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
//     int charValue = 0;

//     for(int i = 0; i < rows; i++) {
//         for(int j = 0; j < 8; j++) {
//             if(bytes[i][j] == 1) {
//                 charValue += bit_values[j];
//             }
//         }
//         string[i] = charValue;
//         charValue = 0;
//     }
// }
//

    void reverse(const char* text, char* result){
        int length = strlen(text);
    for (int i = 0; i < length; i++) {
        result[i] = text[length - i - 1];
    }
    result[length] = '\n'; 
    
}
//
void vigenere_encrypt(const char* key, const char* text, char* result) {
    int textLength = strlen(text);
    int keyLength = strlen(key); 
    
    for (int i = 0, j = 0; i < textLength; i++, j++) {
        if (j >= keyLength) {
            j = 0;
        }
        char textSymbol = text[i];
        if (textSymbol >= 97 && textSymbol <= 122) {
            textSymbol -= 32; 
        }
        
        if (!(textSymbol >= 65 && textSymbol <= 90)) {
            j--;
            result[i] = textSymbol;
            continue;
        }
        char keySymbol = key[j];
        if (keySymbol >= 97 && keySymbol <= 122) {
            keySymbol -= 32; 
        }
        int shift = (int)keySymbol - 65; 
        char tmp = textSymbol + shift; 
        if (tmp > 90) {
            tmp -= 26; 
        }
        result[i] = tmp;
    }
    result[strlen(text)]='\0';
}

//
// void vigenere_decrypt(const char* key, const char* text, char* result){
//     int textLenght=strlen(text);
//     int keyLenght=strlen(key);
//     for (int i = 0, j = 0; i < textLenght; i++, j++){
//         if(j>=keyLenght){
//             j=0;
//         }
//         char textSymbol = text[i];
//         if (textSymbol >= 97 && textSymbol <= 122) {
//             textSymbol -= 32; 
//         }
        
//         if (!(textSymbol >= 65 && textSymbol <= 90)) {
//             j--;
//             result[i] = textSymbol;
//             continue;
//         }
    
//     char keySymbol = key[j];
//         if (keySymbol >= 97 && keySymbol <= 122) {
//             keySymbol -= 32; 
//         }
//         int shift = (int)keySymbol - 65;
//         char tmp = textSymbol - shift;
    
//     if (tmp < 65) {
//             tmp += 26; 
//         }
//         result[i] = tmp;
        
//     }

// }
void bit_encrypt(const char* text, unsigned char* result){
    bool bits[8];
    bool bit[8];
    int bitss[4];
    int bitsss[4];
    int smena[4];
    int proverkaXOR[4];
    for(int i=0;i<strlen(text);i++){
        encode_char(text[i], bits);
        
        for(int k=0;k<4;k++){
            bitss[k]=bits[k];  
        }
        for(int k=0, i=4;k<4;k++, i++){   
            bitsss[k]=bits[i];  
        }
        for(int k=0;k<4;k++){
            smena[k]=bitss[k];  
            
        }
        bitss[0]=smena[1];
        bitss[1]=smena[0];
        bitss[2]=smena[3];
        bitss[3]=smena[2];
        for(int i=0;i<4;i++){
            if(bitss[i]==bitsss[i]){
                proverkaXOR[i]=0;
            }else{
                proverkaXOR[i]=1;
            }
        }
        for(int i=0;i<4;i++){
            bit[i]=bitss[i];
        }
        for(int i=4, k=0;i<8;i++, k++){
            bit[i]=proverkaXOR[k];
        }
        
        result[i]=decode_char(bit);
    }
   result[strlen(text)]='\0';
   
}
//
// void bit_decrypt(const  char* text, unsigned char* result){
//    bool bits[8];
//    bool bit[8];
//     int bitss[4];
//     int bitsss[4];
//     int smena[4];
//     int proverkaXOR[4];
//    int len=strlen(text);
//    printf("\n");
//     for(int i=0;i<len;i++){
//        encode_char(text[i], bits);
//         printf("\n");
//     for(int k=0;k<4;k++){
//             bitss[k]=bits[k];  
//         }
//         for(int k=0, i=4;k<4;k++, i++){   
//             bitsss[k]=bits[i];  
//         }
//         for(int k=0;k<4;k++){
//             smena[k]=bitss[k];  
            
//         }
//         for(int i=0;i<4;i++){
//             if(bitss[i]==bitsss[i]){
//                 proverkaXOR[i]=0;
//             }else{
//                 proverkaXOR[i]=1;
//             }
//         }
//         bitss[0]=smena[1];
//         bitss[1]=smena[0];
//         bitss[2]=smena[3];
//         bitss[3]=smena[2];
//         for(int i=0;i<4;i++){
//             bit[i]=bitss[i];
//         }
//         for(int i=4, k=0;i<8;i++, k++){
//             bit[i]=proverkaXOR[k];
//         }
        
//         result[i]=decode_char(bit);

//     }
//     result[strlen(text)]='\0';
//     }
    


        
    








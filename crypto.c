#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//
void encode_char(const char character, bool bits[8]){
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
char decode_char(const bool bits[8]){
    int Value=0;
    int bit_valuels[8] = {128, 64 ,32 ,16 ,8 ,4 ,2 ,1};
    for(int i=0;i<8;i++){
        if(bits[i]>0){
            Value+=bit_valuels[i];
        
        }
    }
    return Value;
}
//
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    bool bits[8];
    for(int i=0;i<strlen(string);i++){
        encode_char(string[i], bits);
          
    }
}
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
}

//
void vigenere_decrypt(const char* key, const char* text, char* result){
    int textLenght=strlen(text);
    int keyLenght=strlen(key);
    for (int i = 0, j = 0; i < textLenght; i++, j++){
        if(j>=keyLenght){
            j=0;
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
        char tmp = textSymbol - shift;
    
    if (tmp < 65) {
            tmp += 26; 
        }
        result[i] = tmp;
        
    }

}
void bit_encrypt(const char* text, char* result){
    bool bits[8];
    int bitss[4];
    int bitsss[4];
    int smena[4];
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
            
        }
    }
   
   for(int i=0;i<4;i++){
    printf("%d", bitss[i]);
   } 
    printf("\n");
    for(int i=0;i<4;i++){
    printf("%d", bitsss[i]);
    }
    printf("\n");
}

        
    








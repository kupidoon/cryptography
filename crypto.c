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
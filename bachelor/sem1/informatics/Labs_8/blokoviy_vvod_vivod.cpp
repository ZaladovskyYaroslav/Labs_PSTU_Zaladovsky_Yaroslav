#include <iostream>
#include <clocale>
#include <stdio.h>
#include <string.h>
#include <bitset>
using namespace std;

int main(){
    setlocale(LC_ALL, ".UTF8");


    // const char* str1 = "Good morning!\n";

    // fwrite(str1, sizeof(char), strlen(str1), stdout);

    char buf[16];
    size_t i, len;

    FILE* f1 = fopen("text.txt", "rb");

    if(!f1){
        printf("Ошибка при попытке открыть файл!");
        return 0;
    }


    while((len = fread(buf, sizeof(unsigned char), sizeof(buf), f1)) > 0){
        for(size_t i = 0; i < len; i++){
            printf("%02x ", buf[i]);
        }
        printf("\n");
    }


    if(fclose(f1)){
        printf("Ошибка при попытке закрыть файл!");
    }

    return 0;

}
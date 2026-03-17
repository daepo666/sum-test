#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<fcntl.h>
#include<malloc.h>
#include "add_n_print.h"
#include<cstdlib>


int main(int argc, char* argv[]){
    uint32_t *arr = (uint32_t *)calloc(0,sizeof(uint32_t));
    FILE * file;
    if(argc <2){
        printf("Usage: ./sum-nbo <4byte file>");
        exit(-1);
    }
    for(int i = 1; ; i++){
        if(argv[i] != NULL){
            file = fopen(argv[i], "rb");
            if(file == NULL){
                puts("open failed");
                exit(-1);
            }
            arr = (uint32_t *)realloc(arr, sizeof(uint32_t)*i + 4);
            arr[0] = i;
            fseek(file, 0, 0);
            if(fread(&arr[i], 1,4,file) != 4){
                puts("4byte read error!");
                exit(-1);
            };
            fclose(file);
        }
        else{
            break;
        }
    }
    add_n_print(arr);
    return 0;
}
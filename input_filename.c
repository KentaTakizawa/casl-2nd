#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

char *input_filename(void){
    char *filename;
    filename = (char*)malloc(sizeof(char) * 20);
    printf("File>");
    fgets(filename,SIZE,stdin);
    strtok(filename,"\n");
    free(filename);
    return filename;
}
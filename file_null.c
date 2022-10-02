#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int file_null(FILE *fp,char *filename){
    if(fp == NULL){
        printf("%sのファイルは見つかりませんでした．\n",filename);
        return FALSE;
    }
    return TRUE;
}
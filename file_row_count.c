#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int file_row_count(FILE *fp){
    int frc=0;
    char len_str[SIZE];
    while(fgets(len_str,SIZE,fp) != NULL){
        frc++;
    }
    //100行以上ならエラーを返す
    if(frc>100){
        fprintf(stderr,"ファイルが100行以上存在しています．\n");
        return FALSE;
    }
    return TRUE;
}
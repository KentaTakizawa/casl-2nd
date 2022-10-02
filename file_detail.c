#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int file_detail(FILE *fp,char *filename){
    //ファイルの中身がない場合
    if(file_null(fp,filename)==FALSE){
        return FALSE;
    }
    //ファイルの行数を数える(100行ならエラー)
    if(file_row_count(fp)==FALSE){
        return FALSE;
    }
    return TRUE;
}
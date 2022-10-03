#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

char *literal_list(char *str,char *str1){
    char *list=NULL;
    list = (char *)malloc(sizeof(char));
    //リテラル名をラベルにする
    strcat(list,str);
    strcat(list,",");
    //リテラルの命令をDSで登録
    strcat(list,"DC");
    strcat(list,",");
    //リテラルの中身を登録
    strcat(list,str1);
    strcat(list,",");
    //オペランド2はnull
    strcat(list,",");
    //オペランド3もnull
    strcat(list,",");
    //caファイルの中身としてリテラルを登録
    strcat(list,str);
    return list;
}
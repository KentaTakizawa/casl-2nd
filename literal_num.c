#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int literal_num(char *str){
    int i = 0;
    //文字列に数字以外が含まれていないか確認
    //マイナスも弾く
    while(str[i]!='\0'){
        if(isdigit(str[i])==0){
            fprintf(stderr,"リテラルに数字以外の値が入っています．\n");
            fprintf(stderr,"エラー箇所：=%s\n",str);
            return -10;
        }
        i++;
    }
    //01のケースの判定
    if(str[0]=='0'){
        fprintf(stderr,"リテラルの数字が不適切です．\n");
        fprintf(stderr,"エラー箇所：=%s\n",str);
        return -10;
    }
    return atoi(str);
}
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

void literal(PF *pf){
    while(pf->next!=NULL){
        pf = pf->next;
        //リテラルの要素
        char *lstr,*llist;
        lstr=(char *)malloc(sizeof(char));
        llist=(char *)malloc(sizeof(char));
        int lnum;
        char *command;
        char *operand1;
        char *operand2;
        command = pf->command;
        operand1 = pf->operand1;
        operand2 = pf->operand2;
        //リテラルの検索
        if(command[0]=='='){
            //リテラルの中身を得る
            lstr=literal_str(command);
            //リテラルの数値を得る
            lnum=literal_num(lstr);
            //構造体に格納する文字列の作成
            llist=literal_list(command,lstr);
            add_structure(pf,llist,lnum);
        }
        if(operand1[0]=='='){
            //リテラルの中身を得る
            lstr=literal_str(operand1);
            //リテラルの数値を得る
            lnum=literal_num(lstr);
            //構造体に格納する文字列の作成
            llist=literal_list(operand1,lstr);
            add_structure(pf,llist,lnum);
        }
        if(operand2[0]=='='){
            //リテラルの中身を得る
            lstr=literal_str(operand2);
            //リテラルの数値を得る
            lnum=literal_num(lstr);
            //構造体に格納する文字列の作成
            llist=literal_list(operand2,lstr);
            add_structure(pf,llist,lnum);
        }
    }
}
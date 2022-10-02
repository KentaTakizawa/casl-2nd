#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

void add_structure(PF *pf,char *str,int necessary_address){
    //カンマでラベル，コマンド，オペランド，casファイルの中身に分ける
    int i=0,j=0,k=0;
    char list[6][SIZE];
    while(str[i]!='\0'){
        //カンマで区切る
        if(str[i]!=','){
            list[j][k] = str[i];
            k++;
        }
        else{
            //casファイルの中身ではないときは区切る
            if(j<5){
                list[j][k] = '\0';
                j++;
                k=0;
            }
            else{
                list[j][k] = str[i];
                k++;
            }
        }
        list[j][k] = '\0';
        i++;
    }
    //コピーする文字列の作成
    char *label;
    char *command;
    char *operand1;
    char *operand2;
    char *operand3;
    char *cas_file;
    //文字列のアドレスを確保
    label = (char *)malloc(sizeof(char));
    command = (char *)malloc(sizeof(char));
    operand1 = (char *)malloc(sizeof(char));
    operand2 = (char *)malloc(sizeof(char));
    operand3 = (char *)malloc(sizeof(char));
    cas_file = (char *)malloc(sizeof(char));
    //文字列をくっつける
    strcpy(label,list[0]);
    strcpy(command,list[1]);
    strcpy(operand1,list[2]);
    strcpy(operand2,list[3]);
    strcpy(operand3,list[4]);
    strcpy(cas_file,list[5]);
    //登録する
    PF *new;
    new = (PF *)malloc(sizeof(PF));
    new->address=0;
    new->label=label;
    new->command=command;
    new->operand1=operand1;
    new->operand2=operand2;
    new->operand3=operand3;
    new->cas_file=cas_file;
    new->necessary_address=necessary_address;
    new->next=NULL;
    while(pf->next!=NULL) {
        pf = pf->next;
    }
    pf->next = new;
}
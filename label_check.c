#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int label_check(PF *pf){
    while(pf->next!=NULL){
        pf = pf->next;
        if(strlen(pf->label)>8){ 
            fprintf(stderr,"ラベルの文字数は1-8文字にしてください．\n");
            fprintf(stderr,"エラー箇所：%s\n",pf->label);
            return FALSE;
        }
    }
    return TRUE;
}
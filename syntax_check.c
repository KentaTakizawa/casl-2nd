#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int syntax_check(PF *pf){
    while(pf->next!=NULL){
        pf = pf->next;
        if(strlen(pf->label)>9){
            fprintf(stderr,"構文エラーです．\n");
            fprintf(stderr,"エラー箇所：%s\n",pf->cas_file);
            return FALSE;
        }
    }
    return TRUE;
}
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int error_check_structure(PF *pf){
    int error_check;
    //ラベルの文字数のチェック
    if(label_check(pf)==FALSE){
        return FALSE;
    }
    //構文チェック
    if(syntax_check(pf)==FALSE){
        return FALSE;
    }
    return TRUE;
}
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int main(void){
    //アセンブリ言語のデータ構造体の作成
    PF *pf;
    pf = (PF *)malloc(sizeof(PF));
    //構造体の初期化
    init_list(pf);
    //構造体を作成する
    structure_creation(pf);
    //機械語に変換する


    return TRUE;
}

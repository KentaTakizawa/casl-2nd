#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

char *structure_creation(PF *pf){
    //ファイル名を格納する文字列を作成
    char *first_filename;
    char *filename;
    //ファイル名の入力を促す
    printf("ファイル名を入力してください.\n");
    printf("入力を終了するには\\q or \\Qを入力してください.\n");
    //ファイルを読み込んで構造体を作成
    int count=0;
    while(count<10){
        //ファイル名を入力
        filename = input_filename();
        if((strcmp(filename,"\\q")==0)||(strcmp(filename,"\\Q")==0)){
            break;
        }
        //ファイルの保存先を作成
        FILE *fp;
        //ファイルをオープンする
        fp = fopen(filename,"r");
        //ファイルの中身を確認する
        if(file_detail(fp,filename)==FALSE){
            continue;
        }
        fclose(fp);
        //構造体にデータを格納していく
        store_structure(pf,filename);
        count++;
    }
    //リテラルをラベル名として構造体に登録する
    literal(pf);
    while(pf->next!=NULL){
        pf = pf->next;
        printf("%s %s %d\n",pf->label,pf->command,pf->necessary_address);
    }
    return filename;
}
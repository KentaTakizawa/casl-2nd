#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

void store_structure(PF *pf,char *filename){
    //ファイルをオープンする
    FILE *fp;
    fp = fopen(filename,"r");
    //1行ずつ読み込む文字列
    char str[ROW][SIZE];
    //構造体に必要な要素を格納する
    char *as_str[ROW];
    //1行ずつ読み込む
    int i = 0;
    while(fgets(str[i],SIZE,fp)!=NULL){
        as_str[i]=assembly_segmentation(str[i]);
        i++;   
    }
    //ファイルを最後まで読んだので一度閉じる
    fclose(fp);
    //再度ファイルをオープンする
    FILE *fp1;
    fp1 = fopen(filename,"r");
    //内容を先程のデータにアペンドする
    int j = 0;
    //1行ずつ読み込む文字列
    char str1[ROW][SIZE];
    //アドレスの要素
    int add_address[ROW];
    while(fgets(str1[j],SIZE,fp1)!=NULL){
        //改行文字削除
        strtok(str1[j],"\n");
        //先程のデータに結合する
        strcat(as_str[j],str1[j]);
        //アドレスの割り振りを決定
        add_address[j] = address_elements_count(as_str[j]);
        //構造体に追加
        add_structure(pf,as_str[j],add_address[j]);
        j++;   
    }
    fclose(fp1);
}
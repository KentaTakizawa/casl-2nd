#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

char *assembly_segmentation(char *str){
    char *list;  //出力する文字列
    char *ptr[SIZE];  //分割する文字列
    ptr[0] = NULL;  //ラベルを格納
    ptr[1] = NULL;  //コマンドを格納
    ptr[2] = NULL;  //オペランドを格納
    ptr[3] = NULL;  //オペランドを格納
    ptr[4] = NULL;  //オペランドを格納
    ptr[5] = NULL;  //コメントを格納
    int i = 0,count = 0;

    //空行だったら次へ
    if(strcmp(str,"\n")==0){
        list = NULL;
        fprintf(stderr,"空行があります．\n");
        return list;
    }
    //改行文字の削除
    strtok(str,"\n");
    //1文字目が空白か確認する
    if (str[i]==' '){
        //空行ならラベルはNULLにする
        count++;
    }
    ptr[count] = strtok(str," ");
    //文字列のスペースを削除
    remove_space(ptr[count],strlen(ptr[count]));
    count++;
    //コマンド，オペランド，コメントに分割して格納する
    while(1){
        //コマンドとオペランドはスペースで分離されている
        if(count<2){
            if((ptr[count]=strtok(NULL," "))==NULL){
                break;
            }
        }
        //オペランドの間はコンマで区切られている
        else if(count<4){
            if((ptr[count]=strtok(NULL,","))==NULL){
                break;
            }
        }
        else{
            ptr[count]=strtok(NULL,";");
            break;
        }
        //文字列のスペースを削除
        remove_space(ptr[count],strlen(ptr[count]));
        count++;
    }
    //コメントを削除
    delete_comment(ptr,count);
    //構造体に必要なデータを作成
    //ラベル名,コマンド,オペランド1,オペランド2,オペランド3
    list = structure_data_creation(ptr);
    return list;

}
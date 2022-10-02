#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

int address_elements_count(char *str){
    extern CL cl[28];
    extern GR gr[8];
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
    for(int i=0;i<CL_NUMBER;i++){
        if(strcmp(list[1],cl[i].command)==0){
            //命令，START，ENDのとき
            if(cl[i].command_length<3){
                return cl[i].command_length;
            }
            //1語長・2語長の判定結果を返す
            else if(cl[i].command_length==3){
                return word_length_judge(list[2],list[3],list[4]);
            }
            //DS,DC,IN,OUT,RPUSH,RPOPのとき
            else{
                return cl[i].command_length;
            }
        }
    }
    return -1;
}
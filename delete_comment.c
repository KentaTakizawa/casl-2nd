#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

void delete_comment(char *ptr[100],int count){
    int del_com=0;
     while(del_com<count){
        strtok(ptr[del_com],";");
        del_com++;
    }
}
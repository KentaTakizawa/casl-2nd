#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

char *structure_data_creation(char *ptr[5]){
    int i = 0;
    char *list=NULL;
    list = (char *)malloc(sizeof (char)*50);
    while(i<5){
        if((ptr[i]!=NULL)){
            if(i<4){
                strcat(list,ptr[i]);
                strcat(list,",");
            }
            else{
                strcat(list,ptr[i]);
            }
        }
        else{
            strcat(list,",");
        }
        i++;
    }
    strcat(list,";");
    return list;
}
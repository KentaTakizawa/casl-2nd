#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

char *literal_str(char *str){
    int i=1,j=0;
    char *lstr;
    lstr = (char *)malloc(sizeof(char));
    while(i<strlen(str)){
        lstr[j]=str[i];
        i++;
        j++;
    }
    lstr[j]='\0';
    return lstr;
}
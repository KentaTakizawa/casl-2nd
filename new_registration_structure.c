#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

void new_registration_structure(PF *pf,PF *pf1){
    while(pf1->next!=NULL){
        pf1 = pf1->next;
        registration_structure(pf,pf1);
    }
}
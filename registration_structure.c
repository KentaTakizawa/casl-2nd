#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_data.h"
#include "data.h"
#include "function_list.h"

void registration_structure(PF *pf,PF *pf1){
    PF *new;
    new = (PF *)malloc(sizeof (PF));
    new->address=pf1->address;
    new->label=pf1->label;
    new->command=pf1->command;
    new->operand1=pf1->operand1;
    new->operand2=pf1->operand2;
    new->operand3=pf1->operand3;
    new->cas_file=pf1->cas_file;
    new->necessary_address=pf1->necessary_address;
    new->next=NULL;
    while(pf->next!=NULL) {
        pf = pf->next;
    }
    pf->next = new;
}
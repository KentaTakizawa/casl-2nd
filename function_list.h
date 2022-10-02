#ifndef FUNCTION_LIST_H //二重でincludeされることを防ぐ
#define FUNCTION_LIST_H

void init_list(PF *list);
char *input_filename(void);
int file_detail(FILE *fp,char *filename);
int file_null(FILE *FP,char *filename);
int file_row_count(FILE *fp);
void structure_creation(PF *list);
void store_structure(PF *list,char *filename);
char *assembly_segmentation(char *str);
void remove_space(char *arr, int n);
void delete_comment(char *ptr[100],int count);
char *structure_data_creation(char *ptr[5]);
int address_elements_count(char *str);
int word_length_judge(char *operand1,char *operand2,char *operand3);
void add_structure(PF *pf,char *str,int necessary_address);
void literal(PF *pf);
char *literal_str(char *str);
int literal_num(char *str);
char *literal_list(char *str,char *str1);
int ds_num(char *str);
int label_check(PF *pf);
int syntax_check(PF *pf);
int error_check_structure(PF *pf);
void registration_structure(PF *pf,PF *pf1);
void new_registration_structure(PF *pf,PF *pf1);
#endif
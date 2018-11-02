#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H
#include "student_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void student_to_list(struct student_str **p_head, struct student_str student);
void print_list(struct student_str *phead);
void clear_list(struct student_str **p_head);
void delete_node (struct student_str **p_head, int position);
#endif

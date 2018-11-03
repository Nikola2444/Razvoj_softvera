#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H
#include "student_struct.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
void student_to_list(struct student_str **p_head, struct student_str student);
void print_list(struct student_str *phead);
void clear_list(struct student_str **p_head);
void delete_node (struct student_str **p_head, int position);
void list_to_file(struct student_str *p_head);
void list_from_file (struct student_str **p_head);
int update_student(struct student_str **p_head, int position, char field);
char* remove_commas(char *grades);
#endif

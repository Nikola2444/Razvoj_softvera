#ifndef MENU_FUNCTION_H
#define MENU_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include "student_struct.h"
#include <string.h>
#include "list_functions.h"
void registry(struct student_str **p_head);
char menu ();
void enter_student(struct student_str **p_head);
void update_student_info(struct student_str **p_head);
void search_student(struct student_str *p_head);
#endif

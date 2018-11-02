#ifndef STUDENT_STRUCT_H
#define STUDENT_STRUCT_H
struct student_str
{
   char name[100];
   char surename [100];
   char index_num[100];
   char grades[100];
   struct student_str* next;
  
};
//struct student_str *p_head_global;

#endif

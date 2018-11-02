#ifndef LIST_FUNCTIONS_C
#define LIST_FUNCTIONS_C
#include "list_functions.h"

void student_to_list(struct student_str **p_head, struct student_str student)
{
   struct student_str *p_current;
   
   if (*p_head == NULL)
   {   
      *p_head = (struct student_str*)malloc(sizeof(struct student_str));
      if(*p_head == NULL)
         printf("couldnt allocate memory is add student to list");
      strcpy((*p_head)->name, student.name);
      strcpy((*p_head)->surename, student.surename);
      strcpy ((*p_head)->index_num, student.index_num);
      strcpy((*p_head)->grades, student.grades);
      return;
   }
   else
   {
      
      p_current = *p_head;
      while (p_current->next != NULL)
      {        
         p_current = p_current->next;
      }
      p_current->next = (struct student_str*)malloc(sizeof(struct student_str));
      if(p_current == NULL)
         printf("couldnt allocate memory is add student to list");
      strcpy(p_current->next->name, student.name);
      strcpy(p_current->next->surename, student.surename);
      strcpy (p_current->next->index_num, student.index_num);
      strcpy(p_current->next->grades, student.grades);            
   }
   
      
}
void print_list(struct student_str *p_head)
{
   int i = 0;
   if (p_head == NULL)
      printf("\n list is empty");
   p_head->name[strlen(p_head->name)-1] = '\0';
   p_head->surename[strlen(p_head->surename)-1] = '\0';
   p_head->index_num[strlen(p_head->index_num)-1] = '\0';
   while(p_head != NULL)
   {
      i++;
      printf("\n%d. First name: %s", i, p_head->name);
      printf("    Last name: %s", p_head->surename);
      printf("    Index number: %s", p_head->index_num);
      printf("    Grades: %s", p_head->grades);
      p_head = p_head->next;
   }
   
}
void clear_list(struct student_str **p_head)
{
   struct student_str *p_current = *p_head;
   struct student_str *p_next = p_current->next;
   while(p_current != NULL)
   {
      p_next = p_current->next;
      free (p_current);
      p_current = p_next;
   }

   *p_head = NULL;
   return;
}

void delete_node (struct student_str **p_head, int position)
{
   if (*p_head == NULL)
      return;

   struct student_str *p_temp = *p_head;
   if(position == 0)
   {
      *p_head = p_temp->next;
      free(p_temp);
      return;
   }
   for (int i = 0; p_temp != NULL && i < position-1; ++i)
   {
      p_temp = p_temp->next;
   }

   if (p_temp == NULL || p_temp->next == NULL) 
         return;

   struct student_str *next = p_temp->next->next;

   free (p_temp->next);
   p_temp ->next = next;
}
void list_to_file(struct student_str *p_head)
{
   char *my_string;
   my_string = (char *)malloc(sizeof(char));
   FILE *fp;
   fp = fopen("registry.txt", "w");
   int i = 0;
   while(p_head != NULL)
   {
      i++;
      asprintf (&my_string,"\n%d. First name: %s    Last name: %s   Index num: %s    Grades: %s", i, p_head->name, p_head->surename, p_head->index_num, p_head->grades);
      fputs (my_string, fp);
      free (my_string);
      p_head = p_head->next;
   }
}
#endif

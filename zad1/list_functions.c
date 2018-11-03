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
      asprintf (&my_string,"%d. First name: %s    Last name: %s   Index num: %s    Grades: %s\n", i, p_head->name, p_head->surename, p_head->index_num, p_head->grades);
      fputs (my_string, fp);      
      p_head = p_head->next;
   }
   free(my_string);
}

void list_from_file (struct student_str **p_head)   
{
   FILE *fp;
   char * str;
   size_t num_of_bytes = 1;
   struct student_str s;
   int i = 0;

   
   fp = fopen ("registry.txt", "r");
   if (!fp)
   {
      printf ("\nthe registry is empty");
      return;
   }
   str = (char*)malloc(sizeof(char));
   if (!str)
   {
      printf ("couldnt allocate space in read file");
      return;
   }
   
   while(getline(&str, &num_of_bytes, fp) != EOF)
   {
      sscanf(str, "%d. First name: %s    Last name: %s   Index num: %s    Grades: %s;",&i, s.name, s.surename, s.index_num, s.grades);
      student_to_list(p_head, s);
      
   }
   free (str);
}



void update_student(struct student_str **p_head, int position, char field)
{
   struct student_str *p_current = *p_head;
   char *str;
   size_t num_of_bytes = 1;
   char g1[5];
   char g2[5];
   char g3[5];
   
   
   str = (char *)malloc (sizeof(char));
   
   if (str == NULL)
   {
      printf ("\ncouldnt allocate space for student");
      return;
   }
   
   for (int i = 0; i < position-1; ++i)
   {
      
      if(p_current == NULL)
      {
         printf ("\nthere is no student on that position, try again with another one");
         return;
      }
      p_current = p_current->next;
      print_list(p_current);
   }
   switch (field)
   {
   case 'A':
      printf("\nEnter new name:");
      getline(&str, &num_of_bytes, stdin);
      str[strlen(str)-1] = '\0';
      strcpy(p_current->name,str);

      break;
   case 'B':
      printf("\nEnter new surname:");
      getline(&str, &num_of_bytes, stdin);
      str[strlen(str)-1] = '\0';
      strcpy(p_current->surename,str);

      break;
   case 'C':
      printf("\nEnter new index number:");
      getline(&str, &num_of_bytes, stdin);
      str[strlen(str)-1] = '\0';
      strcpy(p_current->index_num,str);

      break;
   case 'D':
      printf("\nEnter new grade 1:");
      getline(&str, &num_of_bytes, stdin);
      str[strlen(str)-1] = '\0';
      
      printf ("%s",p_current->grades);
      strcpy(g1, str);
    
      strcpy(p_current->grades, g1);
      strcat(p_current->grades, ",");
      strcat(p_current->grades, g2);
      strcat(p_current->grades, ",");
      strcat(p_current->grades, g3);
      strcat(p_current->grades, ";");
      break;
      
      
   }      
   free (str);
}
#endif

#ifndef MENU_FUNCTION_C
#define MENU_FUNCTION_C
#include "menu_functions.h"
void registry (struct student_str **p_head)
{
   char option;
   while(option!= 'E')
   {
      option = menu();
      if (!option)
         printf("could not  allocate memory");
      switch(option)
      {
      case 'A':
         enter_student(p_head);
         break;
      case 'B':
         search_student(*p_head);
         break;
      case 'C':
         print_list(*p_head);
         break;
      case 'D':
         update_student_info(p_head);
         break;
      }
   }
}
char menu()
{
   char *option;
   size_t num_of_bytes= 1;
   char chosen_option;
   printf("\nChose option by typing a letter that specifies your fish\n");
   printf("\nA: Enter new student");
   printf("\nB: Search for a student");
   printf("\nC: Print all students in registry");
   printf("\nD: Change certain students information by entering his id number");
   printf("\nE: Exit");
   option = (char*)malloc (sizeof(char));
   if(option == NULL)
   {
      printf("\ncouldnt allocate space for another student");
      return 0;
   }
   printf("\nOption: ");
   getline (&option, &num_of_bytes, stdin);
   sscanf(option, "%c", &chosen_option);
   free (option);
   printf("\nOption you chose is: %c", chosen_option);
   return chosen_option;
}

void enter_student (struct student_str **p_head)
{
   char *name;
   char *surename;
   char* index_num;
   char* grades;
   size_t num_of_bytes = 1;
   struct student_str s;

   //request for user to enter name
   printf("\nEnter name:");
   name = (char *)malloc(sizeof(char));
   if(name == NULL)
      printf("couldnt allocate memory for name");
   getline(&name, &num_of_bytes, stdin);
   name[strlen(name)-1] = '\0';
   
   //request for user to enter surname
   printf("\nEnter surname:");
   surename = (char *)malloc(sizeof(char));
   if(surename == NULL)
      printf("couldnt allocate memory for surename");
   getline(&surename, &num_of_bytes, stdin);
   surename[strlen(surename)-1] = '\0';
   
   //request for user to enter index_num
   printf("\nEnter index_num:");
   index_num = (char *)malloc(sizeof(char));
   if(index_num == NULL)
      printf("couldnt allocate memory for index_num");
   getline(&index_num, &num_of_bytes, stdin);
   index_num[strlen(index_num)-1] = '\0';
   
   //request for user to enter index_num
   printf("\nEnter grade 1: ");
   grades = (char *)malloc(sizeof(char));
   if(grades == NULL)
      printf("couldnt allocate memory for grades");
   getline(&grades, &num_of_bytes, stdin);
   grades[strlen(grades)-1] = '\0';
   strcpy(s.grades, grades);
   strcat(s.grades, ",");
   printf("\nEnter grade 2: ");
   getline(&grades, &num_of_bytes, stdin);
   grades[strlen(grades)-1] = '\0';
   strcat(s.grades, grades);
   strcat(s.grades, ",");
   printf("\nEnter grade 3: ");
   getline(&grades, &num_of_bytes, stdin);
   grades[strlen(grades)-1] = '\0';
   strcat(s.grades, grades);
   strcat(s.grades, ";");
   //copy entered information into a structure s
   strcpy(s.name, name);
   strcpy(s.surename, surename);
   strcpy(s.index_num, index_num);
   // free allocated memory
   free (name);
   free (surename);
   free (grades);
   free (index_num);
   //add structure s to list
   student_to_list(p_head, s);
}
void update_student_info(struct student_str **p_head)
{
   char *str;
   size_t num_of_bytes = 1;
   int position;
   char option;
   
   printf("\nEnter registry position of student\nPosition:");

   str = (char *)malloc (sizeof(char));
   if (str == NULL)
   {
      printf ("\ncouldnt allocate space for student");
      return;
   }
   getline(&str, &num_of_bytes, stdin);
   sscanf(str, "%d", &position);
   while(1)
   {
      printf ("\nChose a field you want to change:");
      printf("\nA: Name\nB: Surname\nC: Index number\nD: Grade 1\nE: Grade 2\nF: Grade 3\nG: Changes done\noption:");
      getline(&str, &num_of_bytes, stdin);
      sscanf(str, "%c", &option);
      switch (option)
      {
      case 'A':
         if(update_student(p_head, position, 'A')<0)
            return;
         break;
      case 'B':
         if(update_student(p_head, position, 'B')<0)
            return;
         break;
      case 'C':
         if(update_student(p_head, position, 'C')<0)
            return;
         break;
      case 'D':
         if(update_student(p_head, position, 'D')<0)
            return;
         break;
      case 'E':
         if(update_student(p_head, position, 'E')<0)
            return;
         break;
      case 'F':
         if(update_student(p_head, position, 'F')<0)
            return;
         break;
      case  'G':
         return;
         break;
      }
   }
   free (str);
}
void search_student(struct student_str *p_head)
{
   char *str;
   str = (char*)malloc(sizeof(char));
   size_t num_of_bytes = 1;
   int i = 0;
   char *p;
   char prezime[] = "Kovacevic";
   if(str == NULL)
   {
      printf ("memory problem couldnt alocate memory try again later");
      return;
   }
   
   printf ("\nEnter first few words of a students surname:");
   getline(&str, &num_of_bytes, stdin);
   printf ("\nStudent with surname that consisnt out of that word are:\n");
   str[strlen(str)-1] = '\0';


   while(p_head != NULL)
   {
      i++;
      p = strstr(p_head->surename,str);
      if (p)
         printf ("\n%d. %s;%s;%s;%s\n", i, p_head->name, p_head->surename, p_head->index_num, p_head->grades);
      p_head = p_head->next;
   }
      
      

}
#endif

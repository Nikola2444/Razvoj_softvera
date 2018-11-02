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
         
         break;
      case 'C':
         print_list(*p_head);
         break;
      }
   }
}
char menu()
{
   char *option;
   size_t num_of_bytes= 1;
   char chosen_option;
   printf("\nchose option by typing a letter that specifies your fish\n");
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
   printf("\noption: ");
   getline (&option, &num_of_bytes, stdin);
   sscanf(option, "%c", &chosen_option);
   free (option);
   printf("\noption you chose is: %c", chosen_option);
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
   printf("\nenter name:");
   name = (char *)malloc(sizeof(char));
   if(name == NULL)
      printf("couldnt allocate memory for name");
   getline(&name, &num_of_bytes, stdin);
   name[strlen(name)-1] = '\0';
   printf("\nenter surename:");
   surename = (char *)malloc(sizeof(char));
   if(surename == NULL)
      printf("couldnt allocate memory for surename");
   getline(&surename, &num_of_bytes, stdin);
   surename[strlen(surename)-1] = '\0';
   printf("\nenter index_num:");
   index_num = (char *)malloc(sizeof(char));
   if(index_num == NULL)
      printf("couldnt allocate memory for index_num");
   getline(&index_num, &num_of_bytes, stdin);
   index_num[strlen(index_num)-1] = '\0';
   printf("\nenter grades:");
   grades = (char *)malloc(sizeof(char));
   if(grades == NULL)
      printf("couldnt allocate memory for grades");
   getline(&grades, &num_of_bytes, stdin);
   grades[strlen(grades)-1] = '\0';
   strcpy(s.name, name);
   strcpy(s.surename, surename);
   strcpy(s.index_num, index_num);
   strcpy(s.grades, grades);

   free (name);
   free (surename);
   free (grades);
   free (index_num);
            
   student_to_list(p_head, s);
}
#endif

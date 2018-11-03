#include <stdio.h>
#include <stdlib.h>
#include "student_struct.h"
#include <string.h>
#include "list_functions.h"
#include "menu_functions.h"
int main ()
{
   
   struct student_str s1,s2;
   struct student_str *p_head = NULL;
   
   int end_insertion = 1;
   list_from_file(&p_head);
   registry(&p_head);
   //print_list(p_head);
   list_to_file(p_head);
   clear_list(&p_head);
   
   
   
   return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include "student_struct.h"
#include <string.h>
#include "list_functions.h"
#include "menu_functions.h"
int main ()
{
   
   struct student_str s1,s2;
   p_head_global = NULL;
   int end_insertion = 1;
   registry();
   print_list(p_head_global);
   clear_list(&p_head_global);
   
   
   return 0;
}



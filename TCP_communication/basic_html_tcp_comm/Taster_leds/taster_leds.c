#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main ()
{
  FILE* fp1, *fp2;
  FILE* led_f;
  int num_of_bytes = 1;
  int t1, t2;
  char *str;
  int s_diff1 = 1;
  int s_diff2 = 0;
  int period = 2000;
  double perc  = 0.00;
  while(1)
    {
      //read taster 50
      fp1 = fopen("/sys/class/gpio/gpio956/value", "r");
      if(fp1==NULL) {
	puts("Problem pri otvaranju 1. fajla");
        return 0;
      }
      str = (char *)malloc(num_of_bytes+1); 
      getline(&str, &num_of_bytes, fp1);
      
      sscanf(str, "%d", &t1);
      free (str);
      if(fclose(fp1)) {
	puts("Problem pri zatvaranju 1. fajla");
        return 0;
      }

      //read taster 51
      fp2 = fopen ("/sys/class/gpio/gpio957/value", "r");
      if(fp2==NULL) {
	puts("Problem pri otvaranju 2. fajla");
        return 0;
      }
      str = (char *)malloc(num_of_bytes+1); 
      getline(&str, &num_of_bytes, fp2);
      if(fclose(fp2)) {
	puts("Problem pri zatvaranju 2. fajla");
        return 0;
      }
      sscanf(str, "%d", &t2);
      //softversko diferenciranje taster 1
      if(t1 == 1 && s_diff1 == 1)
	{
	  s_diff1 = 0;
          led_f = fopen ("/proc/myled", "w");
          if(!led_f)
          {
            puts("\nproblem pri otvaranju led fajla");
            return 0;
          }
          // upis hex vrednosti 0x0 u led fajl
          fputs ("0xf\n", led_f);
          if(fclose(led_f))
            puts("doslo je do greske prilikom zatvaranja fajla");
	}

      else if(t1 == 0)
	s_diff1 = 1;
      //softversko diferenciranje taster 2
      if(t2 == 1 && s_diff2 == 1)
	{	 
	  s_diff2 = 0;
          led_f = fopen("/proc/myled", "w");
          if(!led_f)
          {
            puts("\nproblem pri otvaranju led fajla");
            return 0;
          }
          // upis hex vrednosti 0x0 u led fajl
          fputs("0x0\n", led_f);
          if(fclose(led_f))
            puts("doslo je do greske prilikom zatvaranja fajla");
	}
      else if(t2 == 0)
	s_diff2 = 1;

    }
  return 0;
}

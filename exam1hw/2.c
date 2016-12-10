

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
  
  int num = atoi(argv[1]);
  int binary[1000000];
  if (argv[1] == NULL|| argc == 1) {
    printf("Error, no argument");
    exit(1);
  }
  
  //int binary;
  int i = 1;
  printf("Binary: 0b");
  while (num > 0) {
    if ((num % 2) == 1)
      binary[i++] = 1;
    else
      binary[i++] = 0;
    num = num / 2;
  }
  int j = i - 1;
  for (j; j > 0; j--) {
    printf("%d", binary[j]);
  }
  
  printf("\nHexadecimal: 0x");
  
  num = atoi(argv[1]);
  char hex[100000];
  i = 1;
  while (num > 0) {
    //printf("yee");
    switch(num % 16) {
      case 0:
        hex[i] = '0';
	break;
	case 1:
	  hex[i] = '1';
	  break;
	case 2:
	  hex[i] = '2';
	  break;
	case 3:
	  hex[i] = '3';
	  break;
	case 4:
	  hex[i] = '4';
	  break;
	case 5:
	  hex[i] = '5';
	  break;
	case 6:
	  hex[i] = '6';
	  break;
	case 7:
	  hex[i] = '7';
	  break;
	case 8:
	  hex[i] = '8';
	  break;
	case 9:
	  hex[i] = '9';
	  break;
      case 10:
        hex[i] = 'A';
	break;
	case 11:
	   hex[i] = 'B';
	   break;
	 case 12:
	   hex[i] = 'C';
	   break;
	 case 13:
	   hex[i] = 'D';
	 case 14:
	   hex[i] = 'E';
	   break;
	 case 15:
	   hex[i] = 'F';
	   break;
	 default:
	   hex[i] = num % 16;
	   break;
	}
	i++;
	num = num / 16;
	}
   j = i-1;
   for (j; j > 0; j--) {
     printf("%c", hex[j]);
   }

  }


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE * fd, char * p , int len) {
    // Add your code here.
    // You may see p as an array.
    // p[0] will return the element 0 
    // p[1] will return the element 1 and so on
    //
    
    
      fprintf(fd, "0x%016lX: ", (unsigned long) p);
      for (int i = 0; i <= len-1; i++)  {
        int c = p[i]&0xFF;
       
        fprintf(fd, "%02X ", c);
        if (i == (len-1) && (i % 16 != 15)) {
	  int k = i;
	  for(k; k%16 != 15; k++) {
	    fprintf(fd, "   ");
	  }
	  fprintf(fd, " ");
	  for (int j = k - 15; j <= i; j++) {
	    int d = p[j]&0xFF;
	    fprintf(fd, "%c", (32<=d && d<=127)?d:'.');
	  }
	  fprintf(fd, "\n");
	}
        //fprintf(fd, "%02d  ", i);
	if(i%16 == 15) {
	  fprintf(fd, " ");
	  for (int j = i-15; j <= i; j++) {
	    int d = p[j]&0xFF;
	    fprintf(fd, "%c", (32<=d && d<=127)?d:'.');
	  }
	  fprintf(fd,"\n");
	  if (i < (len - 1)) 
	    fprintf(fd, "0x%016lX: ", (unsigned long) (p+i+1));
	}
     }
   } 
    //fprintf(fd, "0x%016lX: ", (unsigned long) p);
    //int c = p[0]&0xFF;

    // Print first byte as hexadecimal
    //fprintf(fd, "%02X ", c);

    // Print first byte as character
    //fprintf(fd, "%c", (32<=c<=127)?c:'.');
    //fprintf(fd,"\n");  

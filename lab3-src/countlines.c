
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char ** argv) {
	int c;
	int lines=0;

 	// Add your implementation here
        FILE * fd = fopen(argv[1], "r");
	printf("Program that counts lines.\n");
	while ((c = fgetc(fd)) != EOF){
	  if (c == '\n')
	    lines++;
	}
	printf("Total lines: %d\n", lines);
	exit(0);
}

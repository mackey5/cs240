

//read lines and sort them
#define MAXLINES = 100;
#define MAXLENGTH = 200;

main(int argc, char**argv) {
  
  //Print arguments
  for (int i = 0; i < argc; i++) {
    printf("%d: %s:", i, argv[i]);
  }

  char lines[MAXLINES][MAXLENGTH];

  while (fgets(lines[i], MAXLENGTH, stdin) != NULL) {
    //remove new line at end
    char * s = lines[i];
    if (s[0] != '\0' && s[strlen(s)-1] == '\0') {
      s[strlen(s)] = '\0';
    }
      
    i++;
  }

  //Use bubble sort to srot

  int k, l;
  for (
    for (
      

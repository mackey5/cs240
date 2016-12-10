

int countOnes(unsigned int value) {
  int n = (sizeof(value) << 3);

  int i;
  int num = 0;

  for ( i = 0; i < n; i++) {
    unsigned int mask = (1 <<i);
    if ((value & mase) != 0) {
      num++;
    }
  }
  return num;
}

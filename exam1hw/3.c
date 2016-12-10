

#include <stdlib.h>
#include <stdio.h>

  void printArray(int rows, int cols, double matrix[rows][cols]) {
    int i = 0;
    for (i; i < rows; i++) {
      int j = 0;
      for (j; j < cols; j++) {
        printf("%.1lf ", matrix[i][j]);
	}
	printf("\n");
	j = 0;
	}
  }

int main() {
  
  int rows, cols;

  scanf("%d", &rows);
  scanf("%d", &cols);

  double matrix[rows][cols];

  //printf("Original Matrix:\n");

  int i = 0;
  int j = 0;
  for (i; i < rows; i++) {
    for (j; j < cols; j++) {
      scanf("%lf", &matrix[i][j]);
    }
    j = 0;
  }
  printf("Orifinal Matrix:\n");
  printf("%d %d\n", rows, cols);
  printArray(rows, cols, matrix);
  }



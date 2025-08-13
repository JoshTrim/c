#include <stdio.h>
#include <stdlib.h>

FILE *load_file(char *file_path) {
  FILE *fp = fopen(file_path, "r");

  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  return fp;
}

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("zip: file1 [file2...]\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    printf("arg: %d value: %s\n", i, argv[i]);
  }
}

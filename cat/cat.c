#include <stdio.h>
#include <stdlib.h>

FILE *load_file(char *file_path) {
  FILE *fp = fopen(file_path, "r");
  if (fp == NULL) {
    perror("Unable to open file\n");
    exit(EXIT_FAILURE);
  }
  return fp;
}

void read_file(FILE *fp) {
  char buf[10];

  while (fgets(buf, sizeof(buf), fp) != NULL) {
    printf("%s", buf);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("usage: cat filename\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    FILE *fp = load_file(argv[i]);
    read_file(fp);
  }
  exit(EXIT_SUCCESS);
}

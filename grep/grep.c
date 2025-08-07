#include <stdio.h>

FILE *load_file(char *file_path) {
  FILE *fp = fopen(file_path, "r");
  return fp;
}

void read_file(FILE *fp) {}

void grep(char *needle, char *haystack) {}

int main(int argc, char *argv[]) {
  FILE *fp = load_file(argv[1]);
  read_file(fp);

  char *search;
  char *line;
  grep(search, line);
}

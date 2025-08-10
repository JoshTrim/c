#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct program_mode {
  bool numbered;
};

FILE *load_file(char *file_path) {
  FILE *fp = fopen(file_path, "r");
  if (fp == NULL) {
    perror("Unable to open file\n");
    exit(EXIT_FAILURE);
  }
  return fp;
}

void read_file(FILE *fp, struct program_mode mode) {
  char buf[100];
  int i = 1;

  while (fgets(buf, sizeof(buf), fp) != NULL) {

    if (mode.numbered == true) {
      printf("%d: ", i);
      i++;
    }
    printf("%s", buf);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("usage: cat filename\n");
    exit(EXIT_FAILURE);
  }

  struct program_mode mode;

  int c;
  while ((c = getopt(argc, argv, "n")) != -1) {
    switch (c) {
    case 'n':
      mode.numbered = true;
      break;
    }
  }
  int i;
  if (argc == 1) {
    i = 1;
  } else {
    i = 2;
  }

  for (; i < argc; i++) {
    FILE *fp = load_file(argv[i]);
    read_file(fp, mode);
  }
  exit(EXIT_SUCCESS);
}

// flags to implement
/*
 *
 * -b      Number the non-blank output lines, starting at 1.
 *  -e      Display non-printing characters (see the -v option), and display a
 * dollar sign (‘$’) at the end of each line. -l      Set an exclusive advisory
 * lock on the standard output file descriptor.  This lock is set using fcntl(2)
 * with the F_SETLKW command.  If the output file is already locked, cat will
 * block until the lock is acquired. -n      Number the output lines, starting
 * at 1. -s      Squeeze multiple adjacent empty lines, causing the output to be
 * single spaced. -t      Display non-printing characters (see the -v option),
 * and display tab characters as ‘^I’. -u      Disable output buffering. -v
 * Display non-printing characters so they are visible.  Control characters
 * print as ‘^X’ for control-X; the delete character (octal 0177) prints as
 * ‘^?’.  Non-ASCII characters (with the high bit set) are printed as ‘M-’ (for
 * meta) followed by the character for the low 7 bits.
 */

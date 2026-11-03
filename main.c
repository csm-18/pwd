#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *VERSION;
const char *HELP;

void print_physical_path();
void print_logical_path();
void panic(char *msg);

int main(int argc, char **argv) {

  if (argc == 1) {
    print_logical_path();
  } else if (argc == 2) {
    if (strcmp(argv[1], "-v") == 0) {
      puts(VERSION);
    } else if (strcmp(argv[1], "-h") == 0) {
      puts(VERSION);
      puts(HELP);
    } else if (strcmp(argv[1], "-P") == 0) {
      print_physical_path();
    } else if (strcmp(argv[1], "-L") == 0) {
      print_logical_path();
    } else {
      panic("error: Unknown command!");
    }
  } else {
    panic("error: Unknown command!");
  }

  return 0;
}

const char *VERSION = "pwd 1.0.0";
const char *HELP =
    "A reimplementation of the Linux command 'pwd' in C.\n"
    "It displays logical or physical path to current working directory.\n"
    "\n"
    "Commands:\n"
    "  pwd <no args>      -> Print logical path to current working "
    "directory.\n"
    "  pwd -L             -> Print logical path to current working "
    "directory.\n"
    "  pwd -P             -> Print physical path to current working "
    "directory.\n"
    "  pwd -v             -> Print pwd version.\n"
    "  pwd -h             -> Print pwd help.\n"
    "\n"
    "Author: csm\n"
    "License: MIT\n";

void print_physical_path() {
  char *cwd = getcwd(NULL, 0);
  if (cwd == NULL) {
    panic("internal error!");
  }

  puts(cwd);
  free(cwd);
}

void print_logical_path() {
  char *cwd = getenv("PWD");

  if (cwd != NULL) {
    puts(cwd);
    return;
  }

  print_physical_path();
}

void panic(char *msg) {
  puts(msg);
  exit(1);
}

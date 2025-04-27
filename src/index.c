#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * NOTE:
 * PRINTING SECTION
 */

void show_help(void)
{
  printf("kb usage:\n"
         "  -h, --help : show this message\n\n"
         "  commands:\n"
         "    a, add\n"
         "      add something to kb\n"
         "    rm, remove\n"
         "      delete something from kb"
         "\n");
}

void print_not_command(char *cmd)
{
  printf("kb: unknown command '%s'\n", cmd);
}

void print_unknown_option(char *option)
{
  printf("kb: unknown option '%s'\n", option);
}

/**
 * NOTE:
 * UTILITIES SECTION
 */

bool are_strings_same(char *str_1, char *str_2)
{
  return strcmp(str_1, str_2) == 0;
}

/* --- */

int main(int argc, char *argv[])
{
  if (argc == 1) {
    show_help();
    return 1;
  }

  // TODO:
  // logic for adding, removing from kb

  // BUG:
  // if argv does not exist here, breakage
  if (are_strings_same(argv[1], "-h") || are_strings_same(argv[1], "--help")) {
    show_help();
    return 0;
  }

  if (strstr(argv[1], "-") != NULL || strstr(argv[1], "---") != NULL) {
    print_unknown_option(argv[1]);
    return 1;
  }

  print_not_command(argv[1]);
  return 1;

  return 0;
}

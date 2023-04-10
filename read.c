#include <ctype.h>
#include <string.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

char *trim(char *str) {
  size_t len = strlen(str);
  char *end = str + len - 1;

  while (isspace(*str)) {
    str++;
  }
  while (end > str && isspace(*end)) {
    end--;
  }
  *(end + 1) = '\0';

  return str;
}
char* print_until_match(char *line, size_t length, FILE *fp, char *target) {
  ssize_t read;
  while (((read = getline(&line, &length, fp)) != -1) &&
         strstr(line, target) == NULL) {
    line = trim(line);
    line += 2;
    printf("%s\n", line);
  }
  return line;
}

int main(void) {
  FILE *fp;
  char *line = NULL;
  size_t length = 0;
  ssize_t read;

  fp = fopen("main.yaml", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  while (((read = getline(&line, &length, fp)) != -1) &&
         strstr(line, "brew_casks") == NULL) {
  }
  line = print_until_match(line, length, fp, "brew_packages");
  line = print_until_match(line, length, fp, "brew_tap");
  fclose(fp);
  exit(EXIT_SUCCESS);
}

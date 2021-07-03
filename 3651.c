#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER 100001

void strtolower(char * str);

int main () {
  char haystack[BUFFER];
  char needle[10] = "zelda";

  scanf("%s", haystack);
  strtolower(haystack);

  if (strstr(haystack, needle)) {
    printf("Link Bolado\n");
  } else {
    printf("Link Tranquilo\n");
  }
  
  return(0);
}

void strtolower(char * str) {
  unsigned int i;

  for (i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

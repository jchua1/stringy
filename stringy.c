#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jstrlen(char *str) {
  int len = 0;
  while (*str) {
    len++;
    str++;
  }
  return len;
}

char * jstrcpy(char *dest, char *source) {
  int len = jstrlen(source);
  int i;
  for (i = 0; i < len; i++)
    dest[i] = source[i];
  dest[len] = 0;
  return dest;
}

char * jstrncpy(char *dest, char *source, int n) {
  int i;
  for (i = 0; i < n && source[i] != 0; i++)
    dest[i] = source[i];
  dest[i] = 0;
  return dest;
}

char * jstrcat(char *dest, char *source) {
  int dlen = jstrlen(dest);
  int slen = jstrlen(source);
  int i;
  for (i = dlen; i < dlen+slen; i++)
    dest[i] = source[i-dlen];
  dest[i] = 0;
  return dest;
}

char * jstrncat(char *dest, char *source, int n) {
  int dlen = jstrlen(dest);
  int i;
  for (i = dlen; i < dlen+n && source[i-dlen] != 0; i++)
    dest[i] = source[i-dlen];
  dest[i] = 0;
  return dest;
}

int jstrcmp(char *s1, char *s2) {
  int i;
  for (i = 0; s1[i] != 0 && s2[i] != 0; i++)
    if (s1[i] != s2[i])
      return s1[i] - s2[i];
  return 0;
}

char * jstrchr(char *s, char c) {
  int len = jstrlen(s);
  int i;
  for (i = 0; i < len; i++)
    if (s[i] == c)
      return s+i;
  return NULL;
}

//Test cases are from Kenneth Li
int main() {
  char s[1024] = "cat";
  char js[1024] = "cat";

  printf("INITIAL:\n");
  printf("s = %s\n", s);
  printf("js = %s\n", js);
  printf("\n");

  strcpy(s, "dog");
  jstrcpy(js, "dog");

  printf("strcpy(s, \"dog\")\n");
  printf("jstrcpy(js, \"dog\")\n");
  printf("s = %s\n", s);
  printf("js = %s\n", js);
  printf("\n");

  strncpy(s, "turtle", 3);
  jstrncpy(js, "turtle", 3);

  printf("strncpy(s, \"tur\", 3)\n");
  printf("jstrncpy(js, \"tur\", 3)\n");
  printf("s = %s\n", s);
  printf("js = %s\n", js);
  printf("\n");

  printf("strcat(s, \"bat\") = %s\n", strcat(s, "bat"));
  printf("jstrcat(js, \"bat\") = %s\n", jstrcat(js, "bat"));
  printf("strncat(s, \"bat\", 2) = %s\n", strncat(s, "bat", 2));
  printf("jstrncat(s, \"bat\", 2) = %s\n", jstrncat(js, "bat", 2));
  printf("\n");

  printf("strcmp(s, \"turbatba\") = %d\n", strcmp(s, "turbatba"));
  printf("strcmp(s, \"turdog\") = %d\n", strcmp(s, "turdog"));
  printf("jstrcmp(js, \"turbatba\") = %d\n", jstrcmp(js, "turbat"));
  printf("jstrcmp(js, \"turdog\") = %d\n", jstrcmp(js, "turdog"));
  printf("\n");

  printf("strchr(s, 'u') = %s\n", strchr(s, 'u'));
  printf("strchr(s, 'j') = %s\n", strchr(s, 'j'));
  printf("jstrchr(js, 'u') = %s\n", jstrchr(js, 'u'));
  printf("jstrchr(js, 'u') = %s\n", jstrchr(js, 'j')); 
  
  return 0;
}

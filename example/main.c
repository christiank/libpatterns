/*
 * Sample program for libpatterns
 * Christian Koch <cfkoch@edgebsd.org>
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "patterns.h"

struct pair {
  char *string;
  char *pattern;
};


int
main(void)
{
  const struct pair pairs[] = {
    {"hello", "h"},
    {"555-1234", "%d+-%d+"},
    {"555-1234", "(%d+)-(%d+)"},
    {"foo", "bar"},
    {NULL, NULL}
  };

  int i;
  int rv;

  for (i = 0; (pairs[i].string != NULL) && (pairs[i].pattern != NULL); i++) {
    struct str_match match;
    char *error_buf = NULL;

    error_buf = malloc(LINE_MAX);

    rv = str_match(pairs[i].string, pairs[i].pattern, &match, &error_buf);

    printf("string=  %s\n", pairs[i].string);
    printf("pattern= %s\n", pairs[i].pattern);
    printf("%s\n", (rv ? "NO MATCH" : "YES MATCH"));

    for (int j = 0; j < match.sm_nmatch; j++) {
      printf("\t- %s\n", match.sm_match[j]);
    }

    printf("-----\n");

    free(error_buf);
    str_match_free(&match);
  }

	return EXIT_SUCCESS;
}

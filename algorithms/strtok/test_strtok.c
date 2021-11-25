/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <string.h>

int main () {
   char str[80] = "1 + 2 * 3 - 4";
   char const *s = " ";
   char *token;
   
   token = strtok(str, s);
   
   while( token != NULL ) {
      printf("%s\n", token );
      token = strtok(NULL, s);
   }
   
   return(0);
}


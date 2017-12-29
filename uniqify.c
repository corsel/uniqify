#include "definitions.h"
#include <dirent.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DIR* primary_dir = 0;
DIR** secondary_dirs = 0;
int num_secondary_dirs = 0;

ERRCODE get_hash(char* arg_filename, HASH_VAL arg_hash)
{
  FILE* file = fopen(arg_filename, "r");
  if (!file)
  {
    LOG(File not found.)
    return ERR_FILE_NOT_FOUND;
  }
  
  SHA_CTX context;
  SHA1_Init(&context);
  
  char my_char;
  while ((my_char = getc(file)) != EOF)
  {
    SHA1_Update(&context, (void*) &my_char, sizeof(char));
  }
  SHA1_Final(arg_hash, &context);
  
  return ERR_SUCCESS;
}

ERRCODE traverse_directory(DIR* arg_dir, char* arg_dir_name)
{
  arg_dir = opendir(arg_dir_name);
  if (!arg_dir)
  {
    LOG(Directory not found.);
    return ERR_DIR_NOT_FOUND;
  }
  LOG(Directory opened successfully.)
  
  struct dirent* curr_file;
  while ((curr_file = readdir(arg_dir)) != NULL)
  {
    char* name = curr_file->d_name;
    if (strcmp(name, "..") == 0 || strcmp(name, ".") == 0)
      continue;
    char* long_name = malloc((strlen(arg_dir_name) + strlen(name) + 1) * sizeof(char));
    strcpy(long_name, arg_dir_name);
    if (*(strchr(long_name, '\0') - 1) != '/')
      strcat(long_name, "/");
    strcat(long_name, name);
    
    printf("%s:\n", long_name);
    HASH_VAL hash;
    memset(hash, 0, sizeof(HASH_VAL));
    get_hash(long_name, hash);
    
    int i = 0; printf("\n");
    for (i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
      printf("\n%020X", hash[i]);
    }
    printf("\n");
  }

  return ERR_SUCCESS;
}

int main(int argc, char* argv[])
{	
  if (argc <= 1)
  {
    printf("No arguments given, terminating...\n");
    return ERR_NO_ARGS_GIVEN;
  }
  num_secondary_dirs = argc - 2;
  if (num_secondary_dirs > 0)
  {
    secondary_dirs = malloc(sizeof(DIR*) * num_secondary_dirs);
  }
  if(!traverse_directory(primary_dir, argv[1]))
  {
    ;
  }
  
  printf("fin.\n");
  int dummy = 0;
  scanf("%d", &dummy);
  return 0;
}

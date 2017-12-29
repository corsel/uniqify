#ifndef _DEFINITIONS_H_INCLUDED
#define _DEFINITIONS_H_INCLUDED

#include <openssl/sha.h>

// TODO: define a LOG macro for else case.
#ifdef _DEBUG
  #define LOG(msg) printf("debug - %s: %s\n", __func__, #msg);
#else // _DEBUG
  #define LOG(msg)
#endif // _DEBUG

// Error codes
#define ERR_SUCCESS         0x00
#define ERR_NO_ARGS_GIVEN   0x01
#define ERR_DIR_NOT_FOUND   0x02
#define ERR_FILE_NOT_FOUND  0x03

// Type definitions and values
#define TRUE 0xFF
#define FALSE 0x00

typedef char BOOL;
typedef char ERRCODE;
typedef char HASH_VAL[SHA_DIGEST_LENGTH];

#endif // _DEFINITIONS_H_INCLUDED

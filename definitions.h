#ifndef _DEFINITIONS_H_INCLUDED
#define _DEFINITIONS_H_INCLUDED

#ifdef _DEBUG
  #define LOG(msg) printf("debug - %s: %s\n", __func__, #msg);
#endif // _DEBUG

// Error codes
#define ERR_SUCCESS 0x00
#define ERR_NO_ARGS_GIVEN 0x01
#define ERR_DIR_NOT_FOUND 0x02

// Type definitions and values
#define TRUE 0xFF
#define FALSE 0x00

typedef char BOOL;
typedef char ERRCODE;

#endif // _DEFINITIONS_H_INCLUDED

#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSEMBLER_ERROR -1
#define ASSEMBLER_CORRECT 0
int REGISTER_ERROR;
int INSTRUCTION_ERROR;
int IMMEDIATE_ERROR;
void dump_code(FILE *file_, uint32_t code);

void dump_error_information(FILE *file_);

int32_t str_to_uint(char* x);

uint32_t change(char* x);

char* extract_char(char* x);

uint32_t extract_reg_12(char* x);

uint32_t str_to_uint_12(char* x);

uint32_t extract_reg_13(char* x);

uint32_t str_to_uint_13(char* x);

uint32_t extract_reg_32(char* x);

uint32_t str_to_uint_32(char* x);

uint32_t extract_reg_21(char* x);

uint32_t str_to_uint_21(char* x);
#endif

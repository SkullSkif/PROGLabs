#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 4096

void compress(char* input, char* output);

void decompress(char* input, char* output);

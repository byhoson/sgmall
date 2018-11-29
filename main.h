#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int number;
	char id[50];
	char pw[50];
	char name[50];
	char address[200];
	int deposit; // money
	int status; // 1: ordinary, -1: resigned
	int flag; // 1 if customer found, 0 otherwise
} customer;

#endif

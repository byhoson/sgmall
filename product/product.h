#ifndef PRODUCT
#define PRODUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../main.h"
#include "../customer/customer.h"


void handle_product(customer*);
product search_by_number(int);
void search_by_name();
void search_by_category();
void search_all();
//void erase_new_line(char*);

#endif

#ifndef ADMIN
#define ADMIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../main.h"
#include "../product/product.h"

void handle_admin();
void handle_history();
void update_delivery();
void see_customers();
void add_product();
void update_product();
void edit_product(int);
void delete_product(int);

#endif

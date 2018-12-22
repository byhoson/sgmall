#ifndef CUSTOMER
#define CUSTOMER

#include <stdio.h>

#include "../main.h"
#include "../product/product.h"


void handle_customer (customer);
void handle_deposit(customer*);
void push_money(customer*);
void pop_money(customer*);
void handle_order(customer*,product);
void update_history(customer,product);
void update_profile(customer*);
void edit_profile(customer*);
void delete_profile(customer*);

#endif

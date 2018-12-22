#include "main.h"
#include "login/login.h"
#include "customer/customer.h"
#include "signup/signup.h"
#include "product/product.h"
#include "admin/admin.h"


int main() {

//	while(1) {
	
	int input,flag=1;
	customer me;
	me.flag=0; // not logged in

	while(flag) {
	printf("==============================\n");
	printf("SG_MALL에 오신 것을 환영합니다.\n");
	printf("1. 회원 로그인\n");
	printf("2. 회원 가입\n");
	printf("3. 상품 검색\n");
	printf("4. 관리자 로그인\n");
	printf("5. 종료\n");
	printf("------------------------------\n");
	printf("선택: ");

	scanf("%d",&input);


	switch(input) {
		case 1: 
			me = customer_login();
			if(me.flag) {
				handle_customer(me);	
			} else {
				printf("fuck you\n");
			}
			break;
		case 2: 
			signup();
			break;
		case 3: 
			handle_product(&me);
			break;
		case 4: 
			if(admin_login()) {
				handle_admin();
			} else {
				printf("fuck you\n");
			}
			break;	
		case 5: 
			flag = 0;
			break;
		default:
			printf("##### 잘못된 입력입니다. #####\n");
			break;

	}

	
	} // end while
	return 0;
}


// fgets 함수를 사용할때 입력된newline character를 제거
void erase_new_line(char* str) {
	int i=0;
	while(str[i] != '\n') {
		i++;
	}
	str[i] = '\0';
}

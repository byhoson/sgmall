#include "main.h"
#include "login/login.h"
#include "customer/customer.h"
#include "signup/signup.h"
#include "product/product.h"

int main() {
	
	int input;
	customer me;

	printf("SG_MALL에 오신 것을 환영합니다.\n");
	printf("1. 회원 로그인\n");
	printf("2. 회원 가입\n");
	printf("3. 상품 검색\n");
	printf("4. 관리자 로그인\n");
	printf("5. 종료\n");

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
			handle_product();
			break;
		case 4: 
			printf("구현 중..\n");
			break;
		case 5: 
			printf("구현 중..\n");
			break;
		//defalut: break;
	}

	

	return 0;
}

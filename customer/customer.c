#include "customer.h"

void handle_customer(customer me) {
	int input,flag=1;
	while(flag) {
		printf("========================\n");
		printf("%s님, SG-MALL에 오신 것을 환영합니다.\n",me.name);	
		printf("1. 회원정보 수정\n");
		printf("2. 가상계좌 입금 및 출금\n");
		printf("3. 상품 검색\n");
		printf("4. 구매 내역 조회\n");
		printf("5. 배송 내역 조회\n");
		printf("6. 로그아웃 및 종료\n");
		printf("선택: ");
		scanf("%d",&input);

		switch(input) {
			case 3:
				handle_product();
				break;
			case 6:
				flag = 0;
				break;
		}
	}
}

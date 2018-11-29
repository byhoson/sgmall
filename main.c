#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "login/login.h"

int main() {
	
	int input;

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
			login();
			break;
		case 2: 
			printf("구현 중..\n");
			break;
		case 3: 
			printf("구현 중..\n");
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

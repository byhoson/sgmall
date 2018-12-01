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
			case 2:
				handle_deposit(me);
				break;
			case 3:
				handle_product();
				break;
			case 6:
				flag = 0;
				break;
		}
	}
}

void handle_deposit(customer me) {

	int input;

	printf("=====================\n");
	printf("내 가상계좌 입금 및 출금\n");
	printf("내 가상계좌 잔액: %d\n",me.deposit);
	printf("---------------------\n");
	printf("1. 입금하기\n");
	printf("2. 출금하기\n");
	printf("0. 이전 페이지로 돌아가기\n");

	scanf("%d",&input);

	switch(input) {
		case 1: push_money(me); break;
		case 2: pop_money(me); break;
	}
}

void push_money(customer me) {
	int money;
	FILE* fp = fopen("customer.csv","r");;//TODO update file
	FILE* temp = fopen("temp.csv","w");
	char buffer[500];


	printf("-------------------\n");
	printf("입금금액 입력: ");
	scanf("%d",&money);
	me.deposit += money;

	printf("me.number: %d\n",me.number);

	for(int i=0; i<me.number; i++) {
		fgets(buffer,500,fp);
		fputs(buffer,temp);
	}

	fgets(buffer,500,fp);
	fprintf(temp,"%d,%s,%s,%s,%s,%d,%d\n",me.number,me.id,me.pw,me.name,me.address,me.deposit,me.status);

	while(fgets(buffer,500,fp)) {
		fputs(buffer,temp);
	}

	remove("customer.csv");
	rename("temp.csv","customer.csv");

	printf("입금이 완료되었습니다.\n");
	printf("현재 잔액: %d\n",me.deposit);
	
	fclose(fp);
	fclose(temp);
}

void pop_money(customer me) {

}



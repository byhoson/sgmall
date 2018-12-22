#include "customer.h"

// 사용자 관련 기능의 진입점.
void handle_customer(customer me) {
	int input,flag=1;
	while(flag) {
		printf("==============================\n");
		printf("%s님, SG-MALL에 오신 것을 환영합니다.\n",me.name);
		printf("내 잔액: %d\n",me.deposit);

		printf("------------------------------\n");
		printf("1. 회원정보 수정 및 탈퇴\n");
		printf("2. 가상계좌 입금 및 출금\n");
		printf("3. 상품 검색\n");
		printf("4. 구매 내역 조회 (준비 중)\n");
		printf("5. 배송 내역 조회 (준비 중)\n");
		printf("6. 로그아웃 및 종료\n");
		printf("------------------------------\n");
		printf("선택: ");
		scanf("%d",&input);

		switch(input) {
			case 1:
				update_profile(&me);
				break;
			case 2:
				handle_deposit(&me);
				break;
			case 3:
				handle_product(&me);
				break;
			case 6:
				flag = 0;
				break;
			default: 
				printf("##### 잘못된 입력입니다. #####\n");
				break;
		}

		if(me.status == -1) break;
	}
}

// 회원정보 수정 및 탈퇴를 수행하는 함수
void update_profile(customer* me) {
	int input;

	printf("==============================\n");
	printf("회원정보 수정 및 탈퇴\n");
	printf("0. 뒤로\n");
	printf("1. 수정\n");
	printf("2. 탈퇴\n");
	printf("------------------------------\n");

	printf("입력: ");
	
	scanf("%d",&input);

	switch(input) {
		case 1: edit_profile(me);
			break;
		case 2: delete_profile(me);
			break;
		default: 
			printf("##### 잘못된 입력입니다. #####\n");
			break;

	}
}

// 회원정보 수정
void edit_profile(customer* me) {
	FILE* fp = fopen("customer.csv","r");
	FILE* temp = fopen("temp.csv","w");
	char buffer[500];

		
	printf("==============================\n");
	printf("회원정보 수정하기\n");
	
	printf("비밀번호: ");
	scanf("\n");
	fgets(buffer,500,stdin);
	erase_new_line(buffer);
	strcpy(me->pw, buffer);

	printf("이름: ");
	fgets(buffer,500,stdin);
	erase_new_line(buffer);
	strcpy(me->name, buffer);

	printf("주소: ");
	fgets(buffer,500,stdin);
	erase_new_line(buffer);
	strcpy(me->address, buffer);


	// update file
	for(int i=0; i<me->number; i++) {
		fgets(buffer,500,fp);
		fputs(buffer,temp);
	}

	fgets(buffer,500,fp);
	fprintf(temp, "%d,%s,%s,%s,%s,%d,1\n", me->number,me->id,me->pw,me->name,me->address,me->deposit);

	while(fgets(buffer,300,fp)) {
		fputs(buffer,temp);
	}

	printf("##### 회원정보가 수정되었습니다. #####\n");

	remove("customer.csv");
	rename("temp.csv","customer.csv");


	fclose(fp);
	fclose(temp);


}

// 회원정보 삭제
void delete_profile(customer* me) {

	FILE* fp = fopen("customer.csv","r");
	FILE* temp = fopen("temp.csv","w");

	char buffer[500];



	for(int i=0; i<me->number; i++) {
		fgets(buffer,500,fp);
		fputs(buffer,temp);
	}

	fgets(buffer,500,fp);
		
	fprintf(temp, "%d,%s,%s,%s,%s,%d,-1\n", me->number,me->id,me->pw,me->name,me->address,me->deposit);


	while(fgets(buffer,300,fp)) {
		fputs(buffer,temp);
	}

	me->status = -1;

	printf("##### 탈퇴되었습니다. #####\n");

	remove("customer.csv");
	rename("temp.csv","customer.csv");


	fclose(fp);
	fclose(temp);

}

// 가상계좌 입출금 관련 기능의 진입점.
void handle_deposit(customer* me) {

	int input,flag=1;

	while(flag) {
		printf("==============================\n");
		printf("가상계좌 입출금 서비스\n");
		printf("내 가상계좌 입금 및 출금\n");
		printf("내 가상계좌 잔액: %d\n",me->deposit);
		printf("------------------------------\n");
		printf("1. 입금하기\n");
		printf("2. 출금하기\n");
		printf("0. 이전 페이지로 돌아가기\n");
		printf("------------------------------\n");
		printf("입력: ");
		scanf("%d",&input);
	
		switch(input) {
			case 0: flag = 0; break;
			case 1: push_money(me); break;
			case 2: pop_money(me); break;
			default: 
				printf("##### 잘못된 입력입니다. #####\n");
				break;

		}
	}
}

// 가상계좌에 입금을 수행하는 함수
void push_money(customer* me) {
	int money;
	FILE* fp = fopen("customer.csv","r");
	FILE* temp = fopen("temp.csv","w");
	char buffer[500];


	printf("--------------------------------\n");
	printf("입금금액: ");
	scanf("%d",&money);
	me->deposit += money;

	for(int i=0; i<me->number; i++) {
		fgets(buffer,500,fp);
		fputs(buffer,temp);
	}

	fgets(buffer,500,fp);
	fprintf(temp,"%d,%s,%s,%s,%s,%d,%d\n",me->number,me->id,me->pw,me->name,me->address,me->deposit,me->status);

	while(fgets(buffer,500,fp)) {
		fputs(buffer,temp);
	}

	remove("customer.csv");
	rename("temp.csv","customer.csv");

	printf("##### 입금이 완료되었습니다. #####\n");
	printf("현재 잔액: %d\n",me->deposit);
	
	fclose(fp);
	fclose(temp);
}

// 가상계좌로 부터 출금을 수행하는 함수.
void pop_money(customer* me) {
	int money;
	FILE* fp = fopen("customer.csv","r");
	FILE* temp = fopen("temp.csv","w");
	char buffer[500];


	printf("------------------------------\n");
	printf("출급금액: ");
	scanf("%d",&money);

	if(money > me->deposit) {
		printf("##### 잔액이 부족합니다. #####\n");
		return;
	}
	me->deposit -= money;


	for(int i=0; i<me->number; i++) {
		fgets(buffer,500,fp);
		fputs(buffer,temp);
	}

	fgets(buffer,500,fp);
	fprintf(temp,"%d,%s,%s,%s,%s,%d,%d\n",me->number,me->id,me->pw,me->name,me->address,me->deposit,me->status);

	while(fgets(buffer,500,fp)) {
		fputs(buffer,temp);
	}

	remove("customer.csv");
	rename("temp.csv","customer.csv");

	printf("##### 출금이 완료되었습니다. #####\n");
	printf("현재 잔액: %d\n",me->deposit);
	
	fclose(fp);
	fclose(temp);

}

// 상품주문을 수행하는 함수.
void handle_order(customer* me, product pr) {
	
	int input,flag=1;

	FILE* fp;
	FILE* temp;
	char buffer[500];

	
	while(flag) {
		printf("내 보유금액: %d\n", me->deposit);
		printf("결제 금액: %d\n", pr.price);

		if(me->deposit < pr.price) {
			printf("##### 잔액이 부족합니다. 입금하겠습니까? #####\n");
			printf("0. 뒤로\n");
			printf("1. 입금하기\n");
			printf("입력: ");
			scanf("%d",&input);
			
			switch(input) {
				case 0: 
					flag = 0;
					break;
				case 1:
					handle_deposit(me);
					break;
				default: 
					printf("##### 잘못된 입력입니다. #####\n");
					break;

			}
		} else {
		
			fp = fopen("customer.csv","r");
			temp = fopen("temp.csv","w");

			me->deposit -= pr.price;

			for(int i=0; i<me->number; i++) {
				fgets(buffer,500,fp);
				fputs(buffer,temp);
			}

			fgets(buffer,500,fp);
			fprintf(temp,"%d,%s,%s,%s,%s,%d,%d\n",me->number,me->id,me->pw,me->name,me->address,me->deposit,me->status);
				
			while(fgets(buffer,500,fp)) {
				fputs(buffer,temp);
			}
				
			remove("customer.csv");
			rename("temp.csv","customer.csv");

			fclose(fp);
			fclose(temp);

			printf("##### 결제가 완료되었습니다. #####\n");
			printf("현재 잔액: %d\n",me->deposit);
				
			flag = 0;

			update_history(*me,pr);
		}
	}

}

// 상품 주문의 과정에서 history.csv에 결과를 저장하는 함수. 
void update_history(customer me, product pr) {
	FILE* fp = fopen("history.csv","r");
	int number=0;
	char buffer[200];

	while(fgets(buffer,200,fp)) number++;
	
	fclose(fp);

	fp = fopen("history.csv","a");

	fprintf(fp,"%d,%d,%d,0\n",number,me.number,pr.number);

	fclose(fp);


}

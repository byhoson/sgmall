#include "admin.h"

void handle_admin() {
	int input,flag=1;
	while(flag) {
		printf("SG-MALL 관리자 페이지\n");
		printf("1. 회원 정보 조회\n");
		printf("2. 상품 등록\n");
		printf("3. 상품 정보 수정 및 삭제\n");
		printf("4. 상품 조회 및 통계 보기\n");
		printf("5. 구매 내역 및 통계 보기\n");
		printf("6. 로그아웃 및 종료\n");
		printf("선택: ");
		scanf("%d",&input);

		switch(input) {
			case 1: see_customers(); break;
			case 2: add_product(); break;
			case 5: handle_history(); break;			
		}
	}
}

void handle_history() {
	int input,flag=1;

	while(flag) {

		FILE* fp = fopen("history.csv","r");
		char buffer[100];
		char* tok;

		fgets(buffer,100,fp);
	
		while(fgets(buffer,100,fp)) {
			// order number
			tok = strtok(buffer,",");
			printf("주문번호: %d", atoi(tok));

			// product number
			tok = strtok(NULL,",");
			printf(" / 상품번호: %d\n", atoi(tok)); 

			// customer number
			tok = strtok(NULL,",");

			// delivery status
			tok = strtok(NULL,",");
		}
	
		printf("0. 뒤로\n");
		printf("1. 배송 현황 수정\n");
		printf("2. 통계 보기\n");
		printf("입력: ");

		scanf("%d",&input);

		switch(input) {
			case 0: flag=0;
				break;
			case 1: update_delivery(input);
				break;
		}

		fclose(fp);

	}

}


void update_delivery() {
	int order_number;
	int product_number;
	int customer_number;
	int delivery_status;

	FILE* fp = fopen("history.csv","r");
	FILE* temp = fopen("temp.csv","w");
	char buffer[100];
	char* tok;

	printf("주문번호: ");
	scanf("%d",&order_number);

	for(int i=0; i<=order_number; i++) {
		fgets(buffer,100,fp);
	}

	fclose(fp);

	printf("-----------주문 정보----------\n");

	// order number
	tok = strtok(buffer,",");
	printf("주문번호: %d\n", atoi(tok));

	// product number
	tok = strtok(NULL,",");
	product_number = atoi(tok);
	printf("상품번호: %d\n", atoi(tok)); 

	// customer number
	tok = strtok(NULL,",");
	customer_number = atoi(tok);
	printf("회원번호: %d\n", atoi(tok));

	// delivery status
	tok = strtok(NULL,",");
	delivery_status = atoi(tok);
	printf("배송현황: %d\n", atoi(tok));

	printf("-----------------------------\n");

	printf("배송현황 변경\n");
	printf("0. 배송 준비\n");
	printf("1. 배송 중\n");
	printf("2. 배송 완료\n");
	printf("입력: ");
 	scanf("%d",&delivery_status);
	


	// copy history to temp
	fp = fopen("history.csv","r");

	for(int i=0; i<order_number; i++) {
		fgets(buffer,100,fp);
		fputs(buffer,temp);
	}

	fgets(buffer,100,fp);
	fprintf(temp,"%d,%d,%d,%d\n",order_number,product_number,customer_number,delivery_status);

	while(fgets(buffer,100,fp)) {
		fputs(buffer,temp);
	}

	remove("history.csv");
	rename("temp.csv","history.csv");

	printf("수정이 완료되었습니다.\n");


	fclose(fp);
	fclose(temp);

}

void see_customers() {

	FILE* fp = fopen("customer.csv","r");
	char buffer[500];
	char* tok;
	
	customer me;

	fgets(buffer,500,fp);

	while(fgets(buffer,500,fp)) {
		// number
		tok = strtok(buffer,",");
		me.number = atoi(tok);

		// id
		tok = strtok(NULL,",");
		strcpy(me.id,tok);

		// pw
		tok = strtok(NULL,",");
		strcpy(me.pw,tok);

		// name
		tok = strtok(NULL,",");
		strcpy(me.name,tok);

		// adress
		tok = strtok(NULL,",");
		strcpy(me.address,tok);

		// deposit
		tok = strtok(NULL,",");
		me.deposit = atoi(tok);

		// flag
		tok = strtok(NULL,",");
		me.flag = atoi(tok);

		if(me.flag == 1) {
			
			printf("---------------\n");
			printf("회원번호: %d\n",me.number);
			printf("아이디: %s\n",me.id);
			printf("비밀번호: %s\n",me.pw);
			printf("이름: %s\n",me.name);
			printf("주소: %s\n",me.address);
			printf("잔액: %d\n",me.deposit);
			

		} 

	}
	


	fclose(fp);
}


void add_product() {

	FILE* fp;
	product pr;
	char buffer[200];

	pr.number = 0;



	printf("상품 추가하기\n");
	
	
	// name
	printf("상품명: ");
	scanf("\n");
	fgets(buffer,200,stdin);
	erase_new_line(buffer);
	strcpy(pr.name,buffer);
	

	// category
	printf("카테고리: ");
	fgets(buffer,200,stdin);
	erase_new_line(buffer);
	strcpy(pr.category,buffer);

	// price
	printf("가격: ");
	scanf("%d",&pr.price);
	

	// get number for pr
	fp = fopen("product.csv","r");

	while(fgets(buffer,200,fp)) {
		pr.number++;
	}

	fclose(fp);


	// write onto the file
	fp = fopen("product.csv","a");

	fprintf(fp,"%d,%s,%s,%d,1\n",pr.number,pr.name,pr.category,pr.price);

	fclose(fp);
	printf("상품이 등록되었습니다.\n");

}

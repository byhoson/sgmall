#include "product.h"

void handle_product() {
	int input;
	int flag=1;

	while(flag) {

		printf("===================\n");
		printf("상품 검색하기\n");
		printf("0. 이전 화면으로 돌아가기\n");
		printf("1. 이름으로 검색하기\n");
		printf("2. 카테고리로 검색하기\n");
		printf("3. 세일 상품 검색하기\n");
		printf("...\n");
		printf("0. 이전 화면으로 돌아가기\n");
		printf("선택: ");
		scanf("%d",&input);
	
		switch(input) {
			case 0: 
				flag=0; 
				break;
			case 1:
				search_by_name();
				break;
			case 2:
				search_by_category();
				break;
			case 3:
				search_by_sale();
				break;
		}

	}
}

void search_by_name() {
	
	
	char buffer[500];
	FILE* fp = fopen("product.csv","r");
	char* tok;
	product pr;
	pr.flag = 0;

	fgetc(stdin);
	printf("검색: ");
	fgets(pr.name,50,stdin);
	erase_new_line(pr.name);

	fgets(buffer,500,fp);
	while(fgets(buffer,500,fp)) {
		// get number
		tok = strtok(buffer,","); 
		pr.number = atoi(tok);
		
		// get name
		tok = strtok(NULL,","); 
		if(strcmp(tok,pr.name)) continue; // name doesn't match
		pr.flag = 1; // product found

		// get category
		tok = strtok(NULL,",");
		strcpy(pr.category,tok);

		// get price
		tok = strtok(NULL,",");
		pr.price = atoi(tok);

		// get status
		tok = strtok(NULL,",");
		pr.status = atoi(tok);

		printf("-------------------------\n");
		printf("상품코드: %d\n",pr.number);
		printf("상품명: %s\n",pr.name);
		printf("카테고리: %s\n",pr.category);
		printf("가격: %d\n",pr.price);

	}
/*
	if(pr.flag) {
		printf("-------------------------\n");
		printf("상품코드: %d\n",pr.number);
		printf("상품명: %s\n",pr.name);
		printf("카테고리: %s\n",pr.category);
		printf("가격: %d\n",pr.price);

	}

*/
	fclose(fp);
	

}

void search_by_category() {
	char buffer[500];
	FILE* fp = fopen("product.csv","r");
	char* tok;
	product pr;
	pr.flag = 0;

	fgetc(stdin);
	printf("검색: ");
	fgets(pr.category,50,stdin);
	erase_new_line(pr.category);

	fgets(buffer,500,fp);
	while(fgets(buffer,500,fp)) {
		// get number
		tok = strtok(buffer,","); 
		pr.number = atoi(tok);
		
		// get name
		tok = strtok(NULL,","); 
		strcpy(pr.name,tok);

		// get category
		tok = strtok(NULL,",");
		if(strcmp(tok,pr.category)) continue; // category doesn't match
		
	
		// get price
		tok = strtok(NULL,",");
		pr.price = atoi(tok);

		// get status
		tok = strtok(NULL,",");
		pr.status = atoi(tok);

		printf("-------------------------\n");
		printf("상품코드: %d\n",pr.number);
		printf("상품명: %s\n",pr.name);
		printf("카테고리: %s\n",pr.category);
		printf("가격: %d\n",pr.price);

	}
/*
	if(pr.flag) {
		printf("-------------------------\n");
		printf("상품코드: %d\n",pr.number);
		printf("상품명: %s\n",pr.name);
		printf("카테고리: %s\n",pr.category);
		printf("가격: %d\n",pr.price);

	}
*/

	fclose(fp);


}

void search_by_sale() {
	printf("검색: ");

}


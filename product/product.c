#include "product.h"

// 상품관련 기능의 진입점 역할 수행.
void handle_product(customer* me) {
	int input;
	int flag=1;
	int number; // product number
	product pr;

	while(flag) {

		printf("===============================\n");
		printf("상품 검색하기\n");
		printf("0. 이전 화면으로 돌아가기\n");
		printf("1. 이름으로 검색하기\n");
		printf("2. 카테고리로 검색하기\n");
		printf("3. 모두 보기\n");
		printf("------------------------------\n");
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
				search_all();
				break;
			default: 
				printf("##### 잘못된 입력입니다. #####\n");
				break;

		}

		if(flag && me->flag) {
			
			printf("------------------------------\n");
			printf("0. 뒤로\n");
			printf("구매하려면 상품코드를 입력하세요.\n");
			printf("선택: ");
			scanf("%d",&input);
			if(input) {
				number = input;
				pr = search_by_number(number); // handle exception
				if(pr.flag){
					printf("------------------------------\n");
					printf("0. 뒤로\n");
					printf("1. 구매하기\n");
					printf("------------------------------\n");
					printf("선택: ");
					scanf("%d",&input);
					if(input) {
						handle_order(me,pr);
					}
				} else {
					printf("##### 해당상품이 없습니다. #####\n");
				}
			}
		}

	}
}

/*
상품코드를 받아 해당 상품을  product type에 담아 반환.
해당 상품이 없을 시 product의 flag를 이용하여 정보 전달. 
 */
product search_by_number(int number) {
	char buffer[500];
	FILE* fp = fopen("product.csv","r");
	char* tok;
	product pr;
	pr.flag = 0;


	fgets(buffer,500,fp);
	while(fgets(buffer,500,fp)) {
		// get number
		tok = strtok(buffer,","); 
		pr.number = atoi(tok);
		if(pr.number != number) continue; // number doesn't match
		pr.flag = 1;
		
		// get name
		tok = strtok(NULL,","); 
		strcpy(pr.name,tok);

		// get category
		tok = strtok(NULL,",");
		strcpy(pr.category,tok);

		// get price
		tok = strtok(NULL,",");
		pr.price = atoi(tok);

		// get status
		tok = strtok(NULL,",");
		pr.status = atoi(tok);

		printf("------------------------------\n");
		printf("상품코드: %d\n",pr.number);
		printf("상품명: %s\n",pr.name);
		printf("카테고리: %s\n",pr.category);
		printf("가격: %d\n",pr.price);

		break;

	}

	fclose(fp);

	return pr;

}

// 표준입출력으로 이름을 입력받아 일치하는 상품을 표준입출력에 출력해주는 함수
void search_by_name() {
	
	
	char buffer[500];
	FILE* fp = fopen("product.csv","r");
	char* tok;
	product pr;
	pr.flag = 0;

	printf("==============================\n");
	printf("상품명으로 검색하기\n");

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

		printf("------------------------------\n");
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

// 표준입출력을 통해 카테고리를 입력받아 해당 상품 리스트를 출력.
void search_by_category() {
	char buffer[500];
	FILE* fp = fopen("product.csv","r");
	char* tok;
	product pr;
	pr.flag = 0;

	printf("==============================\n");
	printf("카테고리로 검색하기\n");

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

		printf("------------------------------\n");
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

// 표준입출력에 모든 상품의 리스트를 출력.
void search_all() {
	char buffer[500];
	FILE* fp = fopen("product.csv","r");
	char* tok;
	product pr;
	pr.flag = 0;

	printf("==============================\n");
	printf("모두보기\n");


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
		strcpy(pr.category,tok);	
	
		// get price
		tok = strtok(NULL,",");
		pr.price = atoi(tok);

		// get status
		tok = strtok(NULL,",");
		pr.status = atoi(tok);

		printf("------------------------------\n");
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


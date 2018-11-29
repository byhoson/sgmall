#include "product.h"

void handle_product() {
	int input;
	printf("===================\n");
	printf("상품 검색하기\n");
	printf("0. 이전 화면으로 돌아가기\n");
	printf("1. 이름으로 검색하기\n");
	printf("2. 카테고리로 검색하기\n");
	printf("3. 세일 상품 검색하기\n");
	printf("...\n");
	printf("0. 이전 화면으로 돌아가기\n");

	scanf("%d",&input);
	
	switch(input) {
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

void search_by_name() {
	
}

void search_by_category() {

}

void search_by_sale() {

}

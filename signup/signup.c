#include "signup.h"

void signup() {
	
	char buffer[500];
	char* tok;
	customer me;
	FILE* fp = fopen("customer.csv","r");
	me.number = 1;

	printf("=====================\n");
	printf("회원 가입 페이지\n");
	
	// handle name
	fgetc(stdin); // 
	printf("name: ");
	fgets(buffer,500,stdin);
	strcpy(me.name,buffer);
	erase_new_line(me.name);

	// handle id
	printf("id: ");
	fgets(buffer,500,stdin);
	strcpy(me.id,buffer);
	erase_new_line(me.id);

	// id check
	fgets(buffer,500,fp);
	while(fgets(buffer,500,fp)) {
		tok = strtok(buffer,","); // skip number
		tok = strtok(NULL,","); // get id
		if(strcmp(tok,me.id)) {
			me.flag *= 1; // id overlaps
		} else {
			me.flag = 0; // id OK
		}
		me.number++; // get the number of the new customer
	}

	// handle pw
	printf("비밀번호: ");
	fgets(buffer,500,stdin);
	strcpy(me.pw,buffer);
	erase_new_line(me.pw);

	// handle pw check
	printf("비밀번호 확인: ");
	fgets(buffer,500,stdin);
	erase_new_line(buffer);
	if(strcmp(buffer,me.pw)) me.flag = 0; // pw doens't match

	// handle address
	printf("주소: ");
	fgets(buffer,500,stdin);
	strcpy(me.address,buffer);
	erase_new_line(me.address);
	

	fclose(fp);


	if(me.flag) {
		printf("number: %d\n",me.number);
		fp = fopen("customer.csv","a");
		fprintf(fp,"%d,%s,%s,%s,%s,0,1\n",me.number,me.id,me.pw,me.name,me.address);
		fclose(fp);
	} else {
		printf("NOT OK!\n");
	}
}
/*
void erase_new_line(char* str) {
	int i=0;
	while(str[i] != '\n') {
		i++;
	}
	str[i] = '\0';
}
*/

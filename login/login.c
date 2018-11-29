#include "login.h"

void login() {
	char id[50];
	char pw[50];
	char buffer[400];
	char* tok;
	int flag=0;
	int counter=0;

	customer me;
	
	FILE* fp = fopen("customer.csv","r");

	if(fp==NULL) {
		printf("no file\n");
		return;
	}

	printf("로그인 프로그램\n");



	while(counter<3) { // start while


		fp = fopen("customer.csv","r");

		printf("아이디: ");
		scanf("%s",id);
		printf("비밀번호: ");
		scanf("%s",pw);

		fgets(buffer,400,fp); // ignore the first line
		while(fgets(buffer,400,fp)) {

			tok = strtok(buffer,","); // get number
			me.number = atoi(tok); // save number

			tok = strtok(NULL,","); // get id
			if(strcmp(tok,id)) continue; // id doesn't match
			strcpy(me.id,tok); // save id

			tok = strtok(NULL,","); // get pw
			if(strcmp(tok,pw)) continue; // pw doesn't match
			strcpy(me.pw,tok); // save pw

			tok = strtok(NULL,","); // get name
			strcpy(me.name,tok); // save name

			tok = strtok(NULL,","); // get address
			strcpy(me.address,tok); // save address

			flag = 1;
			break; // escape the loop
	}

	fclose(fp);

	if(flag) {
		printf("==================\n");
		printf("회원번호: %d\n",me.number);
		printf("아이디: %s\n",me.id);
		printf("비밀번호: %s\n",me.pw);
		printf("이름: %s\n",me.name);
		printf("주소: %s\n",me.address);
		break;
	} else {
		counter++;
		printf("일치하는 회원이 없습니다.\n");
	}



	} // end while



	
}

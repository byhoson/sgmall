#include "login.h"

customer customer_login() {
	char id[50];
	char pw[50];
	char buffer[400];
	char* tok;
	//int flag=0;
	int counter=0;

	customer me;

	me.flag = 0;
	
	FILE* fp = fopen("customer.csv","r");

	if(fp==NULL) {
		printf("no file\n");
		//me.flag = 0;
		return me;
	}

	printf("====================\n");
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


			tok = strtok(NULL,","); // get deposit
			me.deposit = atoi(tok);

			tok = strtok(NULL,","); // get status
			me.status = atoi(tok);

			me.flag = 1;
			break; // escape the loop
	}

	fclose(fp);

	if(me.flag) {
	/*	printf("==================\n");
		printf("회원번호: %d\n",me.number);
		printf("아이디: %s\n",me.id);
		printf("비밀번호: %s\n",me.pw);
		printf("이름: %s\n",me.name);
		printf("주소: %s\n",me.address);*/
		break;
	} else {
		counter++;
		printf("일치하는 회원이 없습니다.\n");
	}



	} // end while


	return me;
	
}

int admin_login() {
	int counter=0;
	char buffer[100];
	int ret=1;

	while(counter<3) {
		// get id
		printf("관리자 아이디: ");
		scanf("%s",buffer);
		if(strcmp(buffer,"admin")) ret = 0;
		else ret = 1;
		printf("buffer: %s\n",buffer);
		
		// get pw
		printf("관리자 비밀번호: ");
		scanf("%s",buffer);
		if(strcmp(buffer,"password")) ret = 0;
		else ret = 1;
		printf("buffer: %s\n",buffer);

		
		if(ret) return 1;
		else counter++;
	}

	return ret;
}

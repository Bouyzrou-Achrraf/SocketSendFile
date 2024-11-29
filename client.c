#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

void main (){
	int sd ;
	char msg [255];
	FILE *f ;
	char line [1024];
	char fname [255];
	struct sockaddr_in adresse ;

	sd = socket(AF_INET , SOCK_STREAM , 0);
	if (sd<0)
		printf("error of creation \n");

	adresse.sin_family = AF_INET ;
	adresse.sin_port = 1250 ;
	adresse.sin_addr.s_addr = INADDR_ANY ;

	connect(sd , (struct sockaddr*)&adresse , sizeof(adresse));

	printf("Enter Name Of The File : ");

	scanf("%s" ,fname);

	send (sd , fname , sizeof(fname) ,0);

	f = fopen(fname , "r+");

	while(fgets(line , sizeof(line) , f) != NULL ) 

{		send(sd , line , sizeof(line) ,0)	;
		printf("Line sended %s\n", line);

}
	send (sd , "EOF" , sizeof("EOF") , 0);

	fclose(f);
	close(sd);





}
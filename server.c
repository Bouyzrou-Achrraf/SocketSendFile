#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

void main (){
	int sd , cnx ;
	int bytesread ;
	char msg [255] , line[1024];
	FILE * f ;
	struct sockaddr_in adresse ;

	sd = socket(AF_INET , SOCK_STREAM , 0);
	if (sd<0)
		printf("error of creation \n");

	adresse.sin_family = AF_INET ;
	adresse.sin_port = 1250 ;
	adresse.sin_addr.s_addr = INADDR_ANY ;

	bind (sd , (struct sockaddr*)&adresse , sizeof(adresse));

	listen (sd , 5);

	cnx = accept(sd , 0 , 0);

	printf("client is connect .\n ");	

	recv(cnx , msg , sizeof(msg) , 0);
	printf("File Name Recienved Is : %s\n" , msg);

	strcat(msg,"new")
	f = fopen(msg , "w+");

	while((bytesread =  recv (cnx , line , sizeof(line) , 0)) > 0)
		{
			if (!strcmp (line ,"EOF") == 0) fputs(line , f);
			printf("Message recived : %s ( de size %d )\n" , line , bytesread);
			
		}
		

	fclose(f);
	close(cnx);


}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"input.h"

void input(char *ir){
		printf("\tSaisir votre adresse IP en utilisant la rotation CIDR\n");
		printf("IP/Bits Reseau: ");
		scanf("%s", ir);
}
void divided_ir(char *ir , char *ip , int *bits_reseau){
		int bits;
		char *data = NULL;
		data = strtok(ir , "/");
		strcpy(ip , data);
		data = strtok(NULL , "/");
		bits = atoi(data);
		*bits_reseau = bits;
}

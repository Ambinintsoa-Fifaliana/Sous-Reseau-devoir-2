#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"Resultat1.h"

void MSQR(int classe){
	/*Cette fonction affiche la masque de sous-reseau*/
	printf("\tMasque de sous-reseau: ");
	if(classe == 1){
		printf("\n⇒ 255.0.0.0\n ");
		}
	if(classe == 2){
		printf("\n⇒ 255.255.0.0\n ");
		}
	if(classe == 3){
		printf("\n⇒ 255.255.255.0\n ");
		}
}
void number_of_machine(int classe_ip){
	/*Cette fonction affiche le nombre d'adresse IP ou nombre de machine utilisable pour le reseau donnée*/
	printf("\tNombre de machines utilisable :");
	if(classe_ip == 1){
		printf("\n⇒ 16 777 214\n");
		}
	if(classe_ip == 2){
		printf("\n⇒  65 534\n");
		}
	if(classe_ip == 3){
		printf("\n⇒  254\n");
		}
}

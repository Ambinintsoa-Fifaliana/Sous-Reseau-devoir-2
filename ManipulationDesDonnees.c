#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"ManipulationDesDonnees.h"


void indexed_IP(char *ip , adress *divided){
	/*On utlise cette fonction pour diviser l'adresse IP entrer par l'utilisateur pour mieux l'analyser*/
	/*On stocke chaque valeur devant les . de l'adresse dans chacun des membres du structure declarer en-desssus*/
	
	int n1;
	char *IP = NULL;
	
	IP = strtok(ip , ".");
	n1 = atoi(IP);
	divided->firstpart = n1;
	
	IP = strtok(NULL , ".");
	n1 = atoi(IP);
	divided->secondpart = n1;
	
	IP = strtok(NULL , ".");
	n1 = atoi(IP);
	divided->thirdpart = n1;
	
	IP = strtok(NULL , ".");
	n1 = atoi(IP);
	divided->fourthpart = n1;
	
}
void verify_IP_validity(adress *ip1){
	/*Cette fonction verifie si les adresse IP sont valide*/
	
		if(ip1->firstpart < 0 || ip1->secondpart < 0 ||  ip1->thirdpart < 0 || ip1->fourthpart < 0){
			printf("IP Adress invalid\n");
			exit(1);
		}
		if(ip1->firstpart > 255 || ip1->secondpart > 255 ||  ip1->thirdpart > 255 || ip1->fourthpart > 255){
			printf("IP Adress invalid\n");
			exit(1);
		}
}
int verify_IP_class(adress *ip1){
	/*Cette fonction verifie à quel classe appartient l'adresse IP*/
	
		if(ip1->firstpart >= 0 &&  ip1->firstpart <= 127 ){
			return 1;
		}
		else if(ip1->firstpart >= 128 &&  ip1->firstpart <= 191 ){
			return 2;
		}
		else if(ip1->firstpart >= 192 &&  ip1->firstpart <= 223 ){
			return 3;
		}
		else{
			return 0;
			}
}
void network_adress(int class , adress *ip1){
	/*Apres tous ces etapes , cette fonction affiche l'adresse reseau de l'adresse IP donnée*/
	printf("\n\nAdresse IP :%d.%d.%d.%d\nOn a\n", ip1->firstpart , ip1->secondpart , ip1->thirdpart , ip1->fourthpart);
	printf("\tAdresse reseau: ");
	if(class == 1){
		printf("\n⇒ %d.0.0.0\n ", ip1->firstpart);
		}
	if(class == 2){
		printf("\n⇒ %d.%d.0.0\n ", ip1->firstpart , ip1->secondpart);
		}
	if(class == 3){
		printf("\n⇒ %d.%d.%d.0\n ", ip1->firstpart , ip1->secondpart , ip1->thirdpart);
		}
}
void broadcast_adress(int class , adress *ip1){
	/*Cette fonction affiche l'adresse broadcast du reseau*/
	printf("\tAdresse broadcast: ");
	if(class == 1){
		printf("\n⇒ %d.255.255.255\n ", ip1->firstpart);
		}
	if(class == 2){
		printf("\n⇒ %d.%d.255.255\n ", ip1->firstpart , ip1->secondpart);
		}
	if(class == 3){
		printf("\n⇒ %d.%d.%d.255\n ", ip1->firstpart , ip1->secondpart , ip1->thirdpart);
		}
}
int verify_bite_network(int classe_ip , int bits_reseau){
	
		if ((classe_ip == 1) && (bits_reseau >= 24)){ /*IP de classe A*/
			return 1;    /*Le nombre de bits pour le reseau est conforme à la classe de l'adresse IP*/
		}
		else if ((classe_ip == 2) && (bits_reseau >= 16)){ /*IP de classe B*/
			return 2;    /*Le nombre de bits pour le reseau est conforme à la classe de l'adresse IP*/
		}
		else if ((classe_ip == 3) && (bits_reseau >= 8)){ /*IP de classe C*/
			return 3;    /*Le nombre de bits pour le reseau est conforme à la classe de l'adresse IP*/
		}	
		else {
			return 0;
			}
}
void adres_reseau_broadcast(int bits_hotes_decimal , int nbr_sous_reseau , adress *ip1){
		int reseau = 0;
		int broadcast = bits_hotes_decimal;
			/*Calcul et affiche l'adresse reseau et adresse broadcast pour chaque sous reseau*/
		for (int i = 1 ; i <= nbr_sous_reseau ; i++){
			printf("\t**Sous-reseau numero %d:\n", i);
			printf("⇒ Adresse reseau: %d.%d.%d.%d\n" , ip1->firstpart , ip1->secondpart , ip1->thirdpart , reseau);
			printf("⇒ Adresse broadcast: %d.%d.%d.%d\n\n" , ip1->firstpart , ip1->secondpart , ip1->thirdpart , broadcast);
			/*Convertion */
			reseau = broadcast + 1;
			broadcast = reseau + bits_hotes_decimal;
			}
}

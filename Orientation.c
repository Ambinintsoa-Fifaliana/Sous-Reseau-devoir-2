#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#include"calcul.h"
#include"input.h"
#include"ManipulationDesDonnees.h"
#include"Resultat1.h"
#include"ResultatDecoupage.h"

int main(){
	char ir[18];
	char ip[16];   /*Variable pour l'adresse IP*/
	int bits_reseau; /* Variable pour le nombre de bits reseau*/
	adress ip_bits;
	int classe_ip;
	int verify_ip_br; /*Voir si le bits reseau est conforme a la classe de l'adresse IP*/
	int decoupage;
	int nbr_sous_reseau = 0;
	int nbr_bits_hotes = 0;
	int bits_hotes_decimal = 0;
	int msqr = 0;
	
		input(ir);
		divided_ir(ir , ip ,&bits_reseau);
		indexed_IP(ip ,&ip_bits);
		verify_IP_validity(&ip_bits);
		classe_ip = verify_IP_class(&ip_bits);
		network_adress(classe_ip , &ip_bits);
		broadcast_adress(classe_ip , &ip_bits);
		MSQR(classe_ip);
		number_of_machine(classe_ip);
		verify_ip_br = verify_bite_network( classe_ip , bits_reseau);      /*Verifie si l'adresse ip est conforme a la nombre de bits pour le reseau'*/
		decoupage = verify_cutting_number( bits_reseau , verify_ip_br);   /*Nombre de decoupage*/
		nbr_sous_reseau = nombre_sous_reseau( decoupage);     /*Nombre de sous-reseau*/
		nbr_bits_hotes = nombre_bits_hotes(verify_ip_br ,  decoupage);     /*Nombre de bits pour hotes*/
		msqr =  masque_sous_reseau(decoupage);
		nombres_machines_sous_reseau(nbr_sous_reseau , nbr_bits_hotes , decoupage , msqr);
		bits_hotes_decimal = byte( nbr_bits_hotes);     /*Bits pour hotes en decimal*/
		adres_reseau_broadcast(bits_hotes_decimal ,nbr_sous_reseau , &ip_bits );
		
	return 0;
}






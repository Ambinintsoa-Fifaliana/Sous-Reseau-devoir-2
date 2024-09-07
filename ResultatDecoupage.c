#include<stdio.h>
#include<math.h>
#include"ResultatDecoupage.h"

void nombres_machines_sous_reseau(int nbr_sous_reseau , int nbr_bits_hotes , int decoupage , int msqr){
	int n = 0;
	n = pow(2 , nbr_bits_hotes) - 2;
	printf("\t\t***APRES %d DECOUPAGE***\n", decoupage);
	printf("Il y a %d sous-reseaux et %d machines utilisables chacune.\n", nbr_sous_reseau,n);
	printf("Masque de sous-reseau: 255.255.255.%d\n\n", msqr);
}


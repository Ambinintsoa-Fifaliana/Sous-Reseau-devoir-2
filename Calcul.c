#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"calcul.h"

int verify_cutting_number(int bits_reseau , int verify_ip_br){
			/*On verifie le nombre de decoupage*/
			if(verify_ip_br == 3){
					return (bits_reseau - 24);
			}

}
int nombre_sous_reseau(int decoupage){       
		int decoupe;
		decoupe = pow(2 , decoupage);
		return decoupe;
}
int nombre_bits_hotes( int verify_ip_br , int decoupage){
	/*Compter le nombres des bits pour hotes*/
	if(verify_ip_br == 3){
					return (8 - decoupage);
			}
	}
int byte(int nbr_bits_hotes){
	/*Convertir  les bits pour hotes en decimal*/
	int byte_decimal = 0;
		for (int i = 0 ; i < nbr_bits_hotes ; i++){
			byte_decimal += pow(2, i);
		}
	return byte_decimal;
}
int masque_sous_reseau(int decoupage){
	int n = 1;
	int msqr;
	while(n <= decoupage ){
		int i = 7;
		msqr += pow(2, i);
		n ++;
		i ++;
	}
		
	return msqr - 1;
}

#include<stdio.h>
#include"struct.h"
void indexed_IP(char *ip , adress *divided);
void verify_IP_validity(adress *ip1);
int verify_IP_class(adress *ip1);
void network_adress(int class , adress *ip1);
void broadcast_adress(int class , adress *ip1);
int verify_bite_network(int classe_ip , int bits_reseau);
void adres_reseau_broadcast(int bits_hotes_decimal , int nbr_sous_reseau , adress *ip1);

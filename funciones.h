#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include<stdlib.h>
#include<time.h>







using namespace std;

char COD();
void implementacion(unsigned long int*,unsigned short int*);


//metodo I

void m1_codificacion(unsigned long long int  ,unsigned long int ,char* ,char* );
char* m1_decodificacion(unsigned long long int ,unsigned long int ,char *);
void tam(char* ,unsigned long long *);
void lecturaM1(char*,char*,unsigned long long,unsigned );
char *traduccionM1(unsigned long long, char *);
void binarioM1(unsigned long long int* , unsigned ,char*);
void metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void r_metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void sentencia(unsigned long,unsigned long,int8_t*);
void escribirM1 (char *,char *, unsigned long long);

//metodo II

void m2_codificacion(unsigned long long int ,unsigned long int,string,string);
string m2_decodificacion(unsigned long long int *,unsigned long int,string);
string lecturam2(string,unsigned long long*,unsigned);
string bin_m2( unsigned int );
string metodo2(string,unsigned long long,unsigned long int,unsigned long int);
string r_metodo2(string , unsigned long long , unsigned long int  ,unsigned long long int );
string traduccionM2(unsigned long long int tamano, string bina);
void escribirM2 ( string ,string );




// cajero

bool ubicador(char ,string ,unsigned long long *,unsigned long long );
bool buscador(string ,unsigned long long*,string ,char);
string extractor(string ,unsigned long long );
bool numero(string );
string entrada(string comentario);
unsigned long long convertidor(string);
string decodificador(string );
void codificador(string , string );
bool ingreso(string ,char ,string ,unsigned long long *);




#endif // FUNCIONES_H

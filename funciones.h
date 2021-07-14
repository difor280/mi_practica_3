#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <cstring>



#include "metodo_1.h"



using namespace std;

int COD();
void implementacion(unsigned long int*,unsigned short int*);


//metodo I

char* lecturaM1(char*,unsigned long long* );
char *traduccionM1(unsigned long long, char *);
char* binarioM1(unsigned long long,char *);
void metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void r_metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void sentencia(unsigned long,unsigned long,int8_t*);


//metodo II

void m2_codificacion(unsigned long long int ,unsigned long int,string,string*);
void m2_decodificacion(unsigned long long int ,unsigned long int,string,string*);
void lecturam2(string *,string,unsigned long long*);
string *bin_m2(unsigned long long int , string &);
void metodo2(string&,unsigned long long,unsigned long int,unsigned long int);
string *traduccionM2(unsigned long long int tamano, string &bina);
void escribirM2 ( string &,string );
void r_metodo2(string &, unsigned long long , unsigned long int  ,unsigned long int );



// cajero

void administrador(string,string);

#endif // FUNCIONES_H

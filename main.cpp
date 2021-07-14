#include "funciones.h"

int main()
{
    unsigned short int metodo;
    unsigned int long semilla ;
    unsigned long long *tamano = new unsigned long long;
    //codificacion
    if(COD()=='1')
    {

        implementacion(&semilla,&metodo);

        if(metodo==1)
        {
            char *texto=new char,nombre[]="natural.txt";
            texto=lecturaM1(nombre,tamano);
            cout<<endl<<texto<<endl;
            texto=binarioM1(*tamano,texto);
            metodo1(texto,*tamano,semilla,0,0,0);
            cout<<endl<<texto<<endl;
            texto=traduccionM1(*tamano,texto);
            cout<<endl<<texto<<endl;
            delete texto;




        }
        else
        {
            string *texto=new  string,nombre="natural.txt";
            lecturam2(texto,nombre,tamano);

            texto->pop_back();
            *tamano=texto->length();

            cout<<endl<<*texto<<endl<<endl;
            m2_codificacion(*tamano,semilla,"codificado.dat",texto);
            delete texto;
        }

        delete tamano;

    }
    //decodificacion
    else
    {
           implementacion(&semilla,&metodo);

            if(metodo==1)
            {

            }
            else
            {
                string *texto=new  string,nombre="codificado.dat";
                //string *texto=new  string,nombre="natural.txt";
                lecturam2(texto,nombre,tamano);

                texto->pop_back();
                *tamano=texto->length();

                cout<<endl<<*texto<<endl<<endl;
                //m2_codificacion(*tamano,semilla,"codificacion.dat",texto);
                m2_decodificacion(*tamano,semilla,"natural.txt",texto);

                delete texto;
            }
    }

    return 0;
}




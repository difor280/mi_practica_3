#include "funciones.h"

int main()
{
    unsigned short int metodo;
    unsigned int long semilla ;

    //codificacion

    if(COD()==1)
    {
        implementacion(&semilla,&metodo);

        if(metodo==1)
        {
            unsigned long long *tamano = new unsigned long long;
            char nombre_E[]="natural.txt",nombre_S[]="codificado.dat";
            tam(nombre_E,tamano);
            char *texto=new char[*tamano*8];
            texto=lecturaM1(nombre_E,*tamano);
            cout<<endl<<texto<<endl;
            texto=binarioM1(*tamano,texto);
            metodo1(texto,*tamano,semilla,0,0,0);
            cout<<endl<<texto<<endl;
            texto=traduccionM1(*tamano,texto);
            cout<<endl<<texto<<endl;
            escribirM1(nombre_S,texto);
            delete[] texto;
            delete tamano;
        }
        else
        {
            unsigned long long *tamano = new unsigned long long;
            string texto,nombre="natural.txt";
            lecturam2(&texto,nombre,tamano);

            texto.pop_back();
            //*tamano=texto.length();

            cout<<endl<<texto<<endl<<endl;
            m2_codificacion(*tamano,semilla,"codificado.dat",texto);

            delete tamano;
        }



    }
    //decodificacion
    else
    {

           implementacion(&semilla,&metodo);

            if(metodo==1)
            {

            }
            else
            {   unsigned long long *tamano = new unsigned long long;
                string texto,nombre="codificado.dat";
                //string *texto=new  string,nombre="natural.txt";
                lecturam2(&texto,nombre,tamano);

                texto.pop_back();
                //*tamano=texto.length();

                cout<<endl<<texto<<endl<<endl;
                //m2_codificacion(*tamano,semilla,"codificacion.dat",texto);
                m2_decodificacion(*tamano,semilla,"natural.txt",texto);


                delete tamano;
            }
    }

    return 0;
}




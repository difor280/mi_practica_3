# include "funciones.h"


void m2_codificacion(unsigned long long int tamano ,unsigned long int semilla,string nombre,string*texto)
{
    texto=bin_m2(tamano,*texto);
    cout<<endl<<*texto<<endl<<endl<<endl;
    metodo2(*texto,tamano,semilla,0);
    cout<<endl<<*texto<<endl;
    texto=traduccionM2(tamano,*texto);
    cout<<endl<<*texto<<endl;
    escribirM2(*texto,nombre);
    cout<<endl<<*texto<<endl;

}
//cambiar en un futuro
void m2_decodificacion(unsigned long long int tamano ,unsigned long int semilla,string nombre,string*texto)
{
    texto=bin_m2(tamano,*texto);
    cout<<endl<<*texto<<endl<<endl<<endl;

    r_metodo2(*texto,tamano,semilla,0);
    cout<<endl<<*texto<<endl;
    texto=traduccionM2(tamano,*texto);
    cout<<endl<<*texto<<endl;
    escribirM2(*texto,nombre);

    cout<<endl<<*texto<<endl;

}


void lecturam2(string *datos,string nombre,unsigned long long *tamano )
{
       fstream archivo(nombre, fstream::in | fstream::binary | fstream::ate);
       *tamano=archivo.tellg();
        archivo.seekg(0);

       if (!archivo.is_open())
       {
           cout <<"Archivo no encontrado"<< endl;
       }
       /*string *pala= new string;
       while (getline(archivo,*pala,'\n'))
       {
           *datos=*datos+ *pala+'\n' ;
       }
       delete pala;
        */
       for(unsigned long long int i=0 ; i<=*tamano ;i++)
       {    int letra=archivo.get();
            cout<<endl<<letra<<endl;
            cout<<endl<<char(letra)<<endl;
           *datos=*datos+char(letra);

       }
}





string *bin_m2(unsigned long long int tamano, string &escrito)
{

    string *bits= new string , *codificado = new string ;
    string prueba;
    unsigned int ascii;
    for (unsigned long int i=0; i<tamano;i++)
    {
        //prueba = ();

        ascii= unsigned( int (escrito[i]));
        *bits="";
        while(ascii > 0)
        {
            if(ascii % 2 == 0)
            {
                *bits = '0'+*bits;
            }
            else
            {
                *bits = '1'+*bits;
            }
            ascii = (int) ascii/2;
        }

        while(bits->size()<8)
        {
            *bits='0'+*bits;
        }
        *codificado= *codificado+*bits;
    }
    delete bits;
    return codificado;
    delete codificado;
}

string* traduccionM2(unsigned long long int tamano, string &bina)
{

    string *escribir= new string ;
    unsigned int letra;

    for(unsigned int i=0,e=0;e<tamano;e++)
    {   letra=0;
        for(int a=7;0<=a;i++,a--)
        {
            letra=letra+(pow((int(bina[i])-48)*2,a));
        }

        if(bina[i-1]=='0')
        *escribir= *escribir+ char(letra-1);
        else *escribir=*escribir + char(letra);

    }
    return escribir;
    delete  escribir;
}

//metodo 2  codificacion
void metodo2(string &text, unsigned long long tamano, unsigned long int  semilla,unsigned long int posicion)
{

    string nex,ultimo;

    for(unsigned int i=0;i<(tamano*8)/semilla and posicion<tamano*8;i++)
    {
        ultimo=text[posicion+semilla-1];
        nex=text[posicion+1];
        if(2<=semilla)
        {
            text[posicion+1]=text[posicion];
            text[posicion]=ultimo[0];
            posicion=posicion+2;
        }

        for(unsigned int e=2;e<semilla;e++,posicion++)
        {
                ultimo=nex;
                nex=text[posicion];
                text[posicion]=ultimo[0];
        }
    }

    if((tamano*8-posicion)%semilla != 0)
    {   unsigned long int conteo=(tamano*8)-posicion;
        metodo2(text,tamano,conteo,posicion);
    }
}

//metodo dos decodificacion
void r_metodo2(string &text, unsigned long long tamano, unsigned long int  semilla,unsigned long int posicion)
{
    string atras,ultimo;

    for(unsigned int i=0;i<(tamano*8)/semilla and posicion<tamano*8;i++)
    {
        ultimo=text[posicion];
        atras=text[posicion+1];
        text[posicion]=atras[0];
        posicion++;
        for(unsigned int e=1;e<semilla;e++,posicion++)
        {
            atras=text[posicion+1];
            text[posicion]=atras[0];
        }
        text[posicion-1]=ultimo[0];
    }
    if((tamano*8-posicion)%semilla != 0)
    {
        unsigned long int conteo=(tamano*8)-posicion;
        metodo2(text,tamano,conteo,posicion);
    }
}

void escribirM2 ( string &datos,string nombre)
{
    fstream text;    
    text.open(nombre, fstream::out | fstream::binary);
    text<<datos;

    text.close();
}



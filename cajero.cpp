#include "funciones.h"





string entrada(string comentario)
{
    string entrega="a";

    while(not(numero(entrega)))
    {
        cout<<endl<<"ingresa "<<comentario<<
              "\nADVERTENCIA:  solo ingresar caracteres numericos ej;'123495' "<<endl;
        cin>>entrega;
        cout<<endl;
        cout<<"\n\n\n\n\n\n";
        cout<<"\n\n\n\n\n\n";cout<<"\n\n\n\n\n\n";cout<<"\n\n\n\n\n\n";
        bool validacion=numero(entrega);
        if(not(validacion))
        {
            cout<<"algunos de los caracteres ingresados en "<<comentario<<" con invalidos."<<endl<<endl;

        }
        else if(validacion)
        {
             cout<<"\n\n\n\n\n\n";
            cout<<"confirme si es el numero de "<<comentario<<": "<<entrega<<" es el que quiere ingresar\n\n"
                  "0.continuar \n"
                  "1.volver a digitar "<<comentario<<"\n";
            bool  confirmacion;
            cin>>confirmacion;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            if(confirmacion)
            {
               entrega='a';
            }
        }
    }


    return  entrega ;
}

bool numero(string comprovacion)
{
    bool numero=true;
    unsigned tamano=comprovacion.length();
    for(unsigned i=0;i<tamano;i++)
    {
        if(not(unsigned(comprovacion[i])>=48 and unsigned(comprovacion[i])<=57) )
        {
          numero=false;
          break;
        }
    }

    return numero;
}



bool ubicador(char caracter,string texto,unsigned long long *desde,unsigned long long hasta)
{
   bool encontrado= false;
   for(;*desde<hasta;*desde=*desde+1)
   {
       if(texto[*desde]== caracter)
       {
           encontrado= true;
           break;
       }


   }
   return encontrado;
}





//texto = a cadena de caracteres sacados del documento de texto
//posicion= ubicacion desde donde comienza la informacion de un usuario
//clave= cadena de caracteres a buscar
//desde= desde que caracter comenzar a buscar
bool buscador(string texto,unsigned long long *posicion ,string clave,char desde)
{
    bool datos=false;
    unsigned long long tamano=texto.length();
    for(unsigned long long i=0 ;i<tamano;)
    {
        if(ubicador(desde,texto,&i,tamano)==true)
        {
            i++;
            *posicion=i;
            for(unsigned e=0;e < clave.length();e++,i++)
            {
                if(texto[i]==clave[e])
                {
                    datos=true;
                }
                else
                {
                    datos=false;
                    break;
                }

            }
        }
        if(datos != 0 and texto[i]==',')
        {

            break;
        }
        datos=false;

    }



    return datos;
}

unsigned long long convertidor(string nums )
{
    unsigned long long numi=0,potencia;

    for(unsigned i=0,e=nums.length();i<nums.length();i++,e--)
    {
        potencia=pow(10,e-1);
        numi=numi+(potencia*(unsigned(nums[i])-48));

    }


    return numi;
}

string decodificador(string nombre)
{
    string texto;
    unsigned long long tamano;
    texto=lecturam2(nombre,&tamano,8);
    fstream datos;
    datos.open(nombre,fstream::in | fstream::binary);
    for(unsigned i=0;i<8;i++)
    {
        texto=r_metodo2(texto,tamano-8,datos.get(),0);
    }
    texto=traduccionM2(tamano-8,texto);

    datos.close();

    return texto;
}

void codificador(string texto, string nombre )
{
    unsigned long long tamano=texto.length();
    string binario="";
    for(unsigned long long i=0;i<tamano;i++)
    {

        binario=binario+bin_m2(texto[i]);
    }
     texto="";
    srand(time(NULL));
    for(unsigned i=0;i<8;)
    {

        for(unsigned e=rand()%(3-1+1)+1;e>0 and i<8;e--,i++)
        {
            int clave=rand()%(50-1+1)+1;
            binario=metodo2(binario,tamano,clave,0);
            texto=char(clave)+texto;
        }

    }
    binario=traduccionM2(tamano,binario);
    binario=texto+binario;
    escribirM2(binario,nombre);


}


bool ingreso(string escrito,char buscar,string pregunta,unsigned long long *posicion )
{
    bool verdad;
    for(unsigned short i=0;i<3;i++)
    {
        string clave="";
        cout<<"ingresar "<<pregunta << " \n";
        cin>>clave;
        verdad=buscador(escrito,posicion,clave,buscar);
        if(verdad) break;

        else
        {
            cout<<pregunta << " es incorrect@, vuelve a ";
        }

    }
    return verdad;
}

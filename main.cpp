#include "funciones.h"

int main()
{
    unsigned short int metodo;
    unsigned int long semilla;
    unsigned short CoD;

    //codificacion
    metodo=COD();
    if(metodo=='1')
    {
        implementacion(&semilla,&CoD);

        if(CoD==1)
        {
            unsigned long long tamano ;

           char nombre_E[]="natural.txt",nombre_S[]="codificado.dat";
            tam(nombre_E,&tamano);

            char *texto=new char[(tamano)*8];
            lecturaM1(texto,nombre_E,tamano,0);
            m1_codificacion(tamano,semilla,nombre_S,texto);
            delete[] texto;

        }
        else
        {
            unsigned long long tamano ;
            char nombre_E[]="natural.txt",nombre_S[]="codificado.dat";
            tam(nombre_S,&tamano);
            char *texto=new char[tamano*8];

            texto=m1_decodificacion(tamano,semilla,texto);
            escribirM1(texto,nombre_E,tamano);
            cout<<endl<<texto<<endl;
            delete[] texto;
        }


    }
    //decodificacion
    else if (metodo=='2')
    {
            implementacion(&semilla,&CoD);

        if(CoD==1)
        {

            unsigned long long tamano ;
            string texto,nombre="usuario.dat";
            texto=lecturam2(nombre,&tamano,0);


            m2_codificacion(tamano,semilla,"usuario.dat",texto);

        }
        else
        {   unsigned long long *tamano = new unsigned long long;
            string texto,nombre="natural.txt";
            texto=m2_decodificacion(tamano,semilla,"codificado.dat");
            escribirM2(texto,nombre);

            delete tamano;
        }
    }



    else if(metodo=='3')
    {
        cout<<"Bienvenidos  tu cajero practica_3\n";
        CoD=1;
        unsigned short usuario;
        while(CoD)
        {

            cout<<"Que tipo de usuario eres\n"
                  "1.administrador\n"
                  "2.sistema\n";
            cin>>usuario;
            switch (usuario)
            {
                case 1:
                    usuario=1;
                    CoD=0;
                break;

                case 2:
                     usuario=2;
                     CoD=0;
                break;

                default:cout<<"porfavor dejar ingresar solo el numero"
                              " correspondiente al usuario al que quiere ingresar";
            }
        }
        string escrito="";
        if(usuario==1)
        {
            unsigned long long tamano;


           escrito=decodificador("sudo.txt");

             CoD=ingreso(escrito,',',"la CLAVE",&tamano);
             if(CoD)
             {
                  codificador(escrito,"sudo.txt");



                  escrito=decodificador("usuario.dat");



                   string documento;
                   while (CoD)
                   {
                        documento=entrada("el DOCUMENTO");
                        CoD=buscador(escrito,&tamano,documento,'\n');
                            if(CoD)
                        {
                            cout<<"el documento ingresado ya esta en el sistema"<<endl;
                        }

                   }
                   escrito=escrito+documento;
                   documento=entrada("la CLAVE");
                   escrito=escrito+','+documento;
                   documento=entrada("el DEPOSITO");
                   escrito=escrito+','+documento+'\n';
                   codificador(escrito,"usuario.dat");
            }

        }
        else
        {   string documento;
            escrito=decodificador("usuario.dat");
            unsigned long long posicion;
            /*for(unsigned short i=0;i<3;i++)
            {   unsigned long long tamano;
                string clave="";
                cout<<"ingresar el numero de documento \n";
                cin>>clave;
                CoD=buscador(escrito,&tamano,clave,'\n');
                if(CoD) break;
                else
                {
                    cout<<"clave incorrecta, vuelve a ";
                }

            }*/
            CoD=ingreso(escrito,'\n',"el DOCUMENTO", &posicion);
            for(unsigned long long i=posicion;escrito[i]!=',';i++) documento= documento+escrito[i] ;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            while(CoD)
            {

                cout<<"BIENVENIDO usuario " <<documento << ", que diligencia va a realizar?\n"
                      "1.retirar\n"
                      "2.saber el tamano del deposito \n";
                cin>>usuario;
                switch (usuario)
                {
                    case 1:
                        usuario=1;
                        CoD=0;
                    break;

                    case 2:
                         usuario=2;
                         CoD=0;
                    break;

                    default:cout<<"porfavor ingresa una de las opciones mostradas representadas por numeros\n\n\n\n\n\
                                    n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                 }

             }

             unsigned long long tam;

            string superios,medio,inferior;
            for(unsigned long long i=0;i<posicion;i++)
            {
                superios=superios+escrito[i];
            }
            for(;escrito [posicion]!='\n';posicion++)
            {
                 medio=medio+escrito[posicion];
            }
            tam=escrito.length();
            for(;posicion<=tam;posicion++)
            {
                 inferior=inferior+escrito[posicion];
            }
            CoD=ingreso(medio,',',"la CLAVE",&posicion);
            if(CoD)
            {

                if(usuario==1)
                {
                    escrito="";
                    for(unsigned i =medio.length()-1;medio[i]!=',';i--)
                    {
                        escrito=medio[i]+escrito;
                        medio.pop_back();
                    }
                        tam=convertidor(escrito);
                    if(tam>=6000)
                    {   string monto;
                        unsigned long long retiro;
                        while (true)
                        {
                            cout<<"cual va a ser el monto a retirar?\n"
                                  "(recuerda que la cantidad minima a retirar es de 5000) "<<endl;
                            cin>>monto;
                            retiro=convertidor(monto);
                            if(numero(monto)==true and retiro>=5000)
                            {   if(retiro<= tam-1000)
                                {
                                   tam=tam-retiro;
                                   tam=tam-1000;
                                   break;
                                }
                                else
                                {
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nlo sentimos el saldo a retirar excede su deposito actual\n";
                                }
                            }
                            else
                            {
                                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nno se permite usar letras o un retiro inferior a 5000\n"<<endl;
                            }
                        }

                        cout<<"su saldo actual es de "<<tam<<" descontando el impuesto de 1000 por uso"<<endl;
                        monto=to_string(tam);
                        medio=medio+monto;
                    }
                    else
                    {
                        cout<<"lo sentimos, saldo insuficiente para realizar el tramite";
                    }
                }
                else if(usuario==2)
                {
                    escrito="";
                    for(unsigned i =medio.length()-1;medio[i]!=',';i--)
                    {
                        escrito=medio[i]+escrito;
                        medio.pop_back();
                    }
                    tam=convertidor(escrito);
                    if(tam > 1000)
                    {   string monto;
                        tam=tam-1000;
                        cout<<"su salgo actual es de "<<tam<<" descontando 1000 del impuesto por uso";
                        monto=to_string(tam);
                        medio=medio+monto;

                    }
                    else
                    {
                        cout<<"lo sentimos, saldo insuficiente para realizar el tramite";
                    }
                }

            }
            else
            {
                cout<<"\nlimite de intentos"<<endl;
            }

            escrito=superios+medio+inferior;
            codificador(escrito,"usuario.dat");
        }


    }
    else
    {
        unsigned long long tamano;
        string ingreso;
        ingreso=lecturam2("ingreso.txt",&tamano,0);
        ingreso=traduccionM2(tamano,ingreso);
        codificador(ingreso,"usuario.dat");
        codificador(ingreso,"sudo.txt");
    }
    return 0;
}











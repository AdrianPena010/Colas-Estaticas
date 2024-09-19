#include <iostream>
#include "colat5.h"

using namespace std;

int main()
{
    ColaT5 MiCola;
    Constancia x;
    int opc;

    do{
    cout<<"\n1.Dar de alta solicitud.\n2.Elaborar constancia.\n3.Salir.\nIngrese la opcion: ";
    cin>>opc;

    switch(opc)
    {
    case 1:
        //for(int i=1;i<=2; i++){
        cin>>x;
        MiCola.enqueue(x);
        break;
    case 2:
        //for(int i=1;i<=2; i++)
        cout<<MiCola.dequeue();
        break;
    case 3:
        cout<<"Saliendo...";
    default:
        cout<<"Ingrese una opcion valida";
    }

    }while(opc!=3);


    return 0;
}

#include "colat5.h"

using namespace std;

Constancia::Constancia()
{
    alumno="Arturo";
    carrera="Informatica";
    materias_aprob=8;
    promedio=85.6;
}

Constancia::Constancia(string a, string c, int m, float p): alumno(a), carrera(c), materias_aprob(m), promedio(p) {}
void Constancia::operator=(Constancia& x)
{
   alumno=x.alumno;
   carrera=x.carrera;
   materias_aprob=x.materias_aprob;
   promedio=x.promedio;
}

ostream& operator<<(ostream& o, Constancia& c)
{
    cout<<"\nDATOS DE CONSTANCIA"<<endl;
    o<<"Alumno: "<<c.alumno<<"\t Carrera: "<<c.carrera<<"\t Materias aprobadas: "<<c.materias_aprob<<"\t Promedio: "<<c.promedio<<endl;
    return o;
}
istream& operator>>(istream& i, Constancia& c)
{
    cout<<"\n Nombre de alumno: ";
    i>>c.alumno;
    cout<<"\n Carrera: ";
    i>>c.carrera;
    cin.ignore();
    cout<<"\n Materias aprobadas: ";
    i>>c.materias_aprob;
    cout<<"\n Promedio: ";
    i>>c.promedio;

    return i;
}

bool ColaT5::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool ColaT5::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int ColaT5::ultimo()const
{
    return ult;
}

ostream& operator<<(ostream &o, ColaT5& L)
{
    int i=0;
    cout<<"\n";
    while(i<=L.ultimo())
    {
        o<<L.datos[i];
        i++;
    }
    return o;
}

void ColaT5::enqueue(Constancia& elem)
{
    inserta(elem,0);
}

Constancia& ColaT5::dequeue()
{
    if(vacia()){
        cout<<"\n La cola esta vacia"<<endl;
    }
    else{
        ult--;
        return datos[ult+1];
    }
}

bool ColaT5::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int ColaT5::inserta(Constancia& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}

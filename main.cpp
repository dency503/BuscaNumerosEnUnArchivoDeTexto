
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

string numero;
int num;

void ingreso(ofstream & x)
{
               cout<<"\n\t-Digite el numero que desee agregar: ";
               cin>>num;
x.open("arreglo.txt", ios_base::app);
x<<num<< ' ';
x.close();

system("pause");
}

void lista(ifstream & y)
{
y.open("arreglo.txt", ios::in);
         if (y.fail())
{
                   cout<<"\n\t\a ----La listas se encuentra vacia----"<<endl;
exit(1);
}

                    cout << "\n\t*****Numeros ingresados en la lista*****\n" << endl;
                    while (!y.eof())
{
getline(y, numero);
                    cout<<numero<<endl;
}y.close();

system("pause");
}

void busqueda(ifstream & y)
{
y.open("arreglo.txt", ios::in);
    string numbusqueda;

              cout << "\n\tDigite el numero que desee buscar: ";
              cin >> numbusqueda;

      bool enc = false;
      while (!y.eof()&& !enc)
y>>numero;

      if(numbusqueda == numero)
{
               cout << "\n\t***Si se pudo encontrar el numero en la lista***" << endl;
enc = true;
}y.close();

    if (!enc)
                cout << "\n\t-No se pudo encontrar el numero" << endl;

system("pause");
}

int main(){
       ifstream  y;
       ofstream  x;

    int op;
do{
    system("cls");

                 cout<<"\t********** MENU DE OPCIONES **********"<<endl;
                 cout<<"\t* 1-Agregar numero a la lista        *"<<endl;
                 cout<<"\t* 2-Ver los numeros de la lista      *"<<endl,
                 cout<<"\t* 3-Buscar un numero en la lista     *"<<endl;
                 cout<<"\t* 4-Salir                            *"<<endl;
                 cout<<"\t**************************************"<<endl;
                 cout<<"\tOpcion: ";cin>>op;

    system("cls");
switch (op)
{
        case 1:
        ingreso(x);
            break;

        case 2:
        lista(y);
            break;

        case 3:
        busqueda(y);
            break;

        case 4:
        cout << "\n\t\aSaliendo...." << endl;
        return 0;
            break;
        default:
        cout << "\nLa opcion que eligio no es valida" << endl;
            break;
}
} while (op != 4);

return 0;
}


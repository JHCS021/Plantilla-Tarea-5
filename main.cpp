#include "Vellonera.h"
#include <iostream>
#include <string>

using namespace std;
Vellonera* vellonera = new Vellonera();

bool Listar()
{
    cout << endl << endl;
    int i = 1;
    Cancion* cancion = vellonera->GetPrimera();
    while(cancion != NULL)
    {
        tiempo duracion = cancion->GetDuracion();
        cout << i << "- " << cancion->GetTitulo() << " " << cancion->GetArtista() << " (" <<
            duracion.minutos << ":" << duracion.segundos << ")" << endl;
        cancion = cancion->GetSiguiente();
        i++;
    }
    if(i == 1)
    {
        cout << endl << "** Vellonera vacía **" << endl;
        return false;
    }
    cout << endl << endl;
    return true;
}

void Introducir()
{
    string titulo;
    string artista;
    tiempo duracion;
    cout << "Introducir el titulo de la cancion: ";
    getline(cin, titulo);
    cout << "Introducir el artista de la cancion: ";
    getline(cin, artista);
    cout << "Introducir duracion (minutos) de la canción: ";
    cin >> duracion.minutos;
    cout << "Introducir duracion (segundos) de la canción: ";
    cin >> duracion.segundos;
    Cancion* cancion = new Cancion(titulo, artista, duracion);
    vellonera->Agregar(cancion);
    cout << "-- Cancion Agregada --" << endl;
    cout << endl;
}

void Eliminar()
{
    if(!Listar())
    {
        return;
    }
    int indice = 0;
    cout << "Elija el cancion a eliminar => ";
    cin >> indice;
    vellonera->Eliminar(indice - 1);
    cout << endl;
    Listar();
    cout << endl;
}

void MostrarCancionActual()
{
    Cancion* cancion = vellonera->GetActual();
    if(cancion == NULL)
    {
        cout << "No hay ninguna canción reproduciéndose en este momento" << endl;
        return;
    }
    tiempo duracion = cancion->GetDuracion();
    cout << "Canción actual: " << cancion->GetTitulo() << " " << cancion->GetArtista() << " (" <<
        duracion.minutos << ":" << duracion.segundos << ")" << endl;    
}

void MostrarMenu()
{
    int opcion = 0;
    do
    {
        cout << endl;        
        cout << "1- Agregar nueva canción" << endl;
        cout << "2- Visualizar canciones" << endl;
        cout << "3- Mostrar Canción Actual" << endl;
        cout << "4- Próxima Canción" << endl;
        cout << "5- Canción Anterior" << endl;
        cout << "6- Activar Repetición en Lista" << endl;
        cout << "7- Eliminar" << endl;
        cout << "8- Salir" << endl;
        cout << "Elija una opción => ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion)
        {
            case 1:
                Introducir();
            break;
            case 2:
                Listar();
            break;
            case 3:
                MostrarCancionActual();
            break;
            case 4:
                vellonera->CancionSiguiente();
            break;
            case 5:
                vellonera->CancionAnterior();
            break;
            case 6:
                vellonera->SetRepetir(!vellonera->GetRepetir());
            break;
            case 7:
                Eliminar();            
            break;
            case 8:
            break;
            default:
                cout << "Opción inválida" << endl;
            break;
        }
    }while(opcion != 8);
}

int main()
{
    MostrarMenu();
    return 0;
}

#include "Vellonera.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Vellonera::Vellonera(): _repetir(false), _primera(NULL) , _ultima(NULL),  _actual(NULL)
{
}

void Vellonera::Agregar(Cancion* cancion)
{
    /*IMPLEMENTAR ESTE METODO PARA AGREGAR NUEVA CANCIÓN  LA VELLONERA*/
}

void Vellonera::OrdenarCanciones()
{    
    /*IMPLEMENTAR ESTE METODO PARA ORDERNAR LAS CANCIONES DE MENOR A MAYOR (SEGUN SU DURACION)*/

}

void Vellonera::CancionSiguiente()
{
    /*IMPLEMENTAR ESTE MÉTODO PARA AVANZAR A LA SIGUIENTE CANCION (Ver puntero _actual)*/
}

void Vellonera::CancionAnterior()
{
    /*IMPLEMENTAR ESTE MÉTODO PARA REGRESAR A LA CANCION ANTERIOR (Ver puntero _actual)*/
}

bool Vellonera::Eliminar(int indice)
{
    /*ELIMINAR UNA CANCION RETORNA FALSO SI EL INDICE NO ESTABA EN LA LISTA*/
    /*EL INIDICE INICIA EN CERO*/
    return false;
}


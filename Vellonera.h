#ifndef VELLONERA_H
#define VELLONERA_H

#include <string>
#include "Cancion.h"

class Vellonera
{
    public:
        Vellonera();
        void Agregar(Cancion* cancion);
        Cancion* GetPrimera() { return _primera; }
        Cancion* GetActual() { return _actual; }
        bool Eliminar(int indice);
        void SetRepetir(bool repetir) { _repetir = repetir; }
        bool GetRepetir() { return _repetir; }
        void CancionSiguiente();
        void CancionAnterior();
        
    private:
        void OrdenarCanciones();
        bool _repetir;
        Cancion* _primera;
        Cancion* _ultima;
        Cancion* _actual;
};
#endif

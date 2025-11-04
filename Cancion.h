#ifndef CANCION_H
#define CANCION_H

#include <string>

struct tiempo
{
    int minutos;
    int segundos; 
    int GetTiempoTotal() { return (minutos * 60) + segundos; }
};

class Cancion
{
    public:
        Cancion(std::string titulo, std::string artista, tiempo duracion);
        void SetTitulo(std::string titulo) { _titulo = titulo; }
        std::string GetTitulo(){ return _titulo; }
        void SetArtista(std::string artista) { _artista = artista; }
        std::string GetArtista(){ return _artista; }
        void SetDuracion(tiempo &duracion) { _duracion = duracion; }
        tiempo GetDuracion(){ return _duracion; }
        void SetSiguiente(Cancion* siguiente) { _siguiente = siguiente; }
        Cancion* GetSiguiente() { return _siguiente; }
        void SetAnterior(Cancion* anterior) { _anterior = anterior; }
        Cancion* GetAnterior() { return _anterior; }

    private:
        std::string _titulo;
        std::string _artista;
        tiempo _duracion;
        Cancion* _siguiente;
        Cancion* _anterior;
};
#endif

#include <string>
#include <iostream>

using namespace std;

struct tiempo
{
    int minutos;
    int segundos;
    int GetTiempoTotal() const { return (minutos * 60) + segundos; }
};

class Cancion
{
public:
    Cancion(const std::string &titulo, const std::string &artista, const tiempo &duracion);
    void SetTitulo(const std::string &titulo) { _titulo = titulo; }
    std::string GetTitulo() const { return _titulo; }
    void SetArtista(const std::string &artista) { _artista = artista; }
    std::string GetArtista() const { return _artista; }
    void SetDuracion(const tiempo &duracion) { _duracion = duracion; }
    tiempo GetDuracion() const { return _duracion; }
    void SetSiguiente(Cancion *siguiente) { _siguiente = siguiente; }
    Cancion *GetSiguiente() const { return _siguiente; }
    void SetAnterior(Cancion *anterior) { _anterior = anterior; }
    Cancion *GetAnterior() const { return _anterior; }

private:
    std::string _titulo;
    std::string _artista;
    tiempo _duracion;
    Cancion *_siguiente;
    Cancion *_anterior;
};

class Vellonera
{
public:
    Vellonera();
    ~Vellonera();
    void Agregar(Cancion *cancion);
    Cancion *GetPrimera() const { return _primera; }
    Cancion *GetActual() const { return _actual; }
    bool Eliminar(int indice);
    void SetRepetir(bool repetir) { _repetir = repetir; }
    bool GetRepetir() const { return _repetir; }
    void CancionSiguiente();
    void CancionAnterior();

private:
    bool _repetir;
    Cancion *_primera;
    Cancion *_ultima;
    Cancion *_actual;
};

Cancion::Cancion(const std::string &titulo, const std::string &artista, const tiempo &duracion)
    : _titulo(titulo), _artista(artista), _duracion(duracion), _siguiente(nullptr), _anterior(nullptr)
{
}

Vellonera::Vellonera() : _repetir(false), _primera(nullptr), _ultima(nullptr), _actual(nullptr) {}

Vellonera::~Vellonera()
{
    Cancion *actual = _primera;
    while (actual != nullptr)
    {
        Cancion *siguiente = actual->GetSiguiente();
        delete actual;
        actual = siguiente;
    }
}

void Vellonera::Agregar(Cancion *cancion)
{
    if (cancion == nullptr) return;
    
    cancion->SetAnterior(nullptr);
    cancion->SetSiguiente(nullptr);

    if (_primera == nullptr)
    {
        _primera = _ultima = _actual = cancion;
        return;
    }

    int tNuevo = cancion->GetDuracion().GetTiempoTotal();

    if (tNuevo <= _primera->GetDuracion().GetTiempoTotal())
    {
        cancion->SetSiguiente(_primera);
        _primera->SetAnterior(cancion);
        _primera = cancion;
    }
    else if (tNuevo >= _ultima->GetDuracion().GetTiempoTotal())
    {
        cancion->SetAnterior(_ultima);
        _ultima->SetSiguiente(cancion);
        _ultima = cancion;
    }
    else
    {
        Cancion *actual = _primera->GetSiguiente();
        while (actual != nullptr)
        {
            if (tNuevo < actual->GetDuracion().GetTiempoTotal())
            {
                Cancion *anterior = actual->GetAnterior();
                anterior->SetSiguiente(cancion);
                cancion->SetAnterior(anterior);
                cancion->SetSiguiente(actual);
                actual->SetAnterior(cancion);
                return;
            }
            actual = actual->GetSiguiente();
        }
    }
}

void Vellonera::CancionSiguiente()
{
    if (_actual != nullptr)
    {
        if (_actual->GetSiguiente() != nullptr)
        {
            _actual = _actual->GetSiguiente();
        }
        else if (_repetir)
        {
            _actual = _primera;
        }
    }
}

void Vellonera::CancionAnterior()
{
    if (_actual != nullptr)
    {
        if (_actual->GetAnterior() != nullptr)
        {
            _actual = _actual->GetAnterior();
        }
        else if (_repetir)
        {
            _actual = _ultima;
        }
    }
}

bool Vellonera::Eliminar(int indice)
{
    if (_primera == nullptr || indice < 0) return false;

    Cancion *aEliminar = _primera;
    int i = 0;
    while (aEliminar != nullptr && i < indice)
    {
        aEliminar = aEliminar->GetSiguiente();
        i++;
    }

    if (aEliminar == nullptr) return false;

    if (aEliminar == _actual)
    {
        if (aEliminar->GetSiguiente() != nullptr)
            _actual = aEliminar->GetSiguiente();
        else
            _actual = aEliminar->GetAnterior();
    }

    Cancion *anterior = aEliminar->GetAnterior();
    Cancion *siguiente = aEliminar->GetSiguiente();

    if (anterior != nullptr)
        anterior->SetSiguiente(siguiente);
    else
        _primera = siguiente;

    if (siguiente != nullptr)
        siguiente->SetAnterior(anterior);
    else
        _ultima = anterior;

    delete aEliminar;

    return true;
}
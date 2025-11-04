#include "Cancion.h"

Cancion::Cancion(std::string titulo, std::string artista, tiempo duracion): _titulo(titulo), _artista(artista), _duracion(duracion), _siguiente(NULL), _anterior(NULL)
{}

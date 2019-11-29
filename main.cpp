#include <iostream>
#include "CObjeto.h"
#include "CArena.h"
int main() {
    CArena arena;
    arena.Llenar_Tablero();
    arena.Agregar_Obstaculos();
    arena.Posiciones_libres();
    arena.AgregarRobot();
    arena.AgregarRobot();
    arena.iralataque();
}
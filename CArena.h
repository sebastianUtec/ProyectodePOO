//
// Created by SEBASTIAN on 28/11/2019.
//

#ifndef PROYECTOFINALPOOII_2019_2_SEB_CARENA_H
#define PROYECTOFINALPOOII_2019_2_SEB_CARENA_H

#include "CObjeto.h"
#include "CRobot.h"
#include "CObstaculo.h"
#include<vector>
class CArena {
private:
    TipoEntero Filas_De_La_Arena;
    TipoEntero Columnas_De_La_Arena;
    Caracter ** Tablero_General;
    vector<CObjeto*> Grupo_de_Objetos;
    vector<vector<TipoEntero> > PosicionesLibres;
    void Algoritmo_Sp(TipoEntero pix , TipoEntero piy , TipoEntero pfx , TipoEntero pfy, vector<vector<TipoEntero >>posiciones_libres , vector<vector<vector<TipoEntero >>>&camino_exitoso , vector<vector<TipoEntero >>caminos_intentados , TipoEntero conteo ,vector<TipoEntero >&conteomax );
public:
    void Llenar_Tablero();
    void Agregar_Obstaculos();
    void Posiciones_libres();
    void AgregarRobot();
    void ActualizarArena();
    void ImprimirArena();
    void iralataque();
};


#endif //PROYECTOFINALPOOII_2019_2_SEB_CARENA_H

//
// Created by SEBASTIAN on 28/11/2019.
//

#include "CObstaculo.h"
CObstaculo::CObstaculo() {}

CObstaculo::CObstaculo(TipoEntero Posicion_X, TipoEntero Posicion_Y, TipoEntero Vida_del_Objeto,
                       TipoEntero Tamanio_de_Ataque, Caracter Caracter_del_Objeto, string Nombre_del_Objeto) {
    this->Posicion_X=Posicion_X;
    this->Posicion_Y=Posicion_Y;
    this->Vida_del_Objeto=Vida_del_Objeto;
    this->Tamanio_de_Ataque=Tamanio_de_Ataque;
    this->Caracter_del_Objeto=Caracter_del_Objeto;
    this->Nombre_del_Objeto=Nombre_del_Objeto;
}
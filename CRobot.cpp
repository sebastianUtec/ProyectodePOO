//
// Created by SEBASTIAN on 28/11/2019.
//

#include "CRobot.h"
CRobot::CRobot() {}
CRobot::CRobot(TipoEntero Posicion_X, TipoEntero Posicion_Y, TipoEntero Vida_del_Objeto, TipoEntero Tamanio_de_Ataque,
        Caracter Caracter_del_Objeto, string Nombre_del_Objeto) {
    this->Posicion_X=Posicion_X;
    this->Posicion_Y=Posicion_Y;
    this->Vida_del_Objeto=Vida_del_Objeto;
    this->Tamanio_de_Ataque=Tamanio_de_Ataque;
    this->Caracter_del_Objeto=Caracter_del_Objeto;
    this->Nombre_del_Objeto=Nombre_del_Objeto;
}
CRobot::atacar(CRobot& Robot1){
    if (robot2.Posicion_X==robot1.Posicion_X and robot2.Posicion_Y==robot1.Posicion_Y) {
        Robot1.vidas -= danio;
    }
}


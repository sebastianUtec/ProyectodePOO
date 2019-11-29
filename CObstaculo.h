//
// Created by SEBASTIAN on 28/11/2019.
//

#ifndef PROYECTOFINALPOOII_2019_2_SEB_COBSTACULO_H
#define PROYECTOFINALPOOII_2019_2_SEB_COBSTACULO_H

#include "CObjeto.h"

class CObstaculo: public CObjeto {
public:
    CObstaculo();
    CObstaculo(TipoEntero Posicion_X ,TipoEntero Posicion_Y,TipoEntero Vida_del_Objeto,TipoEntero Tamanio_de_Ataque,Caracter Caracter_del_Objeto,string Nombre_del_Objeto);
    ~CObstaculo(){};
    //Set-> puedes editar los datos de cada robot, con los set
    void setPosicion_X(TipoEntero posicion_en_x){this->Posicion_X=posicion_en_x;}
    void setPosicion_Y(TipoEntero posicion_en_y){this->Posicion_Y=posicion_en_y;}
    void setVida_de_Objeto(TipoEntero Vida_del_objeto){this->Vida_del_Objeto=Vida_del_objeto;}
    void setTamanio_de_ataque(TipoEntero tamniodelataque){this->Tamanio_de_Ataque=tamniodelataque;}
    void setCaracter_Del_Objeto(Caracter caracter_del__objeto){this->Caracter_del_Objeto=caracter_del__objeto;}
    void setNombre_del_Objeto(string nombredelobjeto){this->Nombre_del_Objeto=nombredelobjeto;}
    //get->Con los gets , puedes ver los datos de cada robot.
    TipoEntero getPosicion_X(){return Posicion_X;}
    TipoEntero getPosicion_Y(){return Posicion_Y;}
    TipoEntero getVida_de_Objeto(){ return Vida_del_Objeto;}
    TipoEntero getTamanio_de_ataque(){return Tamanio_de_Ataque;}
    Caracter getCaracter_Del_Objeto(){return Caracter_del_Objeto;}
    string  getNombre_del_Objeto(){return Nombre_del_Objeto;}
    //metodos.
    void ubicarse_en_la_arena(){}
    void moverse (){}
};


#endif //PROYECTOFINALPOOII_2019_2_SEB_COBSTACULO_H

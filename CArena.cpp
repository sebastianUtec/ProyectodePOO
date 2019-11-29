//
// Created by SEBASTIAN on 28/11/2019.
//


/*
void CArena::Algoritmo_S() {
    //Algoritmo &SFPM&
    Caracter caracterdelobjeto;
    VoF Y = false;
    TipoEntero posicion_en_el_vector;
    do {
        cout << "Porfavor ingrese el caracter del Objeto(robot) que va a utilizar :" << endl;
        cin >> caracterdelobjeto;

        Y = buscarsiseencuentra(Grupo_de_Objetos, caracterdelobjeto, posicion_en_el_vector);
    } while (Y == false);
    TipoEntero pix = Grupo_de_Objetos[posicion_en_el_vector]->getPosicion_X();
    TipoEntero piy = Grupo_de_Objetos[posicion_en_el_vector]->getPosicion_Y();
    Caracter otrorobot;
    VoF Y2;
    TipoEntero posicion_en_el_vector2;
    do {
        cout << "Porfavor ingrese hacia que robot quiere ir : ";
        cin >> otrorobot;
        Y = buscarsiseencuentra(Grupo_de_Objetos, caracterdelobjeto, posicion_en_el_vector2, caracterdelobjeto);
    } while (Y2 == false);
    TipoEntero pfx = Grupo_de_Objetos[posicion_en_el_vector2]->getPosicion_X();
    TipoEntero pfy = Grupo_de_Objetos[posicion_en_el_vector2]->getPosicion_Y();
    TipoEntero medida_del_vector = PosicionesLibres.size();
}//asemejamos una variable para el tamaño del vector de posiciones libres .

    if(pix==pfx && piy==pfy){ //si la posicion inicial es igual a la final
        camino_exitoso.push_back(caminos_intentados); //camino exitoso guardara los caminos ya establecidos , sera guardado por referencia.
        conteomax.push_back(conteo);// se agregara al conteomax los pasos que este dio.
    }
    else{
        TipoEntero x=pix , y=piy , ab , ar , iz , de ;
        ab=verifica(posiciones_libres, x+1 , y);//mov abajo
        if(ab==1){

            TipoEntero  conteo_2 = conteo;
            conteo_2++;
            vector<TipoEntero >temp={x+1 , y};
            vector<vector<TipoEntero >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<TipoEntero >>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x+1 , y, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
        ar=verifica(posiciones_libres , x-1 , y);//mov arriba
        if(ar==1){
            TipoEntero  conteo_2 = conteo;
            conteo_2++;
            vector<TipoEntero >temp={x-1 , y};
            vector<vector<TipoEntero >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<TipoEntero >>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x-1 , y, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
        iz=verifica(posiciones_libres , x , y-1 );//mov izquierda
        if(iz==1){
            TipoEntero  conteo_2 = conteo;
            conteo_2++;
            vector<TipoEntero >temp={x , y-1};
            vector<vector<TipoEntero >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<TipoEntero >>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x , y-1, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
        de=verifica(posiciones_libres , x , y+1);//mov derecha
        if(de==1) {
            TipoEntero  conteo_2 = conteo;
            conteo_2++;
            vector<TipoEntero >temp={x , y+1};
            vector<vector<TipoEntero >> posi_temp=caminos_intentados;
            posi_temp.push_back(temp);
            vector<vector<TipoEntero >>copia_posiciones_libress=posiciones_libres;
            borrar(copia_posiciones_libress , x , y+1);
            borrar(copia_posiciones_libress , x , y-1);
            borrar(copia_posiciones_libress , x+1 , y);
            borrar(copia_posiciones_libress , x-1 , y);
            Algoritmo_Sp(x , y+1, pfx , pfy , copia_posiciones_libress , camino_exitoso , posi_temp , conteo_2 , conteomax);
        }
    }
}
 */

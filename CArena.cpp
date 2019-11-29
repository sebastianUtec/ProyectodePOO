//
// Created by SEBASTIAN on 28/11/2019.
//
#include "CArena.h"
#include <fstream>
const string fichero = "../Laberinto.txt";
void CArena::ActualizarArena() {
    for(TipoEntero i=0 ; i<Filas_De_La_Arena ; i++){
        for(TipoEntero j=0 ;j <Columnas_De_La_Arena; j++){
            Tablero_General[i][j]='*';
        }
    }
    if(Grupo_de_Objetos.size()>0){
        for(TipoEntero i=0 ; i<Grupo_de_Objetos.size();i++){
            TipoEntero posiciondexdelobjeto=(Grupo_de_Objetos[i]->getPosicion_X());
            TipoEntero posiciondeydelobjeto=(Grupo_de_Objetos[i]->getPosicion_Y());
            Caracter momen = (Grupo_de_Objetos[i]->getCaracter_Del_Objeto());
            Tablero_General[posiciondexdelobjeto][posiciondeydelobjeto]=momen;
        }
    }
}
void CArena::ImprimirArena() {
    for (TipoEntero i=0;i<Filas_De_La_Arena;i++){
        for(TipoEntero j=0 ; j<Columnas_De_La_Arena ;j++){
            cout<<"["<<Tablero_General[i][j]<<"]"<<"\t";
        }
        cout<<endl<<endl<<endl;
    }
}
void VerificarSiPuedeOspedarseAhi(TipoEntero &xx , TipoEntero &yy , vector<vector<TipoEntero >> &espaciosdisponibles  ){
    VoF comprobar=false;
    do{
        cout<<"Ingrese las coordenadas del robot ."<<endl;
        cout<<"Ingrese la coordenada en x :";cin>>xx;
        cout<<"Ingrese la coordenada en y : ";cin>>yy;
        for(TipoEntero i=0 ; i<espaciosdisponibles.size() ; i++){
            if(xx==espaciosdisponibles[i][0] && yy==espaciosdisponibles[i][1]){
                comprobar=true;
            }
        }
        if(comprobar==false){
            cout<<"Porfavor , intente con otras coordenadas , este espacio no se encuentra disponible ."<<endl;
        }
    }while(comprobar== false);

}
void llenarTablero(Caracter **tablero , TipoEntero filas_1, TipoEntero columnas_1){
    for(TipoEntero i=0 ; i<filas_1;i++){
        for(TipoEntero j=0 ; j<columnas_1;j++){
            tablero[i][j]='*';
        }
    }
}
void llenar_la_arena_completa(TipoEntero *puntero1 , TipoEntero *puntero2 , Caracter **puntero3 , TipoEntero j){
    for (TipoEntero i=0 ;i<j ;i++){
        TipoEntero posicionx , posiciony;
        posicionx=puntero1[i];
        posiciony=puntero2[i];
        puntero3[posicionx][posiciony]='O';
    }
}
void CArena::Llenar_Tablero() {
    ifstream fi;
    fi.open(fichero);
    if(fi.is_open()){
        TipoEntero filas , columnas , cantidad_de_obstaculos;
        fi>>filas>>columnas>>cantidad_de_obstaculos;
        TipoEntero *x= nullptr;
        TipoEntero *y= nullptr;
        x=new TipoEntero[cantidad_de_obstaculos];
        y=new TipoEntero[cantidad_de_obstaculos];
        for(int i=0 ; i<cantidad_de_obstaculos ; i++){
            fi>>x[i];
            fi>>y[i];
        }
        Tablero_General = new Caracter*[filas];
        for(TipoEntero i=0;i<filas;i++){
            Tablero_General[i]=new Caracter[columnas];
        }
        llenarTablero(Tablero_General , filas , columnas);
        llenar_la_arena_completa(x , y , Tablero_General , cantidad_de_obstaculos);
        Filas_De_La_Arena=filas;
        Columnas_De_La_Arena=columnas;
        ImprimirArena();

    }
    else{
        cout<<"Lo sentimos no hemos podido abrir el archivo.";
    }

}
void CArena::Agregar_Obstaculos() {
    TipoEntero a;
    do{
        cout<<"Ingrese la cantidad de danio del Obstaculo : ";
        cin>>a;
        cout<<endl;
    }while (a<0 || a>7);
    TipoEntero aa=0;
    cout<<Filas_De_La_Arena;
    cout<<Columnas_De_La_Arena;
    for(TipoEntero i=0 ; i<Filas_De_La_Arena;i++){
        for(TipoEntero j=0;j<Columnas_De_La_Arena;j++){
            if(Tablero_General[i][j]=='O'){
                CObstaculo *momentanio=new CObstaculo(i,j,1000,a,'O',"Obstaculo");
                Grupo_de_Objetos.push_back(momentanio);
            }
        }
    }
    cout<<"La cantidad de obstaculos presentes es : "<<Grupo_de_Objetos.size();
    cout<<endl;
}
void CArena::Posiciones_libres() {
    TipoEntero conteo=0;
    for(TipoEntero i=0 ; i<Filas_De_La_Arena ;i++){
        for(TipoEntero j=0 ;j<Columnas_De_La_Arena ;j++){
            if(Tablero_General[i][j]=='*'){
                vector<TipoEntero > mom = {i,j};
                PosicionesLibres.push_back(mom);
            }
        }
    }
    for(TipoEntero i=0 ;i<(PosicionesLibres.size());i++){
        cout<<"<";
        cout<<PosicionesLibres[i][0];
        cout<<" ; ";
        cout<<PosicionesLibres[i][1];
        cout<<">";
        cout<<" ";
    }

}
void CArena::AgregarRobot() {
    cout<<"Hola , porfavor siga las indicaciones :";
    cout<<endl;
    string Nombre_del_Robot_Nuevo;
    cout<<"Ingrese el Nombre de su Robot : ";cin>>Nombre_del_Robot_Nuevo;
    Caracter Caracter_momentanio;
    do {
        cout << "Indique el Caracter que tendra su Robot : ";
        cin >> Caracter_momentanio;
        cout<<"Que no sea '*' ";
        cout<<endl;
    }while (Caracter_momentanio=='*');
    TipoEntero PosicionenX=0,PosicionenY=0;
    VerificarSiPuedeOspedarseAhi(PosicionenX , PosicionenY , PosicionesLibres);
    TipoEntero Vida_del_robot;
    do{
        cout<<"Indique la vida del robot : ";cin>>Vida_del_robot;
    }while (Vida_del_robot<0 ||Vida_del_robot>150);
    TipoEntero Ataque_del_robot;
    do{
        cout<<"Indique el danio del robot , cual es el danio que tendra : ";cin>>Ataque_del_robot;
        if(Ataque_del_robot>15){
            cout<<"Te hago recordar que el ataque no sea mallor a 15."<<endl;
        }
    }while(Ataque_del_robot<0 || Ataque_del_robot>15);
    CRobot *momentanio=new CRobot(PosicionenX, PosicionenY,Vida_del_robot,Ataque_del_robot, Caracter_momentanio , Nombre_del_Robot_Nuevo);
    Grupo_de_Objetos.push_back(momentanio);
    ActualizarArena();
    ImprimirArena();
}





TipoEntero verifica(vector<vector<TipoEntero >>&vectorprobar, TipoEntero x , TipoEntero y){
    TipoEntero medida=vectorprobar.size();
    TipoEntero a=0;
    TipoEntero posicion;
    for (int i=0 ; i<medida; i++){
        if(x==vectorprobar[i][0] && y==vectorprobar[i][1]){
            a=1;
        }
    }
    return a;
}
void borrar(vector<vector<TipoEntero >>&vv , TipoEntero x , TipoEntero  y ){
    TipoEntero medida=vv.size();
    TipoEntero a=0;
    TipoEntero posicion;
    for (int i=0 ; i<medida; i++){
        if(x==vv[i][0] && y==vv[i][1]){
            a=1;
            posicion=i;
        }
    }
    if(a==1){
        vv.erase(begin(vv)+posicion);
    }
}
void CArena::Algoritmo_Sp(TipoEntero pix , TipoEntero piy , TipoEntero pfx , TipoEntero pfy, vector<vector<TipoEntero >>posiciones_libres , vector<vector<vector<TipoEntero >>>&camino_exitoso , vector<vector<TipoEntero >>caminos_intentados , TipoEntero conteo ,vector<TipoEntero >&conteomax ){
    //Algoritmo &SFPM&
    TipoEntero medida_del_vector = posiciones_libres.size(); //asemejamos una variable para el tamaño del vector de posiciones libres .
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
VoF buscarsiseencuentra(vector<CObjeto*> &vctr , Caracter &U, TipoEntero &posicionenelvector){
    VoF comprobacion=false;
    if(vctr.size()>0){
        for(TipoEntero i=0 ; i<vctr.size();i++){
            if(vctr[i]->getCaracter_Del_Objeto()==U){
                comprobacion=true;
                posicionenelvector= i;
            }
        }
        return comprobacion;
    }
    else{
        cout<<"No hay robots en la arena.";
    }

}
VoF buscarsiseencuentra(vector<CObjeto*> &vctr , Caracter &U, TipoEntero &posicionenelvector , Caracter m){
    VoF comprobacion=false;
    if((vctr.size()>0) && (U!=m)){
        for(TipoEntero i=0 ; i<vctr.size();i++){
            if(vctr[i]->getCaracter_Del_Objeto()==m){
                comprobacion=true;
                posicionenelvector= i;
            }
        }
        return comprobacion;
    }
    else{
        cout<<"No hay robots en la arena y son de la misma clase , eso no vale.";
    }

}
void CArena::iralataque() {
    Caracter caracterdelobjeto;
    VoF Y=false;
    TipoEntero posicion_en_el_vector;
    do{
        cout<<"Porfavor ingrese el caracter del Objeto(robot) que va a utilizar :"<<endl;
        cin>>caracterdelobjeto;
        Y=buscarsiseencuentra(Grupo_de_Objetos , caracterdelobjeto , posicion_en_el_vector);
    }while (Y == false);
    TipoEntero pix = Grupo_de_Objetos[posicion_en_el_vector]->getPosicion_X();
    TipoEntero piy=Grupo_de_Objetos[posicion_en_el_vector]->getPosicion_Y();


    Caracter otrorobot;
    VoF Y2;
    TipoEntero posicion_en_el_vector2;
    do{
        cout<<"Porfavor ingrese hacia que robot quiere ir : ";cin>>otrorobot;
        Y2=buscarsiseencuentra(Grupo_de_Objetos , caracterdelobjeto , posicion_en_el_vector2 , otrorobot);
    }while (Y2== false);
    TipoEntero pfx=Grupo_de_Objetos[posicion_en_el_vector2]->getPosicion_X();
    TipoEntero pfy=Grupo_de_Objetos[posicion_en_el_vector2]->getPosicion_Y();
    TipoEntero medida_del_vector = PosicionesLibres.size();

    vector<vector<vector<TipoEntero >>> camino_exitosos;
    TipoEntero conteo=0;
    vector<TipoEntero >conteomax;
    vector<vector<TipoEntero >> intentados;
    Algoritmo_Sp(pix , piy , pfx , pfy , PosicionesLibres ,camino_exitosos  , intentados,conteo ,conteomax);

    TipoEntero menor=1000000;
    TipoEntero posicionenlaqueseencuentra;
    for(TipoEntero i=0 ; i<conteomax.size(); i++){
        if(conteomax[i]<menor){
            menor=conteomax[i];
            posicionenlaqueseencuentra=i;
        }
    }
    for(TipoEntero i=0 ; i<camino_exitosos[posicionenlaqueseencuentra].size();i++){
        Grupo_de_Objetos[posicion_en_el_vector]->setPosicion_X(camino_exitosos[posicionenlaqueseencuentra][i][0]);
        Grupo_de_Objetos[posicion_en_el_vector]->setPosicion_Y(camino_exitosos[posicionenlaqueseencuentra][i][1]);
        ActualizarArena();
        ImprimirArena();
    }


}


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

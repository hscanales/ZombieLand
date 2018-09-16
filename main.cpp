/*incluyendo todas las librerias utilizadas*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

using namespace std;
///*Creando la clase y las funciones que leen y guardan los datos de la matriz*///////7

using namespace std;
   
 struct nodo{
    int dato;
    nodo *sig;
};

class ListaSimple{
private:
    nodo *inicio;
    
public:
    ListaSimple();
    nodo *CrearNodo(int);
    void insertarInicio(int);
    void insertarFinal(int);
    void mostrar();
    int getdato(int);
    void modificardato(int,int); 
    
    
};

ListaSimple::ListaSimple() {
    this->inicio=NULL;
}
nodo *ListaSimple::CrearNodo(int dato){
    nodo *nuevo= new(nodo);
    nuevo->dato= dato;
    nuevo->sig=NULL;
    return nuevo;
}
void ListaSimple::insertarInicio(int dato){
    nodo *nuevo = ListaSimple::CrearNodo(dato);
    nuevo->sig=this->inicio;
    this->inicio=nuevo;
}

void ListaSimple::mostrar(){
    nodo *salto = this->inicio;
    while(salto)
    {
        cout << salto->dato << " ";
        salto=salto->sig;
    }
    cout << "\n";
    cout<<"ds";
}
void ListaSimple::insertarFinal(int dato){
      nodo *nuevo = ListaSimple::CrearNodo(dato);
       nodo *aux;
       if(this->inicio)
      {
          aux=this->inicio; 
          while(aux->sig)
          {
              aux=aux->sig;
          }
          aux->sig=nuevo; 
          nuevo->sig=NULL;
      }
      else
      {
          
        nuevo->sig=this->inicio; 
        this->inicio=nuevo; 
          
      }
}
int ListaSimple::getdato(int dato){
    nodo *aux=this->inicio;
    int cont=0;
    int n=0;
    while(aux->sig && cont < dato){
        //cout<<" "<<aux->dato;
        aux=aux->sig;
        cont++;
    }
    n=aux->dato;
    return n;
}
void ListaSimple::modificardato(int dato, int pos){
    nodo *aux=this->inicio;
    int cont=0;
    while(aux->sig && cont < pos){
        aux=aux->sig;
        cont++;
    }
    aux->dato=dato;
    
}
    
/////////////////////////////////////////////////////////////////////////////////7
//////////////////////////////////////////////////////////////////////////////777
/*Creando clases que administras la matriz, y resuelve el algoritmo*/
class archivo{
private:
    int nfil,ncol;
    ListaSimple lista;
    
public:
    void leer(string);
    void mostrar(SDL_Surface *, SDL_Surface *);
    void resolverV(int,int);
    bool resolver(int,int);
};
void archivo::leer(string lab){
    
    ifstream archivo(lab,ios::in);
    string l;
    char chad;
    //cout<<"hola";
    int contl=0,contc=0,cont=0;
    if(archivo.is_open()){
        //cout<<"hola";
        while(!archivo.eof()){
            //cout<<"hola";
            getline(archivo,l);
            contl++;
            cont=l.size();
            if(cont>contc){
                contc=cont;
            }
        }
    }
    archivo.close();
    string aa;
    archivo.open(lab);
    string p = "M";
    string c = "0";
    string v = "S";
    int a[cont][contc];
    for(int i=0;i<contl;i++){
        getline(archivo,l);
        for(int j=0;j<contc;j++){
            if(j<l.size()){
                aa=l[j];
                if(aa==p){
                    //cout<<"t";
                    a[i][j]=1;
                    
                }
                if(aa==c){
                    //cout<<"k";
                    a[i][j]=0;
                    
                }
                if(aa==v){
                    //cout<<"l";
                    a[i][j]=2;
                    
                }
                if(aa!=v && aa!=c && aa!=p){
                    //cout<<"z";
                    a[i][j]=1;
                }
                
            }
            else{
                //cout<<"a";
                a[i][j]=1;
            }
        }
    }
    cout<<endl;
    //cout<<"hola";
    this->nfil=contl;
    this->ncol=contc;
    for(int i=0;i<contl;i++){
        //cout<<"ooooooooo";
        for(int j=0;j<contc;j++){
           // cout<<a[i][j];
            lista.insertarFinal(a[i][j]);
        }
      //  cout<<endl;
    }
    //cout<<"ad";
    cout<<" filas: "<<nfil<<endl;
    cout<<" columnas: "<<ncol<<endl;
   // lista.mostrar();
   // cout<<"d";
    
    
    
    //cout<<"sdsd \n";
    

    
}


void archivo::mostrar(SDL_Surface *pared, SDL_Surface *cami){
   interfaz l;
 SLD_BlitSurface(image1,NULL,windowSurface,NULL);
  SDL_Surface *sal = NULL;
    sal = IMG_Load("maps/pared4.png");
    int po=0;
    int k=nfil,p=ncol;
    int a[k][p];
 
    cout<<endl;
    for(int i=0;i<k;i++){
        for(int j = 0;j<p;j++){
            if(a[i][j]=='c'){
            i.imagenponer(cami,i*30,j*30,10,10);}
            if(a[i][j]=='p'){
                i.imagenponer(pared,i*30,j*30,10,10);
            }
            else if{
                i.imagenponer(sal,i*30,j*30,10,10);
            }    
            a[i][j]=lista.getdato(po);
            po++;
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

bool archivo::resolver(int x,int y){
       int po=0;
    int k=nfil,p=ncol;
    int a[k][p];
    //int y=lista.getdato(3);
   // cout<<k;
    //cout<<p;
   // cout<<"aki"<<y;
        for(int i=0;i<k;i++){
        for(int j = 0;j<p;j++){
            a[i][j]=lista.getdato(po);
            po++;
           //cout<<a[i][j];
        }
      //  cout<<endl;
    }
    // c v si encontramos la salida xd
    if(a[x][y]==2){
        return true;
    }
    //raton :V
    po=0;
    a[x][y]=5;
    for(int i=0;i<k;i++){
        for(int j = 0;j<p;j++){
            a[i][j]=lista.getdato(po);
            if(i==x && j==y){
               // cout<<"DFDFSDF";
                lista.modificardato(5,po);
            }
            po++;
            //cout<<a[i][j];
        }
      //  cout<<endl;
    }
    
    if(x>=0 && (a[x-1][y]==0 || a[x-1][y]==2 ) && archivo::resolver(x-1,y)){
       // cout<<"Fdf";
        return true;
    }
    if(x < k && (a[x+1][y]==0 || a[x+1][y]==2) && archivo::resolver(x+1,y)){
        return true;
    }
    if(y >= 0 && (a[x][y-1]==0 || a[x][y-1]==2) && archivo::resolver(x,y-1)){
        return true;
    }
    if(y < p && (a[x][y+1]==0 || a[x][y+1]==2) && archivo::resolver(x,y+1)){
        return true;
    }
   // cout<<endl;
    po=0;
    a[x][y]=0;
   for(int i=0;i<k;i++){
        for(int j = 0;j<p;j++){
            a[i][j]=lista.getdato(po);
            if(i==x && j==y){
                lista.modificardato(0,po);
            }
            po++;
        }
    }
    return false;
}




void sdl();
/////////////////////////////////////////////////////////////////////////////////7
//////////////////////////////////////////////////////////////////////////////777
/*Creando clases de interzas y la structura que llevara el top ten*/

struct top{
    float tiempo;
    string nickname, laberinto;
    top *sig;
};

class interfaz{
private:
    SDL_Window *ventana ;
    float tiempo;
    SDL_Surface *fondo ;
    string seleccion, nickname, laberin;
    top *ten;
    int num;
    //char m[25][25];
public:
    /*Setter,getter y datos para persona en el top ten, juego funciones para la interfaz */
    interfaz ();
    void crearnodo(string,float,string);
    void archivotop();
    void ordenartopmax();
    void guardastoplista ();
    void setLaberin (string);
    void setTime(float);
    void setNickname(string);
    string getLaberin();
    float getTime();
    string getNickname();
    void inicializador ();
    void seleccionarMapa();
    int Recorrer (SDL_Surface *,int,int,int);
    void Imagenponer (SDL_Surface *, int, int, int, int);
    void tiempito ();
    void laberinto (SDL_Surface *, SDL_Surface *, char *,string);//pared y suelo a utilizar, nombre ventana, nombre archivo de text
    void finalgameover ();
    
};
/*SE CREA EL NODO, PARA EL TOP TEN, QUE SE RESUELVE SOLO :)*/
void interfaz::crearnodo(string name, float time, string lab){
top *nuevo = new top;
nuevo->nickname = name;
nuevo->laberinto = lab;
nuevo->tiempo = time;
nuevo->sig = ten;
ten = nuevo;
}
/*LLENANDO Y ASIGNANDO SETTERS Y GETTERS*/
void interfaz::setLaberin(string labe){
    this ->laberin = labe;
}
void interfaz::setNickname(string name){
    this ->nickname = name;
}
void interfaz::setTime(float ti_me){
    this ->tiempo = ti_me;
}
string interfaz::getLaberin(){
    return this->laberin;
}
string interfaz::getNickname(){
    return this->nickname;
}
float interfaz::getTime(){
    return this->tiempo;
}
/*CONTRUCTOR BASE :V*/
interfaz::interfaz(){
    SDL_Init(SDL_INIT_VIDEO);
    this->ventana = NULL;
    this->fondo = NULL;
    this->ten = NULL;
}

void interfaz::laberinto(SDL_Surface *par, SDL_Surface *cami, char* lab, string Eleccion){
    SDL_Event e;
    bool in=true;
    archivo l;
    /*se llama la clase que tiene la funcion que guarda los datos del txt en dos arrays*/
    l.leer(Eleccion);
    l.mostrar(par,cami);
    /*Se crea la ventana del laberinto :3*/
this->ventana = SDL_CreateWindow(lab, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 938,713,SDL_WINDOW_SHOWN);//creando ventana
this->fondo = SDL_GetWindowSurface(this->ventana);//tirando ventana al fodo
while(in){//Mientras este corriendo el programa
        SDL_Event e;//Declaramos los eventos con una variable e
        if(e.type==SDL_QUIT){
             SDL_DestroyWindow(this->ventana); // destruimos la ventana
             this->ventana=NULL;
             SDL_Quit(); // salimos de sdl
             in=false;
        }
        while(SDL_PollEvent(&e)){//Nos deja manipular varios eventos sin afectar a otros  referenciados al evento e
            if(e.type == SDL_MOUSEBUTTONDOWN){//cerifica si hay eventos del mouse
            
                    if(e.button.button==SDL_BUTTON_LEFT){//verifica que se el boton del mouse usado fuese el izquierdo
                    //los siguientes if y else if verifican el evento donde ocurrio el link para enviarlo a lfuncion de inicializacion 
                         if(e.button.x >= 410 and e.button.y >= 600 and e.button.x <= 460 and e.button.y <= 700){
/*
                            time(&tfinal);
                            segundos=difftime(tfinal,tinicio);
                            cout<<"los segundos en esta pantalla fueron= "<<segundos<<endl;
*/
                             SDL_DestroyWindow(this->ventana); // destruimos la ventana
                            this->ventana=NULL;
                            SDL_Quit(); // salimos de sdl
                            
                            
                    }
                }
                }
        }
        SDL_UpdateWindowSurface(this->ventana);//Obdulio dijo que refresca la ventanita y deja limpio
    }
}

void interfaz::Imagenponer(SDL_Surface *zombieimagen, int x, int y, int w, int h){
    SDL_Rect coor;//guarda las coordenadas de un evento
    coor.x = x;//coordenadas x
    coor.y = y;//coordenanadas y
    coor.w = w;//corrdenadas de anchura
    coor.h = h;//coordenadas de altura
    SDL_BlitSurface(zombieimagen,NULL, this->fondo, &coor);//pone la imagen en su lugar de coordenadas asignadas   
}

void interfaz::inicializador(){
    int seleccion;// declarar el caso para el laberinto que se usara
    bool in = true,i=true;//bandera para el while
    bool end = false;//bandera final x2
    time_t tinicio;
    time_t tfinal;
    double segundos;
    time(&tinicio);
    SDL_Surface *botonjugar = NULL, *fondoMenu = NULL;//declaracion de mapas y fondo sdl
    botonjugar = IMG_Load("boton-jugar.png");//dandole variables a las imagenes y llamandolas desde carpeta raiz
    fondoMenu = IMG_Load("fondo inicio.png");//x5
    this->ventana = SDL_CreateWindow("Zombielandia  ( . Y . )", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 938,713,SDL_WINDOW_SHOWN);//creando ventana
    this->fondo = SDL_GetWindowSurface(this->ventana);//tirando ventana al fodo
    SDL_BlitSurface(fondoMenu,NULL,fondo,NULL);//se pone fondo a la ventana
    Imagenponer(botonjugar, 410, 600, 5, 5);//se colocan los botones e imagenes en el menu.

    while(in){//Mientras este corriendo el programa
        SDL_Event e;//Declaramos los eventos con una variable e
        if(e.type==SDL_QUIT){
             SDL_DestroyWindow(this->ventana); // destruimos la ventana
             this->ventana=NULL;
             SDL_Quit(); // salimos de sdl
             in=false;
        }
        while(SDL_PollEvent(&e)){//Nos deja manipular varios eventos sin afectar a otros  referenciados al evento e
            if(e.type == SDL_MOUSEBUTTONDOWN){//cerifica si hay eventos del mouse
            
                    if(e.button.button==SDL_BUTTON_LEFT){//verifica que se el boton del mouse usado fuese el izquierdo
                    //los siguientes if y else if verifican el evento donde ocurrio el link para enviarlo a lfuncion de inicializacion 
                         if(e.button.x >= 410 and e.button.y >= 600 and e.button.x <= 460 and e.button.y <= 700){
                            time(&tfinal);
                            segundos=difftime(tfinal,tinicio);
                            cout<<"los segundos en esta pantalla fueron= "<<segundos<<endl;
                             SDL_DestroyWindow(this->ventana); // destruimos la ventana
                            this->ventana=NULL;
                            SDL_Quit(); // salimos de sdl
                            seleccionarMapa();
                            
                    }
                }
                }
        }
        SDL_UpdateWindowSurface(this->ventana);//Obdulio dijo que refresca la ventanita y deja limpio
    }
}

void interfaz::seleccionarMapa(){
    int seleccion;// declarar el caso para el laberinto que se usara
    bool in = true,i=true;//bandera para el while
    bool end = false;//bandera final x2
    SDL_Surface *mapaz1 = NULL, *mapaz2 = NULL, *mapaz3 = NULL, *mapaz4 = NULL, *fondoSelectMap = NULL, *im1 = NULL, *im2 = NULL, *im3 = NULL, *im4 = NULL, 
    *pasi1=NULL,*pasi2=NULL,*pasi3=NULL,*pasi4=NULL,
    *cami1=NULL,*cami2=NULL,*cami3=NULL,*cami4=NULL;//declaracion de mapas y fondo sdl
    mapaz1 = IMG_Load("maps/images.jpeg");//dandole variables a las imagenes y llamandolas desde carpeta raiz
    mapaz2 = IMG_Load("maps/images.jpeg");//x2
    mapaz3 = IMG_Load("maps/images.jpeg");//x3
    mapaz4 = IMG_Load("maps/images.jpeg");//x4
    fondoSelectMap = IMG_Load("Map-Selector.png");//x5
    im1 = IMG_Load("maps/lab-1.png");//x6
    im2 = IMG_Load("maps/lab-1.png");//x7
    im3 = IMG_Load("maps/lab-3.png");//x8
    im4 = IMG_Load("maps/lab-4.png"); //x9
    pasi1 = IMG_Load("pasi/pared4.png");//x10
    pasi2 = IMG_Load("pasi/pared6.png");//x11
    pasi3 = IMG_Load("pasi/pared.png");//x12
    pasi4 = IMG_Load("pasi/pared3.png"); //x13
    cami1 = IMG_Load("pasi/suelo.png");//x14
    cami2 = IMG_Load("pasi/suelo2.png");//x15
    cami3 = IMG_Load("pasi/suelo7.png");//x16
    cami4 = IMG_Load("pasi/suelo4.png"); //x17
    this->ventana = SDL_CreateWindow("Elejir mapa  ( . Y . )", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600,SDL_WINDOW_SHOWN);//creando ventana
    this->fondo = SDL_GetWindowSurface(this->ventana);//tirando ventana al fodo
    SDL_BlitSurface(fondoSelectMap,NULL,fondo,NULL);//se pone fondo a la ventana
    Imagenponer(mapaz1, 80, 150, 5, 5);//se colocan los botones e imagenes en el menu.
    Imagenponer(mapaz2, 550, 150, 5, 5);//x2
    Imagenponer(mapaz3, 80, 370, 5, 5);//x3
    Imagenponer(mapaz4, 550, 370, 5, 5);//x4
    Imagenponer(im1, 100, 300, 5, 5);//x5
    Imagenponer(im2, 570, 300, 0, 0);//x6
    Imagenponer(im3, 100, 520, 5, 5);//x7
    Imagenponer(im4, 570, 520, 5, 5); //x8
                
    while(in){//Mientras este corriendo el programa
        SDL_Event e;//Declaramos los eventos con una variable e
        if(e.type==SDL_QUIT){
             SDL_DestroyWindow(this->ventana); // destruimos la ventana
             this->ventana=NULL;
             SDL_Quit(); // salimos de sdl
             in=false;
        }
        while(SDL_PollEvent(&e)){//Nos deja manipular varios eventos sin afectar a otros  referenciados al evento e
            if(e.type==SDL_MOUSEBUTTONDOWN){//cerifica si hay eventos del mouse
                if(e.button.button==SDL_BUTTON_LEFT){//verifica que se el boton del mouse usado fuese el izquierdo
                    //los siguientes if y else if verifican el evento donde ocurrio el link para enviarlo a lfuncion de inicializacion 
                    if(e.button.x >= 100 && e.button.y >= 300 && e.button.x <= 200 && e.button.y <= 350){
                        seleccion = 1;
                        //inicializador();
                        laberinto(pasi1, cami1, "xxx.:(.Y.):.xxx", "mapaz1.txt");
                        in = false;
                    }
                    else if(e.button.x >= 570 && e.button.y >= 300 && e.button.x <= 670 && e.button.y <= 350){
                        seleccion = 2;
                        //laberinto(pasi2, cami2, "xxx.:(.Y.):.xxx", "mapaz2.txt");
                        in = false;
                    }
                    else if(e.button.x >= 100 && e.button.y >= 520 && e.button.x <= 200 && e.button.y <= 570){
                        seleccion = 3;
                        //laberinto(pasi3,cami3 "xxx.:(.Y.):.xxx", "mapaz3.txt");
                        in = false;
                    }
                    else if(e.button.x >= 570 && e.button.y >= 520 && e.button.x <= 670 && e.button.y <= 570){
                        seleccion = 4;
                        //laberinto(pas4, cami4, "xxx.:(.Y.):.xxx", "mapaz4.txt");
                        in = false;
                    }
                }
            }
        }
        SDL_UpdateWindowSurface(this->ventana);//Obdulio dijo que refresca la ventanita y deja limpio
    }
    SDL_DestroyWindow(this->ventana); // destruimos la ventana
    this->ventana=NULL;
    SDL_Quit(); // salimos de sdl
}

int main(int argc, char** argv) {
    interfaz i;
    i.inicializador();
   
    return 0;
}


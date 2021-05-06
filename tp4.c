#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//estructuras
typedef struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea;
struct Tnodo{
    Tarea tarea;
    struct Tnodo *siguente;
};
typedef struct Tnodo * Lista;

//funciones
Lista *crearListaVacia();
Tarea crearTarea(int);
Lista crearNodo(Tarea);
void insertarNodoALista(Lista* L, Lista nodo);
void mostrar(Lista*);

int main(){
    srand(time(NULL));
    int cant_tareas;
    printf("Ingrese la cantidad de tereas a cargar: ");
    scanf("%d", &cant_tareas);
    Lista *tareas=crearListaVacia();
    //crear tareas en arreglo
    for (int i = 0; i < cant_tareas; i++)
    {
        Tarea nuevaTarea= crearTarea(i+1);
        Lista Tnodo= crearNodo(nuevaTarea);
        insertarNodoALista(tareas,Tnodo);
        
    }
    mostrar(tareas);
    
}
Lista *crearListaVacia(){
    return NULL;
}
Tarea crearTarea(int id){
    Tarea nuevaTarea;
    nuevaTarea.TareaID= id;
    nuevaTarea.Descripcion= (char *)malloc(sizeof(char)*100);
    printf("Descripcion de la tarea: ");
    gets(nuevaTarea.Descripcion);
    nuevaTarea.Duracion= rand ()%(100-10+1)+10;
    return nuevaTarea;
}
Lista crearNodo(Tarea tarea1){
    Lista nuevaTarea=(Lista )malloc(sizeof(Lista));
    nuevaTarea->tarea =tarea1;
    nuevaTarea->siguente= NULL;
    return nuevaTarea;
}
void insertarNodoALista(Lista* L, Lista nodo){
    nodo->siguente= *L;
    *L= nodo;
}
void mostrar(Lista *L){
    Lista *aux= L;
    while(aux){
        printf("----Datos de la tarea num %d----\n", (*aux)->tarea.TareaID);
        printf("Descripcion: %s\n", (*aux)->tarea.Descripcion);
        printf("Duracion: %d\n", (*aux)->tarea.Duracion);
        *aux= (*aux)->siguente;
    }
}
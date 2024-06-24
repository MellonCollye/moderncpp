//DEDUCCION DE TIPOS EN TEMPLATES

#include <iostream>

class func{
  public: 
  //Caso 1: Refs y Punteros
    template<typename T>
    void printearRef(T& param);

    template<typename T>
    void printearConstRef(const T& param);

    template<typename T>
    void printearPointer(T* pParam);

  //Caso 2: Doble refs
  
    template<typename T>
    void printearURef(T&& param);
  //Caso 3: Valor
    template<typename T>
    void printear(T param);

  //Caso 4: Arrays
    template <typename T>
    void func::printearArray(T& param);
};



//Caso 1: param es de tipo ref o pointer

template<typename T>
void func::printearRef(T& param){
  std::cout << "\n" << param <<"\n";
}

//T va a ser el tipo del argumento
//si le paso const param se va a deducir como referencia constante, sino como referencia

template<typename T>
void func::printearConstRef(const T& param){
  std::cout << "\n" << param <<"\n";
}
//T va a ser el tipo del argumento
//param va a ser siempre un ref const

template<typename T>
void func::printearPointer(T* pParam){
  std::cout << "\n" << *pParam << "\n";
}
//T va a ser el tipo de pParam
//se deduce igual que el primero, si le paso const,param se va a evaluar como un puntero constante, sino no

//Caso 2: param es una referencia universal

lvalue: Un lvalue es una expresión que representa una ubicación en memoria. Los lvalues tienen una dirección de memoria asociada, lo que significa que puedes tomar su dirección usando el operador &. Los lvalues son generalmente variables, elementos de array, o referencias.

rvalue: Un rvalue es una expresión que representa un valor temporal que no tiene una ubicación de memoria persistente. Los rvalues no pueden tener su dirección tomada (no puedes hacer &rvalue). Los rvalues son típicamente literales (como números) o el resultado de operaciones que devuelven un valor temporal.

referencia universal: Una referencia universal es un tipo especial de referencia introducida en C++11 que puede vincularse tanto a lvalues como a rvalues. Solo se considera una referencia universal en ciertas condiciones específicas, generalmente en el contexto de deducción de plantillas.

La evaluacion va a depender de si param es un lvalue o rvalue
si el argumento es un lvalue:
    -se va a evaluar siempre como ref, si el argumento en const sera ref constante. T y param van a ser del mismo tipo
Si el argumento es rvalue:
    -si el argumento es rvalue, T va a ser el tipo del argumento y param va a ser una doble ref(universal ref)

template<typename T>
void func::printearURef(T&& param){

} 


//Caso 3: param no es ni un puntero ni una referencia

template<typename T>
void func::printear(T param){
  std::cout << "\n" << param << "\n";
}

//Recordar: al pasar por valor un argumento a una funcion lo que se esta haciendo es una nueva copia de la variable original, por eso si paso por ref, estaria pasando el original

La deduccion de tipo se realizara crudamente, simplemente se asignara a T y param el tipo del argumento, ignorando si es ref o const o ref const

Hay una excepcion a esta ignoracion de constnesses y referenceness

si le paso un const int(por ejemplo) * const, osea un puntero constane(inmodificable) a un tipo constante, la consteness del puntero se ignorara piero la del tipo no, entonces el tipo deducido de param sera const int*

//caso 4: arrays pasados a template

se puede hacer que un array decaiga a puntero o alguna bullshit asi,

//el tema es que se hace con refs 
template <typename T>
void func::printearArray(T& param){

}


el compilador hace una magia negra para evaluar, a partir del argumento pasado, el param como un array (con el tamaño exacto inclusive)

Ultima nota: Funciones como argumento:

Las funciones tambien pueden decaer a punteros asi como los Arrays, la diferencia es que decaen a punteros a funcion, si param es por valor se evaluan como ptr-a-funcion, si param es por ref, se evaluan como ref-a-funcion



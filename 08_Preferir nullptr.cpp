a la hora de usar un puntero nulo comunmente se utilizaba 0 o NULL, 
esto esta mal, pues estos tipos suelen ser evaluados como enteris y 
pocas veces son evaluados como punteros.

En este ejemplo se puede verificar este comportamiento:

void f(int);
void f(bool);
void f(void*);

f(0);                   //Va a llamar a f(int), no a f(void*)

f(NULL);    //Puede que no compile siquiera, tipicamente llama a f(int)            
            //Nunca a f(void*)

Por lo tanto, para no romper legacy code es conveniente no sobrecargar 
punteros y enteros como para que ocurra este error con 0 o NULL.

La solucion a este problema es nullptr, un "puntero" que puede apuntar 
a cualquier tipo de puntero de verdad

nullptr es un entero? no, ni ahi. nullptr es un puntero? tampoco. 
En realidad nullptr es de tipo std::nullptr_t (lo gracioso es que el 
tipo de std::nullptr_t es nullptr, redundante). Y este tipo 
std::nullptr_t tiene de especial que puede castearse implicitamente 
a cualquier tipo de raw pointer, esto seria lo que hace que nullptr sea 
"un puntero de todos los tipos".

Por eso, si llamo a f con nullptr va a funcionar como intencionaba:

f(nullptr);     //Llama a f(void*)

-----------------------------------------------------------------------

Nota: Tener muy en cuenta que como NULL y 0 suelen ser evaluados como 
  enteros, si hago inferencia a partir de estos puede armarse quilombo. 
Sobre todo en las templates, pues, puede que se infiera un argumento 
como int cuando queriamos que se infiera como void* y esto puede ser 
un problemon.




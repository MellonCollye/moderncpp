A veces c++ declara funciones "special member funcions" y si queres que el que usa el codigo no pueda llamarlas, vas a tener que deletear el copy constructor y/o el operator =

en c++11 para esto se utiliza delete:

ejemplo:

class Algo
...
public:
 …
 Algo(const Algo& ) = delete;
 Algo& operator=(const Algo&) = delete;
 …
};

-Las funciones deleted no se pueden usar de ninguna forma, si tratas de copiar estos objetos el codigo va a fallar en compilar

-Por convencion, las funciones deleted son declaradas publicas, para que los modificadores de accecibilidad no se metan en el medio

NOTA: cualquier funcion puede ser deleteada(inclusive funciones no miembro), esto puede llegar a servir por ejemplo, para evitar casteos implicitos de int a algo falopa:

bool isLucky(int number); // original function
bool isLucky(char) = delete; // reject chars
bool isLucky(bool) = delete; // reject bools
bool isLucky(double) = delete; // reject doubles and floats

esto prevenira la siquiera compilacion de un codigo que intente llamar a isLucky() con algo que no sea int.

-Aunque las funciones deleted no pueden ser usadas, forman parte del programa, por lo que se toman en cuenta en la resolucion de sobrecargas. Por ello, las llamadas a funciones deletes seran rechazadas.

-Otro uso muy importante del delete es que no solo sirve para las funciones, sino que tambien se puede inhabilitar instanciaciones de template. ejemplo:

class Widget {
public:
 …
 template<typename T>
 void processPointer(T* ptr)
 { … }
 …
};
template<>
void Widget::processPointer<void>(void*) = delete;



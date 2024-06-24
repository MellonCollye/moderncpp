decltype

Dada una expresion, decltype te da el tipo devuelto por la expresion.

//Variable:
const int i = 0;          decltype(i) = const int

//Expresion:
bool f(const Algo& w);    decltype(w) = const Algo&
                          decltype(f) = bool(const Algo&)

//Estructura:
struct Punto{             decltype(Punto::x) = int
 int x, y;                decltype(Punto::y) = int
};

//Clase:
Algo a;                   decltype(a) = Algo

//Expresion condicional:
if ( f (w) )              decltype( f (w) ) = bool

//Libreria estandar:
vector<int> v;            decltype(v) = vector<int>
                          decltype(v[0]) = int&


El uso primario de decltype en C++ es declarar function templates donde el tipo del retorno de la funcion depende de los tipos de parametros enviados:

      template<typename T, typename U>
      auto add(T t, U u) -> decltype ( t + u ){
          return t + u;
      }

Trailing return: el tipo de retorno de la funcion es declarado despues de la lista de parametros, lo que permite realizar inferencias a partir de estos. Si el tipo de retorno esta primero seria imposible utilizar los parametros por que todavia no existirian, y daria error de compilacion. 

Diferencias principales entre auto y trailing return al hacer inferencia de tipos de retorno de Funciones:

--Disponibilidad del Cuerpo de la Función:

auto: La deducción del tipo de retorno se hace en base a la expresión de retorno dentro del cuerpo de la función. Esto significa que el cuerpo de la función debe estar disponible para que el compilador pueda deducir el tipo de retorno.
Trailing return type (->): Permite especificar el tipo de retorno antes del cuerpo de la función, lo que puede ser útil para funciones declaradas fuera de una clase o en un archivo de cabecera. 


--Complejidad de Deducción:

auto: Es directo y simple para casos donde el tipo de retorno puede deducirse fácilmente de una expresión en el cuerpo de la función.

Trailing return type (->): Es más flexible y puede manejar situaciones más complejas, especialmente en funciones plantillas y cuando el tipo de retorno depende de los tipos de los parámetros.


--Funciones Plantillas y Lambdas:

auto: Es útil en funciones lambda donde la deducción del tipo de retorno es automática.

Trailing return type (->): Es útil en funciones plantillas complejas donde el tipo de retorno depende de los parámetros de la plantilla.


C++14 añade un par de capacidades a decltype:

decltype(auto) 

auto especifica que el tipo sera deducido, y decltype especifica que se deducira de acuerdo a las reglas de deduccion de decltype

Sirve para hacer inferencia de retornos de funciones y parar declarar variables, todo cuando queres utilizar las reglas de deduccion de decltype

Este tipo de inferencia es complejo, hay que usarlo con cuidado, puede llegar a producir comportamientos indefinidos, creo que es conveniente usar trailing return o auto

//retorno de funcion
template<typename Container, typename Index> 
decltype(auto) authAndAccess(Container& c, Index i){
    authenticateUser();
    return c[i];
}

//variables
Widget w;
const Widget& cw = w;
auto myWidget1 = cw; // auto type deduction
decltype(auto) myWidget2 = cw; //decltype type deduction


Tener en cuenta: el uso de parentesis alrededor de una expr indica una ref
//si le hago deduccion a algo como:
int x = 10;
decltype((x)) y; //el tipo de y va a ser int&





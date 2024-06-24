Como regla general, los valores de inicializacion pueden ser 
especificados con parentesis, un signo igual o con llaves.

int x (0);

int y = 0;

int z{ 0 };   //estos dos son tratados de la misma manera
int z = { 0 };

Es importante no confundir asignacion con inicializacion al 
inicializar con signo igual (=), sobre todo al trabajar con tipos 
definidos por el usuario.

Widget w1;  //default constructor

Widget w2 = w1 // inicializacion: constructor

w1 = w2       // asignacion: operator =

Los diferentes tipos de inicializacion pueden llevar a confusiones y 
errores, por eso es que en c++11 se introduce la Braced Initialization
-Ejemplo: std::vector <int> v{ 1, 3, 5};;

----------------------------------------------------------------------

Ventajas de la inicializacion Uniforme:

-De las formas de inicializacion que hay en c++11, la braced 
initialization es la unica que se puede utilizar en todos los casos

-La inicializacion uniforme prohibe la narrowing conversion, osea el 
casteo de tipos mas complejos a menos complejos. (ej: de double a int)

-Otra ventaja de la inicializacion uniforme es que ahorra confusiones 
entre funciones e inicializaciones:
  
Widget w2(); //es ambiguo, vos estas queriendo hacer una inicializacion 
//pero el compilador te lo puede tomar como una declaracion de funcion

Widget w2{}; //no se va a confundir, es una inicializacion uniforme

-----------------------------------------------------------------------

Desventajas de la inicializacion uniforme:

-Inicializacion Uniforme y auto no se llevan bien: una variable inferida 
con auto e inicializada con braced sera inferida de tipo 
std::initializer_list y esto va a traer problemas en los constructores 
sobrecargados

-Cuestion que tiene problemas en general con los std::initializer_list, 
si quiero inicializar algo con esto vacio lo tengo que llamar con doble 
{{}}, por que sino llama al constructor sin argumentos

Widget w5{{}};  //ahi lo va a tomar al std::initializer list vacio

-std::vector tambien tiene un problemita, si lo inicializo con parentesis 
el primer arg va a ser el tamaño y el segundo el valor de todos los 
elementos del array, en cambio si lo inicializo con llaves se 
inicializara normalmente

std::vector<int> v1(10, 20); // use non-std::initializer_list ctor: 
//create 10-element std::vector, all elements have value of 20
std::vector<int> v2{10, 20}; // use std::initializer_list ctor: 
//create 2-element std::vector, element values are 10 and 20








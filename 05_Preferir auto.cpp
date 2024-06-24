Razones para preferir auto en vez de declaraciones explicitas

-las variables auto tienen su tipo deducido desde su inicializacion, por lo que siempre deben ser inicializadas, evitando indeterminaciones y el problema de las variables sin inicializar

int x1; // potencialmente no inicializada
auto x2; // error! inicializacion requerida
auto x3 = 0; // variable inicializada

-las variables auto suelen tener menos verbosidad y ahorran tiempo

-pueden contener closures (ni se que es esto pero bue)

-pueden resolver problemas de compatibilidad entre diferentes implementaciones de tal tipo

-Tener en cuenta:

El tipo de cada variable auto es deducido desde si expresion de inicializacion, y algunas expresiones tienen tipos que no son ni anticipados ni deseados. auto no es perfecto.

En resumen:

-Las variables automáticas deben inicializarse, 
-generalmente son inmunesa discrepancias de tipos que pueden conducir a problemas de portabilidad o eficiencia,
-puede facilitar el proceso de refactorización 
-por lo general, requieren menos escritura que las variables con tipos especificados.


-tener cuidado cuando se usa auto para inferir un bool& desde un std::vector<bool>, por que el auto va a inferir un std::vector<bool>::reference. El tema es que c++ prohibe referencias a bits, por lo tanto se utiliza la clase proxy ::reference para dar la ilusion de que el operador [] aplicado a std::vector<bool> devuelve una referencia a un bit.

-tener mucho cuidado con inferencias de clases proxy "invisibles".


En cambio, si quiero forzar la inferencia tengo que castear la expresion de inicializacion al tipo que quiero que auto infiera:

auto x = static_cast<bool>();

esto es util para el problema de las referencias a bits.

std::vector<bool> v = {0,1,0,1,1};
auto x = static_cast<bool>(w[5]); //x==1

esto evita el comportamiento inesperado de auto y std::vector<bool>::reference



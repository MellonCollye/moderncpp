La deduccion de tipos de auto es igual a la deduccion de tipos del template, solo hay una unica excepcion

en la deduccion de auto, auto juega el papel de T 
auto es mas para inferencia de tipos en asignaciones

//Caso 1: especificador de tipo ref o pointer

auto& x = expr;

x va a ser el tipo de expr
si le paso const, x se va a deducir como const&, sino como referencia

const auto& x = expr;
 
x va a ser el tipo de expr
x va a ser siempre un ref const

auto* = expr;

x va a ser el tipo de expr
se deduce igual que el primero, si le paso const, x se va a evaluar como un puntero constante, sino no

//Caso 2: param es una referencia universal

La evaluacion va a depender de si param es un lvalue o rvalue
si expr es un lvalue:
    -x se va a evaluar siempre como ref, si expr es const sera const&
Si el argumento es rvalue:
    -si el argumento es rvalue, x va a ser el tipo del expr y param va a ser una doble ref(universal ref)


//Caso 3: param no es ni un puntero ni una referencia

La deduccion de tipo se realizara crudamente, simplemente se asignara a x el tipo de expr, ignorando si es ref o const o ref const

//caso 4: arrays pasados a auto, ejemplo

const char name[] = "R. N. Briggs";

auto arr1 = name (arr1 va a ser const char *);

auto arr2 = name (arr2 va a ser const char(&)[13]);

//Caso 5: Funciones como argumento, ejemplo

void func(int, double);

auto func1 = func; (func1 sera void(*)(int,double));

auto& func2 = func; (func2 sera void(&)(int,double));

//Caso 6: diferencia de deduccion entre template y auto

auto x1 = 27; 
auto x2(27);
auto x3 = {27};
auto x4{ 27 };

las primeras dos se evaluan normal, el tipo sera int, y su valor 27

lo curioso es en las ultimas dos, su tipo se deducira como std::initializer_list<int> y su valor sera {27}


la unica diferencia entre estas dos deducciones seria que auto interpreta un inicializador encerrado en llaves como un std::initializer_list, la deduccion de template no.
la deduccion de las ultimas dos inicializaciones no se puede reproducir con templates, tira error

la unica diferencia entre estas dos deducciones seria que auto interpreta un inicializador encerrado en llaves como un std::initializer_list, la deduccion de template no.



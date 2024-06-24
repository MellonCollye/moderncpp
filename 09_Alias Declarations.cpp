En c++98 para acortar los nombres de los tipos y no andar descifrando 
cosas como "std::unique_ptr<std::unordered_map<std::string, std::string>>"
se utilizaban los typedef:


typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS;


No hay mas caso, son feos y dificiles de leer los typedef, para eso 
en c++11 se introdujieron las "Alias Declarations"


using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;

----------------------------------------------------------------------

Considerar: Hay todo una bola sobre las templates y las alias 
declarations, pues los typedefs no pueden ser templatizados y hay que 
parcharlos

Un alias en un template, mira que facil es de usar:

template<typename T>
  using MyAllocList = std::list<T, MyAlloc<T>>;

----------------------------------------------------------------------

NOTA: algo bueno para saber es que se pueden quitar los modificadores 
const y ref de un tipo, esto con la lib <type_traits>:

  std::remove_const<T>::type // yields T from const T
  std::remove_reference<T>::type // yields T from T& and T&&
  std::add_lvalue_reference<T>::type // yields T& from T

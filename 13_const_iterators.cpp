no entiendo mucho lo que dice,

lo que rescato es que hay funciones de la stl que necesitan iteradores, que no se bien lo que son todavia, y en c++11 se pueden hacer constantes

std::vector<int> values;

std::find(values.cbegin(),values.cend(),1983);

values.insert(it,1998);

esto usa const_iterators

template<typename C, typename V>
void findAndInsert(C& container,const V& targetVal,const V& insertVal)
{ 

 using std::cbegin; 
 using std::cend;

 auto it = std::find(cbegin(container),cend(container),targetVal);
 container.insert(it, insertVal);
}

funciones como insert, find, y erase utilizan iterators para identificar las posiciones donde van a actuar dentro del contenedor iterable

por ultimo, menciona que hay que preferir const_iterators a los iterators normales


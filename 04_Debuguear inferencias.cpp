Nota: para obtener informacion sobre tipos se puede usar 

std::type_info::name
typeid(x).name()

Si queres debuguear inferencias en serio usa Boost/TypeIndex

#include <boost/type_index.hpp>
template<typename T>
void f(const T& param)
{
    using std::cout;
    using boost::typeindex::type_id_with_cvr;
  // show T
    cout << "T = "
    << type_id_with_cvr<T>().pretty_name()
    << '\n';
  // show param's type
    cout << "param = "
    << type_id_with_cvr<decltype(param)>().pretty_name()
    << '\n';
 …
}

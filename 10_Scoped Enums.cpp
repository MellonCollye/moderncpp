Los enums del c++98 son "Unscoped", esto quiere decir que los nombres que contenga se consideraran en el scope donde esta declarado el enum, y nada en ese scope podra tener ese nombre.

enum Color { black, white, red }; // black, white, red are
                                  // in same scope as Color
auto white = false; // error! white already
                    // declared in this scope

c++11 introduce "Scoped Enums", los nombres que haya adentro de un scoped enum no pertenceran al scope donde esta el enum, sino al scope en si del enum, de forma que no leakearan para afuera.

enum class Color { black, white, red }; // black, white, red
                                        // are scoped to Color
auto white = false; // fine, no other

Ya de por si, esta evitacion de ruido en el scope que evitan los class enums es razon para preferirlos.

A CONSIDERAR: los enumeradores de un scoped enum estan mucho mas fuertemente tipados, lo que los hace menos vulnerables a conversiones de tipo sin sentido.
A CONSIDERAR: los scoped enums pueden ser forward-declared, esto es, declarados sin ningun enumerador:

enum class Status; // forward declaration
void continueProcessing(Status s); // use of fwd-declared enum


Nota: el underlying type de un scoped siempre se conoce, y para los unscoped, podes especificarlo
Por default, el underlying type de los scoped es int

enum class Status; // underlying type is int

si el default no conforma, podes overridearlo:

enum class Status: std::uint32_t; // underlying type for
 // Status is std::uint32_t
 // (from <cstdint>)

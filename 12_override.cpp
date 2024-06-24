Override

la idea fundamental de c++ en cuanto al overriding es que "las implementaciones de funciones virtuales en clases derivadas overridean las implementaciones de las tales funciones en la clase base"

para que el override se produzca implicitamente las implementaciones derivadas deben tener exactamente la misma firma que las concretas, y a veces esto puede complicarse.

y de no producirse el overriding los mensajes de error son cripticos o ni siquiera notifica nada el compilado

es por eso, que en c++11 se introduce el overriding explicito:

class Base {
public:
 virtual void mf1() const;
 virtual void mf2(int x);
 virtual void mf3() &;
 virtual void mf4() const;
};
class Derived: public Base {
public:
 virtual void mf1() const override;
 virtual void mf2(int x) override;
 virtual void mf3() & override;
 void mf4() const override;   //añadir virtual no es necesario
};

de esta forma, si esta mal el overriding, el compilador te lo va a hacer saber



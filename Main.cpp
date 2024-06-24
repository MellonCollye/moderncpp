#include "Templates.cpp"
#include <memory>
#include <iostream>
#include <string>

using namespace std;

int main(){
  cout << "\nSe declara el objeto\n";
  
  unique_ptr<func>f(new func());;
  
  cout <<"\nSe declaran las variables\n";

  int num = 4;
  string str = "Hola mundo";

  f->printear(num);
  f->printear(str);

  cout << "\npor ref:\n";

  f->printearRef(num);
  f->printearRef(str);
}

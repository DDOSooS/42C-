#include <iostream>

class A {
    public:
     int x = 5;
     //some other things
};
class B : virtual public A { // inherit from the Class A.
    public:
      int i = 6;
};
class C : virtual public A { // inherit from the Class A.
    public:
      int i = 7;
};
class D : public B, public C { // inherit from both class B and C
    // something can go here..
};

int main(){
    D obj;
    std::cout << obj.x << std::endl;
    return 0;
}
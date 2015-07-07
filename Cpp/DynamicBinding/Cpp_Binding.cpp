#include <iostream>

using namespace std;

class Animal {
public:
   virtual void Speak() = 0;
   int GetAge() {
      return 3;
   }
};

class Dog : public Animal {
public:
   void Speak() {
      cout << "Meow";
   }
};

class Cat : public Animal {
public:
   void Speak() {
      cout << "Woof";
   }
};

int main() {
   Animal *a = nullptr;
   cout << "Do you want a: 1) Dog; 2) Cat? ";
   int selection;
   cin >> selection;
   if (selection == 1)
      a = new Dog();
   else
      a = new Cat();

   cout << "Your pet is " << a->GetAge() << " years old and says ";
   a->Speak();
   cout << "!" << endl;
   return 0;
}
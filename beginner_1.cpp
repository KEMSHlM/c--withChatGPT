#include <iostream>
#include <cstring>
#define NAMESIZE 16

class Animal {
    public:
        char* name;
        int age;
        
    public:
        Animal(const char* name, int age); // コンストラクタ (返り値の型がいらない)
        void print();    // 出力関数
};

// const char の型にcharの型は使えない．
Animal::Animal(const char* name, int age) {
    this->name = new char[NAMESIZE+1];
    strcpy(this->name, name); 
    this->age = age;
}

void Animal::print() {
   std::cout << this->name << "is" << this->age << "years old.\n";
}

int main(void) {
    Animal dog("Burton", 5);
    return 0;
}
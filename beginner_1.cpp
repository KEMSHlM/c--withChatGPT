#include <iostream>
#include <cstring>
#define NAMESIZE 16

using namespace std;

class Animal {
    public:
        char* name;
        int age;
        
    public:
        Animal(const char* name, int age); // コンストラクタ (返り値の型がいらない)
        void print(ostream *os);    // 出力関数
};

// const char の型にcharの型は使えない．
Animal::Animal(const char* name, int age) {
    this->name = new char[NAMESIZE+1];
    strcpy(this->name, name); 
    this->age = age;
}

// ostream(出力)，istream(入力)
void Animal::print(ostream *os) {
   *os << this->name << " is " << this->age << "years old.\n";
}

int main(void) {
    Animal dog("Burton", 5);
    dog.print(&cout); 
    return 0;
}
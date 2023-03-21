#include <iostream> 

class BankAccount {
    public:
        BankAccount(int id, int credit);
        void deposit(int money);
        void withdraw(int money);
        void print();

    private:
        int id;
        int credit;
};

BankAccount::BankAccount(int id, int credit){
    this->id = id;
    this->credit = credit;
}

void BankAccount::deposit(int money) {
    this->credit += money;  
}

void BankAccount::withdraw(int money) {
    this->credit -= money;  
}

void BankAccount::print () {
    std::cout << this->id << " : " << this->credit << "\n" ;
}

#define ID 1
#define MY_CREDIT 100

int main (void) {
    BankAccount mine(ID, MY_CREDIT);
    mine.print();
    mine.deposit(100);
    mine.print();
    mine.withdraw(100);
    mine.print();

    return  0; 
}
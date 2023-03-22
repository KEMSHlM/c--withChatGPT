/*
「Person」クラスを作成し、その中に名前と年齢を格納するプライベート変数を作成してください。
名前と年齢を設定するコンストラクタと情報を表示するメソッドを追加してください。また、「Employee」と「Student」クラスを作成し、「Person」クラスを継承してください。
「Employee」クラスには、雇用年数と給与を追加し、「Student」クラスには、学籍番号と専攻を追加してください。
それぞれのクラスに適切なコンストラクタと情報を表示するメソッドを追加してください。
*/
#include <iostream>

class Person {
    public:
        Person(const std::string& name, int age)
            : name(name), age(age) { }
        virtual void showInfo(std::ostream* os) const {
            *os << "Name : " << name << " , Age : " << age << "\n";
        }

    private:
        std::string name;
        int age;
};

class Employee : public Person {
    public:
        Employee(const std::string& name, int age, int employment_age, int salary)
            : Person(name, age), employment_age(employment_age), salary(salary) { }
        
        void showInfo(std::ostream* os) const {
            Person::showInfo(os); 
            *os << "\t" << "Employment age : " << employment_age << " , Salary : " << salary << "\n";
        }

    private:
        int employment_age;
        int salary;
};

class Student : public Person {
    public:
        Student (const std::string& name, int age, int id, std::string major)
            : Person(name, age), id(id), major(major) { }
        
        void showInfo(std::ostream* os) const {
            Person::showInfo(os); 
            *os << "\t" << "ID : " << id << " , Major : " << major << "\n";
        }

    private:
        int id;
        std::string major;
};

int main (void) {
    Person* Persons[] = {new Employee("Tanaka", 26, 3, 500), new Student("Koyama", 24, 6, "Engineering")};
    
    for (Person* person: Persons) {
        person->showInfo(&std::cout);
        delete person;
    }

    return 0;
}

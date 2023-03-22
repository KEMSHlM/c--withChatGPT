/*
C++のSTLを使用して、「Student」クラスのインスタンスを格納するリストを作成し、学生名でソートされた順序で表示するプログラムを作成してください。
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Student {
    public:
        Student(std::string name)
            : name(name) { }
        
        std::string& getName() {
            return name;
        }
        
        void showInfo (std::ostream* os) const {
            *os << name << "\n";
        }

        // 比較演算子をオーバーロードすることで昇順や降順が実現する． 
        // std::sort関数は，デフォルトで『>』演算子を利用するから．
        // そもそも，std::string型は比較演算子が辞書順で比較する．
        bool operator<(const Student &other) const {
            return name < other.name;
        }

    private:
        std::string name;
};

int main (void) {
    std::vector<Student> Students = {}; 
    Students.emplace_back("tanaka");
    Students.emplace_back("koyama");
    Students.emplace_back("shibuta");
    
    // 昇順に並び替える．
    std::cout << "Acending order: " << std::endl;
    std::sort(Students.begin(), Students.end());
    for (const Student student: Students) {
        student.showInfo(&std::cout);
    }

    // 降順に並び替える．rはリバースの意味．
    std::cout << "\nDescending order: " << std::endl;
    std::sort(Students.rbegin(), Students.rend());
    for (const auto iter: Students) {
        iter.showInfo(&std::cout); // イテレーター使ってみた．
    }

    return 0;
}
/*
テンプレートを使って、異なる型のデータを格納できる「Pair」クラスを作成してください。2つのデータを設定するコンストラクタと、それぞれのデータにアクセスするメソッドを追加してください。
*/

#include <iostream>

template<typename T1, typename T2>
class Pair {
    public:
        Pair(const T1& first, const T2& second)
            : first_(first), second_(second) { }
        
        T1 getFirst() const {
            return first_;
        }
        
        T2 getSecond() const {
            return second_;
        }

    private:
        T1 first_;
        T2 second_;
};

int main (void) {
    Pair<int, std::string> pair1(5, "May");
    Pair<double, std::string> pair2(3.14, "PI");
    
    std::cout << "Pair1 : (" << pair1.getFirst() << ", " << pair1.getSecond() << ")\n"; 
    std::cout << "Pair2 : (" << pair2.getFirst() << ", " << pair2.getSecond() << ")\n"; 
    
    return 0; 
}


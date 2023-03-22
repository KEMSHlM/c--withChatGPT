/*
例外処理を使用して、整数の配列を表す「IntArray」クラスを作成してください。インデックスが範囲外の場合、適切な例外をスローするようにしてください。
*/

#include <iostream>
#include <vector>

class IntArray {
    public:
        explicit IntArray(std::vector<int> vec)
            : vec(vec) { }
        
        int getValue(int num) const {
            try {
                int a = vec.at(num); // vec[num]では例外をキャッチできない．
                return a;
            } catch (const std::out_of_range& e) {
                std::cout << "std::out_of_rangeを捕捉" << std::endl;            
                std::cout << e.what() << std::endl;
                return -1;
            }
        }

    private:
        std::vector<int> vec;
};

int main (void) {
    std::vector<int> A = {1, 2, 3, 4, 5};
    IntArray B(A);
    
    std::cout << B.getValue(3) << std::endl;
    std::cout << B.getValue(6) << std::endl;
    std::cout << B.getValue(-1) << std::endl;

    return 0; 
}
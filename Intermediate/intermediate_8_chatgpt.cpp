/*
例外処理を使用して、整数の配列を表す「IntArray」クラスを作成してください。インデックスが範囲外の場合、適切な例外をスローするようにしてください。
*/

#include <iostream>
#include <stdexcept>
#include <vector>

class IntArray {
public:
    IntArray(size_t size) : data_(size) {}

    // なぜ二つあるのか
    // constメンバ関数用のオーバーロードと非コンスト用のオーバーロードを作成する必要がある．
    int& operator[](size_t index) {
        if (index >= data_.size()) { // data_もサイズ関数とか使えんだな．
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const int& operator[](size_t index) const {
        if (index >= data_.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

private:
    std::vector<int> data_;
};

int main() {
    IntArray arr(5);

    try {
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;

        std::cout << "arr[2]: " << arr[2] << std::endl;

        // Out of range access
        std::cout << "arr[10]: " << arr[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // ここまで実行できる 
    std::cout << "Hi" << std::endl;

    return 0;
}

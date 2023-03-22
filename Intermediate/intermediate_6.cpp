/*
演算子オーバーロードを使って、ベクトルの加算、減算、スカラー乗算を行う「Vector」クラスを作成してください。
また、そのクラスのインスタンス間での比較演算子をオーバーロードして、ベクトルの大きさに基づいて比較できるようにしてください。
*/

#include <iostream>
#include <cmath>

class Vector {
    public:
        Vector(double x, double y)
            : x(x), y(y) { }
        
        double norm() const {
            return sqrt(x*x + y*y); 
        }

        Vector operator+(const Vector& other) const {
            return Vector(x + other.x, y + other.y);
        }
        
        Vector operator-(const Vector& other) const {
            return Vector(x - other.x, y + other.y);
        }
        
        Vector operator*(double scalar) const {
            return Vector(x * scalar, y * scalar);
        }

        // 一個目のconstがメンバを更新しない,　二個目のconstが引数として受け取ったVectorを変更しない役割がある．
        // ノルムを計算する場合，constをつけないとother.norm()がシグネチャが合わず使えない． 
        bool operator<(const Vector& other) const {
            return norm() < other.norm();
        }
        
        bool operator>(const Vector& other) const {
            return norm() > other.norm();
        }
        
        bool operator==(const Vector& other) const {
            return norm() == other.norm();
        }
        
        bool operator>=(const Vector& other) const {
            return !(*this < other);
        }
        
        bool operator<=(const Vector& other) const {
            return !(*this > other);
        }
        
        bool operator!=(const Vector& other) const {
            return !(*this != other);
        }
        
    private:
        double x;
        double y;
};

int main (void) {
    Vector v1(3.0, 4.0);
    Vector v2(2.0, 6.0);
    Vector v3(3.0, 4.0);
    
    if (v1 > v2) {
        std::cout << "v1 > v2" << std::endl;
    } else {
        std::cout << "v1 < v2" << std::endl;
    }
    
    if (v1 == v3) {
        std::cout << "v1 == v3" << std::endl;
    } else {
        std::cout << "v1 != v3" << std::endl;
    }
    
    return 0; 
}

// chat gpt が作成．
#include <iostream>
#include <string>
#include <vector> // ベクター配列を使うためのインクルード

class Score {
private:
    std::string subject; // std::string型　
    int score;

public:
    // 省略した書き方
    Score(const std::string& subject, int score)
        : subject(subject), score(score) {}

    void display() const {
        std::cout << "Subject: " << subject << ", Score: " << score << std::endl;
    }
};

class Student {
private:
    std::string name;
    std::string student_id;
    std::vector<Score> scores; // ベクター配列．

public:
    Student(const std::string& name, const std::string& student_id) // ここでstring型が＆であるのは理由があるのか？
        : name(name), student_id(student_id) {}

    void addScore(const std::string& subject, int score) {
        scores.emplace_back(subject, score); // コンストラクタ引数を受け取る
        /*  回りくどいが，このようにして要素をそのまま渡すことができる．
            Score a(subject, score);
            scores.bush_back(a);
        */
    }

    // const メンバーの書き換えを禁止する修飾子
    void displayScores() const {
        std::cout << "Student Name: " << name << ", Student ID: " << student_id << std::endl;
        // 型推論でiteratorを呼び出している
        for (const auto& score : scores) {
            score.display();
        }
    }
};

int main() {
    Student student("John Doe", "123456");
    student.addScore("Math", 85);
    student.addScore("English", 90);
    student.addScore("Physics", 78);

    student.displayScores();

    return 0;
}
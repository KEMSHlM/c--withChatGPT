/*
ファイル入出力を使用して、テキストファイルを読み込み、内容を表示し、別のテキストファイルに書き込むプログラムを作成してください。
*/

#include <iostream>
#include <fstream>
#include <string>

int main (void) {
    std::string inFile = "./in.txt";
    std::string outFile = "./out.txt";

    std::ifstream ifs("./in.txt");
    std::ofstream ofs("./out.txt");
    std::string str;
    
    if (ifs.fail()) {
        std::cerr << "Failed to open " << inFile << std::endl;
        std::exit(1);
    }
    if (ofs.fail()) {
        std::cerr << "Failed to open " << outFile << std::endl;
        std::exit(1);
    }
    while (getline(ifs, str)) {
        ofs << str << std::endl;
    }

    return 0;
}
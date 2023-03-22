/*
マルチスレッドを使用して、1から指定された整数までの素数を計算するプログラムを作成してください。複数のスレッドを使用して計算を並列化し、処理を高速化してください。
以下はchatgptが作成したもの
*/

#include <iostream>
#include <vector>
#include <thread>   // threadで並列かすることができる．
#include <algorithm>
#include <mutex>
#include <cmath>

std::mutex mtx;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void find_primes(int start, int end, std::vector<int>& primes) {
    for (int n = start; n <= end; n++) {
        if (is_prime(n)) {
            std::unique_lock<std::mutex> lock(mtx);
            primes.push_back(n);
            lock.unlock();
        }
    }
}

int main() {
    int max_value = 10000;
    int num_threads = std::thread::hardware_concurrency();

    int range = max_value / num_threads;
    std::vector<std::thread> threads;
    std::vector<int> primes;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * range + 1;
        int end = (i + 1) * range;
        if (i == num_threads - 1) {
            end = max_value;
        }
        threads.push_back(std::thread(find_primes, start, end, std::ref(primes)));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::sort(primes.begin(), primes.end());

    std::cout << "Primes up to " << max_value << ":\n";
    for (const auto& prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
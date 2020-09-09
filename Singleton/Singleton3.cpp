//
// Created by nl on 2020/9/9.
//

#include <bits/stdc++.h>
using namespace std;

class Singleton3 {
public:
    static Singleton3& get_instance();
private:
    Singleton3() {cout << "constructor__" << endl; }
    ~Singleton3() {cout << "deconstructor__" << endl; }
    Singleton3(const Singleton3&) = delete;
    Singleton3& operator= (const Singleton3&) = delete;

};

// c++ 11 线程安全的单例模式
Singleton3& Singleton3::get_instance() {
    static Singleton3 instance;
    return instance;
}

void func(int tid) {
    cout << "线程id = "<< tid << endl;
    cout << &Singleton3::get_instance() << endl;
}
int main() {
    vector<thread> threads;
    for (int i = 0; i < 6; ++ i) {
        threads.push_back(thread(func, i));
    }

    for (auto& th : threads) th.join();
    return 0;
}
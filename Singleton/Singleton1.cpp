//
// Created by nl on 2020/9/8.
//

#include <bits/stdc++.h>
#include <thread>
using namespace std;
//01 普通懒汉式单例 （ 线程不安全 ）
class Singleton1 {
public:
    static shared_ptr<Singleton1> get_instance();
    void print();
    ~Singleton1();
private:
    Singleton1();

    Singleton1(const Singleton1&) = delete;
    Singleton1& operator=(const Singleton1&) = delete;

private:
    static shared_ptr<Singleton1> m_instance;
};

shared_ptr<Singleton1> Singleton1::m_instance = nullptr;

shared_ptr<Singleton1> Singleton1::get_instance() {
    if (m_instance == nullptr) {
        m_instance = shared_ptr<Singleton1>(new Singleton1);
    }
    return m_instance;
}

void Singleton1::print() {
    cout << "我的实例内存地址是:" << this << endl;
}

Singleton1::Singleton1()  {
    cout << "constructor " << endl;
}

Singleton1::~Singleton1() {
    cout << "deconstructor" << endl;
}

void f(int tid) {
    cout << "我是线程id = " << tid << endl;
    Singleton1::get_instance()->print();
}


int main() {
    constexpr int N = 6;
    vector<thread> threads;
    cout << "start**********" << endl;

    for (int i = 0; i < N; ++ i) {
        cout << "main ----" << i << endl;
        threads.push_back(thread(f, i));
    }
    for (auto& th : threads) th.join();

    cout << "end-------" << endl;
    return 0;
}
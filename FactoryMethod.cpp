//
// Created by nl on 2020/9/8.
//
// 学习连接：https://zhuanlan.zhihu.com/p/83535678
// 工厂方法模式
#include <bits/stdc++.h>
using namespace std;

// 鞋子的抽象类　稳定的
class Shoes {
public:
    virtual ~Shoes() = default;
    virtual void show() = 0;
};

class NiKeShoes : public Shoes {
public:
    void show() {
        cout << "NiKeShoes" << endl;
    }
};


class LiNingShoes : public Shoes {
public:
    void show() {
        cout << "LiNingShoes" << endl;
    }
};


// 总鞋厂 稳定的
class ShoesFactory
{
public:
    // 根据鞋子类型创建对应的鞋子对象
    // 修改
    virtual shared_ptr<Shoes> CreateShoes() = 0;
    virtual ~ShoesFactory() = default;
};

class NiKeShoesFactory : public ShoesFactory {
    shared_ptr<Shoes> CreateShoes() {
        return make_shared<NiKeShoes>();
    }
};

class LiNingShoesFactory : public ShoesFactory {
    shared_ptr<Shoes> CreateShoes() {
        return make_shared<LiNingShoes>();
    }
};

int main() {
    shared_ptr<ShoesFactory> shoesfactory = make_shared<NiKeShoesFactory>();

    auto p1 = shoesfactory->CreateShoes();
    if (p1) {
        p1->show();
    }
    shared_ptr<ShoesFactory> shoesfactory2 = make_shared<LiNingShoesFactory>();
    auto p2 = shoesfactory2->CreateShoes();
    if (p2) {
        p2->show();
    }
    return 0;
}
//
// Created by nl on 2020/9/8.
//

// 当增加一个新产品时，需要修改抽象工厂基类和具体工厂类，打破了开放封闭原则
#include <bits/stdc++.h>
using namespace std;

// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// 耐克衣服
class NiKeClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "NiKeClothe" << std::endl;
    }
};

// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "NiKeShoes" << std::endl;
    }
};

// 总厂
class Factory
{
public:
    // 当增加一个新产品时，需要修改，打破了开放封闭原则
    virtual shared_ptr<Shoes> CreateShoes() = 0;
    virtual shared_ptr<Clothe> CreateClothe() = 0;
    virtual ~Factory() {}
};

// 耐克生产者/生产链
// 当增加一个新产品时，需要修改，打破了开放封闭原则
class NiKeProducer : public Factory
{
public:
    shared_ptr<Shoes> CreateShoes()
    {
        return make_shared<NiKeShoes>();
    }

    shared_ptr<Clothe> CreateClothe()
    {
        return make_shared<NiKeClothe>();
    }
};
//
//int main() {
//    shared_ptr<Factory> factory = make_shared<NiKeProducer>();
//    shared_ptr<Shoes> shoes = factory->CreateShoes();
//    shared_ptr<Clothe> clothe = factory->CreateClothe();
//    shoes->Show();
//    clothe->Show();
//    return 0;
//}
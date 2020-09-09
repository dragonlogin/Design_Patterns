//
// Created by nl on 2020/9/8.
//
// https://zhuanlan.zhihu.com/p/83537599

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
    void Show() override
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
    void Show() override
    {
        std::cout << "NiKeShoes" << std::endl;
    }
};


/*
 * 新加一个类别
 * */

class Pen {
public:
    virtual void show() = 0;
    virtual ~Pen() = default;
};

class ConcretePen : public Pen {
public:
    void show() override {
        cout << "pen" << endl;
    }
};

// 现在是稳定的
// 工厂
template <class AbstractProduct_t>
class AbstractFactory
{
public:
    // 当增加一个新产品时，需要修改，打破了开放封闭原则
    virtual shared_ptr<AbstractProduct_t> Create() = 0;
    virtual ~AbstractFactory() {}
};

// 耐克生产者/生产链
// 当增加一个新产品时，需要修改，打破了开放封闭原则
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t>
{
public:
    shared_ptr<AbstractProduct_t> Create()
    {
        return make_shared<ConcreteProduct_t>();
    }

};

//int main() {
//    shared_ptr<AbstractFactory<Shoes>> factory = make_shared<ConcreteFactory<Shoes, NiKeShoes>>();
//    shared_ptr<AbstractFactory<Clothe>> fclothe = make_shared<ConcreteFactory<Clothe, NiKeClothe>>();
//
//    shared_ptr<Shoes> shoes = factory->Create();
//    shared_ptr<Clothe> clothe = fclothe->Create();
//    shoes->Show();
//    clothe->Show();
//
//    // 新加
//    shared_ptr<AbstractFactory<Pen>> fpen = make_shared<ConcreteFactory<Pen, ConcretePen>>();
//    shared_ptr<Pen> pen = fpen->Create();
//    pen->show();
//
//    return 0;
//}
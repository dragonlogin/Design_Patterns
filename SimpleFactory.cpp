//
// Created by nl on 2020/9/8.
//

#include <bits/stdc++.h>
using namespace std;

// 鞋子的抽象类
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


class AdidasShoes : public Shoes {
public:
    void show() {
        cout << "AdidasShoes" << endl;
    }
};

class LiNingShoes : public Shoes {
public:
    void show() {
        cout << "LiNingShoes" << endl;
    }
};

enum SHOES_TYPE {
    NIKE,
    LINING,
    ADIDAS
};

// 总鞋厂
class ShoesFactory
{
public:
    // 根据鞋子类型创建对应的鞋子对象
    shared_ptr<Shoes> CreateShoes(SHOES_TYPE type)
    {
        switch (type)
        {
            case NIKE:
                return make_shared<NiKeShoes>();
                break;
            case LINING:
                return make_shared<LiNingShoes>();
                break;
            case ADIDAS:
                return make_shared<AdidasShoes>();
                break;
            default:
                return NULL;
                break;
        }
    }
};

int main() {
    ShoesFactory shoesfactory;

    auto p1 = shoesfactory.CreateShoes(NIKE);
    if (p1) {
        p1->show();
    }
    return 0;
}
//
// Created by nl on 2020/9/8.
//

#include <bits/stdc++.h>
using namespace std;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

class ConcreteObserver1 : public Observer {
public:
    void update() {
        cout << "ConcreteObserver1__" << endl;
    }
};

class ConcreteObserver2 : public Observer {
public:
    void update() {
        cout << "ConcreteObserver2__" << endl;
    }
};

// 稳定的
class Subject {
protected:
    list<shared_ptr<Observer>> observers;
public:
    virtual ~Subject() = default;
    virtual void attach(shared_ptr<Observer>) = 0;
    virtual void detach(shared_ptr<Observer>) = 0;
    virtual void notify() = 0;
};
// 稳定的
class ConcreteSubject : public Subject {
public:
    void attach(shared_ptr<Observer> ob) {
        observers.push_back(ob);
    }

    void detach(shared_ptr<Observer> ob) {
        for (auto it = observers.begin(); it != observers.end();) {
            if (*it == ob) {
                observers.erase(it++);
            } else {
                ++it;
            }
        }
    }

    void notify() {
        for (auto it = observers.begin(); it != observers.end(); ++ it) {
            (*it)->update();
        }
    }
};

int main() {
    shared_ptr<Observer> ob1 = make_shared<ConcreteObserver1>();
    shared_ptr<Observer> ob2 = make_shared<ConcreteObserver2>();

    shared_ptr<Subject> sub = make_shared<ConcreteSubject>();
    sub->attach(ob1);
    sub->attach(ob2);
    sub->notify();
    sub->detach(ob1);
    sub->notify();
    return 0;
}
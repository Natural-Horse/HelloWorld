#include<bits/stdc++.h>
#include<iostream>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int m, s;
char c;

struct A;
struct B;

struct A {
    std::shared_ptr<B> pointer;
    ~A() {
        std::cout << "A 被销毁" << std::endl;
    }
};
struct B {
    std::shared_ptr<A> pointer;
    ~B() {
        std::cout << "B 被销毁" << std::endl;
    }
}; 

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->pointer = b;
    // b->pointer = a;
    printf("a : %d\n", a.use_count());
    printf("b : %d\n", b.use_count());
    return 0;
}
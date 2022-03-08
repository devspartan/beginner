#include <bits/stdc++.h>

using namespace std;

class B;
class A {
  private:
    int a;
    int b;
    void printInPvt() { cout << "Pr int in a's pvt"; }

  public:
    A();
    A(int x, int y) {
        a = x;
        b = y;
    };

    void showData() { cout << "A : " << a << " " << b << endl; }
    int getSum() { return a + b; }

    friend int sumAB(A, B);

    void helloB(B);
};

class B {
  private:
    int m;
    int n;

  public:
    B();
    B(int x, int y) {
        m = x;
        n = y;
    };

    friend class A;
    void showData() { cout << "B : " << m << " " << n << endl; }
    friend int sumAB(A a, B b) { return a.a + a.b + b.m + b.n; }

    void helloA(A hr) { cout << " Hello a "; }
};

void A::helloB(B qw) { cout << "Pvt of b: " << qw.m << " " << qw.n << endl; }

// int sumAB(A a, B b){
//     return a.a + a.b + b.m + b.n;
// }

int main() {

    A num1(3, 4);
    B num2(1, 2);

    num1.helloB(num2);
    num1.showData();
    num2.showData();
    cout << sumAB(num1, num2) << endl;
}

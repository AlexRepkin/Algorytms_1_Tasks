#include <iostream>
using  std::cin;
using  std::cout;

int G(int n);

int F(int n) {
    if (n > 1) return (F(n - 1) - G(n - 1));
    return 1;
}

int G(int n) {
    if (n > 1) return (F(n - 1) + G(n - 1));
    return 1;
}

int main(){
    cout << "Answer for Task number 16 is " << F(5)/G(5);
}
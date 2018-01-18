#include<iostream>
using namespace std;

class fib{
    int fibn;
public:
    fib( int);
    int fibonacci(int );
};

fib::fib( int fibn){
    this->fibn = 0;
}
int fib::fibonacci(int n){
    if(n<=2){
        return 1;
    }
    return(fibonacci(n)+fibonacci(n-1));
}

int main(void){
    fib f(0);
    cout<< "The f of n is "<<f.fibonacci(6);
    return 0;
}
#include <iostream>
#include <windows.h>

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    using std::cout;
    using std::cin;
    int n;
    cout<<"Сколько чисел Фибоначчи? ";
    cin>>n;
    if (n<=0){
        cout<<"Число должно быть натуральным.";
        return -1;
    }
    int x = 0;
    int b = 1;
    cout<< 0<<" ";
    for(n; n>1; n-- ){
        x = x + b;
        b = x - b;
        cout<<x<<" ";
    }
    return 0;
}
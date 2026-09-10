#include <iostream>
#include <windows.h>
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    using std::cout;
    using std::cin;
    int N;
    cout<<"Сколько первых нечетных чисел сложить? ";
    cin>>N;
    if (N<0){
        cout<<"Число должно быть положительным.";
        return -1;
    }
    int x = N*N;
    cout<<"Сумма первых "<< N<< " нечетных чисел равна " << x; 
    return 0;
}
#include <iostream>
#include <windows.h>

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    using std::cout;
    using std::cin;
    int a, b, d;
    bool f = false;
    cout<<"Введите первый член прогрессии a, конец отрезка b, разность прогрессии d ";
    cin>> a >> b >> d;
    if((b < a)){
        cout<<"b должно быть больше a.";
        return -1;
    }
    
    
    cout<<"Члены данной прогрессии на этом отрезке, которые кратны 3:"<< std::endl;

    if(d<=0){
        if(a%3 == 0){
            cout<<a;
        }
        else{
            cout<<"Нет подходящих членов";
            }
        return 0;
        
    }

    for(a; a <= b; a=a+d){
        if(a % 3 == 0){
            cout<<a<<" ";
            f = true;
        }
    }
    if (f == false){
        cout<<"Нет подходящих членов";
    }
    return 0;
}
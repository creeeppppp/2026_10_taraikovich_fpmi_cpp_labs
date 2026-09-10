#include <iostream>
#include<windows.h>
int main(){
    using std::cout;
    using std::cin;
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, k, counter = 0;
    cout<<"Введите с какого дня n начинается неделя и количество дней k в месяце. ";
    cin>>n>>k;
    if(((n<0)||(n>7))||((k<0)||(k>99))){
        cout<<"Число дней n должно быть больше нуля и не больше 7 или количество дней k должно быть больше 0 и не больше 99. ";
        return -1;
    }
    for(n; n>1; n--){
        cout<<"   ";
        counter++;
    }
    for(int i=1; i<=k; ++i){
        if(counter<7){
            if(i<10){
                cout<<" "<<i<<" ";
                counter++;
            }
            else{
                cout<<i<<" ";
                counter++;
            }
        }
        else{
            counter = 0;
            cout<<"\n";
            i = i-1;
        }
        
    }
    return 0;
}
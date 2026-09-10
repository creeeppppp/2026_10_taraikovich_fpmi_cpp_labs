#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    using std::cout;
    using std::cin;
    cout << "Введите шестизначное натуральное число" << std::endl;
    int n;
    cin >> n;

    if ((n < 100000) || (n > 999999)){
        cout << "Число должно быть шестизначным натуральным.";
        return -1;
    }

    int first = n % 10; 
    int sec = (n/10) % 10;
    int third = (n/100) % 10;
    int four = (n/1000) % 10;
    int five = (n/10000) % 10;
    int six = (n/100000) % 10;


    if((first + sec + third) == (four + five + six)){
        cout << "Число счастливое";
    } else {
        cout << "Число несчастливое";
    }

    return 0;
}
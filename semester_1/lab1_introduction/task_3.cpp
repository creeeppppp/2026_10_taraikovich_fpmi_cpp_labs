#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    using std::cout;
    using std::cin;
    cout << "Введите четырехзначное натуральное число" << std::endl;
    int n;
    cin >> n;

    if ((n < 1000) || (n > 9999)){
        cout << "Число должно быть четырехзначным натуральным.";
        return -1;
    }

    int first = n % 10; 
    int sec = (n/10) % 10;
    int third = (n/100) % 10;
    int four = (n/1000) % 10;

    if((first == four) && (sec == third)){
        cout << "Палиндром";
    } else {
        cout << "Не палиндром";
    }

    return 0;
}
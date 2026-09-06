#include <iostream>

int main() {
    using std::cout;
    using std::cin;
    int n;
    cin >> n;
    int first = n % 10; 
    int sec = (n/10) % 10;
    int third = (n/100) % 10;
    int four = (n/1000) % 10;
    if((first == four) && (sec == third)){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
#include <iostream>

int main(){
    using std::cout;
    using std::cin;
    setlocale(LC_ALL, ".65001");
    int n, m, k = 1, a = 0, b = 0, c = 0, j = 2;
    cout<<"Введите до какого натурального n будут пифагоровы тройки. ";
    cin>>n;
    if(n<=0){
        cout<<"Число должно быть натуральным.";
        return -1;
    }
    while(true){
        m = k+1;
        if(m*m + k*k > n){
            break;
        }
        while(true){
            a = m*m - k*k;
            b = 2*k*m;
            c = m*m + k*k;
            if(c>n){
                break;
            }

            int tm = m, tk = k;
                while(tk != 0){
                    int temp = tk;
                    tk = tm % tk;
                    tm = temp;
                }
            if((tm == 1) && ((m-k)%2 != 0)){
                cout<<"("<<a<<", "<<b<<", "<<c<<")"<<std::endl;
                while((c*j)<=n){
                cout<<"("<<a*j<<", "<<b*j<<", "<<c*j<<")"<<std::endl;
                j++;
                }
            }
            j = 2;
            m++;

        }  
        k++; 
    }
}
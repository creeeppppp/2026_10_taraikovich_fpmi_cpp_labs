#include<iostream>
#include<cmath>
#include<iomanip>

int main(){
    using std::cin;
    using std::cout; 
    int n, k=1;
    double x;
    cin>>n>>x;
    double a_k = -1 * x * x * 0.5;
    double sum = 1;
    while(std::fabs(a_k)>=std::pow(10, -n)){
    k++;
    sum +=  a_k;
    a_k =  a_k * (-1 * x * x / ((2*k)*(2*k-1)));
    }
    cout<<std:: setprecision(n)<<"Result "<<sum<<"\n";
    cout<<std:: setprecision(n)<<std::cos(x);



}
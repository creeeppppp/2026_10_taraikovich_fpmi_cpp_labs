#include<iostream>
#include<cmath>
#include<iomanip>
#include<windows.h>

int main(){
using std::cin;
using std::cout; 
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
int n;
 double x;
 int k  =1;
 cout<<"Введите n,x";
 cin>>n>>x;
 if((x>0.25)||(x<-0.25)){
    cout<<"x вне промежутка";
    return -1;
 }
 double a_k = 2*x;
 double sum=1;

 while(std::fabs(a_k)>=std::pow(10, -n)){
    sum +=  a_k;
    a_k =  a_k *((-2*x)*(2*k-1))/(k+1);
    k++;
    //cout<<a_k;
    
 }

cout<<std:: setprecision(n)<<"Результат "<<sum<<"\n";
cout<<std:: setprecision(n)<<std::pow(1+4*x, 0.5);
 



}
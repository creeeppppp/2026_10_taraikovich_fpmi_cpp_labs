#include <iostream>

int main(){
    int n, m, i;
    
    using std::cout;
    using std::cin;
    cout <<"Enter two positive numbers m and n"<<std::endl;
    cin >>n>>m;
   
    if((m<=0)||(n<=0)){
        cout<<"Numbers must be positive"<<std::endl;
        return -1;
    }
    int min = std::min(m, n);
    cout<<"Common dividers:"<<"\n";
    for(i=1; i<=min; i++){
        if((m%i==0)&&(n%i==0)){
            cout<<i<< ' ';
        }
    }
    
}

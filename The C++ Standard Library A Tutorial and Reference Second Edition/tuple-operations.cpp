// p.97
#include<iostream>
#include<tuple>
#include<complex>
#include<string>

using namespace std;

int main(){
    // create a 4-element tuple. Elements has default value : 0
    tuple<string,int,int,complex<double>> t;
    
    tuple<int,float,string> t1(41,6.3,"dung");
    
    cout<<get<0>(t1)<<" ";
    cout<<get<1>(t1)<<" ";
    cout<<get<2>(t1)<<" ";
    cout<<endl;
    
    // create tuple with make_tuple()
    auto t2 = make_tuple(22,44,"dung");
    get<1>(t1) = get<1>(t2);
    
    return 0;
}

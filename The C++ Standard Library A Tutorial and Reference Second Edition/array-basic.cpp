// p.201
#include<iostream>
#include<string>
#include<array>

using namespace std;

int main(){
    array<string,5> coll = {"ho","anh","dung"}; // array containers of 5 string eles
    for(int i=0;i<coll.size();i++)
        cout<<i<<" : "<<coll[i]<<endl;
    return 0;
}

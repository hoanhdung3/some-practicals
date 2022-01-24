// p.45
#include<iostream>
#include<initializer_list>

void print(std::initializer_list<int> vals){
    for(std::initializer_list<int>::iterator i = vals.begin(); i != vals.end(); i++){
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";
}

int main(){
    print({1,2,3,4,5});
    return 0;
}

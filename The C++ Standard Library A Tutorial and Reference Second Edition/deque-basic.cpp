// p.199
#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<float> coll;
    for(int i=1;i<=6;i++){
        coll.push_front(i*1.1); // insert at the front
    }
    for(auto i : coll) cout<<i<<" ";
    cout<<endl;
    return 0;
}

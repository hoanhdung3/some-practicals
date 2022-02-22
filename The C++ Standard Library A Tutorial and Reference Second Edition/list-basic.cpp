// p.203
#include <iostream>
#include<list>
using namespace std;

int main()
{
    list<char> coll; // list is not kind of random access so use [] is bad
    for(char i='a';i<='z';i++){
        coll.push_back(i);
    }
    
    while(!coll.empty()){
        cout << coll.front() <<' ';
        coll.pop_front();
    }
    cout<<endl;
    return 0;
}

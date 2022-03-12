// p.471
#include<iostream>
#include<iterator>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    // The function advance() increments the position of an iterator passed as the argument.
    // Thus, thefunction lets the iterator step forward(or backward)more than one element
    
    list<int> coll;
    for(int i=1;i<=9;i++) coll.push_back(i);
    
    list<int>::iterator pos = coll.begin();
    
    cout<<*pos<<endl;
    
    advance(pos,3);
    cout<<*pos<<endl;
    advance(pos,-1);
    cout<<*pos<<endl;
    return 0;
}

// p.205
#include <iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<long> coll = {2,3,5,7,11,13,17};
    //resize two times
    coll.resize(9); // change num of elems
    coll.resize(10,99);
    // If the size grows,you can pass an additional parameter to specify the value of the new elements
    // Otherwise,the default value(zero for fundamental types)is used.
    for(auto i : coll) cout<<i<<" ";
    return 0;
}
// A forward_list<>is implemented as a singly linked-list of element
// As a consequence, a forward-list is in principle just a limited list, where all operations that move backward or that would cause a performance penalty are not supported.For this reason, member functions such as push_back() and even size()are not provide
// can’t search for an element and then delete(because hve to be at the position of the preceding element) it or insert another element in front of it.

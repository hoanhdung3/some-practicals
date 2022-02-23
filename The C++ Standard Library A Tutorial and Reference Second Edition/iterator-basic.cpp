// p.218
#include <iostream>
#include<list>
using namespace std;

// begin(): points to first elem
// end(): points to behind the last elem
int main()
{
    list<char> coll;
    for(char i='a';i<='z';++i){
        coll.push_back(i);
    }
    
    //const_iterator is provided to iterate over elements in read-only mode.
    list<char>::const_iterator pos;
    // use ++pos becauses have better performance than pos++
    // The latter internally involves a temporary object because it must return the old position of the iterator.
    for(pos = coll.begin();pos != coll.end(); ++pos){
        cout<<*pos<<" ";
    }
    cout<<endl;
    
    list<char>::iterator pos2;
    for(pos2 = coll.begin();pos2 != coll.end(); ++pos2){
        *pos2 = toupper(*pos2);
        cout<<*pos2<<" ";
    }
    cout<<endl;
    return 0;
}
// use cbegin() and cend() for type const_iterator

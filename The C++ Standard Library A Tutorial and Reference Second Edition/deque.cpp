// p.317
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<iterator>
using namespace std;

void PRINT_ELEMENT(deque<string> a){
    copy(a.cbegin(), a.cend(), ostream_iterator<string>(cout," "));
    cout<<endl;
}

int main()
{
    deque<string> coll;
    
    coll.assign(3,string("string"));
    coll.push_back("last string");
    coll.push_front("first string");
    
    PRINT_ELEMENT(coll);
    
    coll.pop_front();
    coll.pop_back();
    
    // insert "another" into every elem but the first
    for(unsigned i=1;i<coll.size();++i)
        coll[i] = "another" + coll[i];
    
    // change size to 4 elems
    coll.resize(4,"resized string");
    PRINT_ELEMENT(coll);
    return 0;
}

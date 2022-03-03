// p.247
#include<iostream>
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;

int main()
{
    list<int> coll;
    for(int i=1;i<=6;++i){
        coll.push_back(i);
        coll.push_front(i);
    }
    
    cout<<"pre: ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
    
    // <1>
    // remove(coll.begin(), coll.end(), 3); // remove all elems with value 3
    
    // cout<<"post: ";
    // copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout," "));
    // cout<<endl;
    
    // pre: 6 5 4 3 2 1 1 2 3 4 5 6 
    // post: 6 5 4 2 1 1 2 4 5 6 5 6 
    
    // </1>
    
    // <2>
    list<int>::iterator end = remove(coll.begin(), coll.end(), 3);
    
    copy(coll.begin(), end, ostream_iterator<int>(cout," "));
    cout<<endl;
    
    cout<<"number of removed elements: "<<distance(end, coll.end())<<endl;
    
    coll.erase(end,coll.end());
    
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
    
    // </2>
    return 0;
}
// remove() did not change the number of elems in the collection.

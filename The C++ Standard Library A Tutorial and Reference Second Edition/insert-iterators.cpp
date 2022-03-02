// p.241
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<deque>
#include<list>
#include<set>
using namespace std;

int main()
{
    list<int> coll1 = {1,2,3,4,5,6,7,8,9};
    
    // copy the elems of coll1 into coll2 by appending them
    vector<int> coll2;
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
    
    //copy the elems of coll1 into coll3 by inserting them at the front_inserter
    // reverse the order of the elems
    deque<int> coll3;
    copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));
    
    // only inserter that works for associative collections
    set<int> coll4;
    copy(coll1.cbegin(), coll1.cend(), inserter(coll4,coll4.begin()));
    
    for(auto i: coll4) cout<<i<<" "; cout<<endl;
    return 0;
}
// Insert iterators, or inserters, are used to let algorithms operate in insert mode rather than in overwrite mode.
// In particular, inserters solve the problem of algorithms that write to a destination that does not have enough room:They let the destination grow accordingly.

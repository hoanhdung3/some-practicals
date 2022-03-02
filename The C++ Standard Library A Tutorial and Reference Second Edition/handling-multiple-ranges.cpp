// p.238
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<list>
using namespace std;

int main()
{
    list<int> coll1 = {1,2,3,4,5,6,7,8,9};
    vector<int> coll2;
    
    // resize destination to have enough room for the overwriting algorithm
    coll2.resize(coll1.size());
    
    // copy elems from first into coll2
    // overwrites existing elems in destination
    copy(coll1.cbegin(), coll1.cend(), coll2.begin());
    
    deque<int> coll3(coll1.size());
    
    copy(coll1.cbegin(), coll1.cend(), coll3.begin());
    return 0;
}

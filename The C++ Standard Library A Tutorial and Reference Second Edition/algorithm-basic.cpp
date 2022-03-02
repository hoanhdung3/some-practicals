// p.229
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> coll = {2,5,4,1,6,3};
    
    auto minpos = min_element(coll.cbegin(), coll.cend());
    cout<<"min: "<<*minpos<<endl;
    auto maxpos = max_element(coll.cbegin(), coll.cend());
    cout<<"max: "<<*maxpos<<endl;
    
    sort(coll.begin(), coll.end());
    
    auto pos3 = find(coll.begin(), coll.end(), 3); 
    // if true: return the position
    // if false: return the end of range
    // not use cbegin/cend because later modify the elements pos3 refers to
    
    reverse(pos3,coll.end());
    // reverse the order of the found ele with value 3 and all following elements
    
    for(auto i : coll) cout<<i<<" ";
    cout<<endl;
    return 0;
}

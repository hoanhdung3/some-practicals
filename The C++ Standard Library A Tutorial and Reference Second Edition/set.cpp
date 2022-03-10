// p.3
#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;


int main()
{
    set<int> c;
    c.insert({1,2,4,5,6});
    
    cout<<"lower_bound(3): "<< *c.lower_bound(3)<<endl;
    cout<<"upper_bound(3): "<< *c.upper_bound(3)<<endl;
    cout<<"euqal_range(3): "<< *c.equal_range(3).first<<" "<<*c.equal_range(3).second<<"\n"<<endl;
    
    cout<<"lower_bound(5): "<< *c.lower_bound(5)<<endl;
    cout<<"upper_bound(5): "<< *c.upper_bound(5)<<endl;
    cout<<"euqal_range(5): "<< *c.equal_range(5).first<<" "<<*c.equal_range(5).second<<endl;
    
    /////////////////////////////////////////////////////////////////////////////////////////
    set<int,greater<int>> coll1;
    coll1.insert({4,3,5,1,6,2});
    coll1.insert(5);
    copy(coll1.cbegin(), coll1.cend(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    
    auto status = coll1.insert(4);
    if(status.second)
        cout<<"4 inserted as elem "<<distance(coll1.begin(), status.first) + 1 <<endl;
    else
        cout<<"4 already exists"<<endl;
    
    set<int> coll2(coll1.cbegin(), coll1.cend());
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    
    coll2.erase(coll2.begin(), coll2.find(3));
    
    int num;
    num = coll2.erase(5);
    cout<<num<<" element(s) removed"<<endl;
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}

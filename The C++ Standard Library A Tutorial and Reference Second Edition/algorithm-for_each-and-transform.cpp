// p.253
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iterator>

using namespace std;

void print(int x){
    cout<<x<<" ";
}

int square(int x){
    return x*x;
}

int main()
{
    set<int> coll1;
    vector<int> coll,coll2;
    for(int i=1;i<=9;i++){
        coll1.insert(i);
        coll.push_back(i);
    }
    
    for_each(coll.cbegin(), coll.cend(), print);
    cout<<endl;
    
    cout<<"initialized: ";
    copy(coll1.cbegin(),coll1.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
    
    transform(coll1.cbegin(),coll1.cend(), // source
                back_inserter(coll2),  // destination
                square);  // operation
    
    cout<<"squared: ";
    copy(coll2.cbegin(),coll2.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
    return 0;
}

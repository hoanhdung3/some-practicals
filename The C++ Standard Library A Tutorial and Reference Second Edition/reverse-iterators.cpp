// p.242
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> coll;
    
    for(int i=1;i<=9;++i){
        coll.push_back(i);
    }
    
    // crbegin/crend: read-only reverse iterator for coll
    copy(coll.crbegin(), coll.crend(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}

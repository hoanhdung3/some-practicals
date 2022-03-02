// p.242
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
    vector<string> coll;
    
    // read all words fromthe standard innput
    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(coll));
    // istream_iterator<string>(cin): creates a stream iterator that reads from the standard input stream cin
    // istream_iterator<string>(): creates a so-called end-of-stream iterator
    
    sort(coll.begin(),coll.end());
    
    // print all elems without duplicates
    unique_copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
    return 0;
}

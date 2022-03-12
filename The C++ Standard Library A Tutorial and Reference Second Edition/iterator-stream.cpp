// p.490
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    ostream_iterator<int> intWriter(cout,"\n");
    
    *intWriter = 42;
    intWriter++;
    *intWriter = 77;
    intWriter++;
    *intWriter = -5;
    
    vector<int> coll = {1,2,3,4,5,6,7,8,9};
    
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout," < "));
    cout<<endl;
    
    // istream_iterator<int> intReader(cin);
    // istream_iterator<int> intReaderEOF;
    
    // while(intReader != intReaderEOF){
    //     cout<<"once:        "<<*intReader<<endl;
    //     cout<<"once again:  "<<*intReader<<endl;
    //     ++intReader;
    // }
    
    // <-- STREAM ITERATORS AND advance() -->
    
    istream_iterator<string> cinPos(cin);
    ostream_iterator<string> coutPos(cout," ");
    
    while(cinPos != istream_iterator<string>()){
        // ignore the following two strings
        advance(cinPos,2);
        
        // read and write the third string
        if(cinPos != istream_iterator<string>())
            *coutPos++ = *cinPos++;
        cout<<endl;
    }
    return 0;
}

// p.597
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<iterator>
#include<cstdlib>
#include<array>
#include<numeric>

using namespace std;

template<typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last){
    for(int i = first; i <= last; ++i)
        coll.insert(coll.end(), i);
}

template<typename T>
inline void PRINT_ELEMENTS(const T& coll, const string& optcstr=""){
    cout<<optcstr;
    for(auto elem : coll)
        cout<<elem<<" ";
    cout<<endl;
}

template<typename T>
inline void PRINT_MAPPED_ELEMENTS(const T& coll, const string& optcstr=""){
    cout<<optcstr;
    for(auto elem : coll)
        cout<<'['<<elem.first<<','<<"] ";
    cout<<endl;
}
using namespace std;

int main()
{
    // <-- ASSIGNING NEW VALUES -->
        // print ten times 7.7
    fill_n(ostream_iterator<float>(cout," "), 10, 7.7); // beginning of destination, count, new value
    cout<<endl;
    
    list<string> coll;
    fill_n(back_inserter(coll), 9, "hello");
    PRINT_ELEMENTS(coll,"coll:  ");
    
        // overwrite all elems with "again"
    fill(coll.begin(), coll.end(), "again");
    PRINT_ELEMENTS(coll, "coll: ");
    
        // replace all but 2 elems with "hi"
    fill_n(coll.begin(), coll.size()-2, "hi");
    PRINT_ELEMENTS(coll,"coll:  ");
    
        // replace the 2nd and up to the last elem but 1 with "hmmm"
    list<string>::iterator pos1, pos2;
    pos1 = coll.begin();
    pos2 = coll.end();
    fill(++pos1, --pos2, "hmmm");
    PRINT_ELEMENTS(coll,"coll:  ");
    
    // <-- ASSIGNING GENERATED VALUES -->
    list<int> l;
        // insert 5 random numbers
    generate_n(back_inserter(l), 5, rand);
    PRINT_ELEMENTS(l);
        
        // overwrite with 5 new random numbers
    generate(l.begin(), l.end(), rand);
    PRINT_ELEMENTS(l);
    
    // <-- ASSIGNING SEQUENCE OF INCREMENTS VALUES -->
    array<int,10> a;
    iota(a.begin(), a.end(), 42);
    PRINT_ELEMENTS(a,"a:    ");
    return 0;
}

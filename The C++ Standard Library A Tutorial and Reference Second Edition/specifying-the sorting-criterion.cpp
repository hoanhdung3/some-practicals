// p.357
#include<iostream>
#include<set>
#include<iterator>
#include<string>
using namespace std;

class RuntimeCmp{
    public:
        enum cmp_mode{normal, reverse};
    private:
        cmp_mode mode;
    public:
        // constructor for sorting criterion
        // default criterion uses value normal
        RuntimeCmp(cmp_mode m=normal) : mode(m){
        }
        // comparison of elems
        // member func for any elem type
        template<typename T>
        bool operator() (const T& t1, const T& t2) const{
            return mode==normal ? t1<t2 : t2<t1;
        }
        // comparison of sorting criteria
        bool operator== (const RuntimeCmp& rc) const{
            return mode == rc.mode;
        }
};

// type of a set that uses this sorting criterion
typedef set<int, RuntimeCmp> IntSet;

void PRINT_ELEMENTS(IntSet s, string a){
    cout<<a;
    copy(s.begin(), s.end(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    // create, fill, and print set with normal elem order
    //uses default sorting criterion
    IntSet coll1 = {4,7,5,1,6,2,5};
    PRINT_ELEMENTS(coll1, "coll1: ");
    
    // create sorting criterion with reverse elem order
    RuntimeCmp reverse_order(RuntimeCmp::reverse);
    
    // create, fill and print set with reverse elem order
    IntSet coll2(reverse_order);
    coll2 = {4,7,5,1,6,2,5};
    PRINT_ELEMENTS(coll2, "coll2: ");
    
    // assign elems AND sorting criterion
    coll1 = coll2;
    coll1.insert(3);
    PRINT_ELEMENTS(coll1, "coll1: ");
    
    if(coll1.value_comp() == coll2.value_comp())
        cout<<"coll1 and coll2 have same sorting criterion"<<endl;
    else
        cout<<"coll1 and coll2 have different sorting criterion"<<endl;
    return 0;
}

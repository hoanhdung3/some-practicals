// p.507
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;

class IntSequence{
    private:
        int value;
    public:
        IntSequence(int initialValue) : value(initialValue) {} // constructor
        int operator()(){  // func call
            return ++value;
        }
};

void PRINT_ELEMENTS(list<int> c){
    copy(c.cbegin(), c.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    list<int> coll;
    
    // insert values from 1 to 9
    generate_n(back_inserter(coll), // start
                9,  // number of elems
                IntSequence(1)); // generates values, start with 1
    PRINT_ELEMENTS(coll);
    
    // replace 2nd to last elem but one with values starting at 42
    generate(next(coll.begin()), // start
                prev(coll.end()),  // end
                IntSequence(42)); // generates values, start with 42
    PRINT_ELEMENTS(coll);
    
    coll.clear();
    
    IntSequence seq(1); // integral sequence starting with 1
    
    // insert values from 1 to 4
    // -pass func obj by reference
    // so that it will continue  with 5
    generate_n<back_insert_iterator<list<int>>, int, IntSequence&>(back_inserter(coll), // start
                                                                    4, // num of elems
                                                                    seq); // generates values
    PRINT_ELEMENTS(coll);
    
    // insert values from 42 to 45
    generate_n(back_inserter(coll), 4, IntSequence(42));
    PRINT_ELEMENTS(coll);
    
    // continue with first sequence
    // -pass func obj by value
    // so that it will continue with 5 again
    generate_n(back_inserter(coll), 4, seq);
    PRINT_ELEMENTS(coll);
    
    // continue with first sequence again
    generate_n(back_inserter(coll), 4, seq);
    PRINT_ELEMENTS(coll);
    return 0;
}

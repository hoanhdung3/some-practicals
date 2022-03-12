// p.500
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

template<typename Container>

class asso_insert_iterator : public iterator<output_iterator_tag, typename Container::value_type>{
    protected:
        Container& container; // container in which elems are inserted
    public:
        // constructor
        explicit asso_insert_iterator(Container& c) : container(c){}
        
        // assignment operator
        // -insert a value into the container
        asso_insert_iterator<Container>& operator= (const typename Container::value_type& value){
            container.insert(value);
            return *this;
        }
        
        // dereferenting is a no-op that returns the iterator itself
        asso_insert_iterator<Container>& operator* () {
            return *this;
        }
        
        // increment operation is a no-op that returns the iterator itself
        asso_insert_iterator<Container>& operator++ () {
            return *this;
        }
        asso_insert_iterator<Container>& operator++ (int) {
            return *this;
        }
};

// convenience func to create the inserter
template<typename Container>
inline asso_insert_iterator<Container> asso_inserter(Container& c){
    return asso_insert_iterator<Container>(c);
}

void PRINT_ELEMENTS(unordered_set<int> s){
    copy(s.cbegin(), s.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    unordered_set<int> coll;
    
    // create inserter fpr coll
    // -inconvenient way
    asso_insert_iterator<decltype(coll)> iter(coll);
    
    // insert elems with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;
    
    PRINT_ELEMENTS(coll);
    
    // use inserter for coll and insert elems
    // -convenient way
    asso_inserter(coll) = 44;
    asso_inserter(coll) = 5;
    
    PRINT_ELEMENTS(coll);
    
    // use inserter with an algorithm
    vector<int> vals = {33,67,-4,13,5,2};
    copy(vals.begin(), vals.end(), asso_inserter(coll));
    PRINT_ELEMENTS(coll);
    return 0;
}

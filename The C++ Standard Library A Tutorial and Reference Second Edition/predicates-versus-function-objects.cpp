// p.513
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

class Nth{  // func obj that returns true for the nth call
    private:
        int nth; // call for which to return true 
        int count; // call counter
    public:
        Nth(int n) : nth(n), count(0) {}
        bool operator() (int){
            return ++count == nth;
        }
};

void PRINT_ELEMENTS(list<int> c, string a){
    cout<<a;
    copy(c.cbegin(), c.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    // Predicates are functions or functio nobjects that return a Boolean value
    
    list<int> coll = {1,2,3,4,5,6,7,8,9,10};
    PRINT_ELEMENTS(coll,"coll:      ");
    
    // remove 3rd elem 
    list<int>::iterator pos;
    pos = remove_if(coll.begin(), coll.end(), Nth(3));
    coll.erase(pos,coll.end());
    PRINT_ELEMENTS(coll,"3rd removed: ");
    return 0;
}

// p.380
#include<iostream>
#include<map>
#include<iterator>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

// func object to compare strings
// -allows u to set the comparison criterion runtime
// -allows u to compare case insensitive
class RuntimeStringCmp{
    public:
        // constants for the comparison criterion
        enum cmp_mode {normal, nocase};
    private:
        // actual comparison mode
        const cmp_mode mode;
        
        // auxiliary func to compare case insensitive
        static bool nocase_compare(char c1, char c2){
            return toupper(c1) < toupper(c2);
        }
    public:
        // constructor: initializes the comparison criterion
        RuntimeStringCmp(cmp_mode m=normal) : mode(m){
        }
        
        // the comparison
        bool operator()(const string& s1, const string& s2) const{
            if(mode==normal)
                return s1<s2;
            else
                return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
        }
};

typedef map<string,string,RuntimeStringCmp> StringStringMap;

//func that fills and prints such containers
void fillAndPrint(StringStringMap& coll);

int main(){
    StringStringMap coll1;
    fillAndPrint(coll1);
    
    // create a container with the default comparison criterion
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
    
    // create a container with the case-insensitive comparisons
    StringStringMap coll2(ignorecase);
    fillAndPrint(coll2);
    
    // coll1 uses the default function object of type RuntimeStringCmp, 
    // which compares the elements by using operator <.
    // coll2 uses a function object of type RuntimeStringCmp, 
    // which is initialized by value nocas eof class RuntimeStringCmp.
    // nocase forces this function object to sort strings in a case-insensitive way.
    return 0;
}

void fillAndPrint(StringStringMap& coll){
    coll["Deutschland"]= "Germany";
    coll["deutsch"]= "German";
    coll["Haken"]= "snag";
    coll["arbeiten"]= "work";
    coll["Hund"]= "dog";
    coll["gehen"]= "go";
    coll["Unternehmen"]= "enterprise";
    coll["unternehmen"]= "undertake";
    coll["gehen"]= "walk";
    coll["Bestatter"]= "undertaker";
    
    cout.setf(ios::left, ios::adjustfield);
    for(const auto& elem : coll)
        cout<<setw(15)<<elem.first<<" "<<elem.second<<endl;
    cout<<endl;
}

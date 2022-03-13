// p.519
#include<iostream>
#include<functional>
#include<algorithm>
#include<locale>
#include<string>
#include<vector>

using namespace std;

char myToupper(char c){
    std::locale loc;
    return std::use_facet<std::ctype<char> >(loc).toupper(c);
}

class Person{
    private:
        string name;
    public:
        Person(const string& n) : name(n) {}
        
        void print() const{
            cout<<name<<endl;
        }
        
        void print2(const string& prefix) const{
            cout<<prefix<<name<<endl;
        }
};

int main()
{
    // <-- CALLING GLOBAL FUNCTIONS -->
    string s("Internationalization");
    string sub("Nation");
    
    // search substring case insensitive
    string::iterator pos;
    pos = search(s.begin(), s.end(), sub.begin(), sub.end(), bind(equal_to<char>(), bind(myToupper,placeholders::_1), bind(myToupper, placeholders::_2)));
    
    if(pos != s.end())
        cout<<"\""<<sub<<"\" is part of \""<<s<<"\""<<endl; 
        
    // <-- CALLING MEMBER FUNCTIONS -->
    vector<Person> coll = {Person("Tick"), Person("Trick"), Person("Track") };
    
    // call member func print() for each Person
    for_each(coll.begin(), coll.end(), bind(&Person::print, placeholders::_1));
    cout<<endl;
    
    // call member func print2() with additional argument for each Person
    for_each(coll.begin(), coll.end(), bind(&Person::print2, placeholders::_1, "Person: "));
    cout<<endl;
    
    // call print2() for temporary Person
    bind(&Person::print2, placeholders::_1, "This is: ")(Person("nico"));
    return 0;
}

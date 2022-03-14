// p.528
#include<iostream>
#include<cmath>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<functional>
#include<string>
#include<locale>

using namespace std;

void PRINT_LIST_INT(list<int> a, string s){
    cout<<s;
    copy(a.begin(), a.end(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

char myToupper(char c){
    std::locale loc;
    return std::use_facet<std::ctype<char> >(loc).toupper(c);
}

class Person{
    private:
        string name;
    public:
        Person(const string& n) : name(n){}
        void print() const{
            cout<<name<<endl;
        }
        void print2(const string& prefix) const{
            cout<<prefix<<name<<endl;
        }
};

int main()
{
    // <-- LAMBDAS VERSUS BINDERS -->
    auto plus10 = [] (int i) {
        return i+10;
    };
    cout<<"+10:     "<<plus10(7)<<endl;
    
        // use lambdas:
    auto lambdas_plus10times2 = [] (int i) {
        return (i+10)*2;
    };
    cout<<"+10 *2:  "<<lambdas_plus10times2(7)<<endl;
    
        // use binders:
    auto binders_plus10times2 = std::bind(std::multiplies<int>(), std::bind(std::plus<int>(), std::placeholders::_1, 10), 2);
    
    auto pow3 = [] (int i) {
        return i*i*i;  
    };
    cout<<"x*x*x:   "<<pow3(7)<<endl;
    
    auto inversDivide = [] (double d1, double d2) {
        return d2/d1;
    };
    cout<<"invdiv:  "<<inversDivide(49,7)<<endl;
    
    // <-- LAMBDAS VERSUS STATEFUL FUNC OBJS -->
    vector<int> coll = {1,2,3,4,5,6,7,8};
        // process and print mean value
        // -use labdas:
    long sum = 0;
    for_each(coll.begin(), coll.end(), [&sum] (int elem) {
        sum+=elem; 
    });
    double mv = static_cast<double>(sum)/static_cast<double>(coll.size());
    cout<<"mean value:  "<<mv<<endl;
    
        // -use stateful func objs:
    // MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
    // cout<<"mean value: "<<mv.value()<<endl;
    
    list<int> coll2 = {1,2,3,4,5,6,7,8,9,10};
    PRINT_LIST_INT(coll2,"coll2:        ");
    
        // remove third elem
    list<int>::iterator pos;
    int count = 0;
    pos = remove_if(coll2.begin(), coll2.end(), [count] (int) mutable{
        return ++count == 3; 
    });
    coll2.erase(pos, coll2.end());
    PRINT_LIST_INT(coll2, "3rd removed:  ");
    
    // <-- LAMBDAS CALLING GLOBAL AND MEMBER FUNCS -->>
    string s("Internationalization");
    string sub("Nation");
    
        // search substring case insensitive
    string::iterator pos2;
    pos2 = search(s.begin(), s.end(), sub.begin(), sub.end(), [] (char c1, char c2){
        return myToupper(c1)==myToupper(c2);
    });
    
    if(pos2 != s.end())
        cout<< "\""<<sub<<"\" is part of \""<<s<<"\""<<endl;
        
    vector<Person> coll3 = { Person("Tick"), Person("Trick"), Person("Track") };
    
    for_each(coll3.begin(), coll3.end(), [] (const Person& p){
        p.print();
    });
    cout<<endl;
    
    for_each(coll3.begin(), coll3.end(), [] (const Person& p){
        p.print2("Person: ");
    });
    
    
    return 0;
}

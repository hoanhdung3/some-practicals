// p.374
#include<iostream>
#include<map>
#include<iterator>
#include<string>
#include<algorithm>
#include<iomanip>
#include<utility>
using namespace std;


int main()
{
    // <-- USING ALGORITHMS AND LAMBDAS --> 
    
    map<string,double> coll { {"tim", 9.9}, {"struppi", 11.77} };
    for_each(coll.begin(), coll.end(), [](pair<const string,double>& elem){
        elem.second *= elem.second;
    });
    
    for_each(coll.begin(), coll.end(), [](const map<string,double>::value_type& elem){
       cout<<elem.first<<": "<<elem.second<<endl; 
    });
    
    // <-- USING MAP AS AN ASSOCIATIVE ARRAY -->
    
    typedef map<string,float> StringFloatMap;
    
    StringFloatMap stocks;
    
    stocks["BASF"] = 369.50;
    stocks["VW"] = 413.50;
    stocks["Daimler"] = 819.00;
    stocks["BMW"] = 834.00;
    stocks["Siemens"] = 842.20;
    
    StringFloatMap::iterator pos;
    cout<<left; // left-adjust values
    for(pos = stocks.begin(); pos!=stocks.end(); ++pos){
        cout<<"stocks: "<< setw(12)<<pos->first<<"price: "<<pos->second<<endl;
    }
    cout<<endl;
    
    for(pos = stocks.begin(); pos!=stocks.end(); ++pos){
        pos->second *= 2;
    }
    
    for(pos = stocks.begin(); pos!=stocks.end(); ++pos){
        cout<<"stocks: "<< setw(12)<<pos->first<<"price: "<<pos->second<<endl;
    }
    cout<<endl;
    
    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");
    
    for(pos = stocks.begin(); pos!=stocks.end(); ++pos){
        cout<<"stocks: "<< setw(12)<<pos->first<<"price: "<<pos->second<<endl;
    }
    cout<<endl;
    
    // <-- USING A MULTIMAP AS A DICTIONARY -->
    
    multimap<string,string> dict;
    dict.insert( { {"day","Tag"}, {"strange","fremd"}, {"car","Auto"},
                    {"smart","elegant"}, {"trait","Merkmal"}, {"strange","seltsam"},
                    {"smart","raffiniert"}, {"smart","klug"}, {"clever","raffiniert"} } );
    
    cout.setf(ios::left, ios::adjustfield);
    cout<<' '<<setw(10)<<"english "<<"german "<<endl;
    cout<<setfill('-')<<setw(20)<<""<<setfill(' ')<<endl;
    for(const auto& elem : dict){
        cout<<' '<<setw(10)<<elem.first<<elem.second<<endl;
    }
    
    string word("smart");
    cout<<word<<": "<<endl;
    for(auto pos = dict.lower_bound(word); pos!=dict.upper_bound(word); ++pos){
        cout<<"    "<<pos->second<<endl;
    }
    
    word = ("raffiniert");
    cout<<word<<": "<<endl;
    for(const auto& elem : dict)
        if(elem.second==word)
            cout<<"    "<<elem.first<<endl;
    
    // <-- FINDING ELEMENTS WITH CERTAIN VALUES -->
    
    map<float,float> coll2 = { {1,7}, {2,4}, {3,2}, {4,3}, {5,6}, {6,1}, {7,3} };
    auto posKey = coll2.find(3.0);
    if(posKey != coll2.end())
        cout<<"key 3.0 found ("<<posKey->first<<":"<<posKey->second<<")"<<endl;
    
    auto posVal = find_if(coll2.begin(), coll2.end(), [](const pair<float,float>& elem){
        return elem.second == 3.0; 
    });
    
    if(posVal!=coll2.end())
        cout<<"value 3.0 found ("<<posVal->first<<":"<<posVal->second<<")"<<endl;
    return 0;
}

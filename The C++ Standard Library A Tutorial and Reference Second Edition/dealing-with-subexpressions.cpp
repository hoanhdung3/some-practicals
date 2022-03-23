// p.750
#include<iostream>
#include<regex>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
    // string data = "XML tag: <tag-name>the value</tag-name>.";
    // cout<<"data:            "<<data<<"\n\n";
    
    // smatch m; // for return details of the match 
    // bool found = regex_search(data, m, regex("<(.*)>(.*)</(\\1)>"));
    
    // cout<<"m.empty():       "<< boolalpha<<m.empty()<<endl;
    // cout<<"m.size():        "<<m.size()<<endl;
    
    // if(found){
    //     cout<<"m.str():             "<<m.str()<<endl;
    //     cout<<"m.length():          "<<m.length()<<endl;
    //     cout<<"m.position():        "<<m.position()<<endl;
    //     cout<<"m.prefix().str():    "<<m.prefix().str()<<endl;
    //     cout<<"m.suffix().str():    "<<m.suffix().str()<<endl;
    //     cout<<endl;
        
    //     // iterating over all matches (using the match index)
    //     for(int i=0;i<m.size();++i){
    //         cout<<"m["<<i<<"].str():        "<<m[i].str()<<endl;
    //         cout<<"m.str("<<i<<"):          "<<m.str(i)<<endl;
    //         cout<<"m.position("<<i<<"):     "<<m.position(i)<<endl;
    //     }
    //     cout<<endl;
        
    //     // iterating over all matches (using iterators)
    //     cout<<"matches:"<<endl;
    //     for(auto pos=m.begin();pos!=m.end();++pos){
    //         cout<<" "<<*pos<<" ";
    //         cout<<"(length: "<<pos->length()<<")"<<endl;
    //     }
    // }
    
    
    string data2 = "<person>\n"
                   " <first>Nico</first>\n"
                   " <last>Josuttis</last>\n"
                   "</person>\n";
    regex reg("<(.*)>(.*)</(\\1)>");
    
    auto pos = data2.cbegin();
    auto end = data2.cend();
    smatch m2;
    for( ; regex_search(pos, end, m2, reg); pos=m2.suffix().first){
        cout<<"match:   "<<m2.str()<<endl;
        cout<<" tag:    "<<m2.str(1)<<endl;
        cout<<"  value: "<<m2.str(2)<<endl;
    }
    return 0;
}

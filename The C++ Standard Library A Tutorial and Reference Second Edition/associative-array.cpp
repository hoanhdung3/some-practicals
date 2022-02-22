// p.214
#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,float> coll;
    
    //insert some elems using the syntax of an associative array
    coll["VAT1"] = 0.16;
    coll["VAT2"] = 0.07;
    coll["Pi"] = 3.1415;
    coll["an arbitrary number"] = 4983.223;
    coll["Null"] = 0;
    
    coll["VAT1"] += 0.03;
    
    cout<<"VAT difference: "<<coll["VAT1"] - coll["VAT2"] << endl;
    cout<<coll.at("Pi")<<endl; // at(): access the value of key
    return 0;
}
// associative array: can access elems by using the subscript operator []

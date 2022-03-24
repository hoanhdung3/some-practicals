// p.225
#include<iostream>
#include<string>
#include<cctype> // isspace() nad isdigit()

using namespace std;

long strToLong(string str){
    register int i = 0; // index 
    long vz = 1, num = 0; // sign and number
    
    // ignore leading white spaces
    for(int i=0; i<str.size() && isspace(str[i]); ++i);
    
    if(i<str.size()){ // is there a sign?
        if(str[i] == '+'){
            vz = 1;
            ++i;
        }
        if(str[i] == '-'){
            vz = -1;
            ++i;
        }
    }
    
    // sequence of digits -> convert to integer
    for( ; i<str.size() && isdigit(str[i]); ++i)
        num = num*10 + (str[i] - '0');
    return vz*num;
}

int main()
{
    cout<<strToLong("-1234+")<<endl;
    return 0;
}

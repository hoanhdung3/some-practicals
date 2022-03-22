// p.719
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

// replace funcs of the standard char_traits<char>
// so that strings behave in a case-insensitive way
struct ignorecase_traits : public std::char_traits<char>{
    // return whether c1 and c2 are equal
    static bool eq(const char& c1, const char& c2){
        return std::toupper(c1)==std::toupper(c2);
    }
    
    // return whether c1 is less than c2 
    static bool lt(const char& c1, const char& c2){
        return std::toupper(c1)<std::toupper(c2);
    }
    
    // compare up to n characters of s1 and s2
    static int compare(const char* s1, const char* s2, std::size_t n){
        for(size_t i=0;i<n;++i){
            if(!eq(s1[i],s2[i]))
                return lt(s1[i],s2[i]) ? -1 : 1;
        }
        return 0;
    }
    
    // search c in s 
    static const char* find(const char* s, size_t n, const char& c){
        for(size_t i=0;i<n;++i){
            if(eq(s[i], c))
                return &(s[i]);
        }
        return 0;
    }
};

// define a special type for such strings
typedef std::basic_string<char, ignorecase_traits> icstring;
// define an output operator because the traits type is different from that for std::ostream 
inline
std::ostream& operator << (std::ostream& strm, const icstring& s){
    // simply convert the icstring into a normal string 
    return strm << string(s.data(), s.length());
}

int main()
{
    icstring s1("hallo");
    icstring s2("otto");
    icstring s3("hALLo");
    
    cout<<boolalpha;
    cout<<s1<<" == "<<s2<<" : "<<(s1==s2)<<endl;
    cout<<s1<<" == "<<s3<<" : "<<(s1==s3)<<endl;
    
    icstring::size_type idx = s1.find("All");
    if(idx!=icstring::npos)
        cout<<"index of \"All\" in \""<<s1<<"\": "<<idx<<endl;
    else
        cout<<"\"All\" not found in \""<<s1<<endl;
    return 0;
}

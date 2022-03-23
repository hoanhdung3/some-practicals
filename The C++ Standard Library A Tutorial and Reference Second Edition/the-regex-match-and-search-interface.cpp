// p.747
#include<iostream>
#include<regex>

using namespace std;

void out(bool b){
    cout<<( b ? "found" : "not found" )<<endl;
}

// regex: "." stands for "any character except newline"
// regex: "*" stands for "zero or more times"
// regex_match() checks whether the whole character sequence matches a regular expresstion
// regex_search() checks whether the character sequence partially matches a regular expresstion

int main()
{
    // find XML/HTML-tagged value (using default syntax)
    regex reg1("<.*>.*</.*>");
    bool found = regex_match("<tag>value</tag>", // data
                                reg1);          // regular expresstion
    out(found);
    
    // find XML/HTML-tagged value (tags before and after the value must match)
    regex reg2("<(.*)>.*</\\1>");
    found = regex_match("<tag>value</tag>", reg2);
    out(found);
    
    // find XML/HTML-tagged value (using grep syntax)
    regex reg3("<\\(.*\\)>.*</\\1>", regex_constants::grep);
    found = regex_match("<tag>value</tag>", reg3);
    out(found);
    
    // use C-string as regular expresstion (needs explicit cast to regex)
    found = regex_match("<tag>value</tag>", regex("<(.*)>.*</\\1>"));
    out(found);
    cout<<endl;
    
    // regex_match() vs regex_search()
    found = regex_match("XML tag: <tag>value</tag>", regex("<(.*)>.*</\\1>")); // fails to match 
    out(found);
    found = regex_match("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*")); // matches
    out(found);
    found = regex_search("XML tag: <tag>value</tag>", regex("<(.*)>.*</\\1>")); // match
    out(found);
    found = regex_search("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*")); // matches
    out(found);
    return 0;
}

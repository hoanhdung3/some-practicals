// p.208
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
using namespace std;

void PRINT_ELEMENT(vector<string> a){
    copy(a.cbegin(), a.cend(), ostream_iterator<string>(cout," "));
    cout<<endl;
}

int main()
{
    vector<string> sentence;
    
    sentence.reserve(5); // reserve memory for 5 elems to avoid reallocation
    
    sentence.push_back("Hello,");
    sentence.insert(sentence.end(),{"how","are","you","?"});
    PRINT_ELEMENT(sentence);
    
    cout<<" max_size(): "<<sentence.max_size()<<endl;
    cout<<" size(): "<<sentence.size()<<endl;
    cout<<" capacity(): "<<sentence.capacity()<<endl;
    
    swap(sentence[1], sentence[3]);
    
    // insert elem "always" before elem "?"
    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");
    
    sentence.back() = "!";
    
    PRINT_ELEMENT(sentence);
    cout<<" size(): "<<sentence.size()<<endl;
    cout<<" capacity(): "<<sentence.capacity()<<endl;
    
    sentence.pop_back();
    sentence.pop_back();
    
    sentence.shrink_to_fit();
    
    cout<<"After shrink_to_fit(): "<<endl;
    cout<<" size(): "<<sentence.size()<<endl;
    cout<<" capacity(): "<<sentence.capacity()<<endl;
    
    return 0;
}

// p.663
#include<iostream>
#include<stack>
#include<deque>
#include<exception>

using namespace std;

// <-- A USER-DEFINED STACK CLASS -->
template <typename T>
class Stack{
    protected:
        deque<T> c;
    
    public:
        // exception class for pop() and top() with empty stack
        class ReadEmptyStack : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "read empty stack";
                }
        };
        
        typename deque<T>::size_type size() const{
            return c.size();
        }
        
        bool empty() const{
            return c.empty();
        }
        void push(const T& elem){
            c.push_back(elem);
        }
        T pop(){
            if(c.empty()){
                throw ReadEmptyStack();
            }
            T elem(c.back());
            c.pop_back();
            return elem;
        }
        T& top(){
            if(c.empty())
                throw ReadEmptyStack();
            return c.back();
        }
};

int main()
{
    // <-- BASIC -->
    stack<int> st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout<<st.top()<<" ";
    st.pop();
    cout<<st.top()<<" ";
    st.pop();
    
    st.top() = 77;
    
    st.push(4);
    st.push(5);
    st.pop();
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
    // <-- A USER-DEFINED STACK CLASS -->
    try{
        Stack<int> st;
        
        st.push(1);
        st.push(2);
        st.push(3);
        cout<<st.pop()<<" ";
        cout<<st.pop()<<" ";
        
        st.top()=77;
        st.push(4);
        st.push(5);
        
        st.pop();
        
            // pop and print 3 elems
            // -ERROR: 1 elem too many 
        cout<<st.pop()<<" ";
        cout<<st.pop()<<endl;
        cout<<st.pop()<<endl;
    }
    catch(const exception& e){
        cerr<<"EXCEPTION: "<<e.what()<<endl;
    }
    return 0;
}

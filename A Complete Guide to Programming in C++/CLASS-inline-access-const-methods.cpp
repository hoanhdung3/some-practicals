// p.293
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Account{
    private:
        string name;
        unsigned long nr;
        double state;
    public:
        Account(const string& a_name = "X", unsigned long a_nr = 1111111L, double a_state = 0.0){   // Constructor: implicit inline
            name = a_name;
            nr = a_nr;
            state = a_state;
        }
        ~Account(){ } // Dummy destructor: implicit inline
        const string& getName() const {    // Access methods
            return name;
        }
        bool setName(const string& s){
            if(s.size()<1)
                return false;
            name = s;
            return true;
        }
        unsigned long getNr() const {
            return nr;
        }
        void setNr(unsigned long n){
            nr = n;
        }
        double getState() const {
            return state;
        }
        void setState(double x){
            state = x;
        }
        void display() const;
};

// display() outputs data of class Account
inline void Account::display() const {     // Explicit inline
    cout<<fixed<<setprecision(2)
        <<"-------------------------------------\n"
        <<"Account holder:      "<<name<<"\n"
        <<"Account number:      "<<nr<<"\n"
        <<"Account state:       "<<state<<"\n"
        <<"-------------------------------------\n"<<endl;
}

int main()
{
    Account cr;
    cr.display();
    cout<<"cr's number:     "<<cr.getNr()<<endl;
    cr.setState(123.4);
    cr.display();
    return 0;
}

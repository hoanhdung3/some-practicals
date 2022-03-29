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
        void display();
};

// display() outputs data of class Account
inline void Account::display(){     // Explicit inline
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
    return 0;
}

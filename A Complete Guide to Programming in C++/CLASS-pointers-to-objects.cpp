// p.275
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Account{
    private:
        string name;        // Account holder
        unsigned long nr;   // Account number
        double balance;     // Account balance
    public:                 // Public interface
        bool init(const string&, unsigned long, double);
        void display();
};

bool Account::init(const string& i_name, unsigned long i_nr, double i_balance){
    if(i_name.size() < 1)   // No empty name 
        return false;
    name = i_name;
    nr = i_nr;
    balance = i_balance;
    return true;
}

void Account::display(){
    cout<<fixed<<setprecision(2)
        <<"------------------------------------\n"
        <<"Account holder:      "<<name<<"\n"
        <<"Account number:      "<<nr<<"\n"
        <<"Account balance:     "<<balance<<"\n"
        <<"------------------------------------\n"
        <<endl;
}

bool getAccount(Account *pAccount){
    string name, line(50,'-');  // Local variables
    unsigned long nr;
    double startcapital;
    
    cout<<line<<'\n'
        <<"Enter data for a new account: \n"
        <<"Account holder: ";
    if(!getline(cin, name) || name.size()==0)
        return false;
    cout<<"Account number:  ";
    if(!(cin >> nr))
        return false;
    cout<<"Starting capital: ";
    if(!(cin >> startcapital)) 
        return false;
    // All unput ok
    pAccount->init(name, nr, startcapital);
    return true;
}

int main(){
    
    Account current1, current2, *ptr = &current1;
    ptr->init("Cheer, Mary", 3512345, 99.40);       // current1.init(...)
    ptr->display();                                 // current1.display()
    ptr = &current2;    // Let ptr point to current2
    if(getAccount(ptr)) // Input and output a new account
        ptr->display();
    else
        cout<<"Invalid input!"<<endl;
    return 0;
}

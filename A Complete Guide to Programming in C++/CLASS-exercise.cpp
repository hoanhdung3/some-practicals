// p.282
#include<iostream>
#include<ctime>
using namespace std;

class Date{
    private:
        int m,d,y;
    public:
        void init(int month, int day, int year);
        void init(void);
        void print(void);
};

void Date::print(){
    cout<<m<<'-'<<d<<"-"<<y<<endl;
}

void Date::init(int month, int day, int year){
    m = (short) month;
    d = (short) day;
    y = (short) year;
}

void Date::init(){
    struct tm* ptr;
    time_t sec;
    time(&sec);             // Get the present date 
    ptr = localtime(&sec);   // Initialize a struct of type tm and return a pointer to it 
    m = (short) ptr->tm_mon + 1;
    d = (short) ptr->tm_mday;
    y = (short) ptr->tm_year + 1900;
}

int main(){
    
    Date today, birthday, aDate;
    
    today.init();
    birthday.init(9, 12, 2000);
    cout<<"Today's date:        ";
    today.print();
    
    cout<<"\nDung's birthday:  ";
    birthday.print();
    
    cout<<"-----------------------------\n"
            "Some testing outputs:  "<<endl;
    aDate = today;
    aDate.print();
    
    Date *pDate = &birthday;
    pDate->print();
    
    Date &holiday = aDate;      // Reference to aDate
    holiday.init(1,5,2000);
    aDate.print();              // holiday.print()
    return 0;
}

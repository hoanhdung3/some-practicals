// p.453
#include<iostream>
#include<iomanip>
using namespace std;

class DayTime{
    private:
        short hour, minute, second;
        bool overflow, underflow;
    
        void inc(){         // private func for ++
            ++second;
            if(second>=60)  // handle overflow
                second = 0, ++minute;
            if(minute>=60)
                minute = 0, ++hour;
            if(hour >=24)
                hour = 0, overflow = true;
        }
        
        void dec(){         // private func for --
            --second;
            if(second<0)    // handle underflow
                second = 59, --minute;
            if(minute<0)
                minute = 59, --hour;
            if(hour<0)
                hour = 0, underflow = true;
        }
    
    public:
        DayTime(int h=0, int m=0, int s=0){
            overflow = underflow = false;
            if(!setTime(h, m, s))
                hour = minute = second = 0;
        }
        
        bool setTime(int hour, int minute, int second = 0){
            if(hour>=0 && hour<24 && minute>=0 && minute<60 && second>=0 && second<60){
                this->hour = (short)hour;
                this->minute = (short)minute;
                this->second = (short)second;
                return true;
            }
            else
                return false;
        }
        
        int getHour() const{
            return hour;
        }
        
        int getMinute() const{
            return minute;
        }
        
        int getSecond() const{
            return second;
        }
        
        int asSeconds() const{
            return (60*60*hour + 60*minute + second);
        }
        
        DayTime& operator++(){      // ++Seconds 
            inc();
            return *this;
        }
        
        DayTime operator++(int){   // Seconds++
            DayTime temp(*this);
            inc();
            return temp;
        }
        
        DayTime& operator--(){
            dec();
            return *this;
        }
        
        DayTime operator--(int){
            DayTime temp(*this);
            dec();
            return temp;
        }
};

// --- Relational operator ---

inline bool operator<(const DayTime& t1, const DayTime& t2){
    return t1.asSeconds() < t2.asSeconds();
}

inline bool operator<=(const DayTime& t1, const DayTime& t2){
    return t1.asSeconds() <= t2.asSeconds();
}

inline bool operator==(const DayTime& t1, const DayTime& t2){
    return t1.asSeconds() == t2.asSeconds();
}

inline bool operator!=(const DayTime& t1, const DayTime& t2){
    return !(t1==t2);
}

inline bool operator>(const DayTime& t1, const DayTime& t2){
    return (t2<t1);
}

inline bool operator>=(const DayTime& t1, const DayTime& t2){
    return !(t1<t2);
}

// --- Input and Output ---
ostream& operator<<(ostream& os, const DayTime& t){
    os<<setfill('0')<<setw(2)<<t.getHour()<<':'
                    <<setw(2)<<t.getMinute()<<':'
                    <<setw(2)<<t.getSecond()<<" Time";
    os<<setfill(' ');
    return os;
}

istream& operator>>(istream& is, DayTime& t){
    cout<<"Enter DayTime in hh:mm:ss format: ";
    int hr=0, min=0, sec=0;
    char c1=0, c2=0;
    if( !(is>>hr>>c1>>min>>c2>>sec) )
        return is;
    if(c1!=':' || c2!=':' || ! t.setTime(hr,min,sec))
        is.setstate(ios::failbit);      // Error! => Set fail bit 
    return is;
}

int main()
{
    DayTime cinema(20, 30);
    cout<<"\nThe movie starts at "<<cinema<<endl;
    
    DayTime now;
    cout<<"WHat time is it now?"<<endl;
    if( !(cin>>now) )
        cerr<<"Invalid input!"<<endl;
    else
        cout<<"\nThe time is now"<<now<<endl;
    
    cout<<"\nThe movie has ";
    if(cinema<now)
        cout<<"already begun!\n"<<endl;
    else
        cout<<"not yet begun!\n"<<endl;
        
    cout<<"Now it is    "<<now++<<endl;
    cout<<"After 2 seconds: "<<++now<<endl;
    
    DayTime depart(16, 0);
    cout<<"Let's go at "<<--depart<<endl;
    
    if(depart>=now)
        cout<<"You can ride with us!"<<endl;
    else
        cout<<"We don't have room!"<<endl;
    return 0;
}

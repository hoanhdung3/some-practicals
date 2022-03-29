// p.301
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>

using namespace std;

class DayTime{
    private:
        short hour, minute, second;
        bool overflow;
    public:
        DayTime(int h = 0, int m = 0, int s = 0){
            overflow = false;
            if(!setTime(h, m, s))       // this->setTime(...)
                hour = minute = second = 0;
        }
        bool setTime(int hour, int minute, int second = 0){
            if(hour>=0 && hour<24 && minute>=0 && minute<60 && second>=0 && second<60){
                this->hour = (short) hour;
                this->minute = (short) minute;
                this->second = (short) second;
                return true;
            }
            else
                return false;
        }
        int getHour() const {return hour;}
        int getMinute() const {return minute;}
        int getSecond() const {return second;}
        
        int asSecond() const{       // DayTime in seconds
            return (60*60*hour + 60*minute + second);
        }
        bool isLess(DayTime t) const{       // compare *this and t 
            return asSecond() < t.asSecond();
        }   // this->asSecond() < t.asSecond();
        
        void swap(DayTime& t){
            DayTime temp(t);
            t = *this;
            *this = temp;
        }
        void print(){
            cout<<hour<<":"<<minute<<":"<<second<<endl;
        }
};

const DayTime& currentTime(){
    static DayTime curTime;
    time_t sec;
    time(&sec);     // Gets the present time 
    struct tm* time = localtime(&sec);
    curTime.setTime(time->tm_hour, time->tm_min, time->tm_sec);
    return curTime;
}

const DayTime& currentTime();

int main()
{
    DayTime depart1(11,11,11), depart2;
    
    depart2.setTime(12,0,0);
    if(depart1.isLess(depart2))
        cout<<"\nThe 1st plane takes off earlier"<<endl;
        
    DayTime arrival1(14,10), arrival2(15,20);
    arrival1.swap(arrival2);
    
    DayTime cinema(20,30);
    cout<<"\nThe movie starts at ";
    cinema.print();
    
    DayTime now(currentTime());
    cout<<"\nThe current time is ";
    now.print();
    
    cout<<"\nThe movie has ";
    if(cinema.isLess(now))
        cout<<"already begun!\n"<<endl;
    else
        cout<<"not yet begun!\n"<<endl;
    return 0;
}

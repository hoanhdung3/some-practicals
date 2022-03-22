// p.143
#include<iostream>
#include<string>

using namespace std;

#define DELAY 10000000L // output delay 
#define CLS (cout<<"\033[2J") // clear screen
#define LOCATE(z,s) (cout<<"\033["<<z<<';'<<s<<'H') // position the cursor in row z and column s 

int main()
{
    int x=2, y=3, dx=1, speed=0;
    string floor(79, '-'), header = "****   JUMPING BALL ****";
    CLS;
    LOCATE(1,25); cout<<header;
    LOCATE(25,1); cout<<floor;
    
    while(true){
        LOCATE(y,x);
        cout<<'o'<<endl;
        for(long wait=0;wait<DELAY;++wait);
        if(x==1 || x==79) dx=-dx; // bounce off a wall?
        if(y==24){                // on the floor?
            speed = -speed;
            if(speed==0) speed = -7; // restart
        }
        speed+=1; // acceleration = 1 
        LOCATE(y,x); cout<<' ';  // clear output
        y+=speed; x+=dx; // new position
    }
    return 0;
}

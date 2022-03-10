#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

void draw_line(int n, char symbol)
{
    for(int i=0;i<n;i++)
        cout<<symbol;
    cout<<"\n";
}

void rules()
{
    system("clear");
    cout<<"\n\n";
    draw_line(80,'-');
    cout<<"\t\tRULES OF THE GAME\n";
    draw_line(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    draw_line(80,'-');
}

int main()
{
    string player_name;
    char enter;
    int amount;
    int betting_amount;
    int guess;
    int dice;
    char choice;

    srand(time(0)); // "seed" the random generator
    
    draw_line(60,'_');
    cout<<"\n\n\n\t\tCASINO GAME\n\n\n\n";
    draw_line(60,'_');

    cout<<"\n\nEnter your name: ";
    getline(cin,player_name);

    cout<<"\n\nEnter Deposit amount to play game: $";
    cin>>amount;

    do
    {
        system("clear");
        rules();
        cout<<"\n\nYour current balance is $ "<<amount<<"\n";
        do
        {
            cout<<player_name<<", enter money to bet: $";
            cin>>betting_amount;
            if(betting_amount>amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(betting_amount > amount);
        do
        {
            cout<<"Guess your number to bet between 1 to 10: ";
            cin>>guess;
            if(guess <=0 || guess >10)
                cout<<"Check the number? Should be betwwen 1 to 10\n"<<"\nRe-enter data\n";
        }while(guess<=0 || guess >10);

        dice = rand()%10 + 1;
        cout<<"\nYour number is: "<<guess<<endl;

        if(dice == guess)
        {
            cout<<"\n\nLuckyyyyyyyy!! You won Rs."<<betting_amount *10;
            amount = amount + betting_amount*10;
        }
        else
        {
            cout<<"Bad luck!! You lost $ "<<betting_amount<<"\n";
            amount = amount - betting_amount;
        }
        cout<<"\nThe winning number was: "<<dice<<"\n";
        cout<<"\n"<<player_name<<", you have $ "<< amount <<"\n";
        if(amount==0)
        {
            cout<<"You have no money to play";
            break;
        }
        cout<<"\n\n--->Do you want to play again (y/n)?";
        cin>>choice;
    }while(choice=='y'||choice=='Y');

    cout<<"\n\n\n";
    draw_line(70,'=');
    cout<<"\n\nThank you.Your balance amount is $ "<<amount<<"\n\n";
    draw_line(70,'=');
    return 0;
}

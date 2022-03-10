#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

void draw_line(int n, char symbol);
void rules();
int boc();
void current_amount(string player,int amount);

int main()
{
    string player1, player2, player3;
    int amount1, amount2, amount3;
    int card1, card2, card3;
    int betting_amount1, betting_amount2, betting_amount3;
    int sum1, sum2, sum3;
    int max=0;

    srand(time(0));


    draw_line(60,'_');
    cout<<"\n\n\n\t\tGAME BA CAY\n\n\n\n";
    draw_line(60,'_');

    cout<<"\n\nPlayer 1 name: ";
    getline(cin,player1);

    cout<<"\n\n"<<player1<<", enter Deposit amount to play game: $";
    cin>>amount1;

    cout<<"\n\nPlayer 2 name: ";
    cin>>player2;

    cout<<"\n\n"<<player2<<", enter Deposit amount to play game: $";
    cin>>amount2;

    cout<<"\n\nPlayer 3 name: ";
    cin>>player3;

    cout<<"\n\n"<<player3<<", enter Deposit amount to play game: $";
    cin>>amount3;

    do
    {
        system("clear");
        rules();
        do
        {
            cout<<player1<<", enter money to bet: $";
            cin>>betting_amount1;
            if(betting_amount1>amount1)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        } while (betting_amount1 > amount1);
    
        do
        {
            cout<<player2<<", enter money to bet: $";
            cin>>betting_amount2;
            if(betting_amount2>amount2)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        } while (betting_amount2 > amount2);
    
        do
        {
            cout<<player3<<", enter money to bet: $";
            cin>>betting_amount3;
            if(betting_amount3>amount3)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        } while (betting_amount3 > amount3);
        cout<<"\n\n";
        
        card1 = boc();
        card2 = boc();
        card3 = boc();
        sum1 = card1 + card2 +card3;
        cout<<player1<<", your 3 cards is: "<<card1<<" "<<card2<<" "<<card3<<" and your point is: "<<sum1<<endl;

        
        card1 = boc();
        card2 = boc();
        card3 = boc();
        sum2 = card1 + card2 +card3;
        cout<<player2<<", your 3 cards is: "<<card1<<" "<<card2<<" "<<card3<<" and your point is: "<<sum2<<endl;
        
        card1 = boc();
        card2 = boc();
        card3 = boc();
        sum3 = card1 + card2 +card3;
        cout<<player3<<", your 3 cards is: "<<card1<<" "<<card2<<" "<<card3<<" and your point is: "<<sum3<<endl;

        draw_line(90,'-');
        if(sum1 > sum2 && sum1 > sum3)
        {
            cout<<"\n\nSo, the winner of this round is "<<player1<<endl;
            amount1 += betting_amount2 + betting_amount3;
            amount2 = amount2 - betting_amount2;
            amount3 = amount3 - betting_amount3;
        }
        else if(sum2>sum3 && sum2 >sum1)
        {
            cout<<"\n\nSo, the winner of this round is "<<player2<<endl;
            amount2 += betting_amount1 + betting_amount3;
            amount1 = amount1 - betting_amount1;
            amount3 = amount3 - betting_amount3;
        }
        else if(sum2<sum3 && sum3 >sum1)
        {
            cout<<"\n\nSo, the winner of this round is "<<player3<<endl;
            amount3 += betting_amount1 + betting_amount2 ;
            amount1 = amount1 - betting_amount1;
            amount2 = amount2 - betting_amount2;
        }
        else if(sum2==sum3 && sum3 >sum1)
        {
            cout<<"\n\nSo, the winner of this round is "<<player3<<" and "<<player3<<endl;
            amount3 += (betting_amount1 + betting_amount2 )/2;
            amount2 += (betting_amount1 +  betting_amount3)/2;
            amount1 = amount1 - betting_amount1;
        }
        else if(sum1==sum3 && sum2 <sum1)
        {
            cout<<"\n\nSo, the winner of this round is "<<player3<<" and "<<player1<<endl;
            amount3 += (betting_amount1 + betting_amount2 )/2;
            amount1 += ( betting_amount2 + betting_amount3)/2;
            amount2 = amount2 - betting_amount2;
        }
        else if(sum2==sum1 && sum3 <sum1)
        {
            cout<<"\n\nSo, the winner of this round is "<<player3<<" and "<<player3<<endl;
            amount1 += (betting_amount2 + betting_amount3)/2;
            amount2 += (betting_amount1  + betting_amount3)/2;
            amount3 = amount3 - betting_amount3;
        }
        else{
            cout<<"This round is draw";
        }

        current_amount(player1,amount1);
        current_amount(player2,amount2);
        current_amount(player3,amount3);

    } while (amount1 != 0 || amount2 != 0 || amount3 != 0 );

    return 0;
}

void current_amount(string player,int amount)
{
    cout<<player<<" now having $"<<amount<<endl;
}
int boc()
{
    return rand()%9+1;
}

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
    cout << "\t1. Enter your money you want to bet\n";
    cout << "\t2. If 1 player win, take all money\n";
    cout << "\t3. If 2 players win, each take half of whole money \n\n";
    draw_line(80,'-');
}


#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream read("/home/dung/dung_cpp/simple_project/login_system/" + username + ".txt");
    getline(read,un);
    getline(read,pw);

    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    int choice;
    cout<<"1: Register\n2: Login\nYour choice: ";
    cin>>choice;
    if(choice == 1)
    {
        string username,password;
        cout<<"select a username: ";
        cin>>username;
        cout<<"select a password: ";
        cin>>password;

        ofstream file;
        file.open("/home/dung/dung_cpp/simple_project/login_system/" + username + ".txt");
        file << username<<endl<<password;
        file.close();

        main();
    }
    else if(choice == 2)
    {
        bool status = IsLoggedIn();
        if(!status)
        {
            cout<<"False Login!"<<endl;
  
            return 0;
        }
        else
        {
            cout<<"Successfully logged in!"<<endl;

            return 1;
        }
    }
}
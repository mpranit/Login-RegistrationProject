#include<iostream>
#include<fstream>
using namespace std;

struct info
{
    char username[1000];             // username
    char password[1000];             // passsword
    void registration(int);
} obj[1000];

void info::registration(int k)
{
    int i=k;
    cout<<"\nEnter user name :: ";
    cin>>username;
    cout<<"\nEnter password :: ";
    cin>>password;

    ofstream filout;
    filout.open("records.txt",ios::out|ios::app|ios::binary);   //function to write username and password in our file
    if(!filout)
    {
        cout<<"\nCannot open file\n";
    }
    else
    {
        cout<<"\n";
        filout.write((char *)&obj[i],sizeof(obj[i]));
        filout.close();
    }

    cout<<"\n...........You are now registered.......... \n\n";

}   // end of sign up or register username

int main()
{
    
    cout<<"\nnumber of student for registration :: ";
    int numberofstudent;
    cin>>numberofstudent;
    for(int i=1;i<=numberofstudent;i++){
        cout<<"\nEnter Registration Details for User "<<i <<" :: ";
    obj[i].registration(i);
    }

    info obj2;

    ifstream filein;
    filein.open("records.txt",ios::in|ios::binary);
    if(!filein)
    {
        cout<<"\nusernameable to open file to read\n";
    }
    else
    {
        cout<<"\nRegistered Details of All Users :: \n";
        filein.read((char *)&obj2,sizeof(obj2));     //function to read username and password in our file
        while(filein)
        {
            cout<<"\nUsername :: "<<obj2.username<<"\nPasswword :: "<<obj2.password<<"\n";
            filein.read((char *)&obj2,sizeof(obj2));
        }
            filein.close();
    }
        return 0;
}
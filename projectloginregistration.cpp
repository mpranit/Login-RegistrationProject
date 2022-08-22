#include<iostream>
#include<fstream>
using namespace std;

struct info
{
    char username[1000];             // username
    char password[1000];             // passsword
    void registration(int);
} var[1000];

void info::registration(int k)
{
    int i=k;
    cout<<"\nEnter user name :: ";
    cin>>username;
    cout<<"\nEnter password :: ";
    cin>>password;

    ofstream filout;
    filout.open("records.txt",ios::out|ios::app|ios::binary);   //function to write username and password in our file
    
        cout<<"\n";
        filout.write((char *)&var[i],sizeof(var[i]));
        filout.close();
    

    cout<<"\n...........You are now registered.......... \n\n";

}   // end of sign up or register username

int main()
{
    
    cout<<"\nnumber of student for registration :: ";
    int numberofstudent;
    cin>>numberofstudent;
    for(int i=1;i<=numberofstudent;i++){
        cout<<"\nEnter Registration Details for User "<<i <<" :: ";
    var[i].registration(i);
    }

    info object;

    ifstream filein;
    filein.open("records.txt",ios::in|ios::binary);
    if(!filein)
    {
        cout<<"\nusernameable to open file to read\n";
    }
    else
    {
        cout<<"\nRegistered Details of All Users :: \n";
        filein.read((char *)&object,sizeof(object));     //function to read username and password in our file
        while(filein)
        {
            cout<<"\nUsername :: "<<object.username<<"\nPasswword :: "<<object.password<<"\n";
            filein.read((char *)&object,sizeof(object));
        }
            filein.close();
    }
        return 0;
}

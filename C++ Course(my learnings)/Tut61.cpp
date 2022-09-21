//*******Read write in the same program and closing files*******
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //Connecting our file with hout stream
    ofstream hout("sample60.txt");


    //Creating a name string and filling it with the string entered by the user
    cout<<"Enter your name"<<endl;
    string name;
    cin>>name;


    
    //Writing string to the file created
    hout<<name +" is my name";
      hout.close();//link has been disabled

    ifstream hin("sample60.txt");
    string content;
    hin>>content;
    cout<<"The content of this file is "<<content;
    hin.close();

    return 0;
}
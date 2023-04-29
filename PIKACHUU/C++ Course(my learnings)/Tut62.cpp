//Another way of reading and writing to a file

#include <iostream>
#include<fstream>
//#include<string>
using namespace std;
int main()
{
ofstream out;
out.open ("sample60.txt");
out<<"This is me\n";
out<<"This is also me";
out<<"This is another form of me";
out<<"This is my another unpredictable avatar";
out.close();


ifstream in;
string st,st2;
in.open("sample60b.txt");
//in>>st>>st2;  //one way to get the output
//cout<<st<<st2;

//another way to get all the text contained in the file
while (in.eof()==0)//eof meaning end of file
{
    getline(in,st);//Harry bhay used string library for getline() but its working without that also in my laptop 
    cout<<st<<endl;

}
in.close();
    return 0;
}
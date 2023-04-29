//C++ Templates : Templates with Multiple Parameters
/*
template <class T1,class T2>
class nameofClass{
    //body
}
}
*/
#include <iostream>
using namespace std;
template<class T1,class T2>
class myClass{
public:
T1 data1;
T2 data2;
myClass(T1 a,T2 b)
{
    data1=a;
    data2=b;
}
void display()
{
    cout<<this->data1<<endl<<this->data2;
}

};

int main()
{
    myClass <int,char>obj(1,'6');
    myClass <int,float>tmp(4,1.8);
    obj.display();
    cout<<endl;
    tmp.display();
    return 0;
}
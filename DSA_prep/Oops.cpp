#include<bits/stdc++.h>
using namespace std;


class Papa{
    public:
    Papa(){
        cout<<"Papa constructor"<<endl;
    }
   
    protected:
    int a=3;
};
class Mama{
    private:
    int a=4;
    public:
    Mama(){
        cout<<"Mama constructor"<<endl;
    }
    virtual int get(){
        cout<<"Mama get"<<endl;
        return 1;
    }
};
class Child: public Mama, public Papa{
    public:
    Child(){
        cout<<"Child constructor"<<endl;
    }
    int get(){
        cout<<"Child get"<<endl;
        return 1;
    }
};

int main(){
    Mama* m = new Child();
    
    return 0;
}
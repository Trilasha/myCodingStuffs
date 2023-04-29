//*******Array of Objects Using Pointers in C++*******
#include <iostream>
using namespace std;
class shopitem
{
    int id;
    float price;
    public:
    void set_data(int a,float b)
    {
        id = a;
        price=b;
    }
    void get_data(void)
    {
        cout<<"Code of this item is "<<id<<endl;
        cout<<"Price of this item is "<<price<<endl;
    }
};

int main()
{
    int size = 3;
    shopitem *ptr=new shopitem [size];
    shopitem *ptrTemp = ptr;
    //the method that we followed earlier-->int *ptr=&size;
    //but now we are writing it as-->int *ptr=new int [34]; but the difference is that our class is now the data type 
    //1.general_store
    //2.veggies
    //3.hardware
    int p,i;
    float q;
    for (i = 1; i < size+1; i++)
    {
        cout<<"Enter the Id and Price of the item "<<i<<endl;
        cin>>p>>q;
        ptr->set_data(p,q);
        ptr++;
    }
    
    for (i = 0; i < size; i++)
    {
        cout<<"Item Number : "<<i+1<<endl;
        ptrTemp->get_data();
        ptrTemp++;
    }
    //The same thing cannot be done without pointers because for incrementation pointers are needed(A/me rest need to be confirmed once)
    return 0;
}
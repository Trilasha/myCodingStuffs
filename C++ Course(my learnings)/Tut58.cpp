//********Abstract Base Class And Pure Virtual Functions in C++*******
#include <iostream>
using namespace std;
class cwh
{
protected:
    string title;
    float rating;

public:
    cwh(string s, float r)
    {
        title = s;
        rating = r;
    }
   //////////////////////The application of the new content is in this part////////////////////////////
    virtual void display()=0;   //do nothing function -->pure virtual function
    //Pure virtual function is used for making abstract bse class
    //whose intention is to allow the formation of derived classes from it to be worked upon
    //so in this case if there is no display function defined in that particular derived class
    //then the compiler will show an error because unlike the previous case
    //*********Abstract class will have atlest one pure virtual function*********
};
class cwhvideo : public cwh
{
    float videolength;

public:
    cwhvideo(string s, float r, float vl) : cwh(s, r)
    {
        videolength = vl;
    }
    void display()
    {
        cout << "This is an amazing video with title " << title << endl;
        cout << "Ratings: " << rating << " out of 5 stars" << endl;
        cout << "Length of this video is: " << videolength << " minutes" << endl;
    }
};
class cwhtext : public cwh
{
    int words;

public:
    cwhtext(string s, float r, int wc) : cwh(s, r)
    {
        words = wc;
    }
     void display()
    {
        cout<<"This is an amazing tutorial with title "<<title<<endl;
        cout<<"Ratings of this text material: "<<rating<<" out of 5 stars"<<endl;
        cout<<"No. of words in the text tutorial is: "<<words<<" words"<<endl;
    }
};
int main()
{

    string title;
    float rating, vlen;
    int words;

    //for cwh videos
    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    cwhvideo djvideo(title, rating, vlen);
    //djvideo.display();

    //for code with harry text
    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;
    cwhtext djtext(title, rating, words);
    djtext.display();

    //Main learning starts from this part
    cwh *tuts[2];
    tuts[0] = &djvideo;
    tuts[1] = &djtext;

    tuts[0]->display();
    tuts[1]->display();
    return 0;
}
/*
-->After analysing the previous tutorials 55,56,57 and 58,it can be said that 
1)In the case of base class if we make a pointer in it and then point it to a derived class object
then then any call will return the base class members only and changes can be made in the base class variables solely.
To call only the function sharing the same name from any derived class(but not the base)then we can make the function virtual 
and at best we can make a pure virtual function which will make sure that a derived class has got such a same named function 
without which the program will show an error...
2)In the case of derived class,if we make a pointer in it and then point it to its own object then through the pointer,
we will be able to make changes in the variables of only the derived class and can call the function of that derived class only...
*/
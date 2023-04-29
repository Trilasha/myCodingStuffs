#include <iostream>
#include <cstring>
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
    //void display()
    virtual void display()
    {
        cout << "Hello this is my own disney world" << endl;
    }
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
    // void display()
    //{
    //    cout<<"This is an amazing tutorial with title "<<title<<endl;
    //    cout<<"Ratings of this text material: "<<rating<<" out of 5 stars"<<endl;
    //    cout<<"No. of words in the text tutorial is: "<<words<<" words"<<endl;
    //}
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
    //Above two will execute their respective displays only if virtual keyword is written before the display of the void function
    //otherwise the display function of the base class will run
    //thereby creating conandrum

    //*******RULES FOR DEFINING THE VIRTUAL FUNCTIONS*******
    /*
-->They cannot be static
-->They are accesssed by object pointers
-->Virtual functions can be a friend of another class
-->A virtual function in base class might not be used
-->If a virtual function is defined in a base class,there is no necessity of redefining it in the derived class 

//The last point can be understood by commenting out the display function(of any derived class besides the base class)and then if called from any particular derived class 
//as written in the above code,it will diswplay the base class display function only in the absence of any display funtion in the respective derived class
//without any error
*/
    return 0;
}
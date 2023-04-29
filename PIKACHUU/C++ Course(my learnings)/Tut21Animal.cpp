#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    string name, sound;//Instead declaring string as an array of characters,C++ provides a data type called "string" unlike C
    int speed;
    void set_animal_data(string parm_name, string parm_sound, int parm_speed); //Only declaration done
    void get_animal_data();                                                    //Only declaration done
};


void Animal::set_animal_data(string parm_name, string parm_sound, int parm_speed)
{
    name = parm_name; //These two names have to be different
    sound = parm_sound;
    speed = parm_speed;
}
void Animal::get_animal_data()
{
    cout << "Name : " << name << "\nSound : " << sound << "\nSpeed : " << speed;
}

int main()
{
    Animal Human;
    Human.set_animal_data("homosapien", "Language", 20); //Speed is in km/h
    Human.get_animal_data();
    return 0;
}
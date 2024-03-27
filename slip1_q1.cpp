// Write the definition for a class Cylinder that contains data members radius and height. The class
// has the following member functions:
// a. void setradius(float) to set the radius of data member.
// b. void setheight(float) to set the height of data member.
// c. float volume( ) to calculate and return the volume of the cylinder.
// Write a C++ program to create cylinder object and display its volume.
#include<iostream>
using namespace std;
class Cylinder 
{
    private:
        float radius;
        float height;

    public:
        void setradius(float r) 
        {
            radius = r;
        }

        void setheight(float h) {
            height = h;
        }

        float volume() {
            return 3.14 * radius * radius * height;
        }
};

int main(void)
{
    Cylinder c;
    float r, h;

    cout << "Enter the radius of the cylinder: ";
    cin >> r;
    c.setradius(r);

    cout << "Enter the height of the cylinder: ";
    cin >> h;
    c.setheight(h);
    cout << "The volume of the cylinder is: " << c.volume() << endl;
}

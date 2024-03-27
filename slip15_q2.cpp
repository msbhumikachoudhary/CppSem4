// Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram), Volume
// (Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program to perform
// read, convert and display operations. (Use Pure virtual function)
#include<iostream>
using namespace std;

class Conversion{
    public:
        virtual void read() = 0; //Pure virtual function
        virtual void convert() = 0; //Pure virtual function
        virtual void display() = 0; //Pure virtual function
};

class Weight : public Conversion{
    private:
        float gram, kilogram;
    public:
        void read(){
            cout<<"Enter weight in Grams: ";
            cin>>gram;
        }
        void convert(){
            kilogram = gram / 1000.0;
        }
        void display(){
            cout<<gram<<" Grams = "<<kilogram<<" Kilograms"<<endl;
        }
};

class Volume : public Conversion{
    private:
        float milliliter, liter;
    public:
        void read(){
            cout<<"Enter volume in Milliliters: ";
            cin>>milliliter;
        }
        void convert(){
            liter = milliliter / 1000.0;
        }
        void display(){
            cout<<milliliter<<" Milliliters = "<<liter<<" Liters"<<endl;
        }
};

class Currency : public Conversion{
    private:
        float rupees, paise;
    public:
        void read(){
            cout<<"Enter amount in Rupees: ";
            cin>>rupees;
        }
        void convert(){
            paise = rupees * 100.0;
        }
        void display(){
            cout<<rupees<<" Rupees = "<<paise<<" Paise"<<endl;
        }
};

int main(){
    Conversion *cptr;
    Weight w;
    Volume v;
    Currency c;
    int choice;
    do{
        cout<<"\n1. Convert Weight\n2. Convert Volume\n3. Convert Currency\n4. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cptr = &w;
                cptr->read();
                cptr->convert();
                cptr->display();
                break;
            case 2:
                cptr = &v;
                cptr->read();
                cptr->convert();
                cptr->display();
                break;
            case 3:
                cptr = &c;
                cptr->read();
                cptr->convert();
                cptr->display();
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Try again."<<endl;
        }
    }while(choice != 4);
    return 0;
}

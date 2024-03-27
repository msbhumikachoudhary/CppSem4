// Design a two base classes Employee (Name, Designation) and Project(Project_Id, title).
// Derive a class Emp_Proj(Duration) from Employee and Project. Write a menu driven
// program to
// a. Build a master table.
// b. Display a master table
// c. Display Project details in the ascending order of duration
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Employee{
    protected:
        string name;
        string designation;
    public:
        void getdata(){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter designation: ";
            cin >> designation;
        }
        void display(){
            cout << "Name: " << name << endl;
            cout << "Designation: " << designation << endl;
        }
};

class Project{
    protected:
        int project_id;
        string title;
    public:
        void getdata(){
            cout << "Enter Project ID: ";
            cin >> project_id;
            cout << "Enter title: ";
            cin >> title;
        }
        void display(){
            cout << "Project ID: " << project_id << endl;
            cout << "Title: " << title << endl;
        }
};

class Emp_Proj : public Employee, public Project{
    protected:
        int duration;
    public:
        void getdata(){
            Employee::getdata();
            Project::getdata();
            cout << "Enter duration: ";
            cin >> duration;
        }
        void display(){
            Employee::display();
            Project::display();
            cout << "Duration: " << duration << endl;
        }
        int getDuration(){
            return duration;
        }
};

int main(void){
    Emp_Proj emp_proj[100];
    int choice = 0, count = 0;

    while(true){
        cout << "Menu:\n";
        cout << "1. Build a master table\n";
        cout << "2. Display a master table\n";
        cout << "3. Display Project details in the ascending order of duration\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1){
            emp_proj[count].getdata();
            count++;
        }
        else if(choice == 2){
            if(count == 0){
                cout << "Master table is empty\n";
            }
            else{
                for(int i=0; i<count; i++){
                    emp_proj[i].display();
                    cout << endl;
                }
            }
        }
        else if(choice == 3){
            if(count == 0){
                cout << "Master table is empty\n";
            }
            else{
                sort(emp_proj, emp_proj+count, [](Emp_Proj a, Emp_Proj b) { return a.getDuration() < b.getDuration(); });
                for(int i=0; i<count; i++){
                    emp_proj[i].display();
                    cout << endl;
                }
            }
        }
        else if(choice == 4){
            break;
        }
        else{
            cout << "Invalid choice\n";
        }
    }
}

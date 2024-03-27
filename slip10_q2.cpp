// Create a class String which contains a character pointer (Use new and delete operator). Write a
// C++ program to overload following operators:
// a. < To compare length of two strings
// b. == To check equality of two strings
// c. + To concatenate two strings
#include<iostream>
#include<cstring>
using namespace std;

class String {
   private:
      char* str;
   public:
      String() {
         str = new char[1];
         str[0] = '\0';
      }
      String(const char* s) {
         int len = strlen(s);
         str = new char[len+1];
         strcpy(str, s);
      }
      String(const String& s) {
         int len = strlen(s.str);
         str = new char[len+1];
         strcpy(str, s.str);
      }
      ~String() {
         delete [] str;
      }
      int length() const {
         return strlen(str);
      }
      bool operator<(const String& s) const { // < operator overloading
         return (length() < s.length());
      }
      bool operator==(const String& s) const { // == operator overloading
         return (strcmp(str, s.str) == 0);
      }
      String operator+(const String& s) const { // + operator overloading
         int len = strlen(str) + strlen(s.str);
         char* temp = new char[len+1];
         strcpy(temp, str);
         strcat(temp, s.str);
         String res(temp);
         delete [] temp;
         return res;
      }
      void display() const {
         cout << str << endl;
      }
};

int main() {
   String s1("Test");
   String s2("TEST");

   if(s1 < s2) {
      cout << "String 1 is less than String 2\n";
   } else {
      cout << "String 1 is greater than or equal to String 2\n";
   }

   if(s1 == s2) {
      cout << "String 1 is equal to String 2\n";
   } else {
      cout << "String 1 is not equal to String 2\n";
   }
   cout<<"Concatenation of strings : ";
   String s3 = s1 + s2;
   s3.display();

   return 0;
}

// Write a C++ program to display factors of a number. #include <iostream>
using namespace std;

int main(void) {
   int n;

   cout << "Enter a positive integer: ";
   cin >> n;

   cout << "Factors of " << n << " are: ";
   for (int i = 1; i <= n; ++i) {
      if (n % i == 0) {
         cout << i << " ";
      }
   }
}
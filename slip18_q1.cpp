// Write a C++ program to calculate following series:
// (1) + (1+2) + (1+2+3) + (1+2+3+4) + ... +(1+2+3+4+...+n) 
#include <iostream>
using namespace std;

int main(void) {
   int n, inner_sum, i, j;
   cout << "Enter a number: ";
   cin >> n;
   int sum = 0;
   for(i = 1; i <= n; i++) {
     inner_sum = 0;
      for(j = 1; j <= i; j++) {
         inner_sum += j;
      }
      sum += inner_sum;
   }
   cout << "The sum of the series is " << sum << endl;
}

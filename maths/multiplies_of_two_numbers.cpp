#include<bits/stdc++.h>

using namespace std;

int target = 1000;
ll sumOfMultiplies(int n){
  int p = target / n; // p = the number of the mulitplies of n from 1 to target
  // n * ( n + 1 ) / 2 = 1 + 2 + 3 + .... + n
  // so when i multiply it bu p we can get the sum of mulitplies of n
  return p * (n * (n + 1)) / 2;
}
int main(){
  /*we can calculate the sum of multiplies of two numbers by
  using a simple for loop and if the number is divisible by a or b
  we add it to the sum and the time complexity is O(n)*/
  int a = 3, b = 5;
  int sum1 = 0;
  for(int i = 0; i < target; i++)
    if(i % a == 0 || i % b == 0)
      sum1 += i;
  
  /*instead we can calculate the sum in time complexity O(1) using
  inclusion-execlusion principle so we add the sum of the multiplies of a
  and sum of the multiplies of b and substart multiplies of a * b */
  
  int a = 3, b = 5;
  ull sum2 = sumOfMultiplies(a) + sumOfMultiplies(b) - sumOfMultiplies(a * b);
  
  
  return 0;  
}

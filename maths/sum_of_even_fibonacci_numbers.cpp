#include<bits/stdc++.h>

using namespace std;

int main(){
  
  /*  the fibonacci sequence is 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ….
 * so if the nth number of the sequence is even we will add it to the answer*/
    int a = 1, b = 2;
    int c = a + b;
    ull sum = 2;
    while(c <= 4e6){
        if(c % 2 == 0) sum += c;
        a = b;
        b = c;
        c = a + b;
    }
    cout << sum << endl;


//another implementation
    /* if we take a closer look at fibonacci sequence we can find that
     * evey third position in the sequence is even so if take
     * the even numbers we get this sequence 0, 2, 8, 34, 144, 610, 2584…
     * and the sequence following this recursive formula:
     * EFn = 4EFn-1 + EFn-2
     * with seed values
     * EF0 = 0 and EF1 = 2.*/

    int a1= 0, b1 = 2;
    int c1 = 4 * b1 + a1;
    int sum1 = 2;
    while(c1 <= 4e6){
        sum1 += c1;
        a1 = b1;
        b1 = c1;
        c1 = 4 * b1 + a1;
    }
    cout << sum1 << endl;
  
 return 0; 
}

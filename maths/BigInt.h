#ifndef BIGINT_H
#define BIGINT_H

using namespace std;

const int MAX = 300;

class BigInt{

private:
    int big[MAX]{};

public:

    //constructors
    BigInt(){}
    BigInt(string& s) {
        int n = s.size() - 1;
        for (int i = n; i >= 0; i--)
            big[n - i] = s[i] - '0';
    }

    BigInt(int x) {
        int i = 0;
        while(x){
            big[i++] = x % 10;
            x /= 10;
        }
    }

    BigInt(BigInt& a):BigInt(){ //copy constructor
        for(int i = 0; i < MAX; i++)
            big[i] = a.big[i];
    }


    //destructor
    ~BigInt(){
        for(int & i : big)
            i = 0;
    }


    //member functions
    int length(){
        int j = MAX - 1;
        while(big[j] == 0){
            j--;
        }
        return j + 1;
    }

    void print(){
        int n  = length();
        for(int i = n - 1;i>=0;i--){
            cout << big[i];
        }
        cout << "\n";
    }

    int cmp(const BigInt& a){
        int i;
        for (i=MAX-1 ; i>=0 ; i--)
        {
            if (a.big[i] < big[i])
                return 1;
            else if (a.big[i] > big[i])
                return -1;
        }
        return 0;
    }
    int cmp(int a){
        BigInt temp(a);
        return cmp(temp);
    }

    BigInt& operator=(const BigInt& a){
        for(int i = 0; i < MAX; i++)
            big[i] = a.big[i];
        return *this;
    }

    BigInt operator+(BigInt a){
        BigInt res;
        int i, carry = 0;
        for(i = 0; i < MAX; i++){
            res.big[i] = carry + big[i] + a.big[i];
            carry = res.big[i] / 10;
            res.big[i] %= 10;
        }
        return res;
    }

    BigInt operator+(int a){
        BigInt res;
        for(int i = 0; i < MAX; i++){
            res.big[i] = a + big[i];
            a = res.big[i] / 10;
            res.big[i] %= 10;
        }
        return res;
    }

    BigInt operator*(int a){
        BigInt res;
        int carry = 0;
        for(int i = 0; i < MAX; i++){
            res.big[i] = big[i] * a + carry;
            carry = res.big[i] / 10;
            res.big[i] %= 10;
        }
        return res;
    }

    BigInt operator*(BigInt a){
        BigInt res;
        int carry = 0, posi= 0, posj=0;
        for(int i = 0; i < MAX; posj=0,posi++, i++){
            for(int j = 0; j < MAX;posj++, j++) {
                res.big[posi+posj] += big[i] * a.big[j] + carry;
                carry = res.big[posi+posj] / 10;
                res.big[posi+posj] %= 10;
            }
        }
        return res;
    }

    BigInt operator-(BigInt a){
        BigInt res;
        if(this->cmp(a) < 0){
            for (int i = 0; i < MAX; i++){
                res.big[i] = a.big[i] - big[i];
            }
            for (int i = 0; i < MAX; i++){
                while(res.big[i] < 0){
                    res.big[i] += 10;
                    res.big[i + 1] -= 1;
                }
            }
            res.big[res.length()-1]*=-1;
        }
        else{
            for (int i = 0; i < MAX; i++){
                res.big[i] = big[i] - a.big[i];
            }
            for (int i = 0; i < MAX; i++){
                while(res.big[i] < 0){
                    res.big[i] += 10;
                    res.big[i + 1] -= 1;
                }
            }
        }
        return res;
    }
    BigInt operator-(int a) {
        BigInt res;
        int i = 0;
        for (i = 0; i < MAX && a; i++) {
            int carry = a % 10;
            a /= 10;
            while (big[i] < carry) {
                big[i] += 10;
                big[i + 1] -= 1;
            }
            res.big[i] = big[i] - carry;
        }
        for(; i < MAX; i++){
            res.big[i] = big[i];
        }
        return res;
    }

    BigInt operator/(int div) {
        int i = length();
        BigInt reminder;
        int carry = 0;

        while (i >= 0)
        {
            reminder.big[i] = big[i];
            carry *= 10;
            carry += big[i];
            big[i] = 0;

            if (reminder.cmp(div) >= 0)
            {
                big[i] = carry / div;
                carry %= div;
            }
            i--;
        }
        return reminder;
    }
};

#endif

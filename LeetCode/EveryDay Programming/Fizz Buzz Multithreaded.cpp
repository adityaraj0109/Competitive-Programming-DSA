#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int i;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->i=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (i<=n){
            {
            unique_lock<mutex>lock(m);
            while(i<=n && !(i%3==0 && i%5!=0)) cv.wait(lock);
            if(i<=n){
                printFizz();
                i++;
            }
            cv.notify_all();
        }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (i<=n){
            unique_lock<mutex>lock(m);
            while(i<=n && !(i%3!=0 && i%5==0)) cv.wait(lock);
            if(i<=n){
                printBuzz();
                i++;
            }
            cv.notify_all();
        } 
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (i<=n){
            unique_lock<mutex>lock(m);
            while(i<=n && !(i%3==0 && i%5==0)) cv.wait(lock);
            if(i<=n){
                printFizzBuzz();
                i++;
            }
            cv.notify_all();
        }         
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (i<=n){
            unique_lock<mutex>lock(m);
            while(i<=n && !(i%3!=0 && i%5!=0)) cv.wait(lock);
            if(i<=n){
                printNumber(i++);
            }
            cv.notify_all();
        }         
    }
};

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

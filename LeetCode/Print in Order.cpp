#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Foo {
    mutex m;
    condition_variable cv;
    int turn;

    public: 
        Foo()
        {
            turn=0;
        }

        void first(function<void()> printFirst)
        {
            printFirst();
            turn=1;
            cv.notify_all();
        }

        void second(function<void()> printSecond)
        {
            unique_lock<mutex>lock(m);
            while (turn!=1) cv.wait(lock);
            printSecond();
            turn = 2;
            cv.notify_all();
        }

        void third(function<void()> printThird)
        {
            unique_lock<mutex>lock(m);
            while (turn != 2) cv.wait(lock);
            printThird();
        }
};

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

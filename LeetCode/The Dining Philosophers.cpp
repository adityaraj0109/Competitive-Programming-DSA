#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Semaphore{
    mutex m;
    condition_variable cv;
    int count;
public:
    Semaphore(){};
    Semaphore(int c): count(c){};

    void setCount(int a){
        count=a;
    }

    inline void signal(){
        count++;
        if(count<=0) cv.notify_one();
    }

    inline void wait(){
        unique_lock<mutex> lock(m);
        count--;
        while(count<0) cv.wait(lock);
    }
};

class DiningPhilosophers {
    Semaphore fork[5];
    mutex m,l;
public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; i++)
        {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		lock_guard<mutex>lock(m);
        fork[(philosopher+1)%5].wait();
        fork[philosopher].wait();

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();
    }
};

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

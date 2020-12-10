#include <iostream>
#include <tr1/memory>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mtx;

void lockMutex(std::mutex *p);
void unlockMutex(std::mutex *p);
void printChar(char c, int n);

//handle copying behaviour by performing reference counting
//we want to unlock the mutex when the reference count reaches 0
//in case of Lock object being copied, the number of objects (mPtr smart pointers)
//referring to the resource (the mutex) is incremented
class Lock{
    public:
        explicit Lock(std::mutex *p)
        :mPtr(p, unlockMutex)
        {
            lockMutex(mPtr.get());
        }
    private:
        std::tr1::shared_ptr<std::mutex> mPtr;
};


int main(){
    std::thread t1(printChar, 'a', 15);
    std::thread t2(printChar, 'b', 10);

    t1.join();
    t2.join();

    return 0;
}


void lockMutex(std::mutex *p){
    cout<<"Locking the mutex...\n\n";
    p->lock();
}

void unlockMutex(std::mutex *p){
    cout<<"\n\nUnlocking the mutex...\n\n";
    p->unlock();
}

void printChar(char c, int n){
    Lock mLock(&mtx);

    for( int i = 0; i < n; i++ )
        cout<<c;
    cout<<"\n";
}
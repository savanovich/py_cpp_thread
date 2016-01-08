#include "twait.h"

using namespace std;

condition_variable CondVar;
mutex my_mutex;
bool predicate = false;

/* The C++11 documentation guarantees that this function is always
   called with the mutex that protects "predicate", locked. This
   is why there is no critical section here. */
bool MyPred()
{
    bool retval = predicate;
    return retval;
}

void worker_thread()
{
    cout << "[WorkerThread] I/O operation started " << endl;

    chrono::duration<int, milli> delay(5000);
    this_thread::sleep_for(delay);

    {
        unique_lock<mutex> lock(my_mutex);
        predicate = true;
    }

    CondVar.notify_one();

    cout << "[WorkerThread] I/O operation terminated " << endl;
}

void start_io_thread()
{
    bool retval;

    chrono::duration<int, milli> delay(1000);

    thread T(worker_thread);
    T.detach();

    /* The wait function returns !=0 only if the wait is not spureous
       and the waited event has actually happened. */
    do
    {
        unique_lock<std::mutex> my_lock(my_mutex);
        retval = CondVar.wait_for<int, milli>(my_lock, delay, MyPred);
        if (!retval)
            cout << "[MainThread] Timed out after 1 second" << endl;

    } while(!retval);

    cout << "[MainThread] Wait terminated " << endl;
}

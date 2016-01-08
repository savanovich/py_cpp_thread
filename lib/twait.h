#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

extern "C" {
    void start_io_thread();
}

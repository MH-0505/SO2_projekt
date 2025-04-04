#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>
#include <atomic>

#include "Philosopher.h"
#include "Fork.h"
using namespace std::chrono_literals;

int p_num;          // philosophers number
int time_limit;     // execution time in seconds

int main(int argc, char *argv[]) {
    if (argc < 2) {
        p_num = 5;
        time_limit = 30;
    } else if (argc == 2){
        p_num = std::stoi(argv[1]);
        time_limit = 30;
    } else{
        p_num = std::stoi(argv[1]);
        time_limit = std::stoi(argv[2]);
    }

    std::atomic<bool> stop_flag(false);
    std::vector<std::unique_ptr<Fork>> forks;

    for(int i = 0; i < p_num; i++){
        forks.push_back(std::make_unique<Fork>(i));
    }
    std::vector<Philosopher> philosophers;
    std::vector<std::thread> threads;

    static std::counting_semaphore<> dining_limit(p_num-1);

    for(int i = 0; i < p_num; i++){
        philosophers.emplace_back(i);
    }

    for(int i = 0; i < p_num; i++){
        threads.emplace_back(&Philosopher::loop_static, &philosophers[i], std::ref(forks), p_num, std::ref(dining_limit), std::ref(stop_flag));
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    while(true){
        std::this_thread::sleep_for(1s);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time;
        int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed_time).count();

        if (elapsed_seconds >= time_limit){
            stop_flag = true;
            break;
        }
    }

    for(int i = 0; i < p_num; i++){
        threads[i].join();
    }


    std::cout << "\nTime limit reached.\nSimulation results:";
    std::cout << "\n                      Times eaten";

    for(int i = 0; i < p_num; i++){
        std::printf("\nPhilosopher [ %3d ]      %8d", i, philosophers[i].times_eaten);
    }

    return 0;
}

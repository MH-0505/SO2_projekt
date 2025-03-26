#include <iostream>
#include <vector>
#include <thread>
#include <semaphore>
#include "Philosopher.h"
#include "Fork.h"

using namespace std::chrono_literals;

Philosopher::Philosopher() = default;

Philosopher::Philosopher(int index) {
    id = index;
    times_eaten = 0;
    state = State::THINKING;
}

void Philosopher::loop(std::vector<std::unique_ptr<Fork>>& forks, int N) {
    while (true) {
        think();
        eat(forks, N);
    }
}

void Philosopher::loop_static(Philosopher* that, std::vector<std::unique_ptr<Fork>>& forks, int N) {
    that->loop(forks, N);
}

void Philosopher::think() {
    state = State::THINKING;
    std::printf("Philosopher [%d] is thinking.\n", id);
    std::this_thread::sleep_for(200ms);
}

void Philosopher::eat(std::vector<std::unique_ptr<Fork>>& forks, int N) {
    static std::counting_semaphore<> dining_limit(N-1);
    int left_fork_id = id;
    int right_fork_id = (id + 1) % N;

    state = State::HUNGRY;
    std::printf("Philosopher [%d] is hungry.\n", id);

    dining_limit.acquire();

    forks[left_fork_id]->mutex.lock();
    forks[right_fork_id]->mutex.lock();
    std::printf("Philosopher [%d] picked up forks (%d, %d).\n", id, left_fork_id, right_fork_id);


    state = State::EATING;
    std::printf("Philosopher [%d] is eating.\n", id);
    times_eaten++;
    std::this_thread::sleep_for(200ms);

    std::printf("Philosopher [%d] put down forks (%d, %d).\n", id, left_fork_id, right_fork_id);
    forks[right_fork_id]->mutex.unlock();
    forks[left_fork_id]->mutex.unlock();

    dining_limit.release();
}



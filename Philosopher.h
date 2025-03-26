#ifndef PROJEKT_1_PHILOSOPHER_H
#define PROJEKT_1_PHILOSOPHER_H

#include <atomic>
#include "Fork.h"

enum State {THINKING, HUNGRY, EATING};

class Philosopher {
public:
    State state;
    int id{};
    int times_eaten;

    Philosopher();
    explicit Philosopher(int index);

    void loop(std::vector<std::unique_ptr<Fork>>& forks, int N, std::counting_semaphore<>& dining_limit, std::atomic<bool>& stop_flag);
    static void loop_static(Philosopher* that, std::vector<std::unique_ptr<Fork>>& forks, int N, std::counting_semaphore<>& dining_limit, std::atomic<bool>& stop_flag);
    void think();
    void eat(std::vector<std::unique_ptr<Fork>>& forks, int N, std::counting_semaphore<>& dining_limit);
};


#endif //PROJEKT_1_PHILOSOPHER_H

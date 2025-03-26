#ifndef PROJEKT_1_PHILOSOPHER_H
#define PROJEKT_1_PHILOSOPHER_H


#include "Fork.h"

enum State {THINKING, HUNGRY, EATING};

class Philosopher {
public:
    State state;
    int id{};
    int times_eaten;

    Philosopher();
    explicit Philosopher(int index);

    void loop(std::vector<std::unique_ptr<Fork>>& forks, int N);
    static void loop_static(Philosopher* that, std::vector<std::unique_ptr<Fork>>& forks, int N);
    void think();
    void eat(std::vector<std::unique_ptr<Fork>>& forks, int N);
};


#endif //PROJEKT_1_PHILOSOPHER_H

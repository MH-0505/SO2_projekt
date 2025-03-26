#ifndef PROJEKT_1_FORK_H
#define PROJEKT_1_FORK_H
#include <mutex>

class Fork {
public:
    int id;
    std::mutex mutex;

    Fork();
    Fork(int index);
};


#endif //PROJEKT_1_FORK_H

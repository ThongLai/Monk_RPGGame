//
// Created by Mike on 19/03/2019.
//

#ifndef MONKASSIGNMENT_RANDOMCONTROLLER_H
#define MONKASSIGNMENT_RANDOMCONTROLLER_H


#include <random>

class RandomController {
private:
    std::random_device rd;

public:
    int getRandomIndex(int,int);
};


#endif //MONKASSIGNMENT_RANDOMCONTROLLER_H

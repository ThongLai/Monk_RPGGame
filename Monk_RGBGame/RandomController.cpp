//
// Created by Mike on 19/03/2019.
//

#include "RandomController.h"

int RandomController::getRandomIndex(int from, int to) {
    static std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr (from, to);

    return distr(eng);
}

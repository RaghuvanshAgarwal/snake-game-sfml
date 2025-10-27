//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#ifndef SNAKE_GAME_LEVELDATA_H
#define SNAKE_GAME_LEVELDATA_H
#include "LevelNumber.h"

namespace Level {
    struct LevelData {
        explicit LevelData(LevelNumber ind) {
            level_index = ind;
        }
        LevelNumber level_index;
    };
}
#endif //SNAKE_GAME_LEVELDATA_H
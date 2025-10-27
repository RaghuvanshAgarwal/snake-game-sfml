//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#ifndef SNAKE_GAME_LEVELMODEL_H
#define SNAKE_GAME_LEVELMODEL_H
#include <vector>

#include "LevelData.h"

namespace Level {
    class LevelModel {
        std::vector<LevelData> level_configurations;

        float cell_width = 0.f;
        float cell_height = 0.f;
    public:
        static constexpr int number_of_rows = 28;
        static constexpr int number_of_columns = 50;

        LevelModel();
        ~LevelModel();

        void initialize(int width, int height);

        float getCellWidth() const;
        float getCellHeight() const;

    };
} // Level

#endif //SNAKE_GAME_LEVELMODEL_H

//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#include "../../include/Level/LevelModel.h"

namespace Level {
    LevelModel::LevelModel() = default;

    LevelModel::~LevelModel() = default;

    void LevelModel::initialize(int width, int height) {
        cell_width = width / number_of_columns;
        cell_height = height / number_of_rows;
    }

    float LevelModel::getCellWidth() const {
        return cell_width;
    }

    float LevelModel::getCellHeight() const {
        return cell_height;
    }
} // Level
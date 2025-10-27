//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#include "../../include/Level/LevelController.h"

#include "../../include/Level/LevelView.h"
#include "../../include/Level/LevelModel.h"

namespace Level {
    LevelController::LevelController() {
        level_view = new LevelView();
        level_model = new LevelModel();
        initialize();
    }

    LevelController::~LevelController() {
        delete level_model;
        delete level_view;
    }

    void LevelController::initialize() {
        level_view->initialize();
        level_model->initialize(static_cast<int>(level_view->getGridWidth()) , static_cast<int>(level_view->getGridHeight()));
    }

    void LevelController::update() {
        level_view->update();
    }

    void LevelController::render() {
        level_view->render();
    }

    float LevelController::getCellWidth() const {
        return level_model->getCellWidth();
    }

    float LevelController::getCellHeight() const {
        return level_model->getCellHeight();
    }
} // Level
//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#include "../../include/Level/LevelService.h"
#include "../../include/Level/LevelController.h"

namespace Level {

    LevelService::LevelService() {
        level_controller = nullptr;
        createLevelController();
    }

    LevelService::~LevelService() {
        destroy();
    }

    void LevelService::initialize() {
        level_controller->initialize();
    }

    void LevelService::update() {
        level_controller->update();
    }

    void LevelService::render() {
        level_controller->render();
    }

    void LevelService::createLevel(const LevelNumber level_to_load) {
        current_level = level_to_load;
    }

    void LevelService::createLevelController() {
        level_controller = new LevelController();
    }

    void LevelService::destroy() const {
        delete level_controller;
    }

} // Level
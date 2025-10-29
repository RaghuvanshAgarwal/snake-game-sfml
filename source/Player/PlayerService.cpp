//
// Created by Raghuvansh Agarwal on 27/10/25.
//

#include "../../include/Player/PlayerService.h"

#include "../../include/Player/SnakeController.h"

namespace Player {

    PlayerService::PlayerService() {
        createSnakeController();
    }

    PlayerService::~PlayerService() {
        delete snake_controller;
    }

    void PlayerService::initialize() {
        snake_controller->initialize();
    }

    void PlayerService::update() {
        snake_controller->update();
    }

    void PlayerService::render() {
        snake_controller->render();
    }

    void PlayerService::spawnPlayer() {
        snake_controller->spawnSnake();
    }

    void PlayerService::createSnakeController() {
        snake_controller = new SnakeController();
    }
} // Player
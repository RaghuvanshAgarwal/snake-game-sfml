//
// Created by Raghuvansh Agarwal on 27/10/25.
//

#include "../../include/Player/SnakeController.h"

#include <iostream>
#include <ostream>

namespace Player {
    void SnakeController::processPlayerInput() {
    }

    void SnakeController::updateSnakeDirection() {
    }

    void SnakeController::moveSnake() {
    }

    void SnakeController::processSnakeCollision() {
    }

    void SnakeController::handleRestart() {
    }

    void SnakeController::reset() {
    }

    void SnakeController::respawnSnake() {
    }

    void SnakeController::setSnakeState(SnakeState state) {
        snake_state = state;
    }

    SnakeState SnakeController::getSnakeState() const {
        return snake_state;
    }

    void SnakeController::spawnSnake() {
    }

    SnakeController::SnakeController() {
    }

    SnakeController::~SnakeController() {
    }

    void SnakeController::initialize() {
    }

    void SnakeController::update() {
        switch (getSnakeState()) {
            default:
                std::cerr << "Unknown SnakeState" << std::endl;
                break;
            case SnakeState::ALIVE:
                processPlayerInput();
                moveSnake();
                processSnakeCollision();
                break;
            case SnakeState::DEAD:
                handleRestart();
                break;
        }
    }

    void SnakeController::render() {
    }
} // Player
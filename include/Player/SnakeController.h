//
// Created by Raghuvansh Agarwal on 27/10/25.
//

#ifndef SNAKE_GAME_SNAKECONTROLLER_H
#define SNAKE_GAME_SNAKECONTROLLER_H
#include "Direction.h"
#include "SFML/System/Vector2.hpp"

namespace Player {
    enum class SnakeState {
        ALIVE,
        DEAD
    };
    class SnakeController {
        const int initial_snake_length = 10;
        const Direction default_direction = Direction::RIGHT;
        const sf::Vector2u default_snake_position = sf::Vector2u(25, 13);

        SnakeState snake_state = SnakeState::ALIVE;
        Direction current_snake_direction = default_direction;

        void processPlayerInput();
        void updateSnakeDirection();
        void moveSnake();
        void processSnakeCollision();
        void handleRestart();
        void reset();
    public:
        SnakeController(); // Default constructor
        ~SnakeController(); // Destructor

        void initialize(); // To be called when the object is created
        void update(); // To be called on every frame
        void render(); // To be called on every frame

        void spawnSnake();
        void respawnSnake();
        void setSnakeState(SnakeState state);
        [[nodiscard]]SnakeState getSnakeState() const;
    };
} // Player

#endif //SNAKE_GAME_SNAKECONTROLLER_H

//
// Created by Raghuvansh Agarwal on 27/10/25.
//

#ifndef SNAKE_GAME_SNAKECONTROLLER_H
#define SNAKE_GAME_SNAKECONTROLLER_H

namespace Player {
    class SnakeController {
    public:
        SnakeController(); // Default constructor
        ~SnakeController(); // Destructor

        void initialize(); // To be called when the object is created
        void update(); // To be called on every frame
        void render(); // To be called on every frame
    };
} // Player

#endif //SNAKE_GAME_SNAKECONTROLLER_H

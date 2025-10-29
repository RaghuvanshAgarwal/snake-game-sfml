//
// Created by Raghuvansh Agarwal on 27/10/25.
//

#ifndef SNAKE_GAME_PLAYERSERVICE_H
#define SNAKE_GAME_PLAYERSERVICE_H

namespace Player {
    class PlayerService {
        class SnakeController* snake_controller = nullptr;
        void createSnakeController();
    public:
        PlayerService(); // Default constructor
        ~PlayerService(); // Destructor

        void initialize(); // To be called when the object is created
        void update(); // To be called on every frame
        void render(); // To be called on every frame

        void spawnPlayer();
    };
} // Player

#endif //SNAKE_GAME_PLAYERSERVICE_H

//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#ifndef SNAKE_GAME_LEVELCONTROLLER_H
#define SNAKE_GAME_LEVELCONTROLLER_H

namespace Level {
    class LevelController {
        public:
        LevelController(); // Default constructor
        ~LevelController(); // Destructor

        void initialize(); // To be called when the object is created
        void update(); // To be called on every frame
        void render(); // To be called on every frame
    };
} // Level

#endif //SNAKE_GAME_LEVELCONTROLLER_H

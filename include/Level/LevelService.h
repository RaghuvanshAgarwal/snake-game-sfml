//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#ifndef SNAKE_GAME_LEVELSERVICE_H
#define SNAKE_GAME_LEVELSERVICE_H
#include "LevelNumber.h"

namespace Level {
    class LevelController;
    class LevelService {

        LevelController* level_controller;
        LevelNumber current_level = LevelNumber::ONE;

        void createLevelController();
        void destroy() const;

        public:
        LevelService(); // Default constructor
        ~LevelService(); // Destructor
        void initialize(); // To be called when the object is created
        void update(); // To be called on every frame
        void render(); // To be called on every frame

        void createLevel(LevelNumber level_to_load);
    };
} // Level

#endif //SNAKE_GAME_LEVELSERVICE_H

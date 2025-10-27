//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#ifndef SNAKE_GAME_LEVELCONTROLLER_H
#define SNAKE_GAME_LEVELCONTROLLER_H


namespace Level {
    class LevelController {
        class LevelModel* level_model = nullptr;
        class LevelView* level_view = nullptr;
        public:
        LevelController(); // Default constructor
        ~LevelController(); // Destructor

        void initialize(); // To be called when the object is created
        void update(); // To be called on every frame
        void render(); // To be called on every frame

        float getCellWidth() const;
        float getCellHeight() const;

    };
} // Level

#endif //SNAKE_GAME_LEVELCONTROLLER_H

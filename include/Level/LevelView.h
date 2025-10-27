//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#ifndef SNAKE_GAME_LEVELVIEW_H
#define SNAKE_GAME_LEVELVIEW_H
#include "../UI/UIElement/AnimatedImageView.h"
#include "SFML/Graphics.hpp"

namespace UI::UIElement {
    class RectangleShapeView;
}

namespace Level {


    class LevelView {
        const sf::Color background_color = sf::Color(180,200,160);
        const sf::Color border_color = sf::Color::Black;

        UI::UIElement::RectangleShapeView* background_rectangle;
        UI::UIElement::RectangleShapeView* border_rectangle;

        float grid_width = 0.f;
        float grid_height = 0.f;

        void initializeBackground();
        void initializeBorder();
        void calculateGridExtents();

        public:
        static constexpr int border_thickness = 10;
        static constexpr int border_offset_left = 40;
        static constexpr int border_offset_top = 40;
        LevelView(); // Default constructor
        ~LevelView(); // Destructor

        void initialize(); // To be called when the object is created
        void update(); // To be called on every frame
        void render(); // To be called on every frame

        [[nodiscard]] float getGridWidth() const;
        [[nodiscard]] float getGridHeight() const;
    };
} // Level

#endif //SNAKE_GAME_LEVELVIEW_H

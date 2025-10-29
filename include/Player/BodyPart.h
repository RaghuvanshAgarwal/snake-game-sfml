//
// Created by Raghuvansh Agarwal on 29/10/25.
//

#ifndef SNAKE_GAME_BODYPART_H
#define SNAKE_GAME_BODYPART_H
#include "Direction.h"
#include "SFML/System/Vector2.hpp"

namespace UI::UIElement {
    class ImageView;
}

namespace Player {
    class BodyPart {
        UI::UIElement::ImageView *body_part_image = nullptr;
        sf::Vector2i grid_position = sf::Vector2i(0, 0);
        Direction direction = Direction::RIGHT;
        float body_part_width = 0.f;
        float body_part_height = 0.f;

        [[nodiscard]] sf::Vector2f getBodyPartScreenPosition() const;
        [[nodiscard]] float getRotationAngle() const;
        void createBodyPartImage();
        void initializeBodyPartImage() const;

    public:
        BodyPart(); // Default constructor
        ~BodyPart(); // Destructor
        void initialize(float width,float height, sf::Vector2i pos, Direction dir);
        void update();
        void render() const; // To be called on every frame

        void setDirection(Direction dir);
        void updatePosition();
    };
} // Player

#endif //SNAKE_GAME_BODYPART_H

//
// Created by Raghuvansh Agarwal on 29/10/25.
//

#include "../../include/Player/BodyPart.h"

#include "../../include/Global/Config.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelView.h"
#include "../../include/UI/UIElement/ImageView.h"

namespace Player {
    using namespace UI::UIElement;
    void BodyPart::createBodyPartImage() {
        body_part_image = new ImageView();
    }

    void BodyPart::initializeBodyPartImage() const {
        body_part_image->initialize(Global::Config::snake_body_texture_path, body_part_width,body_part_height,getBodyPartScreenPosition());
        body_part_image->setCentreAlinged();
    }

    BodyPart::BodyPart() {
        grid_position = sf::Vector2i(0, 0);
        createBodyPartImage();
    }

    BodyPart::~BodyPart() {
        delete body_part_image;
    }

    void BodyPart::initialize(const float width, const float height, sf::Vector2i pos, Direction dir) {
        direction = dir;
        grid_position = pos;
        body_part_width = width;
        body_part_height = height;
        initializeBodyPartImage();
    }

    void BodyPart::update() {

    }

    void BodyPart::render() const {
        body_part_image->render();
    }

    void BodyPart::setDirection(const Direction dir) {
        direction = dir;
    }

    void BodyPart::updatePosition() {
        body_part_image->setPosition(getBodyPartScreenPosition());
        body_part_image->setRotation(getRotationAngle());
        body_part_image->update();
    }

    sf::Vector2f BodyPart::getBodyPartScreenPosition() const {
        float x = Level::LevelView::border_offset_left + (grid_position.x * body_part_width) + (body_part_width * 0.5f);
        float y = Level::LevelView::border_offset_top + (grid_position.y * body_part_height) + (body_part_height * 0.5f);
        return sf::Vector2f(x, y);
    }

    float BodyPart::getRotationAngle() const {
        switch (direction) {
            default:
            case Direction::UP:
                return 270;
            case Direction::DOWN:
                return 90;
            case Direction::LEFT:
                return 180;
            case Direction::RIGHT:
                return 0;
        }
    }
} // Player
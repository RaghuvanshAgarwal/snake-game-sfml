//
// Created by Raghuvansh Agarwal on 29/10/25.
//

#include "../../include/Player/BodyPart.h"

#include "../../include/Global/Config.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/UI/UIElement/ImageView.h"

namespace Player {
    using namespace UI::UIElement;
    void BodyPart::createBodyPartImage() {
        body_part_image = new ImageView();
    }

    void BodyPart::initializeBodyPartImage() {
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

    sf::Vector2f BodyPart::getBodyPartScreenPosition() {
        Global::ServiceLocator::getInstance()->getLevelService()->
    }
} // Player
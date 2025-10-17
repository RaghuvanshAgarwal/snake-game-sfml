//
// Created by Raghuvansh Agarwal on 16/10/25.
//

#include "../../include/Level/LevelView.h"

#include "../../include/Global/ServiceLocator.h"
#include "../../include/UI/UIElement/RectangleShapeView.h"

namespace Level {
    using namespace UI::UIElement;
    using namespace Global;

    LevelView::LevelView() {
        initialize();
    }

    LevelView::~LevelView() {
        delete background_rectangle;
        delete border_rectangle;
    }

    void LevelView::initialize() {
        calculateGridExtents();
        initializeBackground();
        initializeBorder();
    }

    void LevelView::update() {
        background_rectangle->update();
        border_rectangle->update();
    }

    void LevelView::render() {
        background_rectangle->render();
        border_rectangle->render();
    }

    float LevelView::getGridWidth() const {
        return grid_width;
    }

    float LevelView::getGridHeight() const {
        return grid_height;
    }

    void LevelView::initializeBackground() {
        const sf::RenderWindow* window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        const auto size = static_cast<sf::Vector2f>(window->getSize());
        background_rectangle = new RectangleShapeView();
        background_rectangle->initialize(size,{0,0},0,background_color);
        background_rectangle->show();
    }

    void LevelView::calculateGridExtents() {
        const sf::RenderWindow* window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        grid_width = static_cast<float>(window->getSize().x) - ((border_offset_left + border_thickness) * 2);
        grid_height = static_cast<float>(window->getSize().y) - ((border_offset_top + border_thickness) * 2);
    }

    void LevelView::initializeBorder() {
        const auto border_size = sf::Vector2f(grid_width, grid_height);
        const auto border_position = sf::Vector2f(border_offset_left, border_offset_top);
        border_rectangle = new RectangleShapeView();
        border_rectangle->initialize(border_size,border_position,border_thickness,sf::Color::Transparent, border_color );
        border_rectangle->show();
    }
} // Level
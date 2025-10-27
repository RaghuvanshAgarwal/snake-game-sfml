//
// Created by Raghuvansh Agarwal on 27/10/25.
//

#include "../../../include/UI/LevelSelection/LevelSelectionUIController.h"

#include "../../../include/Global/Config.h"
#include "../../../include/Global/ServiceLocator.h"
#include "../../../include/UI/UIElement/ImageView.h"
#include "../../../include/UI/UIElement/ButtonView.h"

namespace UI::LevelSelection {


    LevelSelectionUIController::LevelSelectionUIController() {
        createBackgroundImage();
        createButtons();
    }

    LevelSelectionUIController::~LevelSelectionUIController() {
        delete background_image;
        delete level_one_button;
        delete level_two_button;
        delete menu_button;
    }



    void LevelSelectionUIController::initialize() {
        initializeBackground();
        initializeButtons();
        registerButtonCallbacks();
    }

    void LevelSelectionUIController::update() {
        background_image->update();
        level_one_button->update();
        level_two_button->update();
        menu_button->update();
    }

    void LevelSelectionUIController::render() {
        background_image->render();
        level_one_button->render();
        level_two_button->render();
        menu_button->render();
    }

    void LevelSelectionUIController::show() {
        background_image->show();
        level_one_button->show();
        level_two_button->show();
        menu_button->show();
    }


    float LevelSelectionUIController::calculateLeftOffsetForButton() const {
        float game_width = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;
        return (game_width * 0.5f) - (button_width * 0.5f);
    }

    void LevelSelectionUIController::createBackgroundImage() {
        background_image = new UIElement::ImageView();
    }

    void LevelSelectionUIController::createButtons() {
        level_one_button = new UIElement::ButtonView();
        level_two_button = new UIElement::ButtonView();
        menu_button = new UIElement::ButtonView();
    }

    void LevelSelectionUIController::initializeBackground() const {
        sf::Vector2u window_size = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();
        background_image->initialize(Global::Config::background_texture_path,window_size.x, window_size.y, {0,0});
    }

    void LevelSelectionUIController::initializeButtons() const {
        float xOffset = calculateLeftOffsetForButton();
        level_one_button->initialize("Level One", Global::Config::level_one_button_texture_path, button_width, button_height, {xOffset,level_one_button_y_position});
        level_two_button->initialize("Level Two", Global::Config::level_two_button_texture_path, button_width, button_height, {xOffset,level_two_button_y_position});
        menu_button->initialize("Menu", Global::Config::menu_button_texture_path, button_width, button_height, {xOffset,menu_button_y_position});
    }

    void LevelSelectionUIController::registerButtonCallbacks() {
        level_one_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::singleLinkedButtonCallback, this));
        level_two_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::doubleLinkedButtonCallback, this));
        menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menuButtonCallback, this));
    }

    void LevelSelectionUIController::singleLinkedButtonCallback() {
    }

    void LevelSelectionUIController::doubleLinkedButtonCallback() {
    }

    void LevelSelectionUIController::menuButtonCallback() {
    }
} // LevelSelection
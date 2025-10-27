//
// Created by Raghuvansh Agarwal on 27/10/25.
//

#ifndef SNAKE_GAME_LEVELSELECTIONUICONTROLLER_H
#define SNAKE_GAME_LEVELSELECTIONUICONTROLLER_H
#include "../Interface/IUIController.h"


namespace UI::UIElement {
    class ImageView;
    class ButtonView;
}

namespace UI::LevelSelection {

    class LevelSelectionUIController : public Interface::IUIController {

        const float button_width = 400.f;
        const float button_height = 140.f;

        const float level_one_button_y_position = 500.f;
        const float level_two_button_y_position = 700.f;
        const float menu_button_y_position = 900.f;

        const float background_alpha = 85.f;

        UIElement::ImageView* background_image = nullptr;
        UIElement::ButtonView* level_one_button = nullptr;
        UIElement::ButtonView* level_two_button = nullptr;
        UIElement::ButtonView* menu_button = nullptr;

        [[nodiscard]] float calculateLeftOffsetForButton() const;

        void createBackgroundImage();
        void createButtons();
        void initializeBackground() const;
        void initializeButtons() const;

        void registerButtonCallbacks();
        void levelOneButtonCallback();
        void levelTwoButtonCallback();
        void menuButtonCallback();

    public:
        LevelSelectionUIController(); // Default constructor
        ~LevelSelectionUIController() override; // Destructor

        void initialize() override; // To be called when the object is created
        void update() override; // To be called on every frame
        void render() override; // To be called on every frame
        void show() override;
    };
} // LevelSelection

#endif //SNAKE_GAME_LEVELSELECTIONUICONTROLLER_H

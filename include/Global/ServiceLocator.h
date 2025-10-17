#pragma once
#include "../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../UI/UIService.h"
#include "../Sound/SoundService.h"
#include "../Time/TimeService.h"
#include "../Level/LevelService.h"


namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Level::LevelService* level_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService() const;
        Graphics::GraphicService* getGraphicService() const;
        Sound::SoundService* getSoundService() const;
        UI::UIService* getUIService() const;
        Time::TimeService* getTimeService() const;
        Level::LevelService *getLevelService() const;

        void deleteServiceLocator() const;
    };
}

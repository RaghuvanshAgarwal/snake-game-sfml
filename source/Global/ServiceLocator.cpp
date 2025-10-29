#include "../../include/Global/ServiceLocator.h"

#include "../../include/Main/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Time;
	using namespace Level;
	using namespace Player;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		time_service = nullptr;
		level_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		sound_service = new SoundService();
		ui_service = new UIService();
		time_service = new TimeService();
		level_service = new LevelService();
		player_service = new PlayerService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		ui_service->initialize();
		time_service->initialize();
		level_service->initialize();
		player_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		ui_service->update();
		time_service->update();
		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY) {
			level_service->update();
			player_service->update();
		}
	}

	void ServiceLocator::render()
	{
		ui_service->render();
		graphic_service->render();
		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY) {
			level_service->render();
			player_service->render();
		}
	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(graphic_service);
		delete(sound_service);
		delete(event_service);
		delete(time_service);
		delete(level_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() const { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() const { return graphic_service; }

	SoundService* ServiceLocator::getSoundService() const { return sound_service; }

	UIService* ServiceLocator::getUIService() const { return ui_service; }

	TimeService* ServiceLocator::getTimeService() const { return time_service; }

	LevelService* ServiceLocator::getLevelService() const { return level_service; }

	Player::PlayerService * ServiceLocator::getPlayerService() const { return player_service; }

	void ServiceLocator::deleteServiceLocator() const { delete(this); }
}

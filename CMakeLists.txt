cmake_minimum_required(VERSION 3.28)
project("Snake Game" LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(snake_game main.cpp
        include/Event/EventService.h
        source/Event/EventService.cpp
        include/Global/Config.h
        source/Global/Config.cpp
        include/Global/ServiceLocator.h
        source/Global/ServiceLocator.cpp
        include/Graphics/GraphicService.h
        source/Graphics/GraphicService.cpp
        include/Main/GameService.h
        source/Main/GameService.cpp
        include/Sound/SoundService.h
        source/Sound/SoundService.cpp
        include/Time/TimeService.h
        source/Time/TimeService.cpp
        include/UI/UIService.h
        source/UI/UIService.cpp
        include/UI/Credits/CreditsScreenUIController.h
        source/UI/Credits/CreditsScreenUIController.cpp
        include/UI/Instructions/InstructionsScreenUIController.h
        source/UI/Instructions/InstructionsScreenUIController.cpp
        include/UI/Interface/IUIController.h
        include/UI/MainMenu/MainMenuUIController.h
        source/UI/MainMenu/MainMenuUIController.cpp
        include/UI/SplashScreen/SplashScreenUIController.h
        source/UI/SplashScreen/SplashScreenUIController.cpp
        include/UI/UIElement/AnimatedImageView.h
        source/UI/UIElement/AnimatedImageView.cpp
        include/UI/UIElement/ButtonView.h
        source/UI/UIElement/ButtonView.cpp
        include/UI/UIElement/ImageView.h
        source/UI/UIElement/ImageView.cpp
        include/UI/UIElement/RectangleShapeView.h
        source/UI/UIElement/RectangleShapeView.cpp
        include/UI/UIElement/TextView.h
        source/UI/UIElement/TextView.cpp
        include/UI/UIElement/UIView.h
        source/UI/UIElement/UIView.cpp
        source/Level/LevelModel.cpp
        include/Level/LevelModel.h
        source/Level/LevelView.cpp
        include/Level/LevelView.h
        source/Level/LevelController.cpp
        include/Level/LevelController.h
        source/Level/LevelService.cpp
        include/Level/LevelService.h
        include/Level/LevelNumber.h
        include/Level/LevelData.h
        source/UI/LevelSelection/LevelSelectionUIController.cpp
        include/UI/LevelSelection/LevelSelectionUIController.h
        source/Player/PlayerService.cpp
        include/Player/PlayerService.h
        source/Player/SnakeController.cpp
        include/Player/SnakeController.h
        include/Player/Direction.h
)
target_compile_features(snake_game PRIVATE cxx_std_17)
target_link_libraries(snake_game PRIVATE sfml-graphics sfml-audio)
set_target_properties(snake_game PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
target_compile_definitions(snake_game PRIVATE
        PROJECT_ROOT="${CMAKE_SOURCE_DIR}/"
)

if(WIN32)
    add_custom_command(
            TARGET main
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
            VERBATIM)
endif()
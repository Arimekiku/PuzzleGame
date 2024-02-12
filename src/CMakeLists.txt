add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
        game/game.cpp
        game/gameObject/gameObject.cpp
        game/gameObject/gameObjectFactory.cpp
        game/textureHandler/textureHandler.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE vendor)
target_include_directories(${PROJECT_NAME} PRIVATE game)
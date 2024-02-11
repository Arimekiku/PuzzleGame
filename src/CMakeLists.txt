add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
        game/game.cpp
        game/textureHandler/textureHandler.cpp)

link_directories(../resources)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)
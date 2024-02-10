add_subdirectory(SFML)

set(SFML_STATIC_LIBRARIES ON)

add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE sfml-graphics sfml-window sfml-system)
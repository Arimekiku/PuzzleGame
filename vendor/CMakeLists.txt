add_subdirectory(SFML)
add_subdirectory(json)

set(SFML_STATIC_LIBRARIES ON)
set(JSON_Install OFF CACHE INTERNAL "")

add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE sfml-graphics sfml-window sfml-system nlohmann_json)
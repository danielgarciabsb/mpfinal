set(MODULE_NAME repositorio)

add_library(${MODULE_NAME} STATIC ${MODULE_NAME}.cpp)

install(TARGETS ${MODULE_NAME} DESTINATION lib)
install(FILES ${MODULE_NAME}.hpp DESTINATION include)

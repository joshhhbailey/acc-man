add_executable(${TARGETNAME})

target_sources(${TARGETNAME} PRIVATE
	# .cpp
	${PROJECT_SOURCE_DIR}/src/app/AboutWidget.cpp
	${PROJECT_SOURCE_DIR}/src/app/main.cpp
	${PROJECT_SOURCE_DIR}/src/app/MainWindow.cpp
	${PROJECT_SOURCE_DIR}/src/app/AccountContainer.cpp
	${PROJECT_SOURCE_DIR}/src/app/AccountWidget.cpp
	${PROJECT_SOURCE_DIR}/src/app/PlatformContainer.cpp
	${PROJECT_SOURCE_DIR}/src/app/PlatformWidget.cpp
	${PROJECT_SOURCE_DIR}/src/app/Encrypter.cpp

	# .h
	${PROJECT_SOURCE_DIR}/include/app/AboutWidget.h
	${PROJECT_SOURCE_DIR}/include/app/MainWindow.h
	${PROJECT_SOURCE_DIR}/include/app/AccountContainer.h
	${PROJECT_SOURCE_DIR}/include/app/AccountWidget.h
	${PROJECT_SOURCE_DIR}/include/app/PlatformContainer.h
	${PROJECT_SOURCE_DIR}/include/app/PlatformWidget.h
	${PROJECT_SOURCE_DIR}/include/app/Encrypter.h
)

target_include_directories(${TARGETNAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/app)
target_link_libraries(${TARGETNAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
target_link_libraries(${TARGETNAME} PRIVATE cryptopp-static)

set_target_properties(${TARGETNAME} PROPERTIES
    WIN32_EXECUTABLE ON		# Prevent the creation of a console window on Windows [THIS MIGHT BE PROBLEMATIC]
    MACOSX_BUNDLE ON		# Create an application bundle on macOS
)

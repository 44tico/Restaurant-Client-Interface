cmake_minimum_required(VERSION 3.16)

project(Restaurant-Interface VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)  # Ativa o processamento automático de arquivos .ui
set(CMAKE_AUTOMOC ON)  # Ativa o processamento automático de arquivos .hpp com Q_OBJECT
set(CMAKE_AUTORCC ON)  # Ativa o processamento automático de arquivos .qrc

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

# Lista de arquivos de código-fonte
set(PROJECT_SOURCES
    main.cpp
    homewindow.cpp
    homewindow.hpp
    homewindow.ui



    cartmanager.cpp
    cartmanager.hpp
    item.cpp
    item.hpp
)

# Cria o executável
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Restaurant-Interface
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
orderwindow.hpp orderwindow.cpp orderwindow.ui
    )
else()
    if(ANDROID)
        add_library(Restaurant-Interface SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Restaurant-Interface
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Vincula as bibliotecas do Qt
target_link_libraries(Restaurant-Interface PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

# Configurações para macOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Restaurant-Interface)
endif()
set_target_properties(Restaurant-Interface PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Instalação
include(GNUInstallDirs)
install(TARGETS Restaurant-Interface
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalização (apenas para Qt 6)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Restaurant-Interface)
endif()

QT += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    sources/clickablelabel.cpp \
    sources/data_collector.cpp \
    sources/defaults.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/menus_sources/mainmenu.cpp \
    sources/menus_sources/menus_helpers.cpp \
    sources/menus_sources/pvpmenu.cpp \
    sources/menus_sources/settingsmenu.cpp \
    sources/menus_sources/start_game_button.cpp \
    sources/menus_sources/toggle_switch.cpp \
    sources/paths.cpp \
    sources/utils.cpp




HEADERS += \
    headers/clickablelabel.hpp \
    headers/data_collector.hpp \
    headers/defaults.hpp \
    headers/helpers.hpp \
    headers/mainwindow.hpp \
    headers/menus_headers/mainmenu.hpp \
    headers/menus_headers/menus_helpers.hpp \
    headers/menus_headers/pvpmenu.hpp \
    headers/menus_headers/settingsmenu.hpp \
    headers/menus_headers/start_game_button.hpp \
    headers/menus_headers/toggle_switch.hpp \
    headers/menus_headers/toggle_switch_style.hpp \
    headers/paths.hpp \
    headers/predefined_classes.hpp \
    headers/utils.hpp



INCLUDEPATH += \
    headers/ \
    headers/menus_headers/ \



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    res.qrc

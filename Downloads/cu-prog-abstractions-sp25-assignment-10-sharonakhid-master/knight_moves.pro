TEMPLATE = app
QT -= gui
CONFIG += console c++17 silent
CONFIG -= app_bundle
SOURCES += \
    src/main.cpp \
    src/knight.cpp
HEADERS += \
    src/knight.h

OTHER_FILES += \
    README.md

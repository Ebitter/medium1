
#cw_mutil_thread_feature_extract.dll
QT += core
QT -= gui

CONFIG += c++11

TARGET = cw_mutil_thread_feature_extract
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = lib

SOURCES +=  cw_mutil_thread_feature_extract.cpp

HEADERS += \
    include/cw_mutil_thread_feature_extract.h

#main
#QT += core
#QT -= gui

#CONFIG += c++11

#TARGET = medium1
#CONFIG += console
#CONFIG -= app_bundle

#TEMPLATE = app

#SOURCES += main.cpp

#HEADERS += \
#    include/cw_mutil_thread_feature_extract.h

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-medium1-Desktop_Qt_5_7_0_MSVC2013_32bit-Debug/release/ -lcw_mutil_thread_feature_extract
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-medium1-Desktop_Qt_5_7_0_MSVC2013_32bit-Debug/debug/ -lcw_mutil_thread_feature_extract
#else:unix: LIBS += -L$$PWD/../build-medium1-Desktop_Qt_5_7_0_MSVC2013_32bit-Debug/ -lcw_mutil_thread_feature_extract

#INCLUDEPATH += $$PWD/../build-medium1-Desktop_Qt_5_7_0_MSVC2013_32bit-Debug/debug
#DEPENDPATH += $$PWD/../build-medium1-Desktop_Qt_5_7_0_MSVC2013_32bit-Debug/debug

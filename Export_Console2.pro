QT += core
QT -= gui
QT += sql

VERSION = 3.0.0.3

CONFIG += c++11

TARGET = Export_Console2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    databasehelp.cpp

HEADERS += \
    databasehelp.h \
    common.h

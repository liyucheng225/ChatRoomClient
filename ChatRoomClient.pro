QT       += core gui
QT       += network
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client/client.cpp \
    Client/clientservice.cpp \
    Client/loginservice.cpp \
    File/domxml.cpp \
    HomePage/homepage.cpp \
    MainWindow/chatlabel.cpp \
    MainWindow/chatstackwidget.cpp \
    MainWindow/chatwidget.cpp \
    MainWindow/mainpage.cpp \
    MainWindow/pushbuttonmodel.cpp \
    MainWindow/scrollareamodel.cpp \
    MainWindow/stackwidgetmodel.cpp \
    MainWindow/userlist.cpp \
    MainWindow/userstackwidget.cpp \
    User/group.cpp \
    User/groupuser.cpp \
    User/user.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Client/client.h \
    Client/clientservice.h \
    Client/loginservice.h \
    File/domxml.h \
    HomePage/homepage.h \
    MainWindow/chatlabel.h \
    MainWindow/chatstackwidget.h \
    MainWindow/chatwidget.h \
    MainWindow/mainpage.h \
    MainWindow/pushbuttonmodel.h \
    MainWindow/scrollareamodel.h \
    MainWindow/stackwidgetmodel.h \
    MainWindow/userlist.h \
    MainWindow/userstackwidget.h \
    User/group.h \
    User/groupuser.h \
    User/user.h \
    mainwindow.h \
    public.h \
    thirdPary/json.hpp

FORMS += \
    HomePage/homepage.ui \
    MainWindow/chatwidget.ui \
    MainWindow/mainpage.ui \
    mainwindow.ui

TRANSLATIONS += \
    ChatRoomClient_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

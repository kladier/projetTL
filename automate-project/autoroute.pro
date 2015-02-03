QT += svg
QT += widgets


HEADERS += \
    mainwindow.h \
    etatright.h \
    etatleft.h \
    etat.h \
    createautomate.h \
    choixpointe.h \
    automate.h \
    transition.h
SOURCES += \
    mainwindow.cpp \
    main.cpp \
    etatright.cpp \
    etatleft.cpp \
    etat.cpp \
    createautomate.cpp \
    choixpointe.cpp \
    automate.cpp \
    transition.cpp
FORMS += \
    mainwindow.ui \
    etatright.ui \
    etatleft.ui \
    createautomate.ui \
    choixpointe.ui
    transition.ui
RESOURCES += Images.qrc
RC_FILE = myApp.rc

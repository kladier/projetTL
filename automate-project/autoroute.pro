QT += svg
QT += widgets


HEADERS += transition.h \
    mainwindow.h \
    etatright.h \
    etatleft.h \
    etat.h \
    createautomate.h \
    choixpointe.h \
    automate.h
SOURCES += transition.cpp \
    mainwindow.cpp \
    main.cpp \
    etatright.cpp \
    etatleft.cpp \
    etat.cpp \
    createautomate.cpp \
    choixpointe.cpp \
    automate.cpp
FORMS += transition.ui \
    mainwindow.ui \
    etatright.ui \
    etatleft.ui \
    createautomate.ui \
    choixpointe.ui
RESOURCES += Images.qrc
RC_FILE = myApp.rc

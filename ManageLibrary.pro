QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_ICONS= icon.ico
SOURCES += \
    Books.cpp \
    Users.cpp \
    about.cpp \
    addaccount.cpp \
    addbook.cpp \
    addnew.cpp \
    editaccounts.cpp \
    editbooks.cpp \
    get_giveback.cpp \
    help.cpp \
    main.cpp \
    mainwindow.cpp \
    manage_all_books.cpp \
    open_database.cpp \
    pubwrttrs.cpp \
    queries.cpp \
    thabt_book.cpp \
    wtp.cpp

HEADERS += \
    Books.hpp \
    Users.hpp \
    about.h \
    addaccount.h \
    addbook.h \
    addnew.h \
    editaccounts.h \
    editbooks.h \
    get_giveback.h \
    help.h \
    mainwindow.h \
    manage_all_books.hpp \
    open_database.hpp \
    pubwrttrs.h \
    queries.h \
    thabt_book.h \
    wtp.hpp

FORMS += \
    about.ui \
    addaccount.ui \
    addbook.ui \
    addnew.ui \
    editaccounts.ui \
    editbooks.ui \
    get_giveback.ui \
    help.ui \
    mainwindow.ui \
    pubwrttrs.ui \
    queries.ui \
    thabt_book.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    file

RESOURCES += \
    GeneralPic.qrc \
    Icon.qrc \
    PPic.qrc

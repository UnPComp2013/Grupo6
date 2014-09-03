TEMPLATE = app

FORMS += \
    menusql.ui

HEADERS += \
    menusql.h \
    headers/menugui.h

SOURCES += \
    menusql.cpp \
    main.cpp \
    Source/main.cpp \
    Source/menugui.cpp
    
QT += \
    widgets \
    sql

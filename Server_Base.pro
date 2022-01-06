QT -= gui core

CONFIG += c++11 console debug
CONFIG -= app_bundle


LIBS +=  -lSDL2main -lSDL2 -lSDL2_net


HEADERS += \
    AmberCommon.h \
    Source/Data/Conversion.h \
    Source/UDPnetwork/AmberUDP.h 

SOURCES += \
    Server_Base.cpp \
    Source/Data/Conversion.cpp \
    Source/UDPnetwork/AmberUDP.cpp 



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

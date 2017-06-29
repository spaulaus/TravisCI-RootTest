# @authors S.V. Paulauskas
if(ROOT_HAS_MINUIT2)
    add_definitions("-D ROOT_HAS_MINUIT2")
endif(ROOT_HAS_MINUIT2)

set(RootInterfaceSources RootInterface.cpp)
add_library(RootInterfaceStatic STATIC ${RootInterfaceSources})

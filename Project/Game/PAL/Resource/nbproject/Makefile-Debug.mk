#
# Gererated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=g77

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Debug/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/rixplay.o \
	${OBJECTDIR}/adplug/rix.o \
	${OBJECTDIR}/text.o \
	${OBJECTDIR}/font.o \
	${OBJECTDIR}/adplug/player.o \
	${OBJECTDIR}/itemmenu.o \
	${OBJECTDIR}/adplug/binio.o \
	${OBJECTDIR}/scene.o \
	${OBJECTDIR}/palcommon.o \
	${OBJECTDIR}/script.o \
	${OBJECTDIR}/adplug/emuopl.o \
	${OBJECTDIR}/util.o \
	${OBJECTDIR}/play.o \
	${OBJECTDIR}/getopt.o \
	${OBJECTDIR}/input.o \
	${OBJECTDIR}/uibattle.o \
	${OBJECTDIR}/game.o \
	${OBJECTDIR}/magicmenu.o \
	${OBJECTDIR}/map.o \
	${OBJECTDIR}/ending.o \
	${OBJECTDIR}/adplug/fmopl.o \
	${OBJECTDIR}/uigame.o \
	${OBJECTDIR}/rngplay.o \
	${OBJECTDIR}/ui.o \
	${OBJECTDIR}/adplug/fprovide.o \
	${OBJECTDIR}/global.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/adplug/binfile.o \
	${OBJECTDIR}/video.o \
	${OBJECTDIR}/palette.o \
	${OBJECTDIR}/sound.o \
	${OBJECTDIR}/res.o \
	${OBJECTDIR}/battle.o \
	${OBJECTDIR}/fight.o \
	${OBJECTDIR}/yj1.o

# C Compiler Flags
CFLAGS=`sdl-config --cflags` 

# CC Compiler Flags
CCFLAGS=`sdl-config --cflags` 
CXXFLAGS=`sdl-config --cflags` 

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Debug/GNU-Linux-x86/sdlpal

dist/Debug/GNU-Linux-x86/sdlpal: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} `sdl-config --libs` -Xlinker -Map=dist/Debug/GNU-Linux-x86/sdlpal.map -o dist/Debug/GNU-Linux-x86/sdlpal  ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/rixplay.o: rixplay.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/rixplay.o rixplay.cpp

${OBJECTDIR}/adplug/rix.o: adplug/rix.cpp 
	${MKDIR} -p ${OBJECTDIR}/adplug
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/adplug/rix.o adplug/rix.cpp

${OBJECTDIR}/text.o: text.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/text.o text.c

${OBJECTDIR}/font.o: font.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/font.o font.c

${OBJECTDIR}/adplug/player.o: adplug/player.cpp 
	${MKDIR} -p ${OBJECTDIR}/adplug
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/adplug/player.o adplug/player.cpp

${OBJECTDIR}/itemmenu.o: itemmenu.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/itemmenu.o itemmenu.c

${OBJECTDIR}/adplug/binio.o: adplug/binio.cpp 
	${MKDIR} -p ${OBJECTDIR}/adplug
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/adplug/binio.o adplug/binio.cpp

${OBJECTDIR}/scene.o: scene.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/scene.o scene.c

${OBJECTDIR}/palcommon.o: palcommon.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/palcommon.o palcommon.c

${OBJECTDIR}/script.o: script.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/script.o script.c

${OBJECTDIR}/adplug/emuopl.o: adplug/emuopl.cpp 
	${MKDIR} -p ${OBJECTDIR}/adplug
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/adplug/emuopl.o adplug/emuopl.cpp

${OBJECTDIR}/util.o: util.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/util.o util.c

${OBJECTDIR}/play.o: play.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/play.o play.c

${OBJECTDIR}/getopt.o: getopt.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/getopt.o getopt.c

${OBJECTDIR}/input.o: input.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/input.o input.c

${OBJECTDIR}/uibattle.o: uibattle.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/uibattle.o uibattle.c

${OBJECTDIR}/game.o: game.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/game.o game.c

${OBJECTDIR}/magicmenu.o: magicmenu.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/magicmenu.o magicmenu.c

${OBJECTDIR}/map.o: map.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/map.o map.c

${OBJECTDIR}/ending.o: ending.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/ending.o ending.c

${OBJECTDIR}/adplug/fmopl.o: adplug/fmopl.c 
	${MKDIR} -p ${OBJECTDIR}/adplug
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/adplug/fmopl.o adplug/fmopl.c

${OBJECTDIR}/uigame.o: uigame.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/uigame.o uigame.c

${OBJECTDIR}/rngplay.o: rngplay.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/rngplay.o rngplay.c

${OBJECTDIR}/ui.o: ui.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/ui.o ui.c

${OBJECTDIR}/adplug/fprovide.o: adplug/fprovide.cpp 
	${MKDIR} -p ${OBJECTDIR}/adplug
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/adplug/fprovide.o adplug/fprovide.cpp

${OBJECTDIR}/global.o: global.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/global.o global.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/adplug/binfile.o: adplug/binfile.cpp 
	${MKDIR} -p ${OBJECTDIR}/adplug
	$(COMPILE.cc) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/adplug/binfile.o adplug/binfile.cpp

${OBJECTDIR}/video.o: video.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/video.o video.c

${OBJECTDIR}/palette.o: palette.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/palette.o palette.c

${OBJECTDIR}/sound.o: sound.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/sound.o sound.c

${OBJECTDIR}/res.o: res.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/res.o res.c

${OBJECTDIR}/battle.o: battle.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/battle.o battle.c

${OBJECTDIR}/fight.o: fight.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/fight.o fight.c

${OBJECTDIR}/yj1.o: yj1.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -D_DEBUG -I/usr/include/SDL -o ${OBJECTDIR}/yj1.o yj1.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/sdlpal

# Subprojects
.clean-subprojects:

//-----------------------------INCLUDES------------------------------


#include "Sound.h"


//--------------------------TEXTURES_PATHS---------------------------


#define BLOCKSPATH "Blocks.png"
#define QUESTIONPATH "question.png"
#define TRAMPOLINEPATH "trampoline.png"
#define COINPATH "Coin.png"
#define FLAGBOTTOMPATH "flag_bottom.png"
#define FLAGMIDDLEPATH "flag_middle.png"
#define FLAGTOPPATH "flag_top.png"
#define GOOMBAPATH "Goomba.png"
#define GOOMBA1PATH "Goomba1.png"
#define GRASSPATH "Grass.png"
#define MARIOPATH "Mario.png"
#define BACKGROUNDPATH "menu.jpg"


//---------------------------LEVELS_PATHS----------------------------


#define LEVELSPATH "Levels.txt"


//---------------------------SOUNDS_PATHS----------------------------


#define COINSOUNDSPATH "coin.wav"
#define GAMEOVERSOUNDSPATH "gameover.wav"
#define JUMPSOUNDSPATH "jump.wav"
#define MAINTHEMESOUNDSPATH "main_theme.wav"
#define MENUSOUNDPATH "menu.wav"
#define DIEDSOUNDPATH "died.wav"
#define PAUSESOUNDSPATH "pause.wav"
#define STOMPSOUNDSPATH "stomp.wav"
#define VICTORYPATH "victory.wav"
#define WINSOUNDSPATH "winlevel.wav"
#define TRAMPOLINESOUNDPATH "trampoline.wav"
#define POWERUPSOUNDPATH "powerup.wav"
#define CLICKSOUNDPATH "click.wav"


//---------------------------FONTS_PATHS-----------------------------


#define FONTSPATH "SuperMario.ttf"


//------------------------------ID'S---------------------------------


#define FONTID "font1" 
#define MARIOID "player"
#define COINID 'g'
#define GOOMBAID 'e'
#define GOOMBA1ID 'f'
#define GRASSID 'G'
#define TURTLEID 's'
#define FINISHLINEID 'F'
#define WHITESPACEID '-'
#define BRICKID '1' 
#define QUESTIONID '2'
#define TRAMPOLINEID 'T'
#define EMPTYID '3'
#define GRASSTOPID '4'
#define GRASSLEFTCORNERID '5'
#define GRASSLEFTID '6'
#define DIRTID '7'
#define GRASSRIGHTID '8'
#define GRASSRIGHTCORNER '9'
#define PIPETOPLEFT 'A'
#define PIPETOPRIGHT 'B'
#define PIPELEFT 'C'
#define PIPERIGHT 'D'
#define FLAGBOTTOM 'b'
#define FLAGMIDDLE 'm'
#define FLAGTOP 't'
#define TOPLEFTCLOUD 'i'
#define TOPRIGHTCLOUD 'o'
#define BOTTOMLEFTCLOUD 'k'
#define BOTTOMRIGHTCLOUD 'l'


//------------------------------CONSTS-------------------------------

#define GAMETITLE "Super Mario"
#define WINDOWWIDTH 700
#define WINDOWHIEGHT 650
#define GRAVITY .0075f
#define OBJECTHEIGHT 1
#define OBJECTWIDTH 1
#define PLAYERHEIGHT 2
#define ENEMYSPEED .04f
#define PLAYERSPEED .01f
#define PLAYERJUMPSPEED -.25f
#define PLAYERMAXSPEED .15f
#define PLAYERSTOPSPEED .005f
#define PLAYERFIRSTPOS { 10.f, 2.f }
#define ENEMYLIFE 1
#define PLAYERLIFE 3

#define MAX_MAIN_MENU 10

#define NUMOFLEVELS 5

#define ZERO 0

#define PLAY "Play"
#define BUTTONS "BUTTONS"
#define EXIT "Exit"

#define MOVEMENT "Movement:"
#define MOVE "         Arrow/WASD     keys move"
#define VOL "Volume:"
#define PAUSE "         P                       Pause"
#define VOLUME "         B/N/M  increas/decrease/mute"
#define PLAYAGAIN "play again"
#define BACK "<-BACK"


//--------------------------------------------------------------------------------------------------
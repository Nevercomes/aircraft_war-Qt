#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtWidgets>

// Name
#define NAME_SUPPLY_BLOOD 1
#define NAME_SUPPLY_BOMB 2
#define NAME_SUPPLY_BULLET 3

#define NAME_PLAYER_PLANE 4
#define NAME_PLAYER_BULLET 6
#define NAME_PLAYER_BULLET_1 9
#define NAME_PLAYER_BOMB 8

#define NAME_ENEMY_PLANE 5
#define NAME_ENEMY_BULLET 7


// Size
#define SIZE_WIDTH_SCENE  480
#define SIZE_HEIGHT_SCENE  800

#define SIZE_SUPPLY_BLOOD 30
#define SIZE_SUPPLY_BOMB 60
#define SIZE_SUPPLY_BULLET 60

#define SIZE_PLAYER_PLANE 70
#define SIZE_PLAYER_BULLET 20
#define SIZE_PLAYER_BOMB 300

#define SIZE_FISH 60
#define SIZE_FISH_1 100
#define SIZE_FISH_2 200
#define SIZE_FISH_BULLET 20
#define SIZE_FISH_BULLET_1 20
#define SIZE_FISH_BULLET_2 20

#define SIZE_BOSS 200
#define SIZE_BOSS_BULLET 20
#define SIZE_BOSS_BULLET_1 150
#define SIZE_WIDTH_BOSS_BULLET 150
#define SIZE_HEIGHT_BOSS_BULLET 150

#define SIZE_WIDTH_TEXT_POINT 120
#define SIZE_HEIGHT_TEXT_POINT 40
#define SIZE_WIDTH_TEXT_SCORE 60。
#define SIZE_HEIGHT_TEXT_SCORE 40
#define SIZE_WIDTH_TEXT_BOSSHINT 200
#define SIZE_HEIGHT_TEXT_BOSSHINT 60

#define SIZE_STATUS_BLOOD 30
#define SIZE_STATUS_BOMB 40


// Speed
#define SPEED_SUPPLY_BLOOD 3
#define SPEED_SUPPLY_BOMB 3
#define SPEED_SUPPLY_BULLET 3

#define SPEED_PLAYER_PLANE 10
#define SPEED_PLAYER_BULLET 20
#define SPEED_PLAYER_BOMB 10

#define SPEED_FISH 5
#define SPEED_FISH_1 4
#define SPEED_FISH_2 2
#define SPEED_FISH_BULLET 8
#define SPEED_FISH_BULLET_1 6
#define SPEED_FISH_BULLET_2 4

#define SPEED_BOSS 2
#define SPEED_BOSS_BULLET 5
#define SPEED_BOSS_BULLET_1 10
#define SPEED_BOSS_BULLET_2 15


//UpdateTime advance函数中step的意义
const int INTERVAL = 50;

const int STEP_PLAYER_SHOOT  = 5;

const int STEP_SHOOT_BOSS = 70;

const int STEP_SHOOT_FISH = 60;
const int STEP_SHOOT_FISH_1 = 60;
const int STEP_SHOOT_FISH_2 = 60;

const int STEP_BOMB_PIX = 4;
const int STEP_BOSS_PIX = 10;

const int STEP_DESTROY = 3;
const int STEP_TEXTHINT = 20;


// Score
#define SCORE_FISH 10
#define SCORE_FISH_1 20
#define SCORE_FISH_2 30
#define SCORE_BOSS 300


// Hp
#define HP_FISH 2
#define HP_FISH_1 5
#define HP_FISH_2 15
#define HP_BOSS 200

//UP（上限）
#define UP_PLAYER_PLANE_BLOOD 3
#define UP_PLAYER_BOMB 3

const QString IMG_BACKGROUND = "://res/imgae/background.png";

const QString IMG_START_LOGO = "://res/imgae/logo.png";
const QString IMG_START_PLANE_LEFT = "://res/imgae/loading_03.png";
const QString IMG_START_PLANE_RIGHT = "://res/imgae/loading_03_right.png";

const QString IMG_PLAYER_PLANE   = "://res/imgae/F1_06.png";
const QString IMG_PLAYER_PLANE_1 = "://res/imgae/F1_02.png";
const QString IMG_PLAYER_PLANE_2 = "://res/imgae/F1_03.png";
const QString IMG_PLAYER_PLANE_3 = "://res/imgae/F1_04.png";
const QString IMG_PLAYER_PLANE_4 = "://res/imgae/F1_05.png";

const QString IMG_PLAYER_BULLET   = "://res/imgae/bullet_01.png";
const QString IMG_PLAYER_BULLET_1 = "://res/imgae/bullet_02.png";

const QString IMG_PLAYER_BOMB   = "://res/imgae/blast1.png";
const QString IMG_PLAYER_BOMB_1 = "://res/imgae/blast2.png";
const QString IMG_PLAYER_BOMB_2 = "://res/imgae/blast3.png";
const QString IMG_PLAYER_BOMB_3 = "://res/imgae/blast4.png";
const QString IMG_PLAYER_BOMB_4 = "://res/imgae/blast5.png";
const QString IMG_PLAYER_BOMB_5 = "://res/imgae/blast6.png";

const QString IMG_FISH1   = "://res/imgae/F2_01.png";
const QString IMG_FISH1_1 = "://res/imgae/F2_02.png";
const QString IMG_FISH1_2 = "://res/imgae/F2_03.png";
const QString IMG_FISH1_3 = "://res/imgae/F2_04.png";
const QString IMG_FISH1_4 = "://res/imgae/F2_05.png";

const QString IMG_FISH2   = "://res/imgae/F3_01.png";
const QString IMG_FISH2_1 = "://res/imgae/F3_02.png";
const QString IMG_FISH2_2 = "://res/imgae/F3_03.png";
const QString IMG_FISH2_3 = "://res/imgae/F3_04.png";
const QString IMG_FISH2_4 = "://res/imgae/F3_05.png";
const QString IMG_FISH2_5 = "://res/imgae/F3_06.png";

const QString IMG_FISH3   = "://res/imgae/F4_01.png";
const QString IMG_FISH3_1 = "://res/imgae/F4_02.png";
const QString IMG_FISH3_2 = "://res/imgae/F4_03.png";
const QString IMG_FISH3_3 = "://res/imgae/F4_04.png";
const QString IMG_FISH3_4 = "://res/imgae/F4_05.png";
const QString IMG_FISH3_5 = "://res/imgae/F4_06.png";
const QString IMG_FISH3_6 = "://res/imgae/F4_07.png";
const QString IMG_FISH3_7 = "://res/imgae/F4_08.png";
const QString IMG_FISH3_8 = "://res/imgae/F4_09.png";

const QString IMG_FISH_BULLET   = "://res/imgae/bullet_04.png";
const QString IMG_FISH_BULLET_1 = "://res/imgae/bullet_04.png";
const QString IMG_FISH_BULLET_2 = "://res/imgae/bullet_06.png";

const QString IMG_BOSS1   = "://res/imgae/boss0_0.png";
const QString IMG_BOSS1_1 = "://res/imgae/boss0_1.png";
const QString IMG_BOSS1_2 = "://res/imgae/boss0_3.png";
const QString IMG_BOSS1_3 = "://res/imgae/boss0_4.png";
const QString IMG_BOSS1_4 = "://res/imgae/boss0_2.png";

const QString IMG_BOSS_BULLET   = "://res/imgae/bullet_04.png";
const QString IMG_BOSS_BULLET_1 = "://res/imgae/bullet_05.png";
const QString IMG_BOSS_BULLET_2 = "://res/imgae/bullet_06.png";

const QString IMG_SUPPLY_BOLLD  = "://res/imgae/blood.png";
const QString IMG_SUPPLY_BOMB   = "://res/imgae/supply_bomb.png";
const QString IMG_SUPPLY_BULLET = "://res/imgae/supply_double.png";

const QString IMG_STATUS_BOMB    = "://res/imgae/bomb_status.png";
const QString IMG_STATUS_BLOOD   = "://res/imgae/blood.png";
const QString IMG_STATUS_BLOOD_1 = "://res/imgae/blood.png";

const QString IMG_TEXT_POINT   = "://res/imgae/point1_1.png";
const QString IMG_TEXT_POINT_1 = "://res/imgae/point1_2.png";

const QString IMG_TEXT_SCORE = "://res/imgae/text_score_in.png";

const QString IMG_TEXT_BOSSHINT = "://res/imgae/text_boss.png";


// sound
const QString SOUND_START_BG = "qrc:/res/sound/sound_start.mp3";

const QString SOUND_BATTLE_NORMAL_BG = "qrc:/res/sound/sound_battle_normal.mp3";
const QString SOUND_BATTLE_BOSS_BG = "qrc:/res/sound/sound_battle_boss.mp3";


#endif // GLOBAL_H

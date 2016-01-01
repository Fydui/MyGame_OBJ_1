//-----本文件是对于maincall.h中部分函数的实现部分-----//
//-----LEX工作室渣游--极舞-----//

#include "maincall.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

int Sum;        //图元计数的全局变量
bool Stop = 0;  //暂停音乐的全局变量
bool Men = 0;   //菜单按钮的全局变量
bool Vol = 0;   //音量按钮的全局变量
QMediaPlayer *Music = nullptr;   //音乐的指针
ParametersStru *Cle_1 = new ParametersStru; //退出函数全局指针

void maincall::StartGame()//入口函数
{


    GamesHomeUI();
}

void maincall::GamesHomeUI() //游戏主页
{

    AddPixmapItem("E:/game/开始_背景.png",0,0);
    AddPixmapItem("E:/game/主页开始_正常.png",0,0,"LevelUI","E:/game/主页开始_按下.png");
    AddPixmapItem("E:/game/主页关于_正常.png",0,0,"GAboutUI","E:/game/主页关于_按下.png");
    AddPixmapItem("E:/game/音量_有.png",0,0,"Volume","E:/game/音量_无");
    Sum = 4;


}

void maincall::GAboutUI() //关于界面
{

    AddPixmapItem("E:/game/关于_背景.png",0,0);
    AddPixmapItem("E:/game/主页返回_正常.png",0,-60,"Clear","E:/game/主页返回_按下.png",Cle_1);
    AddPixmapItem("E:/game/音量_有.png",0,0,"Volume","E:/game/音量_无.png");
    Cle_1->StringVar<<"退出";
    Sum = 6;


}
void maincall:: LevelUI() //关卡界面
{

    ParametersStru *GameLM_1 = new ParametersStru;
    ParametersStru *GameLM_2 = new ParametersStru;
    ParametersStru *GameLM_3 = new ParametersStru;
    ParametersStru *GameLM_4 = new ParametersStru;

    AddPixmapItem("E:/game/关卡_背景.png",0,0);
    AddPixmapItem("E:/game/主页返回_正常.png",0,-60,"Clear","E:/game/主页返回_按下.png",Cle_1);
    AddPixmapItem("E:/game/关卡1_正常.png",0,0,"GameLvUI","E:/game/关卡1_按下.png",GameLM_1);
    AddPixmapItem("E:/game/关卡2_正常.png",0,0,"GameLvUI","E:/game/关卡2_按下.png",GameLM_2);
    AddPixmapItem("E:/game/关卡3_正常.png",0,0,"GameLvUI","E:/game/关卡3_按下.png",GameLM_3);
    AddPixmapItem("E:/game/关卡4_正常.png",0,0,"GameLvUI","E:/game/关卡4_按下.png",GameLM_4);
    AddPixmapItem("E:/game/音量_有.png",0,0,"Volume","E:/game/音量_无.png");

    GameLM_1->StringVar<<"第一关";
    GameLM_2->StringVar<<"第二关";
    GameLM_3->StringVar<<"第三关";
    GameLM_4->StringVar<<"第四关";
    Cle_1->StringVar<<"退出";

    Sum = 10;


}
void maincall::GameLvUI(ParametersStru* GameLM_1)//开始游戏
{

    AddPixmapItem("E:/game/关卡_背景.png",0,0);
    AddPixmapItem("E:/game/音量_有.png",0,0,"Volume","E:/game/音量_无.png");
    AddPixmapItem("E:/game/菜单.png",0,0,"MenuUI","E:/game/菜单按下.png");
    AddPixmapItem("E:/game/血条框框.png",0,0);
    buttonUI();
    Sum = 19;
    Men = 1;
    Stop = 1;


    if(GameLM_1->StringVar[0]  == "第一关")    //判断音乐
    {
        QMediaPlayer *M1= AddMusic("E:/game/Bad_Apple.mp3",100);

        Music = M1;
    }
    else
    {
        if(GameLM_1 -> StringVar[0] == "第二关")
        {
           QMediaPlayer *M2 = AddMusic("E:/game/清明上河图.mp3",100);
           Music = M2;
        }
        else
        {
            if(GameLM_1 -> StringVar[0] == "第三关")
            {
                QMediaPlayer *M3 = AddMusic("E:/game/雪月花.mp3",100);
                Music = M3;
            }
            else
            {
                QMediaPlayer *M4 = AddMusic("E:/game/千本桜.mp3",100);
                Music = M4;
                //我是第四关
            }
        }
    }

}

/*void maincall::Level_1() //关卡1の判断
{
    //
   //
  


}*/

void maincall::MenuUI() //菜单按钮
{
    if(Men == 0) //判断菜单按钮是否按下
    {
        return;
    }

    ParametersStru *Cle_3 = new ParametersStru;
    ParametersStru *Cle_2 = new ParametersStru;

    AddPixmapItem("E:/game/分数框.png",0,0);
    AddPixmapItem("E:/game/菜单确定_正常.png",0,0,"Clear","E:/game/菜单确定_按下.png",Cle_3);
    AddPixmapItem("E:/game/菜单返回_正常.png",0,0,"Clear","E:/game/菜单返回_按下.png",Cle_2);
    AddPixmapItem("E:/game/菜单退出_正常.png",0,0,"Clear","E:/game/菜单退出_按下.png",Cle_1);


    Cle_2->StringVar<<"返回";
    Cle_3->StringVar<<"确定";
    Men = 0;
    Sum = 23;
    PauseM();



}

void maincall::buttonUI() //游戏按钮
{

    AddPixmapItem("E:/game/按键背景.png",0,0);
    AddPixmapItem("E:/game/按键.png",-25,140,"Null","E:/game/按键深色.png");
    AddPixmapItem("E:/game/按键.png",165,140,"Null","E:/game/按键深色.png");
    AddPixmapItem("E:/game/按键.png",355,140,"Null","E:/game/按键深色.png");
    AddPixmapItem("E:/game/按键.png",545,140,"Null","E:/game/按键深色.png");
    Sum = 28;

}

void maincall::Volume() //静音函数
{
    if(Vol == 0)
    {
        SetMusicVolume(Music,0);
        Vol = 1;
    }
    else
    {
        SetMusicVolume(Music,100);
        Vol = 0;
    }

}

void maincall::PauseM()  //暂停音乐
{
    if(Music != nullptr)
    {
       PauseMusic(Music);
    }
}

void maincall::Clear(ParametersStru* Cle_1) //清理图元函数
{

    if(Cle_1->StringVar[0] == "退出")
    {
        for(int i = 4;Sum >= i; Sum--) //返回到主页
        {DeleteItem(AllItem[Sum]);}

        if(Stop == 1)
        {StopMusic(Music);}

    }
    else
    {
        if(Cle_1->StringVar[0] == "返回")
        {
            for(int k = 10;Sum > k; Sum--) //返回到关卡界面
            {DeleteItem(AllItem[Sum]);}
            StopMusic(Music);
        }
        else
        {
            for(int j = 19;Sum>j; Sum--) //继续游戏
            {DeleteItem(AllItem[Sum]);}
            PlayMusic(Music);
        }
        Men = 1;
    }

}



//-----本文件是游戏中的一些函数调用的实现，引擎的三层封装-----
#pragma once
#include "library.h"

class maincall : public library
{
    //对js的处理函数
Q_OBJECT

public:
    Q_INVOKABLE QScriptValue CallJSFile(QString path,QString functionname=NULL,ParametersStru *Parame=nullptr,QString ParameName=NULL,QString mistake=NULL);
    Q_INVOKABLE QScriptValue CallJSCode(QString code,QString functionname=NULL,ParametersStru *Parame=nullptr,QString ParameName=NULL,QString mistake=NULL);
	void StartGame();
    //在此继续添加
	
	
public slots:
    //此处容纳事件处理与线程函数

    void GamesHomeUI();
    void GAboutUI();
    void LevelUI();
    void GameLvUI(ParametersStru* GameLM_1);
    void Clear(ParametersStru *Cle_1);
    void MenuUI();
    void buttonUI();
    void Volume();
    void PauseM();
    void Music_Json();
};

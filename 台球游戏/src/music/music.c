#include <Windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>
#include"music.h"

//��ʼ������
void IntialSound(void) 
{
	mciSendString("open .\\data\\music\\bgm.mp3", NULL, 0, NULL);
	mciSendString("open .\\data\\music\\pooltoball.mp3", NULL, 0, NULL);
	mciSendString("open .\\data\\music\\balltoball.mp3", NULL, 0, NULL);
	mciSendString("open .\\data\\music\\balltotable.mp3", NULL, 0, NULL);
}
//���Ż�����Ч
void PlaySoundEffect(void) 
{
	mciSendString("close .\\data\\music\\pooltoball.mp3", NULL, 0, NULL);
	mciSendString("open .\\data\\music\\pooltoball.mp3", NULL, 0, NULL);
	mciSendString("play .\\data\\music\\pooltoball.mp3", NULL, 0, NULL);
		
}
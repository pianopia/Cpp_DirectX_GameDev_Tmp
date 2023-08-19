#pragma once

#include "DxLib.h"

#define MusicLoadErrCap		"Ç™ì«Ç›çûÇﬂÇ‹ÇπÇÒÇ≈ÇµÇΩ"
#define MusicLoadErrTitle	"âπäyì«Ç›çûÇ›ÉGÉâÅ["

#define GetVolume(volume)	(255 * volume / 100)

#define MusicPathStrMax	256
#define MusicErrStrMax	512

#define VolumeBGM		50
#define VolumeSE		100

#define MusicPathTitleBGM	".\\music\\bgm\\bgm001.wav"


typedef struct _Music
{
	int Handle = -1;
	char Path[MusicPathStrMax];
	int Volume = -1;
	BOOL IsPlayStart = TRUE;
	int PlayType = DX_PLAYTYPE_BACK;
}Music;

extern Music TitleBGM;

extern BOOL Music_Init(VOID);
extern VOID Music_End(VOID);
extern VOID MusicLoadErrMessage(const char* path);

extern Music LoadMusic(const char* path, int volume, int playType);
extern VOID PlayMusic(Music music);
extern VOID PauseMusic(Music* music);
extern VOID StopMusic(Music* music);
extern VOID DeleteMusic(Music music);

extern VOID ChangeVolumeMusic(Music* music, int volume);

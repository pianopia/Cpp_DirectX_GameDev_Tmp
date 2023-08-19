#include "music.h"

Music TitleBGM;


BOOL Music_Init(VOID)
{
	TitleBGM = LoadMusic(MusicPathTitleBGM, VolumeBGM, DX_PLAYTYPE_LOOP); if (TitleBGM.Handle == -1) { return FALSE; }

	return TRUE;
}


VOID Music_End(VOID)
{
	DeleteMusic(TitleBGM);

	return;
}


VOID MusicLoadErrMessage(const char* path)
{
	char ErrStr[MusicErrStrMax];

	for (int i = 0; i < MusicErrStrMax; i++) { ErrStr[i] = '\0'; }

	sprintf_s(ErrStr, sizeof(ErrStr), "%s%s", path, MusicLoadErrCap);
}


Music LoadMusic(const char* path, int volume, int playType)
{
	Music music;

	strcpy_s(music.Path, sizeof(music.Path), path);

	music.Handle = LoadSoundMem(music.Path);

	if (music.Handle == -1)
	{
		MusicLoadErrMessage(music.Path);
	}
	else
	{
		music.Volume = volume;
		ChangeVolumeMusic(&music, music.Volume);
		music.PlayType = playType;
		music.IsPlayStart = TRUE;
	}

	return music;
}


VOID PlayMusic(Music music)
{
	switch (music.PlayType)
	{
	case DX_PLAYTYPE_BACK:

		PlaySoundMem(music.Handle, DX_PLAYTYPE_BACK, music.IsPlayStart);
		break;
	case DX_PLAYTYPE_LOOP:
		if (CheckSoundMem(music.Handle) == 0)
		{
			PlaySoundMem(music.Handle, DX_PLAYTYPE_LOOP, music.IsPlayStart);
		}
	default:
		break;
	}
}


VOID PauseMusic(Music* music)
{
	music->IsPlayStart = FALSE;

	StopSoundMem(music->Handle);

	return;
}


VOID StopMusic(Music* music)
{
	music->IsPlayStart = TRUE;

	StopSoundMem(music->Handle);

	return;
}


VOID DeleteMusic(Music music)
{
	if (music.Handle != 1)
	{
		DeleteSoundMem(music.Handle);
	}

	return;
}


VOID ChangeVolumeMusic(Music* music, int volume)
{
	ChangeVolumeSoundMem(GetVolume(volume), music->Handle);

	return;
}


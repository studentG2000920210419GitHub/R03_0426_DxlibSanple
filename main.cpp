//�w�b�_�[�̓ǂݍ���
#include "DxLib.h"   //Dxlib���g�����͕K�v

#define GAME_TITLE "�Q�[���^�C�g��"
#define GAME_WIDTH 1280
#define GAME_HIGHT 720
#define GAME_COLOR 32
#define GAME_ICON_ID   333

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetMainWindowText(GAME_TITLE);
	SetGraphMode(GAME_WIDTH, GAME_HIGHT, GAME_COLOR);
	SetWindowSize(GAME_WIDTH, GAME_HIGHT);
	SetBackgroundColor(255, 255, 255);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
		//�������[�v
	}
	while (1)
	{
		if (CheckHitKeyAll() == 0)
		{
			break;
		}
		if (ProcessMessage() != 0)
		{
			break;
		}
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

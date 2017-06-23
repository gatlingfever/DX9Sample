#include "ClientDefine.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	GET_SINGLE(CClient)->OnInit(hInstance);
	return GET_SINGLE(CClient)->Run();
}
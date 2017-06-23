#include "ClientDefine.h"

#include <crtdbg.h>

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// Memory leaking check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(77);


	GET_SINGLE(CClient)->OnInit(hInstance);
	GET_SINGLE(CClient)->Run();
	GET_SINGLE(CClient)->DestroyInstance();
	return 0;
}
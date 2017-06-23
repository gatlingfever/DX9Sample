#include "Client.h"

CClient::CClient()
{
}

CClient::~CClient()
{
}

void CClient::OnInit(HINSTANCE & hInstance)
{
	GET_SINGLE(CWndClass)->InitWindow(hInstance);
}

int CClient::Run()
{
	MSG msg;
	msg.message = WM_NULL;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				return 0;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			OnProcess();
			OnRender();
		}
	}
}

void CClient::OnProcess()
{
}

void CClient::OnRender()
{
}

void CClient::OnRelease()
{
	GET_SINGLE(CWndClass)->DestroyInstance();
}

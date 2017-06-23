#pragma once
#include "ClientDefine.h"

class CWndClass
{
	DECLARE_SINGLETON(CWndClass)
private:
	explicit CWndClass();
public:
	~CWndClass();

private:
	HINSTANCE				m_hInstance;
	HWND					m_hWnd;

public:
	HRESULT					InitWindow			(HINSTANCE& hInstance);
	LRESULT CALLBACK		WndProc				(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK	StaticWndProc		(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};


#include "WndClass.h"

CWndClass::CWndClass()
	: m_hInstance(nullptr)
	, m_hWnd(nullptr)
{
}

CWndClass::~CWndClass()
{
}

HRESULT CWndClass::InitWindow(HINSTANCE & hInstance)
{
	if (!hInstance)
		return E_FAIL;

	m_hInstance = hInstance;

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = StaticWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = TEXT("WindowClass");
	wcex.hIconSm = NULL;
	if (!RegisterClassEx(&wcex))
		return E_FAIL;

	RECT rect = { 0, 0, E_WINSTYLE::WIDTH, E_WINSTYLE::HEIGHT };
	AdjustWindowRect(&rect, E_WINSTYLE::STYLE, true);
	m_hWnd = CreateWindow(wcex.lpszClassName, nullptr, E_WINSTYLE::STYLE,
		CW_USEDEFAULT, 0, rect.right - rect.left, rect.bottom - rect.top, nullptr, nullptr, m_hInstance, nullptr);
	if(!m_hWnd)
	{
		return E_FAIL;
	}

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return S_OK;
}

LRESULT CWndClass::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CWndClass::StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return GetInstance()->WndProc(hWnd, message, wParam, lParam);
}

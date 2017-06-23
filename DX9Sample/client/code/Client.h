#pragma once
#include "ClientDefine.h"

class CClient
{
	DECLARE_SINGLETON(CClient)
private:
	explicit CClient();
public:
	~CClient();

public:
	void	OnInit			(HINSTANCE& hInstance);
	int		Run				();

private:
	void	OnProcess		();
	void	OnRender		();
	void	OnRelease		();
};
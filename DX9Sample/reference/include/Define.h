#ifndef __DEFINE_H__
#define __DEFINE_H__

#pragma region INCLUDE
	// Runtime
	#include <stdlib.h>
	#include <math.h>
	#include <malloc.h>
	#include <memory.h>
	#include <tchar.h>
	#include <algorithm>

	// Data Structure
	#include <vector>
	#include <list>
	#include <queue>
	#include <stack>
	#include <unordered_map>
	#include <unordered_set>  

	// Windows
	#include <sdkddkver.h>
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>

	// DirectX
	#include <d3d9.h>
	#include <d3dx9.h>

	// Common Header
	#include "Constant.h"
	#include "Enumeration.h"
	#include "Macro.h"
#pragma endregion

#pragma region C++
	#ifdef __cplusplus
		#define EXTERN extern "C"
	#else
		#define EXTERN 
	#endif  
#pragma endregion

#endif // !__DEFINE_H__

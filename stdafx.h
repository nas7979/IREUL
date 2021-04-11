#pragma once
#include <math.h>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <functional>
#include <time.h>
#include "SDKsound.h"
#include "SDKwavefile.h"

#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "dsound.lib")

#define g_Device DXUTGetD3D9Device()
#define DT SYSTEM->GetDT()

#define RED 0xffff0000
#define GREEN 0xff00ff00
#define BLUE 0xff0000ff
#define YELLOW 0xffffff00
#define PINK 0xffff00ff
#define SKYBLUE 0xff00ffff
#define ORANGE 0xffff9600
#define YELLOWGREEN 0xffBEff00
#define PURPLE 0xff8000ff
#define MINT 0xff00ffC8
#define BLACK 0xff000000
#define WHITE 0xffffffff

using Vec2 = D3DXVECTOR2;
using Vec3 = D3DXVECTOR3;
using Matrix = D3DXMATRIX;

using namespace std;


#include "cImageManager.h"
#include "cObjectManager.h"
#include "cCameraManager.h"
#include "cSceneManager.h"
#include "cSoundManager.h"
#include "cInputManager.h"
#include "cParticleManager.h"
#include "cSystemManager.h"
#include "Math.h"
using namespace Math;
#include "cScheduleManager.h"

#include "cCollider.h"
#include "cRenderer.h"
#include "cPath.h"
#include "cTimeLine.h"
#include "cAnimation.h"
#include "cEmitter.h"
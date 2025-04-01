// myIDirect3DDevice8.h
#pragma once

typedef int i32;
typedef float f32;
typedef short i16;
typedef unsigned char u8;
typedef char i8;
typedef unsigned int ZunColor;

struct EnemyFlags
{
    // First byte
    u8 unk1 : 2;
    u8 unk2 : 3;
    u8 unk3 : 1;
    u8 unk4 : 1;
    u8 unk5 : 1;

    // Second byte
    u8 unk6 : 1;
    u8 unk7 : 1;
    u8 unk8 : 1;
    u8 isBoss : 1;
    u8 unk10 : 1;
    u8 unk11 : 3;

    // Third byte
    bool shouldClampPos : 1;
    u8 unk13 : 1;
    u8 unk14 : 1;
    u8 unk15 : 1;
    u8 unk16 : 1;

    // Rest is padding.
};

struct AnmVm
{
    char dummy[0x110];
};

struct EnemyEclContext
{
    char dummy[0x4C];
};

struct ZunTimer
{
    char dummy[0xC];
};

struct EnemyBulletShooter
{
    char dummy[0x54];
};

typedef EnemyBulletShooter EnemyLaserShooter;

struct Enemy
{
    AnmVm primaryVm;
    AnmVm vms[8];
    EnemyEclContext currentContext;
    EnemyEclContext savedContextStack[8];
    i32 stackDepth;
    i32 unk_c40;
    i32 deathCallbackSub;
    i32 interrupts[8];
    i32 runInterrupt;
    D3DXVECTOR3 position;
    D3DXVECTOR3 hitboxDimensions;
    D3DXVECTOR3 axisSpeed;
    f32 angle;
    f32 angularVelocity;
    f32 speed;
    f32 acceleration;
    D3DXVECTOR3 shootOffset;
    D3DXVECTOR3 moveInterp;
    D3DXVECTOR3 moveInterpStartPos;
    ZunTimer moveInterpTimer;
    i32 moveInterpStartTime;
    f32 bulletRankSpeedLow;
    f32 bulletRankSpeedHigh;
    i16 bulletRankAmount1Low;
    i16 bulletRankAmount1High;
    i16 bulletRankAmount2Low;
    i16 bulletRankAmount2High;
    i32 life;
    i32 maxLife;
    i32 score;
    ZunTimer bossTimer;
    ZunColor color;
    EnemyBulletShooter bulletProps;
    i32 shootInterval;
    ZunTimer shootIntervalTimer;
    EnemyLaserShooter laserProps;
    void *lasers[32]; // This looks like a structure
    i32 laserStore;
    u8 deathAnm1;
    u8 deathAnm2;
    u8 deathAnm3;
    i8 itemDrop;
    u8 bossId;
    u8 unk_e41;
    ZunTimer exInsFunc10Timer;
    EnemyFlags flags;
};

class myIDirect3DDevice8 : public IDirect3DDevice8   
{
public:

	myIDirect3DDevice8(IDirect3DDevice8* pOriginal);
	virtual ~myIDirect3DDevice8();

	// START: The original DX8.1a function definitions
	HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObj);
    ULONG   __stdcall AddRef(void);
    ULONG   __stdcall Release(void);
    HRESULT __stdcall TestCooperativeLevel(void);
    UINT    __stdcall GetAvailableTextureMem(void);
    HRESULT __stdcall ResourceManagerDiscardBytes(DWORD Bytes);
    HRESULT __stdcall GetDirect3D(IDirect3D8** ppD3D8);
    HRESULT __stdcall GetDeviceCaps(D3DCAPS8* pCaps);
    HRESULT __stdcall GetDisplayMode(D3DDISPLAYMODE* pMode);
    HRESULT __stdcall GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters);
    HRESULT __stdcall SetCursorProperties(UINT XHotSpot,UINT YHotSpot,IDirect3DSurface8* pCursorBitmap);
    void    __stdcall SetCursorPosition(int XScreenSpace,int YScreenSpace,DWORD Flags);
    BOOL    __stdcall ShowCursor(BOOL bShow);
    HRESULT __stdcall CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain8** pSwapChain);
    HRESULT __stdcall Reset(D3DPRESENT_PARAMETERS* pPresentationParameters);
    HRESULT __stdcall Present(CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion);
    HRESULT __stdcall GetBackBuffer(UINT BackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface8** ppBackBuffer);
    HRESULT __stdcall GetRasterStatus(D3DRASTER_STATUS* pRasterStatus);
    void    __stdcall SetGammaRamp(DWORD Flags,CONST D3DGAMMARAMP* pRamp);
    void    __stdcall GetGammaRamp(D3DGAMMARAMP* pRamp);
    HRESULT __stdcall CreateTexture(UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture8** ppTexture);
    HRESULT __stdcall CreateVolumeTexture(UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture8** ppVolumeTexture);
    HRESULT __stdcall CreateCubeTexture(UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture8** ppCubeTexture);
    HRESULT __stdcall CreateVertexBuffer(UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer8** ppVertexBuffer);
    HRESULT __stdcall CreateIndexBuffer(UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer8** ppIndexBuffer);
    HRESULT __stdcall CreateRenderTarget(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,BOOL Lockable,IDirect3DSurface8** ppSurface);
    HRESULT __stdcall CreateDepthStencilSurface(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,IDirect3DSurface8** ppSurface);
    HRESULT __stdcall CreateImageSurface(UINT Width,UINT Height,D3DFORMAT Format,IDirect3DSurface8** ppSurface);
    HRESULT __stdcall CopyRects(IDirect3DSurface8* pSourceSurface,CONST RECT* pSourceRectsArray,UINT cRects,IDirect3DSurface8* pDestinationSurface,CONST POINT* pDestPointsArray);
    HRESULT __stdcall UpdateTexture(IDirect3DBaseTexture8* pSourceTexture,IDirect3DBaseTexture8* pDestinationTexture);
    HRESULT __stdcall GetFrontBuffer(IDirect3DSurface8* pDestSurface);
    HRESULT __stdcall SetRenderTarget(IDirect3DSurface8* pRenderTarget,IDirect3DSurface8* pNewZStencil);
    HRESULT __stdcall GetRenderTarget(IDirect3DSurface8** ppRenderTarget);
    HRESULT __stdcall GetDepthStencilSurface(IDirect3DSurface8** ppZStencilSurface);
    HRESULT __stdcall BeginScene(THIS);
    HRESULT __stdcall EndScene(THIS);
    HRESULT __stdcall Clear(DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil);
    HRESULT __stdcall SetTransform(D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix);
    HRESULT __stdcall GetTransform(D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix);
    HRESULT __stdcall MultiplyTransform(D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix);
    HRESULT __stdcall SetViewport(CONST D3DVIEWPORT8* pViewport);
    HRESULT __stdcall GetViewport(D3DVIEWPORT8* pViewport);
    HRESULT __stdcall SetMaterial(CONST D3DMATERIAL8* pMaterial);
    HRESULT __stdcall GetMaterial(D3DMATERIAL8* pMaterial);
    HRESULT __stdcall SetLight(DWORD Index,CONST D3DLIGHT8* pLight);
    HRESULT __stdcall GetLight(DWORD Index,D3DLIGHT8* pLight);
    HRESULT __stdcall LightEnable(DWORD Index,BOOL Enable);
    HRESULT __stdcall GetLightEnable(DWORD Index,BOOL* pEnable);
    HRESULT __stdcall SetClipPlane(DWORD Index,CONST float* pPlane);
    HRESULT __stdcall GetClipPlane(DWORD Index,float* pPlane);
    HRESULT __stdcall SetRenderState(D3DRENDERSTATETYPE State,DWORD Value);
    HRESULT __stdcall GetRenderState(D3DRENDERSTATETYPE State,DWORD* pValue);
    HRESULT __stdcall BeginStateBlock(THIS);
    HRESULT __stdcall EndStateBlock(DWORD* pToken);
    HRESULT __stdcall ApplyStateBlock(DWORD Token);
    HRESULT __stdcall CaptureStateBlock(DWORD Token);
    HRESULT __stdcall DeleteStateBlock(DWORD Token);
    HRESULT __stdcall CreateStateBlock(D3DSTATEBLOCKTYPE Type,DWORD* pToken);
    HRESULT __stdcall SetClipStatus(CONST D3DCLIPSTATUS8* pClipStatus);
    HRESULT __stdcall GetClipStatus(D3DCLIPSTATUS8* pClipStatus);
    HRESULT __stdcall GetTexture(DWORD Stage,IDirect3DBaseTexture8** ppTexture);
    HRESULT __stdcall SetTexture(DWORD Stage,IDirect3DBaseTexture8* pTexture);
    HRESULT __stdcall GetTextureStageState(DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue);
    HRESULT __stdcall SetTextureStageState(DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value);
    HRESULT __stdcall ValidateDevice(DWORD* pNumPasses);
    HRESULT __stdcall GetInfo(DWORD DevInfoID,void* pDevInfoStruct,DWORD DevInfoStructSize);
    HRESULT __stdcall SetPaletteEntries(UINT PaletteNumber,CONST PALETTEENTRY* pEntries);
    HRESULT __stdcall GetPaletteEntries(UINT PaletteNumber,PALETTEENTRY* pEntries);
    HRESULT __stdcall SetCurrentTexturePalette(UINT PaletteNumber);
    HRESULT __stdcall GetCurrentTexturePalette(UINT *PaletteNumber);
    HRESULT __stdcall DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount);
    HRESULT __stdcall DrawIndexedPrimitive(D3DPRIMITIVETYPE Type,UINT minIndex,UINT NumVertices,UINT startIndex,UINT primCount);
    HRESULT __stdcall DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride);
    HRESULT __stdcall DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertexIndices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride);
    HRESULT __stdcall ProcessVertices(UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer8* pDestBuffer,DWORD Flags);
    HRESULT __stdcall CreateVertexShader(CONST DWORD* pDeclaration,CONST DWORD* pFunction,DWORD* pHandle,DWORD Usage);
    HRESULT __stdcall SetVertexShader(DWORD Handle);
    HRESULT __stdcall GetVertexShader(DWORD* pHandle);
    HRESULT __stdcall DeleteVertexShader(DWORD Handle);
    HRESULT __stdcall SetVertexShaderConstant(DWORD Register,CONST void* pConstantData,DWORD ConstantCount);
    HRESULT __stdcall GetVertexShaderConstant(DWORD Register,void* pConstantData,DWORD ConstantCount);
    HRESULT __stdcall GetVertexShaderDeclaration(DWORD Handle,void* pData,DWORD* pSizeOfData);
    HRESULT __stdcall GetVertexShaderFunction(DWORD Handle,void* pData,DWORD* pSizeOfData);
    HRESULT __stdcall SetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer8* pStreamData,UINT Stride);
    HRESULT __stdcall GetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer8** ppStreamData,UINT* pStride);
    HRESULT __stdcall SetIndices(IDirect3DIndexBuffer8* pIndexData,UINT BaseVertexIndex);
    HRESULT __stdcall GetIndices(IDirect3DIndexBuffer8** ppIndexData,UINT* pBaseVertexIndex);
    HRESULT __stdcall CreatePixelShader(CONST DWORD* pFunction,DWORD* pHandle);
    HRESULT __stdcall SetPixelShader(DWORD Handle);
    HRESULT __stdcall GetPixelShader(DWORD* pHandle);
    HRESULT __stdcall DeletePixelShader(DWORD Handle);
    HRESULT __stdcall SetPixelShaderConstant(DWORD Register,CONST void* pConstantData,DWORD ConstantCount);
    HRESULT __stdcall GetPixelShaderConstant(DWORD Register,void* pConstantData,DWORD ConstantCount);
    HRESULT __stdcall GetPixelShaderFunction(DWORD Handle,void* pData,DWORD* pSizeOfData);
    HRESULT __stdcall DrawRectPatch(UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo);
    HRESULT __stdcall DrawTriPatch(UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo);
    HRESULT __stdcall DeletePatch(UINT Handle);
	// END: The original DX8.1a function definitions

private:
	IDirect3DTexture8* hitbox_texture;
    IDirect3DTexture8* enemy_texture;
	unsigned int count;
	int focused_time;
	bool draw;
	unsigned int frame_count;
    IDirect3DDevice8 *m_pIDirect3DDevice8;
};

struct lvert
{
    FLOAT    x, y, z, q;
	D3DCOLOR diffuse;
	FLOAT    tu, tv;
};

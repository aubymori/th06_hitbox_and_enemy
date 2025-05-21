#pragma once
#include "mind3d8.h"
#include <stdint.h>
#include <math.h>

class CDirect3DDevice8Wrapper : public IDirect3DDevice8
{
private:
	IDirect3DDevice8 *_pD3DDev8;
	IDirect3DTexture8 *_pHitboxTexture;
	IDirect3DTexture8 *_pEnemyTexture;
	UINT _uCount;
	int _iFocusedTime;
	bool _fDraw;
	UINT _uFrameCount;
    int _iLastBossHealth;

public:
	CDirect3DDevice8Wrapper(IDirect3DDevice8 *pOrigD3DDev8);
    ~CDirect3DDevice8Wrapper();

    // == Begin IUnknown interface ==
    STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;
    // == End IUnknown interface ==

    // == Begin IDirect3DDevice8 interface ==
    STDMETHODIMP TestCooperativeLevel() override;
    STDMETHODIMP_(UINT) GetAvailableTextureMem() override;
    STDMETHODIMP ResourceManagerDiscardBytes(DWORD  Bytes) override;
    STDMETHODIMP GetDirect3D(IDirect3D8 **ppD3D8) override;
    STDMETHODIMP GetDeviceCaps(D3DCAPS8 *pCaps) override;
    STDMETHODIMP GetDisplayMode(D3DDISPLAYMODE *pMode) override;
    STDMETHODIMP GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters) override;
    STDMETHODIMP SetCursorProperties(UINT  XHotSpot, UINT  YHotSpot, IDirect3DSurface8 *pCursorBitmap) override;
    STDMETHODIMP_(void) SetCursorPosition(UINT  XScreenSpace, UINT  YScreenSpace, DWORD  Flags) override;
    STDMETHODIMP_(WINBOOL) ShowCursor(WINBOOL  bShow) override;
    STDMETHODIMP CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain8 **pSwapChain) override;
    STDMETHODIMP Reset(D3DPRESENT_PARAMETERS *pPresentationParameters) override;
    STDMETHODIMP Present(const RECT *src_rect, const RECT *dst_rect, HWND dst_window_override,
        const RGNDATA *dirty_region) override;
    STDMETHODIMP GetBackBuffer(UINT  BackBuffer, D3DBACKBUFFER_TYPE  Type, IDirect3DSurface8 **ppBackBuffer) override;
    STDMETHODIMP GetRasterStatus(D3DRASTER_STATUS *pRasterStatus) override;
    STDMETHODIMP_(void) SetGammaRamp(DWORD flags, const D3DGAMMARAMP *ramp) override;
    STDMETHODIMP_(void) GetGammaRamp(D3DGAMMARAMP *pRamp) override;
    STDMETHODIMP CreateTexture(UINT  Width, UINT  Height, UINT  Levels, DWORD  Usage, D3DFORMAT  Format, D3DPOOL  Pool, IDirect3DTexture8 **ppTexture) override;
    STDMETHODIMP CreateVolumeTexture(UINT  Width, UINT  Height, UINT  Depth, UINT  Levels, DWORD  Usage, D3DFORMAT  Format, D3DPOOL  Pool, IDirect3DVolumeTexture8 **ppVolumeTexture) override;
    STDMETHODIMP CreateCubeTexture(UINT  EdgeLength, UINT  Levels, DWORD  Usage, D3DFORMAT  Format, D3DPOOL  Pool, IDirect3DCubeTexture8 **ppCubeTexture) override;
    STDMETHODIMP CreateVertexBuffer(UINT  Length, DWORD  Usage, DWORD  FVF, D3DPOOL  Pool, IDirect3DVertexBuffer8 **ppVertexBuffer) override;
    STDMETHODIMP CreateIndexBuffer(UINT  Length, DWORD  Usage, D3DFORMAT  Format, D3DPOOL  Pool, IDirect3DIndexBuffer8 **ppIndexBuffer) override;
    STDMETHODIMP CreateRenderTarget(UINT  Width, UINT  Height, D3DFORMAT  Format, D3DMULTISAMPLE_TYPE  MultiSample, WINBOOL  Lockable, IDirect3DSurface8 **ppSurface) override;
    STDMETHODIMP CreateDepthStencilSurface(UINT  Width, UINT  Height, D3DFORMAT  Format, D3DMULTISAMPLE_TYPE  MultiSample, IDirect3DSurface8 **ppSurface) override;
    STDMETHODIMP CreateImageSurface(UINT  Width, UINT  Height, D3DFORMAT  Format, IDirect3DSurface8 **ppSurface) override;
    STDMETHODIMP CopyRects(IDirect3DSurface8 *src_surface, const RECT *src_rects,
        UINT rect_count, IDirect3DSurface8 *dst_surface, const POINT *dst_points) override;
    STDMETHODIMP UpdateTexture(IDirect3DBaseTexture8 *pSourceTexture, IDirect3DBaseTexture8 *pDestinationTexture) override;
    STDMETHODIMP GetFrontBuffer(IDirect3DSurface8 *pDestSurface) override;
    STDMETHODIMP SetRenderTarget(IDirect3DSurface8 *pRenderTarget, IDirect3DSurface8 *pNewZStencil) override;
    STDMETHODIMP GetRenderTarget(IDirect3DSurface8 **ppRenderTarget) override;
    STDMETHODIMP GetDepthStencilSurface(IDirect3DSurface8 **ppZStencilSurface) override;
    STDMETHODIMP BeginScene() override;
    STDMETHODIMP EndScene() override;
    STDMETHODIMP Clear(DWORD rect_count, const D3DRECT *rects, DWORD flags, D3DCOLOR color,
        float z, DWORD stencil) override;
    STDMETHODIMP SetTransform(D3DTRANSFORMSTATETYPE state, const D3DMATRIX *matrix) override;
    STDMETHODIMP GetTransform(D3DTRANSFORMSTATETYPE  State, D3DMATRIX *pMatrix) override;
    STDMETHODIMP MultiplyTransform(D3DTRANSFORMSTATETYPE state, const D3DMATRIX *matrix) override;
    STDMETHODIMP SetViewport(const D3DVIEWPORT8 *viewport) override;
    STDMETHODIMP GetViewport(D3DVIEWPORT8 *pViewport) override;
    STDMETHODIMP SetMaterial(const D3DMATERIAL8 *material) override;
    STDMETHODIMP GetMaterial(D3DMATERIAL8 *pMaterial) override;
    STDMETHODIMP SetLight(DWORD index, const D3DLIGHT8 *light) override;
    STDMETHODIMP GetLight(DWORD  Index, D3DLIGHT8 *pLight) override;
    STDMETHODIMP LightEnable(DWORD  Index, WINBOOL  Enable) override;
    STDMETHODIMP GetLightEnable(DWORD  Index, WINBOOL *pEnable) override;
    STDMETHODIMP SetClipPlane(DWORD index, const float *plane) override;
    STDMETHODIMP GetClipPlane(DWORD  Index, float *pPlane) override;
    STDMETHODIMP SetRenderState(D3DRENDERSTATETYPE  State, DWORD  Value) override;
    STDMETHODIMP GetRenderState(D3DRENDERSTATETYPE  State, DWORD *pValue) override;
    STDMETHODIMP BeginStateBlock() override;
    STDMETHODIMP EndStateBlock(DWORD *pToken) override;
    STDMETHODIMP ApplyStateBlock(DWORD  Token) override;
    STDMETHODIMP CaptureStateBlock(DWORD  Token) override;
    STDMETHODIMP DeleteStateBlock(DWORD  Token) override;
    STDMETHODIMP CreateStateBlock(D3DSTATEBLOCKTYPE  Type, DWORD *pToken) override;
    STDMETHODIMP SetClipStatus(const D3DCLIPSTATUS8 *clip_status) override;
    STDMETHODIMP GetClipStatus(D3DCLIPSTATUS8 *pClipStatus) override;
    STDMETHODIMP GetTexture(DWORD  Stage, IDirect3DBaseTexture8 **ppTexture) override;
    STDMETHODIMP SetTexture(DWORD  Stage, IDirect3DBaseTexture8 *pTexture) override;
    STDMETHODIMP GetTextureStageState(DWORD  Stage, D3DTEXTURESTAGESTATETYPE  Type, DWORD *pValue) override;
    STDMETHODIMP SetTextureStageState(DWORD  Stage, D3DTEXTURESTAGESTATETYPE  Type, DWORD  Value) override;
    STDMETHODIMP ValidateDevice(DWORD *pNumPasses) override;
    STDMETHODIMP GetInfo(DWORD  DevInfoID, void *pDevInfoStruct, DWORD  DevInfoStructSize) override;
    STDMETHODIMP SetPaletteEntries(UINT palette_idx, const PALETTEENTRY *entries) override;
    STDMETHODIMP GetPaletteEntries(UINT  PaletteNumber, PALETTEENTRY *pEntries) override;
    STDMETHODIMP SetCurrentTexturePalette(UINT  PaletteNumber) override;
    STDMETHODIMP GetCurrentTexturePalette(UINT *PaletteNumber) override;
    STDMETHODIMP DrawPrimitive(D3DPRIMITIVETYPE  PrimitiveType, UINT  StartVertex, UINT  PrimitiveCount) override;
    STDMETHODIMP DrawIndexedPrimitive(D3DPRIMITIVETYPE  PrimitiveType, UINT  minIndex, UINT  NumVertices, UINT  startIndex, UINT  primCount) override;
    STDMETHODIMP DrawPrimitiveUP(D3DPRIMITIVETYPE primitive_type, UINT primitive_count,
        const void *data, UINT stride) override;
    STDMETHODIMP DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE primitive_type, UINT min_vertex_idx,
        UINT vertex_count, UINT primitive_count, const void *index_data, D3DFORMAT index_format,
        const void *data, UINT stride) override;
    STDMETHODIMP ProcessVertices(UINT  SrcStartIndex, UINT  DestIndex, UINT  VertexCount, IDirect3DVertexBuffer8 *pDestBuffer, DWORD  Flags) override;
    STDMETHODIMP CreateVertexShader(const DWORD *declaration, const DWORD *byte_code,
        DWORD *shader, DWORD usage) override;
    STDMETHODIMP SetVertexShader(DWORD  Handle) override;
    STDMETHODIMP GetVertexShader(DWORD *pHandle) override;
    STDMETHODIMP DeleteVertexShader(DWORD  Handle) override;
    STDMETHODIMP SetVertexShaderConstant(DWORD reg_idx, const void *data, DWORD count) override;
    STDMETHODIMP GetVertexShaderConstant(DWORD  Register, void *pConstantData, DWORD  ConstantCount) override;
    STDMETHODIMP GetVertexShaderDeclaration(DWORD  Handle, void *pData, DWORD *pSizeOfData) override;
    STDMETHODIMP GetVertexShaderFunction(DWORD  Handle, void *pData, DWORD *pSizeOfData) override;
    STDMETHODIMP SetStreamSource(UINT  StreamNumber, IDirect3DVertexBuffer8 *pStreamData, UINT  Stride) override;
    STDMETHODIMP GetStreamSource(UINT  StreamNumber, IDirect3DVertexBuffer8 **ppStreamData, UINT *pStride) override;
    STDMETHODIMP SetIndices(IDirect3DIndexBuffer8 *pIndexData, UINT  BaseVertexIndex) override;
    STDMETHODIMP GetIndices(IDirect3DIndexBuffer8 **ppIndexData, UINT *pBaseVertexIndex) override;
    STDMETHODIMP CreatePixelShader(const DWORD *byte_code, DWORD *shader) override;
    STDMETHODIMP SetPixelShader(DWORD  Handle) override;
    STDMETHODIMP GetPixelShader(DWORD *pHandle) override;
    STDMETHODIMP DeletePixelShader(DWORD  Handle) override;
    STDMETHODIMP SetPixelShaderConstant(DWORD reg_idx, const void *data, DWORD count) override;
    STDMETHODIMP GetPixelShaderConstant(DWORD  Register, void *pConstantData, DWORD  ConstantCount) override;
    STDMETHODIMP GetPixelShaderFunction(DWORD  Handle, void *pData, DWORD *pSizeOfData) override;
    STDMETHODIMP DrawRectPatch(UINT handle, const float *segment_count,
        const D3DRECTPATCH_INFO *patch_info) override;
    STDMETHODIMP DrawTriPatch(UINT handle, const float *segment_count,
        const D3DTRIPATCH_INFO *patch_info) override;
    STDMETHODIMP DeletePatch(UINT  Handle) override;
    // == End IDirect3DDevice8 interface ==
};

struct VERTEXSTRUCT
{
    FLOAT    x, y, z, q;
    D3DCOLOR diffuse;
    FLOAT    tu, tv;
};
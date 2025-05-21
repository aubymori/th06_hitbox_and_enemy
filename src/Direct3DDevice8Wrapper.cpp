#include "Direct3DDevice8Wrapper.h"

CDirect3DDevice8Wrapper::CDirect3DDevice8Wrapper(IDirect3DDevice8 *pOrigD3DDev8)
	: _pD3DDev8(pOrigD3DDev8)
	, _pHitboxTexture(nullptr)
	, _pEnemyTexture(nullptr)
	, _uCount(0)
	, _iFocusedTime(0)
	, _fDraw(0)
	, _uFrameCount(0)
    , _iLastBossHealth(INT32_MAX)
{
}

CDirect3DDevice8Wrapper::~CDirect3DDevice8Wrapper()
{
    if (_pHitboxTexture)
        _pHitboxTexture->Release();
    if (_pEnemyTexture)
        _pEnemyTexture->Release();
}

STDMETHODIMP CDirect3DDevice8Wrapper::QueryInterface(REFIID riid, void **ppvObject)
{
    HRESULT hr = _pD3DDev8->QueryInterface(riid, ppvObject);
    if (SUCCEEDED(hr))
    {
        *ppvObject = this;
    }
    return hr;
}

STDMETHODIMP_(ULONG) CDirect3DDevice8Wrapper::AddRef()
{
    return _pD3DDev8->AddRef();
}

STDMETHODIMP_(ULONG) CDirect3DDevice8Wrapper::Release()
{
    ULONG cRef = _pD3DDev8->Release();
    if (0 == cRef)
        delete this;
    return cRef;
}

HRESULT CDirect3DDevice8Wrapper::TestCooperativeLevel()
{
    return _pD3DDev8->TestCooperativeLevel();
}

UINT CDirect3DDevice8Wrapper::GetAvailableTextureMem()
{
    return _pD3DDev8->GetAvailableTextureMem();
}

HRESULT CDirect3DDevice8Wrapper::ResourceManagerDiscardBytes(DWORD Bytes)
{
    return _pD3DDev8->ResourceManagerDiscardBytes(Bytes);
}

HRESULT CDirect3DDevice8Wrapper::GetDirect3D(IDirect3D8 **ppD3D8)
{
    return _pD3DDev8->GetDirect3D(ppD3D8);
}

HRESULT CDirect3DDevice8Wrapper::GetDeviceCaps(D3DCAPS8 *pCaps)
{
    return _pD3DDev8->GetDeviceCaps(pCaps);
}

HRESULT CDirect3DDevice8Wrapper::GetDisplayMode(D3DDISPLAYMODE *pMode)
{
    return _pD3DDev8->GetDisplayMode(pMode);
}

HRESULT CDirect3DDevice8Wrapper::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
    return _pD3DDev8->GetCreationParameters(pParameters);
}

HRESULT CDirect3DDevice8Wrapper::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface8 *pCursorBitmap)
{
    return _pD3DDev8->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void CDirect3DDevice8Wrapper::SetCursorPosition(UINT XScreenSpace, UINT YScreenSpace, DWORD Flags)
{
    _pD3DDev8->SetCursorPosition(XScreenSpace, YScreenSpace, Flags);
}

WINBOOL CDirect3DDevice8Wrapper::ShowCursor(WINBOOL bShow)
{
    return _pD3DDev8->ShowCursor(bShow);
}

HRESULT CDirect3DDevice8Wrapper::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain8 **pSwapChain)
{
    return _pD3DDev8->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT CDirect3DDevice8Wrapper::Reset(D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    return _pD3DDev8->Reset(pPresentationParameters);
}

HRESULT CDirect3DDevice8Wrapper::Present(const RECT *src_rect, const RECT *dst_rect, HWND dst_window_override, const RGNDATA *dirty_region)
{
    return _pD3DDev8->Present(src_rect, dst_rect, dst_window_override, dirty_region);
}

HRESULT CDirect3DDevice8Wrapper::GetBackBuffer(UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8 **ppBackBuffer)
{
    return _pD3DDev8->GetBackBuffer(BackBuffer, Type, ppBackBuffer);
}

HRESULT CDirect3DDevice8Wrapper::GetRasterStatus(D3DRASTER_STATUS *pRasterStatus)
{
    return _pD3DDev8->GetRasterStatus(pRasterStatus);
}

void CDirect3DDevice8Wrapper::SetGammaRamp(DWORD flags, const D3DGAMMARAMP *ramp)
{
    _pD3DDev8->SetGammaRamp(flags, ramp);
}

void CDirect3DDevice8Wrapper::GetGammaRamp(D3DGAMMARAMP *pRamp)
{
    _pD3DDev8->GetGammaRamp(pRamp);
}

HRESULT CDirect3DDevice8Wrapper::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture8 **ppTexture)
{
    return _pD3DDev8->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture);
}

HRESULT CDirect3DDevice8Wrapper::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture8 **ppVolumeTexture)
{
    return _pD3DDev8->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture);
}

HRESULT CDirect3DDevice8Wrapper::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture8 **ppCubeTexture)
{
    return _pD3DDev8->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture);
}

HRESULT CDirect3DDevice8Wrapper::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer8 **ppVertexBuffer)
{
    return _pD3DDev8->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer);
}

HRESULT CDirect3DDevice8Wrapper::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer8 **ppIndexBuffer)
{
    return _pD3DDev8->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer);
}

HRESULT CDirect3DDevice8Wrapper::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, WINBOOL Lockable, IDirect3DSurface8 **ppSurface)
{
    return _pD3DDev8->CreateRenderTarget(Width, Height, Format, MultiSample, Lockable, ppSurface);
}

HRESULT CDirect3DDevice8Wrapper::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, IDirect3DSurface8 **ppSurface)
{
    return _pD3DDev8->CreateDepthStencilSurface(Width, Height, Format, MultiSample, ppSurface);
}

HRESULT CDirect3DDevice8Wrapper::CreateImageSurface(UINT Width, UINT Height, D3DFORMAT Format, IDirect3DSurface8 **ppSurface)
{
    return _pD3DDev8->CreateImageSurface(Width, Height, Format, ppSurface);
}

HRESULT CDirect3DDevice8Wrapper::CopyRects(IDirect3DSurface8 *src_surface, const RECT *src_rects, UINT rect_count, IDirect3DSurface8 *dst_surface, const POINT *dst_points)
{
    return _pD3DDev8->CopyRects(src_surface, src_rects, rect_count, dst_surface, dst_points);
}

HRESULT CDirect3DDevice8Wrapper::UpdateTexture(IDirect3DBaseTexture8 *pSourceTexture, IDirect3DBaseTexture8 *pDestinationTexture)
{
    return _pD3DDev8->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT CDirect3DDevice8Wrapper::GetFrontBuffer(IDirect3DSurface8 *pDestSurface)
{
    return _pD3DDev8->GetFrontBuffer(pDestSurface);
}

HRESULT CDirect3DDevice8Wrapper::SetRenderTarget(IDirect3DSurface8 *pRenderTarget, IDirect3DSurface8 *pNewZStencil)
{
    return _pD3DDev8->SetRenderTarget(pRenderTarget, pNewZStencil);
}

HRESULT CDirect3DDevice8Wrapper::GetRenderTarget(IDirect3DSurface8 **ppRenderTarget)
{
    return _pD3DDev8->GetRenderTarget(ppRenderTarget);
}

HRESULT CDirect3DDevice8Wrapper::GetDepthStencilSurface(IDirect3DSurface8 **ppZStencilSurface)
{
    return _pD3DDev8->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT CDirect3DDevice8Wrapper::BeginScene()
{
    return _pD3DDev8->BeginScene();
}

HRESULT CDirect3DDevice8Wrapper::EndScene()
{
    if (!_pHitboxTexture)
        D3DXCreateTextureFromFileExW(_pD3DDev8, L"hitbox.png", 0, 0, 9, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, nullptr, nullptr, &_pHitboxTexture);
    if (!_pEnemyTexture)
        D3DXCreateTextureFromFileExW(_pD3DDev8, L"enemy.png", 0, 0, 9, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, nullptr, nullptr, &_pEnemyTexture);

    constexpr float kBorderX = 32.0;
    constexpr float kBorderY = 16.0;
    constexpr float PI = 3.14159f;

    if (_fDraw)
    {
        if (_pHitboxTexture)
        {
            bool fFocused = *((bool *)0x006CB00B);
            bool fPaused = *((bool *)0x00481B44);
            if (!fPaused)
            {
                if (fFocused)
                {
                    _iFocusedTime = max(0, _iFocusedTime - (256 / 32)); //How much the indicator has 'phased in'

                    const float flHalfHitbox = 32.5f * (1.0f - .9f * (_iFocusedTime / 255.0f));
                    const float flPlayerX = *((float *)0x006CAA80) + kBorderX + 1.5f;
                    const float flPlayerY = *((float *)0x006CAA84) + kBorderY + 1.5f;
                    const float flRadians = PI * (_uCount / 128.0f);
                    _uCount++;

                    DWORD dwStateToken;
                    _pD3DDev8->CreateStateBlock(D3DSBT_ALL, &dwStateToken);
                    _pD3DDev8->CaptureStateBlock(dwStateToken);

                    D3DVIEWPORT8 vp = {
                        32, 16,   // X, Y
                        384, 448, // Width, Height
                        0.0, 1.0  // MinZ, MaxZ
                    };

#define VERTEX(sign1, sign2, tu, tv) \
{ \
    flPlayerX + (sign1 ## flHalfHitbox * cosf(flRadians) + sign2 ## flHalfHitbox * -sinf(flRadians)), \
    flPlayerY + (sign1 ## flHalfHitbox * sinf(flRadians) + sign2 ## flHalfHitbox * cosf(flRadians)), \
    0.0045f, \
    1.0f, \
    (D3DCOLOR)(((_iFocusedTime) & 0xffu) << 24), \
    tu, \
    tv \
}

                    VERTEXSTRUCT verts[4] = {
                        VERTEX(-, -, 0.0f, 0.0f),
                        VERTEX(-, +, 0.0f, 1.0f),
                        VERTEX(+, -, 1.0f, 0.0f),
                        VERTEX(+, +, 1.0f, 1.0f)
                    };

#undef VERTEX

                    _pD3DDev8->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
                    _pD3DDev8->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SUBTRACT);
                    _pD3DDev8->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
                    _pD3DDev8->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
                    _pD3DDev8->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
                    _pD3DDev8->SetTexture(0, _pHitboxTexture);

                    _pD3DDev8->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
                    _pD3DDev8->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

                    _pD3DDev8->SetVertexShader(0x144);
                    _pD3DDev8->SetViewport(&vp);

                    _pD3DDev8->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
                    _pD3DDev8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
                    _pD3DDev8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
                    _pD3DDev8->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
                    _pD3DDev8->SetRenderState(D3DRS_SPECULARENABLE, FALSE);
                    _pD3DDev8->SetRenderState(D3DRS_TEXTUREFACTOR, 0x00000000);

                    _pD3DDev8->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &verts, sizeof(VERTEXSTRUCT));

                    _pD3DDev8->ApplyStateBlock(dwStateToken);
                    _pD3DDev8->DeleteStateBlock(dwStateToken);
                }
                else
                {
                    _iFocusedTime = min(_iFocusedTime + (256 / 32), 255);
                }
            }
        }

        const float kEnemyTextureWidth = 48.0f;
        const float kBossIndicatorY = 480 - kBorderY;
        if (_pEnemyTexture)
        {
            void *pBoss = *(void **)0x5A5F60;
            bool fDrawEnemy = false;
            int iBossHealth;
            if (pBoss)
            {
                iBossHealth = *(int *)((char *)pBoss + 0xCE4);
                fDrawEnemy = ((*(DWORD *)((char *)pBoss + 0xE51)) & 8) != 0 // Is the enemy a boss?
                    && iBossHealth > 0;  // Does it have more than 0 health?
            }

            if (fDrawEnemy)
            {
                float flBossX = *(float *)((char *)pBoss + 0xC6C);

                DWORD dwStateToken;
                _pD3DDev8->CreateStateBlock(D3DSBT_ALL, &dwStateToken);
                _pD3DDev8->CaptureStateBlock(dwStateToken);

                float X = kBorderX + flBossX - (kEnemyTextureWidth / 2.0f);
                float Y = kBossIndicatorY;

                D3DVIEWPORT8 vp = {
                    32, Y,         // X, Y
                    384, kBorderY, // Width, Height
                    0.0, 1.0       // MinZ, MaxZ
                };

                float flPlayerX = *(float *)0x006CAA80;
                float flDistance = min(fabsf(flBossX - flPlayerX), 64);
                float flOpacity = min(flDistance / 64 + .25f, 1.0f);

                if (_iLastBossHealth != INT32_MAX && _iLastBossHealth > iBossHealth)
                {
                    flOpacity *= 0.75f;
                }

                D3DCOLOR clrDiffuse = D3DCOLOR_ARGB((UINT)(flOpacity * 255.0f), 0, 0, 0);
                VERTEXSTRUCT verts[4] = {
                    { X,                      Y,            0.0f, 1.0f, clrDiffuse, 0.0f, 0.0f },
                    { X + kEnemyTextureWidth, Y,            0.0f, 1.0f, clrDiffuse, 1.0f, 0.0f },
                    { X,                      Y + kBorderY, 0.0f, 1.0f, clrDiffuse, 0.0f, 1.0f },
                    { X + kEnemyTextureWidth, Y + kBorderY, 0.0f, 1.0f, clrDiffuse, 1.0f, 1.0f }
                };

                _pD3DDev8->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
                _pD3DDev8->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
                _pD3DDev8->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
                _pD3DDev8->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
                _pD3DDev8->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
                _pD3DDev8->SetTexture(0, _pEnemyTexture);

                _pD3DDev8->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
                _pD3DDev8->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

                _pD3DDev8->SetVertexShader(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
                _pD3DDev8->SetViewport(&vp);

                _pD3DDev8->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
                _pD3DDev8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
                _pD3DDev8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
                _pD3DDev8->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
                _pD3DDev8->SetRenderState(D3DRS_SPECULARENABLE, FALSE);
                _pD3DDev8->SetRenderState(D3DRS_TEXTUREFACTOR, 0x00000000);

                _pD3DDev8->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, verts, sizeof(VERTEXSTRUCT));

                _pD3DDev8->ApplyStateBlock(dwStateToken);
                _pD3DDev8->DeleteStateBlock(dwStateToken);

                _iLastBossHealth = iBossHealth;
            }
        }
    }
    else
    {
        _iLastBossHealth = INT32_MAX;
    }

    _fDraw = false;
    return _pD3DDev8->EndScene();
}

HRESULT CDirect3DDevice8Wrapper::Clear(DWORD rect_count, const D3DRECT *rects, DWORD flags, D3DCOLOR color, float z, DWORD stencil)
{
    return _pD3DDev8->Clear(rect_count, rects, flags, color, z, stencil);
}

HRESULT CDirect3DDevice8Wrapper::SetTransform(D3DTRANSFORMSTATETYPE state, const D3DMATRIX *matrix)
{
    return _pD3DDev8->SetTransform(state, matrix);
}

HRESULT CDirect3DDevice8Wrapper::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
    return _pD3DDev8->GetTransform(State, pMatrix);
}

HRESULT CDirect3DDevice8Wrapper::MultiplyTransform(D3DTRANSFORMSTATETYPE state, const D3DMATRIX *matrix)
{
    return _pD3DDev8->MultiplyTransform(state, matrix);
}

HRESULT CDirect3DDevice8Wrapper::SetViewport(const D3DVIEWPORT8 *viewport)
{
    return _pD3DDev8->SetViewport(viewport);
}

HRESULT CDirect3DDevice8Wrapper::GetViewport(D3DVIEWPORT8 *pViewport)
{
    return _pD3DDev8->GetViewport(pViewport);
}

HRESULT CDirect3DDevice8Wrapper::SetMaterial(const D3DMATERIAL8 *material)
{
    return _pD3DDev8->SetMaterial(material);
}

HRESULT CDirect3DDevice8Wrapper::GetMaterial(D3DMATERIAL8 *pMaterial)
{
    return _pD3DDev8->GetMaterial(pMaterial);
}

HRESULT CDirect3DDevice8Wrapper::SetLight(DWORD index, const D3DLIGHT8 *light)
{
    return _pD3DDev8->SetLight(index, light);
}

HRESULT CDirect3DDevice8Wrapper::GetLight(DWORD Index, D3DLIGHT8 *pLight)
{
    return _pD3DDev8->GetLight(Index, pLight);
}

HRESULT CDirect3DDevice8Wrapper::LightEnable(DWORD Index, WINBOOL Enable)
{
    return _pD3DDev8->LightEnable(Index, Enable);
}

HRESULT CDirect3DDevice8Wrapper::GetLightEnable(DWORD Index, WINBOOL *pEnable)
{
    return _pD3DDev8->GetLightEnable(Index, pEnable);
}

HRESULT CDirect3DDevice8Wrapper::SetClipPlane(DWORD index, const float *plane)
{
    return _pD3DDev8->SetClipPlane(index, plane);
}

HRESULT CDirect3DDevice8Wrapper::GetClipPlane(DWORD Index, float *pPlane)
{
    return _pD3DDev8->GetClipPlane(Index, pPlane);
}

HRESULT CDirect3DDevice8Wrapper::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    return _pD3DDev8->SetRenderState(State, Value);
}

HRESULT CDirect3DDevice8Wrapper::GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue)
{
    return _pD3DDev8->GetRenderState(State, pValue);
}

HRESULT CDirect3DDevice8Wrapper::BeginStateBlock()
{
    return _pD3DDev8->BeginStateBlock();
}

HRESULT CDirect3DDevice8Wrapper::EndStateBlock(DWORD *pToken)
{
    return _pD3DDev8->EndStateBlock(pToken);
}

HRESULT CDirect3DDevice8Wrapper::ApplyStateBlock(DWORD Token)
{
    return _pD3DDev8->ApplyStateBlock(Token);
}

HRESULT CDirect3DDevice8Wrapper::CaptureStateBlock(DWORD Token)
{
    return _pD3DDev8->CaptureStateBlock(Token);
}

HRESULT CDirect3DDevice8Wrapper::DeleteStateBlock(DWORD Token)
{
    return _pD3DDev8->DeleteStateBlock(Token);
}

HRESULT CDirect3DDevice8Wrapper::CreateStateBlock(D3DSTATEBLOCKTYPE Type, DWORD *pToken)
{
    return _pD3DDev8->CreateStateBlock(Type, pToken);
}

HRESULT CDirect3DDevice8Wrapper::SetClipStatus(const D3DCLIPSTATUS8 *clip_status)
{
    return _pD3DDev8->SetClipStatus(clip_status);
}

HRESULT CDirect3DDevice8Wrapper::GetClipStatus(D3DCLIPSTATUS8 *pClipStatus)
{
    return _pD3DDev8->GetClipStatus(pClipStatus);
}

HRESULT CDirect3DDevice8Wrapper::GetTexture(DWORD Stage, IDirect3DBaseTexture8 **ppTexture)
{
    return _pD3DDev8->GetTexture(Stage, ppTexture);
}

HRESULT CDirect3DDevice8Wrapper::SetTexture(DWORD Stage, IDirect3DBaseTexture8 *pTexture)
{
    return _pD3DDev8->SetTexture(Stage, pTexture);
}

HRESULT CDirect3DDevice8Wrapper::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
    return _pD3DDev8->GetTextureStageState(Stage, Type, pValue);
}

HRESULT CDirect3DDevice8Wrapper::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    return _pD3DDev8->SetTextureStageState(Stage, Type, Value);
}

HRESULT CDirect3DDevice8Wrapper::ValidateDevice(DWORD *pNumPasses)
{
    return _pD3DDev8->ValidateDevice(pNumPasses);
}

HRESULT CDirect3DDevice8Wrapper::GetInfo(DWORD DevInfoID, void *pDevInfoStruct, DWORD DevInfoStructSize)
{
    return _pD3DDev8->GetInfo(DevInfoID, pDevInfoStruct, DevInfoStructSize);
}

HRESULT CDirect3DDevice8Wrapper::SetPaletteEntries(UINT palette_idx, const PALETTEENTRY *entries)
{
    return _pD3DDev8->SetPaletteEntries(palette_idx, entries);
}

HRESULT CDirect3DDevice8Wrapper::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries)
{
    return _pD3DDev8->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT CDirect3DDevice8Wrapper::SetCurrentTexturePalette(UINT PaletteNumber)
{
    return _pD3DDev8->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT CDirect3DDevice8Wrapper::GetCurrentTexturePalette(UINT *PaletteNumber)
{
    return _pD3DDev8->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT CDirect3DDevice8Wrapper::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    return _pD3DDev8->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT CDirect3DDevice8Wrapper::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT minIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    return _pD3DDev8->DrawIndexedPrimitive(PrimitiveType, minIndex, NumVertices, startIndex, primCount);
}

HRESULT CDirect3DDevice8Wrapper::DrawPrimitiveUP(D3DPRIMITIVETYPE primitive_type, UINT primitive_count, const void *data, UINT stride)
{
    if (!_fDraw)
    {
        D3DVIEWPORT8 vp;
        _pD3DDev8->GetViewport(&vp);
        if (vp.X == 32 && vp.Y == 16)
            _fDraw = true;
    }
    return _pD3DDev8->DrawPrimitiveUP(primitive_type, primitive_count, data, stride);
}

HRESULT CDirect3DDevice8Wrapper::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE primitive_type, UINT min_vertex_idx, UINT vertex_count, UINT primitive_count, const void *index_data, D3DFORMAT index_format, const void *data, UINT stride)
{
    return _pD3DDev8->DrawIndexedPrimitiveUP(primitive_type, min_vertex_idx, vertex_count, primitive_count, index_data, index_format, data, stride);
}

HRESULT CDirect3DDevice8Wrapper::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer8 *pDestBuffer, DWORD Flags)
{
    return _pD3DDev8->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, Flags);
}

HRESULT CDirect3DDevice8Wrapper::CreateVertexShader(const DWORD *declaration, const DWORD *byte_code, DWORD *shader, DWORD usage)
{
    return _pD3DDev8->CreateVertexShader(declaration, byte_code, shader, usage);
}

HRESULT CDirect3DDevice8Wrapper::SetVertexShader(DWORD Handle)
{
    return _pD3DDev8->SetVertexShader(Handle);
}

HRESULT CDirect3DDevice8Wrapper::GetVertexShader(DWORD *pHandle)
{
    return _pD3DDev8->GetVertexShader(pHandle);
}

HRESULT CDirect3DDevice8Wrapper::DeleteVertexShader(DWORD Handle)
{
    return _pD3DDev8->DeleteVertexShader(Handle);
}

HRESULT CDirect3DDevice8Wrapper::SetVertexShaderConstant(DWORD reg_idx, const void *data, DWORD count)
{
    return _pD3DDev8->SetVertexShaderConstant(reg_idx, data, count);
}

HRESULT CDirect3DDevice8Wrapper::GetVertexShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount)
{
    return _pD3DDev8->GetVertexShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT CDirect3DDevice8Wrapper::GetVertexShaderDeclaration(DWORD Handle, void *pData, DWORD *pSizeOfData)
{
    return _pD3DDev8->GetVertexShaderDeclaration(Handle, pData, pSizeOfData);
}

HRESULT CDirect3DDevice8Wrapper::GetVertexShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData)
{
    return _pD3DDev8->GetVertexShaderFunction(Handle, pData, pSizeOfData);
}

HRESULT CDirect3DDevice8Wrapper::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 *pStreamData, UINT Stride)
{
    return _pD3DDev8->SetStreamSource(StreamNumber, pStreamData, Stride);
}

HRESULT CDirect3DDevice8Wrapper::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 **ppStreamData, UINT *pStride)
{
    return _pD3DDev8->GetStreamSource(StreamNumber, ppStreamData, pStride);
}

HRESULT CDirect3DDevice8Wrapper::SetIndices(IDirect3DIndexBuffer8 *pIndexData, UINT BaseVertexIndex)
{
    return _pD3DDev8->SetIndices(pIndexData, BaseVertexIndex);
}

HRESULT CDirect3DDevice8Wrapper::GetIndices(IDirect3DIndexBuffer8 **ppIndexData, UINT *pBaseVertexIndex)
{
    return _pD3DDev8->GetIndices(ppIndexData, pBaseVertexIndex);
}

HRESULT CDirect3DDevice8Wrapper::CreatePixelShader(const DWORD *byte_code, DWORD *shader)
{
    return _pD3DDev8->CreatePixelShader(byte_code, shader);
}

HRESULT CDirect3DDevice8Wrapper::SetPixelShader(DWORD Handle)
{
    return _pD3DDev8->SetPixelShader(Handle);
}

HRESULT CDirect3DDevice8Wrapper::GetPixelShader(DWORD *pHandle)
{
    return _pD3DDev8->GetPixelShader(pHandle);
}

HRESULT CDirect3DDevice8Wrapper::DeletePixelShader(DWORD Handle)
{
    return _pD3DDev8->DeletePixelShader(Handle);
}

HRESULT CDirect3DDevice8Wrapper::SetPixelShaderConstant(DWORD reg_idx, const void *data, DWORD count)
{
    return _pD3DDev8->SetPixelShaderConstant(reg_idx, data, count);
}

HRESULT CDirect3DDevice8Wrapper::GetPixelShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount)
{
    return _pD3DDev8->GetPixelShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT CDirect3DDevice8Wrapper::GetPixelShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData)
{
    return _pD3DDev8->GetPixelShaderFunction(Handle, pData, pSizeOfData);
}

HRESULT CDirect3DDevice8Wrapper::DrawRectPatch(UINT handle, const float *segment_count, const D3DRECTPATCH_INFO *patch_info)
{
    return _pD3DDev8->DrawRectPatch(handle, segment_count, patch_info);
}

HRESULT CDirect3DDevice8Wrapper::DrawTriPatch(UINT handle, const float *segment_count, const D3DTRIPATCH_INFO *patch_info)
{
    return _pD3DDev8->DrawTriPatch(handle, segment_count, patch_info);
}

HRESULT CDirect3DDevice8Wrapper::DeletePatch(UINT Handle)
{
    return _pD3DDev8->DeletePatch(Handle);
}
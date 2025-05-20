#pragma once
#include "mind3d8.h"
#include "Direct3DDevice8Wrapper.h"

class CDirect3D8Wrapper : public IDirect3D8
{
private:
	IDirect3D8 *_pD3D8;

public:
	CDirect3D8Wrapper(IDirect3D8 *pOrigD3D8);

    // == Begin IUnknown interface ==
    STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;
    // == End IUnknown interface ==

	// == Begin IDirect3D8 interface ==
    STDMETHODIMP RegisterSoftwareDevice(void *pInitializeFunction) override;
    STDMETHODIMP_(UINT) GetAdapterCount() override;
    STDMETHODIMP GetAdapterIdentifier(UINT  Adapter, DWORD  Flags, D3DADAPTER_IDENTIFIER8 *pIdentifier) override;
    STDMETHODIMP_(UINT) GetAdapterModeCount(UINT  Adapter) override;
    STDMETHODIMP EnumAdapterModes(UINT  Adapter, UINT  Mode, D3DDISPLAYMODE *pMode) override;
    STDMETHODIMP GetAdapterDisplayMode(UINT  Adapter, D3DDISPLAYMODE *pMode) override;
    STDMETHODIMP CheckDeviceType(UINT  Adapter, D3DDEVTYPE  CheckType, D3DFORMAT  DisplayFormat, D3DFORMAT  BackBufferFormat, WINBOOL  Windowed) override;
    STDMETHODIMP CheckDeviceFormat(UINT  Adapter, D3DDEVTYPE  DeviceType, D3DFORMAT  AdapterFormat, DWORD  Usage, D3DRESOURCETYPE  RType, D3DFORMAT  CheckFormat) override;
    STDMETHODIMP CheckDeviceMultiSampleType(UINT  Adapter, D3DDEVTYPE  DeviceType, D3DFORMAT  SurfaceFormat, WINBOOL  Windowed, D3DMULTISAMPLE_TYPE  MultiSampleType) override;
    STDMETHODIMP CheckDepthStencilMatch(UINT  Adapter, D3DDEVTYPE  DeviceType, D3DFORMAT  AdapterFormat, D3DFORMAT  RenderTargetFormat, D3DFORMAT  DepthStencilFormat) override;
    STDMETHODIMP GetDeviceCaps(UINT  Adapter, D3DDEVTYPE  DeviceType, D3DCAPS8 *pCaps) override;
    STDMETHODIMP_(HMONITOR) GetAdapterMonitor(UINT  Adapter) override;
    STDMETHODIMP CreateDevice(UINT  Adapter, D3DDEVTYPE  DeviceType, HWND  hFocusWindow, DWORD  BehaviorFlags, D3DPRESENT_PARAMETERS *pPresentationParameters, struct IDirect3DDevice8 **ppReturnedDeviceInterface) override;
	// == End IDirect3D8 interface ==
};
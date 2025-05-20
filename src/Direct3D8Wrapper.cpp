#include "Direct3D8Wrapper.h"

CDirect3D8Wrapper::CDirect3D8Wrapper(IDirect3D8 *pOrigD3D8)
    : _pD3D8(pOrigD3D8)
{
}

STDMETHODIMP CDirect3D8Wrapper::QueryInterface(REFIID riid, void **ppvObject)
{
	HRESULT hr = _pD3D8->QueryInterface(riid, ppvObject);
	if (SUCCEEDED(hr))
	{
		*ppvObject = this;
	}
	return hr;
}

STDMETHODIMP_(ULONG) CDirect3D8Wrapper::AddRef()
{
	return _pD3D8->AddRef();
}

STDMETHODIMP_(ULONG) CDirect3D8Wrapper::Release()
{
	ULONG cRef = _pD3D8->Release();
	if (0 == cRef)
		delete this;
	return cRef;
}

STDMETHODIMP CDirect3D8Wrapper::RegisterSoftwareDevice(void *pInitializeFunction)
{
    return _pD3D8->RegisterSoftwareDevice(pInitializeFunction);
}

STDMETHODIMP_(UINT) CDirect3D8Wrapper::GetAdapterCount()
{
    return _pD3D8->GetAdapterCount();
}

STDMETHODIMP CDirect3D8Wrapper::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8 *pIdentifier)
{
    return _pD3D8->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

STDMETHODIMP_(UINT) CDirect3D8Wrapper::GetAdapterModeCount(UINT Adapter)
{
    return _pD3D8->GetAdapterModeCount(Adapter);
}

STDMETHODIMP CDirect3D8Wrapper::EnumAdapterModes(UINT Adapter, UINT Mode, D3DDISPLAYMODE *pMode)
{
    return _pD3D8->EnumAdapterModes(Adapter, Mode, pMode);
}

STDMETHODIMP CDirect3D8Wrapper::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE *pMode)
{
    return _pD3D8->GetAdapterDisplayMode(Adapter, pMode);
}

STDMETHODIMP CDirect3D8Wrapper::CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, WINBOOL Windowed)
{
    return _pD3D8->CheckDeviceType(Adapter, CheckType, DisplayFormat, BackBufferFormat, Windowed);
}

STDMETHODIMP CDirect3D8Wrapper::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    return _pD3D8->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

STDMETHODIMP CDirect3D8Wrapper::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, WINBOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType)
{
    return _pD3D8->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType);
}

STDMETHODIMP CDirect3D8Wrapper::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    return _pD3D8->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

STDMETHODIMP CDirect3D8Wrapper::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8 *pCaps)
{
    return _pD3D8->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

STDMETHODIMP_(HMONITOR) CDirect3D8Wrapper::GetAdapterMonitor(UINT Adapter)
{
    return _pD3D8->GetAdapterMonitor(Adapter);
}

STDMETHODIMP CDirect3D8Wrapper::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DDevice8 **ppReturnedDeviceInterface)
{
    HRESULT hr = _pD3D8->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
    if (SUCCEEDED(hr))
    {
        *ppReturnedDeviceInterface = new CDirect3DDevice8Wrapper(*ppReturnedDeviceInterface);
    }
    return hr;
}

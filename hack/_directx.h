#pragma once
#include "abc.h"
#include "_windows.h"

#pragma region [CoInitialize, CoUninitialize] ----------------------------------
// clang-format off
__ywstd_cfunc_begin
enum COINIT {
  COINIT_MULTITHREADED      = 0x0,
  COINIT_APARTMENTTHREADED  = 0x2,
  COINIT_DISABLE_OLE1DDE    = 0x4,
  COINIT_SPEED_OVER_MEMORY  = 0x8,
};
__declspec(dllimport) void __stdcall CoUninitialize();
__declspec(dllimport) long __stdcall CoInitializeEx(void*, unsigned long);
__ywstd_cfunc_end
__ywstd_export namespace win {
using __ywstd_cfunc COINIT;
using __ywstd_cfunc CoUninitialize;
using __ywstd_cfunc CoInitializeEx;
}
// clang-format on
#pragma endregion --------------------------------------------------------------

#pragma region [DXGI_FORMAT] ---------------------------------------------------
// clang-format off
__ywstd_cfunc_begin
enum DXGI_FORMAT : UINT {
  DXGI_FORMAT_UNKNOWN                                 = 0,
  DXGI_FORMAT_R32G32B32A32_TYPELESS                   = 1,
  DXGI_FORMAT_R32G32B32A32_FLOAT                      = 2,
  DXGI_FORMAT_R32G32B32A32_UINT                       = 3,
  DXGI_FORMAT_R32G32B32A32_SINT                       = 4,
  DXGI_FORMAT_R32G32B32_TYPELESS                      = 5,
  DXGI_FORMAT_R32G32B32_FLOAT                         = 6,
  DXGI_FORMAT_R32G32B32_UINT                          = 7,
  DXGI_FORMAT_R32G32B32_SINT                          = 8,
  DXGI_FORMAT_R16G16B16A16_TYPELESS                   = 9,
  DXGI_FORMAT_R16G16B16A16_FLOAT                      = 10,
  DXGI_FORMAT_R16G16B16A16_UNORM                      = 11,
  DXGI_FORMAT_R16G16B16A16_UINT                       = 12,
  DXGI_FORMAT_R16G16B16A16_SNORM                      = 13,
  DXGI_FORMAT_R16G16B16A16_SINT                       = 14,
  DXGI_FORMAT_R32G32_TYPELESS                         = 15,
  DXGI_FORMAT_R32G32_FLOAT                            = 16,
  DXGI_FORMAT_R32G32_UINT                             = 17,
  DXGI_FORMAT_R32G32_SINT                             = 18,
  DXGI_FORMAT_R32G8X24_TYPELESS                       = 19,
  DXGI_FORMAT_D32_FLOAT_S8X24_UINT                    = 20,
  DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS                = 21,
  DXGI_FORMAT_X32_TYPELESS_G8X24_UINT                 = 22,
  DXGI_FORMAT_R10G10B10A2_TYPELESS                    = 23,
  DXGI_FORMAT_R10G10B10A2_UNORM                       = 24,
  DXGI_FORMAT_R10G10B10A2_UINT                        = 25,
  DXGI_FORMAT_R11G11B10_FLOAT                         = 26,
  DXGI_FORMAT_R8G8B8A8_TYPELESS                       = 27,
  DXGI_FORMAT_R8G8B8A8_UNORM                          = 28,
  DXGI_FORMAT_R8G8B8A8_UNORM_SRGB                     = 29,
  DXGI_FORMAT_R8G8B8A8_UINT                           = 30,
  DXGI_FORMAT_R8G8B8A8_SNORM                          = 31,
  DXGI_FORMAT_R8G8B8A8_SINT                           = 32,
  DXGI_FORMAT_R16G16_TYPELESS                         = 33,
  DXGI_FORMAT_R16G16_FLOAT                            = 34,
  DXGI_FORMAT_R16G16_UNORM                            = 35,
  DXGI_FORMAT_R16G16_UINT                             = 36,
  DXGI_FORMAT_R16G16_SNORM                            = 37,
  DXGI_FORMAT_R16G16_SINT                             = 38,
  DXGI_FORMAT_R32_TYPELESS                            = 39,
  DXGI_FORMAT_D32_FLOAT                               = 40,
  DXGI_FORMAT_R32_FLOAT                               = 41,
  DXGI_FORMAT_R32_UINT                                = 42,
  DXGI_FORMAT_R32_SINT                                = 43,
  DXGI_FORMAT_R24G8_TYPELESS                          = 44,
  DXGI_FORMAT_D24_UNORM_S8_UINT                       = 45,
  DXGI_FORMAT_R24_UNORM_X8_TYPELESS                   = 46,
  DXGI_FORMAT_X24_TYPELESS_G8_UINT                    = 47,
  DXGI_FORMAT_R8G8_TYPELESS                           = 48,
  DXGI_FORMAT_R8G8_UNORM                              = 49,
  DXGI_FORMAT_R8G8_UINT                               = 50,
  DXGI_FORMAT_R8G8_SNORM                              = 51,
  DXGI_FORMAT_R8G8_SINT                               = 52,
  DXGI_FORMAT_R16_TYPELESS                            = 53,
  DXGI_FORMAT_R16_FLOAT                               = 54,
  DXGI_FORMAT_D16_UNORM                               = 55,
  DXGI_FORMAT_R16_UNORM                               = 56,
  DXGI_FORMAT_R16_UINT                                = 57,
  DXGI_FORMAT_R16_SNORM                               = 58,
  DXGI_FORMAT_R16_SINT                                = 59,
  DXGI_FORMAT_R8_TYPELESS                             = 60,
  DXGI_FORMAT_R8_UNORM                                = 61,
  DXGI_FORMAT_R8_UINT                                 = 62,
  DXGI_FORMAT_R8_SNORM                                = 63,
  DXGI_FORMAT_R8_SINT                                 = 64,
  DXGI_FORMAT_A8_UNORM                                = 65,
  DXGI_FORMAT_R1_UNORM                                = 66,
  DXGI_FORMAT_R9G9B9E5_SHAREDEXP                      = 67,
  DXGI_FORMAT_R8G8_B8G8_UNORM                         = 68,
  DXGI_FORMAT_G8R8_G8B8_UNORM                         = 69,
  DXGI_FORMAT_BC1_TYPELESS                            = 70,
  DXGI_FORMAT_BC1_UNORM                               = 71,
  DXGI_FORMAT_BC1_UNORM_SRGB                          = 72,
  DXGI_FORMAT_BC2_TYPELESS                            = 73,
  DXGI_FORMAT_BC2_UNORM                               = 74,
  DXGI_FORMAT_BC2_UNORM_SRGB                          = 75,
  DXGI_FORMAT_BC3_TYPELESS                            = 76,
  DXGI_FORMAT_BC3_UNORM                               = 77,
  DXGI_FORMAT_BC3_UNORM_SRGB                          = 78,
  DXGI_FORMAT_BC4_TYPELESS                            = 79,
  DXGI_FORMAT_BC4_UNORM                               = 80,
  DXGI_FORMAT_BC4_SNORM                               = 81,
  DXGI_FORMAT_BC5_TYPELESS                            = 82,
  DXGI_FORMAT_BC5_UNORM                               = 83,
  DXGI_FORMAT_BC5_SNORM                               = 84,
  DXGI_FORMAT_B5G6R5_UNORM                            = 85,
  DXGI_FORMAT_B5G5R5A1_UNORM                          = 86,
  DXGI_FORMAT_B8G8R8A8_UNORM                          = 87,
  DXGI_FORMAT_B8G8R8X8_UNORM                          = 88,
  DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM              = 89,
  DXGI_FORMAT_B8G8R8A8_TYPELESS                       = 90,
  DXGI_FORMAT_B8G8R8A8_UNORM_SRGB                     = 91,
  DXGI_FORMAT_B8G8R8X8_TYPELESS                       = 92,
  DXGI_FORMAT_B8G8R8X8_UNORM_SRGB                     = 93,
  DXGI_FORMAT_BC6H_TYPELESS                           = 94,
  DXGI_FORMAT_BC6H_UF16                               = 95,
  DXGI_FORMAT_BC6H_SF16                               = 96,
  DXGI_FORMAT_BC7_TYPELESS                            = 97,
  DXGI_FORMAT_BC7_UNORM                               = 98,
  DXGI_FORMAT_BC7_UNORM_SRGB                          = 99,
  DXGI_FORMAT_AYUV                                    = 100,
  DXGI_FORMAT_Y410                                    = 101,
  DXGI_FORMAT_Y416                                    = 102,
  DXGI_FORMAT_NV12                                    = 103,
  DXGI_FORMAT_P010                                    = 104,
  DXGI_FORMAT_P016                                    = 105,
  DXGI_FORMAT_420_OPAQUE                              = 106,
  DXGI_FORMAT_YUY2                                    = 107,
  DXGI_FORMAT_Y210                                    = 108,
  DXGI_FORMAT_Y216                                    = 109,
  DXGI_FORMAT_NV11                                    = 110,
  DXGI_FORMAT_AI44                                    = 111,
  DXGI_FORMAT_IA44                                    = 112,
  DXGI_FORMAT_P8                                      = 113,
  DXGI_FORMAT_A8P8                                    = 114,
  DXGI_FORMAT_B4G4R4A4_UNORM                          = 115,
  DXGI_FORMAT_P208                                    = 130,
  DXGI_FORMAT_V208                                    = 131,
  DXGI_FORMAT_V408                                    = 132,
  DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE         = 189,
  DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE = 190,
};
__ywstd_cfunc_end
__ywstd_export namespace win {
using __ywstd_cfunc DXGI_FORMAT;
}
// clang-format on
#pragma endregion --------------------------------------------------------------

#pragma region [ID] ------------------------------------------------------------
// clang-format off
__ywstd_cfunc_begin
struct GUID {
  unsigned long  Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned char  Data4[ 8 ];
};
using REFGUID = const GUID&;
using REFIID = const GUID&;
#define MIDL_INTERFACE(x) struct __declspec(uuid(x)) __declspec(novtable)
__ywstd_cfunc_end
__ywstd_export namespace win {
using __ywstd_cfunc GUID;
using __ywstd_cfunc REFGUID;
using __ywstd_cfunc REFIID;
}
// clang-format on
#pragma endregion --------------------------------------------------------------

#pragma region [IUnknown] ------------------------------------------------------
// clang-format off
__ywstd_cfunc_begin
extern "C++" MIDL_INTERFACE("00000000-0000-0000-C000-000000000046") IUnknown {
  virtual HRESULT __stdcall QueryInterface(REFIID, void**) = 0;
  virtual unsigned long __stdcall AddRef() = 0;
  virtual unsigned long __stdcall Release() = 0;
  template<typename Q> HRESULT __stdcall QueryInterface(Q** pp) {
    return QueryInterface(__uuidof(Q), (void **)pp);
  }
};
__ywstd_cfunc_end
__ywstd_export namespace win {
using __ywstd_cfunc IUnknown;
}
// clang-format on
#pragma endregion --------------------------------------------------------------

#pragma region [IDXGIObject, IDXGIDeviceSubObject] -----------------------------
__ywstd_cfunc_begin
MIDL_INTERFACE("aec22fb8-76f3-4639-9be0-28eb43a67a2e")
IDXGIObject : public IUnknown {
  virtual HRESULT __stdcall SetPrivateData(REFGUID, unsigned, const void*) = 0;
  virtual HRESULT __stdcall SetPrivateDataInterface(REFGUID, const IUnknown*) = 0;
  virtual HRESULT __stdcall GetPrivateData(REFGUID, UINT*, void*) = 0;
  virtual HRESULT __stdcall GetParent(REFIID, void**) = 0;
};
MIDL_INTERFACE("3d3e0379-f9de-4d58-bb6c-18d62992f1a6")
IDXGIDeviceSubObject : public IDXGIObject {
  virtual HRESULT __stdcall GetDevice(REFIID, void**) = 0;
};
__ywstd_cfunc_end
__ywstd_export namespace win {
using __ywstd_cfunc IDXGIObject;
using __ywstd_cfunc IDXGIDeviceSubObject;
}
#pragma endregion --------------------------------------------------------------


__ywstd_cfunc_begin








struct DXGI_SAMPLE_DESC {
  UINT Count;
  UINT Quality;
};

struct DXGI_SURFACE_DESC {
  UINT Width;
  UINT Height;
  DXGI_FORMAT Format;
  DXGI_SAMPLE_DESC SampleDesc;
};

struct DXGI_MAPPED_RECT {
  INT Pitch;
  BYTE *pBits;
};

MIDL_INTERFACE("cafcb56c-6ac3-4889-bf47-9e23bbd260ec")
IDXGISurface : public IDXGIDeviceSubObject {
  virtual HRESULT __stdcall GetDesc(DXGI_SURFACE_DESC*) = 0;
  virtual HRESULT __stdcall Map(DXGI_MAPPED_RECT*, UINT) = 0;
  virtual HRESULT __stdcall Unmap() = 0;
};

enum DXGI_MODE_ROTATION {
  DXGI_MODE_ROTATION_UNSPECIFIED  = 0,
  DXGI_MODE_ROTATION_IDENTITY     = 1,
  DXGI_MODE_ROTATION_ROTATE90     = 2,
  DXGI_MODE_ROTATION_ROTATE180    = 3,
  DXGI_MODE_ROTATION_ROTATE270    = 4
};

struct DXGI_OUTPUT_DESC {
  WCHAR DeviceName[ 32 ];
  RECT DesktopCoordinates;
  BOOL AttachedToDesktop;
  DXGI_MODE_ROTATION Rotation;
  HMONITOR Monitor;
};

struct DXGI_RATIONAL {
  UINT Numerator;
  UINT Denominator;
};

enum DXGI_MODE_SCANLINE_ORDER {
  DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED       = 0,
  DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE       = 1,
  DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST = 2,
  DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST = 3
};

enum DXGI_MODE_SCALING {
  DXGI_MODE_SCALING_UNSPECIFIED  = 0,
  DXGI_MODE_SCALING_CENTERED     = 1,
  DXGI_MODE_SCALING_STRETCHED    = 2
};

struct DXGI_MODE_DESC {
  UINT Width;
  UINT Height;
  DXGI_RATIONAL RefreshRate;
  DXGI_FORMAT Format;
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING Scaling;
};

struct DXGI_GAMMA_CONTROL_CAPABILITIES {
  BOOL ScaleAndOffsetSupported;
  float MaxConvertedValue;
  float MinConvertedValue;
  UINT NumGammaControlPoints;
  float ControlPointPositions[1025];
};

struct DXGI_RGB {
  float Red;
  float Green;
  float Blue;
};

struct DXGI_GAMMA_CONTROL {
  DXGI_RGB Scale;
  DXGI_RGB Offset;
  DXGI_RGB GammaCurve[ 1025 ];
};

struct DXGI_FRAME_STATISTICS {
  UINT PresentCount;
  UINT PresentRefreshCount;
  UINT SyncRefreshCount;
  LARGE_INTEGER SyncQPCTime;
  LARGE_INTEGER SyncGPUTime;
};

MIDL_INTERFACE("ae02eedb-c735-4690-8d52-5a8dc20213aa")
IDXGIOutput : public IDXGIObject {
public:
  virtual HRESULT __stdcall GetDesc(DXGI_OUTPUT_DESC*) = 0;
  virtual HRESULT __stdcall GetDisplayModeList(DXGI_FORMAT, UINT, UINT*, DXGI_MODE_DESC*) = 0;
  virtual HRESULT __stdcall FindClosestMatchingMode(const DXGI_MODE_DESC*, DXGI_MODE_DESC*, IUnknown*) = 0;
  virtual HRESULT __stdcall WaitForVBlank() = 0;
  virtual HRESULT __stdcall TakeOwnership(IUnknown*, BOOL) = 0;
  virtual void __stdcall ReleaseOwnership() = 0;
  virtual HRESULT __stdcall GetGammaControlCapabilities(DXGI_GAMMA_CONTROL_CAPABILITIES*) = 0;
  virtual HRESULT __stdcall SetGammaControl(const DXGI_GAMMA_CONTROL*) = 0;
  virtual HRESULT __stdcall GetGammaControl(DXGI_GAMMA_CONTROL*) = 0;
  virtual HRESULT __stdcall SetDisplaySurface(IDXGISurface*) = 0;
  virtual HRESULT __stdcall GetDisplaySurfaceData(IDXGISurface*) = 0;
  virtual HRESULT __stdcall GetFrameStatistics(DXGI_FRAME_STATISTICS*) = 0;
};

typedef struct DXGI_ADAPTER_DESC {
  WCHAR Description[ 128 ];
  UINT VendorId;
  UINT DeviceId;
  UINT SubSysId;
  UINT Revision;
  SIZE_T DedicatedVideoMemory;
  SIZE_T DedicatedSystemMemory;
  SIZE_T SharedSystemMemory;
  LUID AdapterLuid;
}   DXGI_ADAPTER_DESC;

MIDL_INTERFACE("2411e7e1-12ac-4ccf-bd14-9798e8534dc0")
IDXGIAdapter : public IDXGIObject {
  virtual HRESULT __stdcall EnumOutputs(unsigned, IDXGIOutput**) = 0;
  virtual HRESULT __stdcall GetDesc(DXGI_ADAPTER_DESC*) = 0;
  virtual HRESULT __stdcall CheckInterfaceSupport(REFGUID, LARGE_INTEGER*) = 0;
};

MIDL_INTERFACE("1841e5c8-16b0-489b-bcc8-44cfb0d5deae")
ID3D11DeviceChild : public IUnknown {
public:
  virtual void __stdcall GetDevice(ID3D11Device**) = 0;
  virtual HRESULT __stdcall GetPrivateData(REFGUID, UINT*, void*) = 0;
  virtual HRESULT __stdcall SetPrivateData(REFGUID, UINT, const void*) = 0;
  virtual HRESULT __stdcall SetPrivateDataInterface(REFGUID, const IUnknown*) = 0;
};

enum D3D11_RESOURCE_DIMENSION {
  D3D11_RESOURCE_DIMENSION_UNKNOWN   = 0,
  D3D11_RESOURCE_DIMENSION_BUFFER    = 1,
  D3D11_RESOURCE_DIMENSION_TEXTURE1D = 2,
  D3D11_RESOURCE_DIMENSION_TEXTURE2D = 3,
  D3D11_RESOURCE_DIMENSION_TEXTURE3D = 4
};

MIDL_INTERFACE("dc8e63f3-d12b-4952-b47b-5e45026a862d")
ID3D11Resource : public ID3D11DeviceChild {
  virtual void __stdcall GetType(D3D11_RESOURCE_DIMENSION*) = 0;
  virtual void __stdcall SetEvictionPriority(UINT) = 0;
  virtual UINT __stdcall GetEvictionPriority() = 0;
};

enum D3D11_USAGE{
  D3D11_USAGE_DEFAULT   = 0,
  D3D11_USAGE_IMMUTABLE = 1,
  D3D11_USAGE_DYNAMIC   = 2,
  D3D11_USAGE_STAGING   = 3
};

struct D3D11_BUFFER_DESC {
  UINT ByteWidth;
  D3D11_USAGE Usage;
  UINT BindFlags;
  UINT CPUAccessFlags;
  UINT MiscFlags;
  UINT StructureByteStride;
};

MIDL_INTERFACE("48570b85-d1ee-4fcd-a250-eb350722b037")
ID3D11Buffer : public ID3D11Resource {
  virtual void __stdcall GetDesc(D3D11_BUFFER_DESC*) = 0;
};

enum D3D_DRIVER_TYPE {
  D3D_DRIVER_TYPE_UNKNOWN   = 0,
  D3D_DRIVER_TYPE_HARDWARE  = 1,
  D3D_DRIVER_TYPE_REFERENCE = 2,
  D3D_DRIVER_TYPE_NULL      = 3,
  D3D_DRIVER_TYPE_SOFTWARE  = 4,
  D3D_DRIVER_TYPE_WARP      = 5
};

enum D3D_FEATURE_LEVEL {
  D3D_FEATURE_LEVEL_1_0_CORE = 0x1000,
  D3D_FEATURE_LEVEL_9_1      = 0x9100,
  D3D_FEATURE_LEVEL_9_2      = 0x9200,
  D3D_FEATURE_LEVEL_9_3      = 0x9300,
  D3D_FEATURE_LEVEL_10_0     = 0xa000,
  D3D_FEATURE_LEVEL_10_1     = 0xa100,
  D3D_FEATURE_LEVEL_11_0     = 0xb000,
  D3D_FEATURE_LEVEL_11_1     = 0xb100,
  D3D_FEATURE_LEVEL_12_0     = 0xc000,
  D3D_FEATURE_LEVEL_12_1     = 0xc100,
  D3D_FEATURE_LEVEL_12_2     = 0xc200
};

struct D3D11_SUBRESOURCE_DATA {
  const void *pSysMem;
  UINT SysMemPitch;
  UINT SysMemSlicePitch;
};

struct D3D11_TEXTURE1D_DESC {
  UINT Width;
  UINT MipLevels;
  UINT ArraySize;
  DXGI_FORMAT Format;
  D3D11_USAGE Usage;
  UINT BindFlags;
  UINT CPUAccessFlags;
  UINT MiscFlags;
};

MIDL_INTERFACE("f8fb5c27-c6b3-4f75-a4c8-439af2ef564c")
ID3D11Texture1D : public ID3D11Resource {
  virtual void __stdcall GetDesc(D3D11_TEXTURE1D_DESC*) = 0;
};

struct D3D11_TEXTURE2D_DESC {
  UINT Width;
  UINT Height;
  UINT MipLevels;
  UINT ArraySize;
  DXGI_FORMAT Format;
  DXGI_SAMPLE_DESC SampleDesc;
  D3D11_USAGE Usage;
  UINT BindFlags;
  UINT CPUAccessFlags;
  UINT MiscFlags;
};

MIDL_INTERFACE("6f15aaf2-d208-4e89-9ab4-489535d34f9c")
ID3D11Texture2D : public ID3D11Resource {
  virtual void __stdcall GetDesc(D3D11_TEXTURE2D_DESC*) = 0;
};

struct D3D11_TEXTURE3D_DESC {
  UINT Width;
  UINT Height;
  UINT Depth;
  UINT MipLevels;
  DXGI_FORMAT Format;
  D3D11_USAGE Usage;
  UINT BindFlags;
  UINT CPUAccessFlags;
  UINT MiscFlags;
};

MIDL_INTERFACE("037e866e-f56d-4357-a8af-9dabbe6e250e")
ID3D11Texture3D : public ID3D11Resource {
  virtual void __stdcall GetDesc(D3D11_TEXTURE3D_DESC*) = 0;
};

enum D3D_SRV_DIMENSION {
  D3D_SRV_DIMENSION_UNKNOWN  = 0,
  D3D_SRV_DIMENSION_BUFFER  = 1,
  D3D_SRV_DIMENSION_TEXTURE1D  = 2,
  D3D_SRV_DIMENSION_TEXTURE1DARRAY  = 3,
  D3D_SRV_DIMENSION_TEXTURE2D  = 4,
  D3D_SRV_DIMENSION_TEXTURE2DARRAY  = 5,
  D3D_SRV_DIMENSION_TEXTURE2DMS  = 6,
  D3D_SRV_DIMENSION_TEXTURE2DMSARRAY  = 7,
  D3D_SRV_DIMENSION_TEXTURE3D  = 8,
  D3D_SRV_DIMENSION_TEXTURECUBE  = 9,
  D3D_SRV_DIMENSION_TEXTURECUBEARRAY  = 10,
  D3D_SRV_DIMENSION_BUFFEREX  = 11,
  D3D10_SRV_DIMENSION_UNKNOWN  = D3D_SRV_DIMENSION_UNKNOWN,
  D3D10_SRV_DIMENSION_BUFFER  = D3D_SRV_DIMENSION_BUFFER,
  D3D10_SRV_DIMENSION_TEXTURE1D  = D3D_SRV_DIMENSION_TEXTURE1D,
  D3D10_SRV_DIMENSION_TEXTURE1DARRAY  = D3D_SRV_DIMENSION_TEXTURE1DARRAY,
  D3D10_SRV_DIMENSION_TEXTURE2D  = D3D_SRV_DIMENSION_TEXTURE2D,
  D3D10_SRV_DIMENSION_TEXTURE2DARRAY  = D3D_SRV_DIMENSION_TEXTURE2DARRAY,
  D3D10_SRV_DIMENSION_TEXTURE2DMS  = D3D_SRV_DIMENSION_TEXTURE2DMS,
  D3D10_SRV_DIMENSION_TEXTURE2DMSARRAY  = D3D_SRV_DIMENSION_TEXTURE2DMSARRAY,
  D3D10_SRV_DIMENSION_TEXTURE3D  = D3D_SRV_DIMENSION_TEXTURE3D,
  D3D10_SRV_DIMENSION_TEXTURECUBE  = D3D_SRV_DIMENSION_TEXTURECUBE,
  D3D10_1_SRV_DIMENSION_UNKNOWN  = D3D_SRV_DIMENSION_UNKNOWN,
  D3D10_1_SRV_DIMENSION_BUFFER  = D3D_SRV_DIMENSION_BUFFER,
  D3D10_1_SRV_DIMENSION_TEXTURE1D  = D3D_SRV_DIMENSION_TEXTURE1D,
  D3D10_1_SRV_DIMENSION_TEXTURE1DARRAY  = D3D_SRV_DIMENSION_TEXTURE1DARRAY,
  D3D10_1_SRV_DIMENSION_TEXTURE2D  = D3D_SRV_DIMENSION_TEXTURE2D,
  D3D10_1_SRV_DIMENSION_TEXTURE2DARRAY  = D3D_SRV_DIMENSION_TEXTURE2DARRAY,
  D3D10_1_SRV_DIMENSION_TEXTURE2DMS  = D3D_SRV_DIMENSION_TEXTURE2DMS,
  D3D10_1_SRV_DIMENSION_TEXTURE2DMSARRAY  = D3D_SRV_DIMENSION_TEXTURE2DMSARRAY,
  D3D10_1_SRV_DIMENSION_TEXTURE3D  = D3D_SRV_DIMENSION_TEXTURE3D,
  D3D10_1_SRV_DIMENSION_TEXTURECUBE  = D3D_SRV_DIMENSION_TEXTURECUBE,
  D3D10_1_SRV_DIMENSION_TEXTURECUBEARRAY  = D3D_SRV_DIMENSION_TEXTURECUBEARRAY,
  D3D11_SRV_DIMENSION_UNKNOWN  = D3D_SRV_DIMENSION_UNKNOWN,
  D3D11_SRV_DIMENSION_BUFFER  = D3D_SRV_DIMENSION_BUFFER,
  D3D11_SRV_DIMENSION_TEXTURE1D  = D3D_SRV_DIMENSION_TEXTURE1D,
  D3D11_SRV_DIMENSION_TEXTURE1DARRAY  = D3D_SRV_DIMENSION_TEXTURE1DARRAY,
  D3D11_SRV_DIMENSION_TEXTURE2D  = D3D_SRV_DIMENSION_TEXTURE2D,
  D3D11_SRV_DIMENSION_TEXTURE2DARRAY  = D3D_SRV_DIMENSION_TEXTURE2DARRAY,
  D3D11_SRV_DIMENSION_TEXTURE2DMS  = D3D_SRV_DIMENSION_TEXTURE2DMS,
  D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY  = D3D_SRV_DIMENSION_TEXTURE2DMSARRAY,
  D3D11_SRV_DIMENSION_TEXTURE3D  = D3D_SRV_DIMENSION_TEXTURE3D,
  D3D11_SRV_DIMENSION_TEXTURECUBE  = D3D_SRV_DIMENSION_TEXTURECUBE,
  D3D11_SRV_DIMENSION_TEXTURECUBEARRAY  = D3D_SRV_DIMENSION_TEXTURECUBEARRAY,
  D3D11_SRV_DIMENSION_BUFFEREX  = D3D_SRV_DIMENSION_BUFFEREX
};

using D3D11_SRV_DIMENSION = D3D_SRV_DIMENSION ;

struct D3D11_BUFFER_SRV {
  union {
    UINT FirstElement;
    UINT ElementOffset;
  };
  union {
    UINT NumElements;
    UINT ElementWidth;
  };
};

struct D3D11_TEX1D_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
};

struct D3D11_TEX1D_ARRAY_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX2D_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
};

struct D3D11_TEX2D_ARRAY_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX2DMS_SRV {
  UINT UnusedField_NothingToDefine;
};

struct D3D11_TEX2DMS_ARRAY_SRV {
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX3D_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
};

struct D3D11_TEXCUBE_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
};

struct D3D11_TEXCUBE_ARRAY_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
  UINT First2DArrayFace;
  UINT NumCubes;
};

struct D3D11_BUFFEREX_SRV {
  UINT FirstElement;
  UINT NumElements;
  UINT Flags;
};

struct D3D11_SHADER_RESOURCE_VIEW_DESC {
  DXGI_FORMAT Format;
  D3D11_SRV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_SRV Buffer;
    D3D11_TEX1D_SRV Texture1D;
    D3D11_TEX1D_ARRAY_SRV Texture1DArray;
    D3D11_TEX2D_SRV Texture2D;
    D3D11_TEX2D_ARRAY_SRV Texture2DArray;
    D3D11_TEX2DMS_SRV Texture2DMS;
    D3D11_TEX2DMS_ARRAY_SRV Texture2DMSArray;
    D3D11_TEX3D_SRV Texture3D;
    D3D11_TEXCUBE_SRV TextureCube;
    D3D11_TEXCUBE_ARRAY_SRV TextureCubeArray;
    D3D11_BUFFEREX_SRV BufferEx;
  };
};

MIDL_INTERFACE("839d1216-bb2e-412b-b7f4-a9dbebe08ed1")
ID3D11View : public ID3D11DeviceChild {
  virtual void __stdcall GetResource(ID3D11Resource**) = 0;
};

MIDL_INTERFACE("b0e06fe0-8192-4e1a-b1ca-36d7414710b2")
ID3D11ShaderResourceView : public ID3D11View {
  virtual void __stdcall GetDesc(D3D11_SHADER_RESOURCE_VIEW_DESC*) = 0;
};

enum D3D11_UAV_DIMENSION {
  D3D11_UAV_DIMENSION_UNKNOWN        = 0,
  D3D11_UAV_DIMENSION_BUFFER         = 1,
  D3D11_UAV_DIMENSION_TEXTURE1D      = 2,
  D3D11_UAV_DIMENSION_TEXTURE1DARRAY = 3,
  D3D11_UAV_DIMENSION_TEXTURE2D      = 4,
  D3D11_UAV_DIMENSION_TEXTURE2DARRAY = 5,
  D3D11_UAV_DIMENSION_TEXTURE3D      = 8
};

struct D3D11_BUFFER_UAV {
  UINT FirstElement;
  UINT NumElements;
  UINT Flags;
};

struct D3D11_TEX1D_UAV {
  UINT MipSlice;
};

struct D3D11_TEX1D_ARRAY_UAV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX2D_UAV {
  UINT MipSlice;
};

struct D3D11_TEX2D_ARRAY_UAV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX3D_UAV {
  UINT MipSlice;
  UINT FirstWSlice;
  UINT WSize;
};

struct D3D11_UNORDERED_ACCESS_VIEW_DESC {
  DXGI_FORMAT Format;
  D3D11_UAV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_UAV Buffer;
    D3D11_TEX1D_UAV Texture1D;
    D3D11_TEX1D_ARRAY_UAV Texture1DArray;
    D3D11_TEX2D_UAV Texture2D;
    D3D11_TEX2D_ARRAY_UAV Texture2DArray;
    D3D11_TEX3D_UAV Texture3D;
  };
};

MIDL_INTERFACE("28acf509-7f5c-48f6-8611-f316010a6380")
ID3D11UnorderedAccessView : public ID3D11View {
  virtual void __stdcall GetDesc(D3D11_UNORDERED_ACCESS_VIEW_DESC*) = 0;
};

enum D3D11_RTV_DIMENSION {
  D3D11_RTV_DIMENSION_UNKNOWN          = 0,
  D3D11_RTV_DIMENSION_BUFFER           = 1,
  D3D11_RTV_DIMENSION_TEXTURE1D        = 2,
  D3D11_RTV_DIMENSION_TEXTURE1DARRAY   = 3,
  D3D11_RTV_DIMENSION_TEXTURE2D        = 4,
  D3D11_RTV_DIMENSION_TEXTURE2DARRAY   = 5,
  D3D11_RTV_DIMENSION_TEXTURE2DMS      = 6,
  D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY = 7,
  D3D11_RTV_DIMENSION_TEXTURE3D        = 8
};

struct D3D11_BUFFER_RTV {
  union {
    UINT FirstElement;
    UINT ElementOffset;
  };
  union {
    UINT NumElements;
    UINT ElementWidth;
  };
};

struct D3D11_TEX1D_RTV {
  UINT MipSlice;
};

struct D3D11_TEX1D_ARRAY_RTV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX2D_RTV {
  UINT MipSlice;
};

struct D3D11_TEX2D_ARRAY_RTV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX2DMS_RTV {
  UINT UnusedField_NothingToDefine;
};

struct D3D11_TEX2DMS_ARRAY_RTV {
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX3D_RTV {
  UINT MipSlice;
  UINT FirstWSlice;
  UINT WSize;
};

struct D3D11_RENDER_TARGET_VIEW_DESC {
  DXGI_FORMAT Format;
  D3D11_RTV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_RTV Buffer;
    D3D11_TEX1D_RTV Texture1D;
    D3D11_TEX1D_ARRAY_RTV Texture1DArray;
    D3D11_TEX2D_RTV Texture2D;
    D3D11_TEX2D_ARRAY_RTV Texture2DArray;
    D3D11_TEX2DMS_RTV Texture2DMS;
    D3D11_TEX2DMS_ARRAY_RTV Texture2DMSArray;
    D3D11_TEX3D_RTV Texture3D;
  };
};

MIDL_INTERFACE("dfdba067-0b8d-4865-875b-d7b4516cc164")
ID3D11RenderTargetView : public ID3D11View {
  virtual void __stdcall GetDesc(D3D11_RENDER_TARGET_VIEW_DESC*) = 0;
};

enum D3D11_DSV_DIMENSION {
  D3D11_DSV_DIMENSION_UNKNOWN          = 0,
  D3D11_DSV_DIMENSION_TEXTURE1D        = 1,
  D3D11_DSV_DIMENSION_TEXTURE1DARRAY   = 2,
  D3D11_DSV_DIMENSION_TEXTURE2D        = 3,
  D3D11_DSV_DIMENSION_TEXTURE2DARRAY   = 4,
  D3D11_DSV_DIMENSION_TEXTURE2DMS      = 5,
  D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY = 6
};

struct D3D11_TEX1D_DSV {
  UINT MipSlice;
};

struct D3D11_TEX1D_ARRAY_DSV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX2D_DSV {
  UINT MipSlice;
};

struct D3D11_TEX2D_ARRAY_DSV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_TEX2DMS_DSV {
  UINT UnusedField_NothingToDefine;
};

struct D3D11_TEX2DMS_ARRAY_DSV {
  UINT FirstArraySlice;
  UINT ArraySize;
};

struct D3D11_DEPTH_STENCIL_VIEW_DESC {
  DXGI_FORMAT Format;
  D3D11_DSV_DIMENSION ViewDimension;
  UINT Flags;
  union {
    D3D11_TEX1D_DSV Texture1D;
    D3D11_TEX1D_ARRAY_DSV Texture1DArray;
    D3D11_TEX2D_DSV Texture2D;
    D3D11_TEX2D_ARRAY_DSV Texture2DArray;
    D3D11_TEX2DMS_DSV Texture2DMS;
    D3D11_TEX2DMS_ARRAY_DSV Texture2DMSArray;
  };
};

MIDL_INTERFACE("9fdac92a-1876-48c3-afad-25b94f84a9b6")
ID3D11DepthStencilView : public ID3D11View {
  virtual void __stdcall GetDesc(D3D11_DEPTH_STENCIL_VIEW_DESC*) = 0;
};

enum D3D11_INPUT_CLASSIFICATION {
  D3D11_INPUT_PER_VERTEX_DATA  = 0,
  D3D11_INPUT_PER_INSTANCE_DATA  = 1
};

struct D3D11_INPUT_ELEMENT_DESC {
  LPCSTR SemanticName;
  UINT SemanticIndex;
  DXGI_FORMAT Format;
  UINT InputSlot;
  UINT AlignedByteOffset;
  D3D11_INPUT_CLASSIFICATION InputSlotClass;
  UINT InstanceDataStepRate;
};

MIDL_INTERFACE("e4819ddc-4cf0-4025-bd26-5de82a3e07b7")
ID3D11InputLayout : public ID3D11DeviceChild {};

struct D3D11_CLASS_INSTANCE_DESC {
  UINT InstanceId;
  UINT InstanceIndex;
  UINT TypeId;
  UINT ConstantBuffer;
  UINT BaseConstantBufferOffset;
  UINT BaseTexture;
  UINT BaseSampler;
  BOOL Created;
};

MIDL_INTERFACE("a6cd7faa-b0b7-4a2f-9436-8662a65797cb")
ID3D11ClassInstance : public ID3D11DeviceChild {
  virtual void __stdcall GetClassLinkage(ID3D11ClassLinkage**) = 0;
  virtual void __stdcall GetDesc(D3D11_CLASS_INSTANCE_DESC*) = 0;
  virtual void __stdcall GetInstanceName(LPSTR, SIZE_T*) = 0;
  virtual void __stdcall GetTypeName(LPSTR, SIZE_T*) = 0;
};

MIDL_INTERFACE("ddf57cba-9543-46e4-a12b-f207a0fe7fed")
ID3D11ClassLinkage : public ID3D11DeviceChild {
  virtual HRESULT __stdcall GetClassInstance(LPCSTR, UINT, ID3D11ClassInstance**) = 0;
  virtual HRESULT __stdcall CreateClassInstance(
    LPCSTR, UINT, UINT, UINT, UINT, ID3D11ClassInstance**) = 0;
};

MIDL_INTERFACE("3b301d64-d678-4289-8897-22f8928b72f3")
ID3D11VertexShader : public ID3D11DeviceChild {};

MIDL_INTERFACE("38325b96-effb-4022-ba02-2e795b70275c")
ID3D11GeometryShader : public ID3D11DeviceChild {};

MIDL_INTERFACE("ea82e40d-51dc-4f33-93d4-db7c9125ae8c")
ID3D11PixelShader : public ID3D11DeviceChild {};

MIDL_INTERFACE("8e5c6061-628a-4c8e-8264-bbe45cb3d5dd")
ID3D11HullShader : public ID3D11DeviceChild {};

MIDL_INTERFACE("f582c508-0f36-490c-9977-31eece268cfa")
ID3D11DomainShader : public ID3D11DeviceChild {};

MIDL_INTERFACE("4f5b196e-c2bd-495e-bd01-1fded38e4969")
ID3D11ComputeShader : public ID3D11DeviceChild {};

struct D3D11_SO_DECLARATION_ENTRY {
  UINT Stream;
  LPCSTR SemanticName;
  UINT SemanticIndex;
  BYTE StartComponent;
  BYTE ComponentCount;
  BYTE OutputSlot;
};


enum D3D11_BLEND {
  D3D11_BLEND_ZERO             = 1,
  D3D11_BLEND_ONE              = 2,
  D3D11_BLEND_SRC_COLOR        = 3,
  D3D11_BLEND_INV_SRC_COLOR    = 4,
  D3D11_BLEND_SRC_ALPHA        = 5,
  D3D11_BLEND_INV_SRC_ALPHA    = 6,
  D3D11_BLEND_DEST_ALPHA       = 7,
  D3D11_BLEND_INV_DEST_ALPHA   = 8,
  D3D11_BLEND_DEST_COLOR       = 9,
  D3D11_BLEND_INV_DEST_COLOR   = 10,
  D3D11_BLEND_SRC_ALPHA_SAT    = 11,
  D3D11_BLEND_BLEND_FACTOR     = 14,
  D3D11_BLEND_INV_BLEND_FACTOR = 15,
  D3D11_BLEND_SRC1_COLOR       = 16,
  D3D11_BLEND_INV_SRC1_COLOR   = 17,
  D3D11_BLEND_SRC1_ALPHA       = 18,
  D3D11_BLEND_INV_SRC1_ALPHA   = 19
};

enum D3D11_BLEND_OP {
  D3D11_BLEND_OP_ADD          = 1,
  D3D11_BLEND_OP_SUBTRACT     = 2,
  D3D11_BLEND_OP_REV_SUBTRACT = 3,
  D3D11_BLEND_OP_MIN          = 4,
  D3D11_BLEND_OP_MAX          = 5
};

struct D3D11_RENDER_TARGET_BLEND_DESC {
  BOOL BlendEnable;
  D3D11_BLEND SrcBlend;
  D3D11_BLEND DestBlend;
  D3D11_BLEND_OP BlendOp;
  D3D11_BLEND SrcBlendAlpha;
  D3D11_BLEND DestBlendAlpha;
  D3D11_BLEND_OP BlendOpAlpha;
  UINT8 RenderTargetWriteMask;
};

struct D3D11_BLEND_DESC {
  BOOL AlphaToCoverageEnable;
  BOOL IndependentBlendEnable;
  D3D11_RENDER_TARGET_BLEND_DESC RenderTarget[8];
};

MIDL_INTERFACE("75b68faa-347d-4159-8f45-a0640f01cd9a")
ID3D11BlendState : public ID3D11DeviceChild {
  virtual void __stdcall GetDesc(D3D11_BLEND_DESC*) = 0;
};

enum D3D11_DEPTH_WRITE_MASK {
  D3D11_DEPTH_WRITE_MASK_ZERO = 0,
  D3D11_DEPTH_WRITE_MASK_ALL  = 1
};

enum D3D11_COMPARISON_FUNC {
  D3D11_COMPARISON_NEVER         = 1,
  D3D11_COMPARISON_LESS          = 2,
  D3D11_COMPARISON_EQUAL         = 3,
  D3D11_COMPARISON_LESS_EQUAL    = 4,
  D3D11_COMPARISON_GREATER       = 5,
  D3D11_COMPARISON_NOT_EQUAL     = 6,
  D3D11_COMPARISON_GREATER_EQUAL = 7,
  D3D11_COMPARISON_ALWAYS        = 8
};

enum D3D11_STENCIL_OP {
  D3D11_STENCIL_OP_KEEP     = 1,
  D3D11_STENCIL_OP_ZERO     = 2,
  D3D11_STENCIL_OP_REPLACE  = 3,
  D3D11_STENCIL_OP_INCR_SAT = 4,
  D3D11_STENCIL_OP_DECR_SAT = 5,
  D3D11_STENCIL_OP_INVERT   = 6,
  D3D11_STENCIL_OP_INCR     = 7,
  D3D11_STENCIL_OP_DECR     = 8
};

struct D3D11_DEPTH_STENCILOP_DESC {
  D3D11_STENCIL_OP StencilFailOp;
  D3D11_STENCIL_OP StencilDepthFailOp;
  D3D11_STENCIL_OP StencilPassOp;
  D3D11_COMPARISON_FUNC StencilFunc;
};

struct D3D11_DEPTH_STENCIL_DESC {
  BOOL DepthEnable;
  D3D11_DEPTH_WRITE_MASK DepthWriteMask;
  D3D11_COMPARISON_FUNC DepthFunc;
  BOOL StencilEnable;
  UINT8 StencilReadMask;
  UINT8 StencilWriteMask;
  D3D11_DEPTH_STENCILOP_DESC FrontFace;
  D3D11_DEPTH_STENCILOP_DESC BackFace;
};

MIDL_INTERFACE("03823efb-8d8f-4e1c-9aa2-f64bb2cbfdf1")
ID3D11DepthStencilState : public ID3D11DeviceChild {
  virtual void __stdcall GetDesc(D3D11_DEPTH_STENCIL_DESC*) = 0;
};

enum D3D11_FILL_MODE {
  D3D11_FILL_WIREFRAME = 2,
  D3D11_FILL_SOLID     = 3
};

enum D3D11_CULL_MODE {
  D3D11_CULL_NONE  = 1,
  D3D11_CULL_FRONT = 2,
  D3D11_CULL_BACK  = 3
};

struct D3D11_RASTERIZER_DESC {
  D3D11_FILL_MODE FillMode;
  D3D11_CULL_MODE CullMode;
  BOOL FrontCounterClockwise;
  INT DepthBias;
  FLOAT DepthBiasClamp;
  FLOAT SlopeScaledDepthBias;
  BOOL DepthClipEnable;
  BOOL ScissorEnable;
  BOOL MultisampleEnable;
  BOOL AntialiasedLineEnable;
};

MIDL_INTERFACE("9bb4ab81-ab1a-4d8f-b506-fc04200b6ee7")
ID3D11RasterizerState : public ID3D11DeviceChild {
  virtual void __stdcall GetDesc(D3D11_RASTERIZER_DESC*) = 0;
};

enum D3D11_FILTER {
  D3D11_FILTER_MIN_MAG_MIP_POINT                          = 0,
  D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR                   = 0x1,
  D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT             = 0x4,
  D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR                   = 0x5,
  D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT                   = 0x10,
  D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR            = 0x11,
  D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT                   = 0x14,
  D3D11_FILTER_MIN_MAG_MIP_LINEAR                         = 0x15,
  D3D11_FILTER_ANISOTROPIC                                = 0x55,
  D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT               = 0x80,
  D3D11_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR        = 0x81,
  D3D11_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT  = 0x84,
  D3D11_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR        = 0x85,
  D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT        = 0x90,
  D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
  D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT        = 0x94,
  D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR              = 0x95,
  D3D11_FILTER_COMPARISON_ANISOTROPIC                     = 0xd5,
  D3D11_FILTER_MINIMUM_MIN_MAG_MIP_POINT                  = 0x100,
  D3D11_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR           = 0x101,
  D3D11_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT     = 0x104,
  D3D11_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR           = 0x105,
  D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT           = 0x110,
  D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR    = 0x111,
  D3D11_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT           = 0x114,
  D3D11_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR                 = 0x115,
  D3D11_FILTER_MINIMUM_ANISOTROPIC                        = 0x155,
  D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_POINT                  = 0x180,
  D3D11_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR           = 0x181,
  D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT     = 0x184,
  D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR           = 0x185,
  D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT           = 0x190,
  D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR    = 0x191,
  D3D11_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT           = 0x194,
  D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR                 = 0x195,
  D3D11_FILTER_MAXIMUM_ANISOTROPIC                        = 0x1d5
};

enum D3D11_TEXTURE_ADDRESS_MODE {
  D3D11_TEXTURE_ADDRESS_WRAP        = 1,
  D3D11_TEXTURE_ADDRESS_MIRROR      = 2,
  D3D11_TEXTURE_ADDRESS_CLAMP       = 3,
  D3D11_TEXTURE_ADDRESS_BORDER      = 4,
  D3D11_TEXTURE_ADDRESS_MIRROR_ONCE = 5
};

struct D3D11_SAMPLER_DESC {
  D3D11_FILTER Filter;
  D3D11_TEXTURE_ADDRESS_MODE AddressU;
  D3D11_TEXTURE_ADDRESS_MODE AddressV;
  D3D11_TEXTURE_ADDRESS_MODE AddressW;
  FLOAT MipLODBias;
  UINT MaxAnisotropy;
  D3D11_COMPARISON_FUNC ComparisonFunc;
  FLOAT BorderColor[ 4 ];
  FLOAT MinLOD;
  FLOAT MaxLOD;
};

MIDL_INTERFACE("da6fea51-564c-4487-9810-f0d0f9b4e3a5")
ID3D11SamplerState : public ID3D11DeviceChild {
  virtual void __stdcall GetDesc(D3D11_SAMPLER_DESC*) = 0;
};

enum D3D11_QUERY {
  D3D11_QUERY_EVENT                         = 0,
  D3D11_QUERY_OCCLUSION                     = 1,
  D3D11_QUERY_TIMESTAMP                     = 2,
  D3D11_QUERY_TIMESTAMP_DISJOINT            = 3,
  D3D11_QUERY_PIPELINE_STATISTICS           = 4,
  D3D11_QUERY_OCCLUSION_PREDICATE           = 5,
  D3D11_QUERY_SO_STATISTICS                 = 6,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE         = 7,
  D3D11_QUERY_SO_STATISTICS_STREAM0         = 8,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM0 = 9,
  D3D11_QUERY_SO_STATISTICS_STREAM1         = 10,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM1 = 11,
  D3D11_QUERY_SO_STATISTICS_STREAM2         = 12,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM2 = 13,
  D3D11_QUERY_SO_STATISTICS_STREAM3         = 14,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM3 = 15
};

struct D3D11_QUERY_DESC {
  D3D11_QUERY Query;
  UINT MiscFlags;
};

MIDL_INTERFACE("4b35d0cd-1e15-4258-9c98-1b1333f6dd3b")
ID3D11Asynchronous : public ID3D11DeviceChild {
  virtual UINT __stdcall GetDataSize() = 0;
};

MIDL_INTERFACE("d6c00747-87b7-425e-b84d-44d108560afd")
ID3D11Query : public ID3D11Asynchronous {
  virtual void __stdcall GetDesc(D3D11_QUERY_DESC *pDesc) = 0;
};

MIDL_INTERFACE("9eb576dd-9f77-4d86-81aa-8bab5fe490e2")
ID3D11Predicate : public ID3D11Query {};

enum D3D11_COUNTER {
  D3D11_COUNTER_DEVICE_DEPENDENT_0 = 0x40000000
};

enum D3D11_COUNTER_TYPE {
  D3D11_COUNTER_TYPE_FLOAT32 = 0,
  D3D11_COUNTER_TYPE_UINT16  = 1,
  D3D11_COUNTER_TYPE_UINT32  = 2,
  D3D11_COUNTER_TYPE_UINT64  = 3
};

struct D3D11_COUNTER_INFO {
  D3D11_COUNTER LastDeviceDependentCounter;
  UINT NumSimultaneousCounters;
  UINT8 NumDetectableParallelUnits;
};

struct D3D11_COUNTER_DESC {
  D3D11_COUNTER Counter;
  UINT MiscFlags;
};

MIDL_INTERFACE("6e8c49fb-a371-4770-b440-29086022b741")
ID3D11Counter : public ID3D11Asynchronous {
  virtual void __stdcall GetDesc(D3D11_COUNTER_DESC*) = 0;
};

enum D3D11_FEATURE {
  D3D11_FEATURE_THREADING                      = 0,
  D3D11_FEATURE_DOUBLES                        = 1,
  D3D11_FEATURE_FORMAT_SUPPORT                 = 2,
  D3D11_FEATURE_FORMAT_SUPPORT2                = 3,
  D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS       = 4,
  D3D11_FEATURE_D3D11_OPTIONS                  = 5,
  D3D11_FEATURE_ARCHITECTURE_INFO              = 6,
  D3D11_FEATURE_D3D9_OPTIONS                   = 7,
  D3D11_FEATURE_SHADER_MIN_PRECISION_SUPPORT   = 8,
  D3D11_FEATURE_D3D9_SHADOW_SUPPORT            = 9,
  D3D11_FEATURE_D3D11_OPTIONS1                 = 10,
  D3D11_FEATURE_D3D9_SIMPLE_INSTANCING_SUPPORT = 11,
  D3D11_FEATURE_MARKER_SUPPORT                 = 12,
  D3D11_FEATURE_D3D9_OPTIONS1                  = 13,
  D3D11_FEATURE_D3D11_OPTIONS2                 = 14,
  D3D11_FEATURE_D3D11_OPTIONS3                 = 15,
  D3D11_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT    = 16,
  D3D11_FEATURE_D3D11_OPTIONS4                 = 17,
  D3D11_FEATURE_SHADER_CACHE                   = 18,
  D3D11_FEATURE_D3D11_OPTIONS5                 = 19,
  D3D11_FEATURE_DISPLAYABLE                    = 20
};

enum D3D11_MAP {
  D3D11_MAP_READ               = 1,
  D3D11_MAP_WRITE              = 2,
  D3D11_MAP_READ_WRITE         = 3,
  D3D11_MAP_WRITE_DISCARD      = 4,
  D3D11_MAP_WRITE_NO_OVERWRITE = 5
};

struct D3D11_MAPPED_SUBRESOURCE {
  void *pData;
  UINT RowPitch;
  UINT DepthPitch;
};

enum D3D_PRIMITIVE_TOPOLOGY {
  D3D_PRIMITIVE_TOPOLOGY_UNDEFINED                    = 0,
  D3D_PRIMITIVE_TOPOLOGY_POINTLIST                    = 1,
  D3D_PRIMITIVE_TOPOLOGY_LINELIST                     = 2,
  D3D_PRIMITIVE_TOPOLOGY_LINESTRIP                    = 3,
  D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST                 = 4,
  D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP                = 5,
  D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ                 = 10,
  D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ                = 11,
  D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ             = 12,
  D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ            = 13,
  D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST    = 33,
  D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST    = 34,
  D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST    = 35,
  D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST    = 36,
  D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST    = 37,
  D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST    = 38,
  D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST    = 39,
  D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST    = 40,
  D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST    = 41,
  D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST   = 42,
  D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST   = 43,
  D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST   = 44,
  D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST   = 45,
  D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST   = 46,
  D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST   = 47,
  D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST   = 48,
  D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST   = 49,
  D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST   = 50,
  D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST   = 51,
  D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST   = 52,
  D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST   = 53,
  D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST   = 54,
  D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST   = 55,
  D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST   = 56,
  D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST   = 57,
  D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST   = 58,
  D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST   = 59,
  D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST   = 60,
  D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST   = 61,
  D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST   = 62,
  D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST   = 63,
  D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST   = 64,
  D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED                  = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED,
  D3D10_PRIMITIVE_TOPOLOGY_POINTLIST                  = D3D_PRIMITIVE_TOPOLOGY_POINTLIST,
  D3D10_PRIMITIVE_TOPOLOGY_LINELIST                   = D3D_PRIMITIVE_TOPOLOGY_LINELIST,
  D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP                  = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP,
  D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST               = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
  D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP              = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
  D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ               = D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ,
  D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ              = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ,
  D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ           = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ,
  D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ          = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ,
  D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED                  = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED,
  D3D11_PRIMITIVE_TOPOLOGY_POINTLIST                  = D3D_PRIMITIVE_TOPOLOGY_POINTLIST,
  D3D11_PRIMITIVE_TOPOLOGY_LINELIST                   = D3D_PRIMITIVE_TOPOLOGY_LINELIST,
  D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP                  = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP,
  D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST               = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
  D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP              = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
  D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ               = D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ,
  D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ              = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ,
  D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ           = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ,
  D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ          = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ,
  D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST  = D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST,
  D3D11_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST
};
using D3D11_PRIMITIVE_TOPOLOGY = D3D_PRIMITIVE_TOPOLOGY ;

struct D3D11_VIEWPORT {
  FLOAT TopLeftX;
  FLOAT TopLeftY;
  FLOAT Width;
  FLOAT Height;
  FLOAT MinDepth;
  FLOAT MaxDepth;
};

using D3D11_RECT = RECT;

struct D3D11_BOX {
  UINT left;
  UINT top;
  UINT front;
  UINT right;
  UINT bottom;
  UINT back;
};

MIDL_INTERFACE("a24bc4d1-769e-43f7-8013-98ff566c18e2")
ID3D11CommandList : public ID3D11DeviceChild {
  virtual UINT __stdcall GetContextFlags() = 0;
};

enum D3D11_DEVICE_CONTEXT_TYPE {
  D3D11_DEVICE_CONTEXT_IMMEDIATE = 0,
  D3D11_DEVICE_CONTEXT_DEFERRED  = 1
};

MIDL_INTERFACE("c0bfa96c-e089-44fb-8eaf-26f8796190da")
ID3D11DeviceContext : public ID3D11DeviceChild {
  virtual void __stdcall VSSetConstantBuffers(UINT, UINT, ID3D11Buffer* const*) = 0;
  virtual void __stdcall PSSetShaderResources(UINT, UINT, ID3D11ShaderResourceView* const*) = 0;
  virtual void __stdcall PSSetShader(ID3D11PixelShader*, ID3D11ClassInstance* const*, UINT) = 0;
  virtual void __stdcall PSSetSamplers(UINT, UINT, ID3D11SamplerState* const*) = 0;
  virtual void __stdcall VSSetShader(ID3D11VertexShader*, ID3D11ClassInstance* const*, UINT) = 0;
  virtual void __stdcall DrawIndexed(UINT, UINT, INT) = 0;
  virtual void __stdcall Draw(UINT, UINT) = 0;
  virtual HRESULT __stdcall Map(ID3D11Resource*, UINT, D3D11_MAP, UINT, D3D11_MAPPED_SUBRESOURCE*) = 0;
  virtual void __stdcall Unmap(ID3D11Resource*, UINT) = 0;
  virtual void __stdcall PSSetConstantBuffers(UINT, UINT, ID3D11Buffer* const*) = 0;
  virtual void __stdcall IASetInputLayout(ID3D11InputLayout*) = 0;
  virtual void __stdcall IASetVertexBuffers(UINT, UINT, ID3D11Buffer* const*, const UINT*, const UINT*) = 0;
  virtual void __stdcall IASetIndexBuffer(ID3D11Buffer*, DXGI_FORMAT, UINT) = 0;
  virtual void __stdcall DrawIndexedInstanced(UINT, UINT, UINT, INT, UINT) = 0;
  virtual void __stdcall DrawInstanced(UINT, UINT, UINT, UINT) = 0;
  virtual void __stdcall GSSetConstantBuffers(UINT, UINT, ID3D11Buffer* const*) = 0;
  virtual void __stdcall GSSetShader(ID3D11GeometryShader*, ID3D11ClassInstance* const*, UINT) = 0;
  virtual void __stdcall IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY) = 0;
  virtual void __stdcall VSSetShaderResources(UINT, UINT, ID3D11ShaderResourceView* const*) = 0;
  virtual void __stdcall VSSetSamplers(UINT, UINT, ID3D11SamplerState* const*) = 0;
  virtual void __stdcall Begin(ID3D11Asynchronous*) = 0;
  virtual void __stdcall End(ID3D11Asynchronous*) = 0;
  virtual HRESULT __stdcall GetData(ID3D11Asynchronous*, void*, UINT, UINT) = 0;
  virtual void __stdcall SetPredication(ID3D11Predicate*, BOOL) = 0;
  virtual void __stdcall GSSetShaderResources(UINT, UINT, ID3D11ShaderResourceView* const*) = 0;
  virtual void __stdcall GSSetSamplers(UINT, UINT, ID3D11SamplerState* const*) = 0;
  virtual void __stdcall OMSetRenderTargets(UINT, ID3D11RenderTargetView* const*, ID3D11DepthStencilView*) = 0;
  virtual void __stdcall OMSetRenderTargetsAndUnorderedAccessViews(UINT, ID3D11RenderTargetView* const*, ID3D11DepthStencilView*, UINT, UINT, ID3D11UnorderedAccessView* const*, const UINT*) = 0;
  virtual void __stdcall OMSetBlendState(ID3D11BlendState*, const FLOAT BlendFactor[4], UINT) = 0;
  virtual void __stdcall OMSetDepthStencilState(ID3D11DepthStencilState*, UINT) = 0;
  virtual void __stdcall SOSetTargets(UINT, ID3D11Buffer* const*, const UINT*) = 0;
  virtual void __stdcall DrawAuto() = 0;
  virtual void __stdcall DrawIndexedInstancedIndirect(ID3D11Buffer*, UINT) = 0;
  virtual void __stdcall DrawInstancedIndirect(ID3D11Buffer*, UINT) = 0;
  virtual void __stdcall Dispatch(UINT, UINT, UINT) = 0;
  virtual void __stdcall DispatchIndirect(ID3D11Buffer*, UINT) = 0;
  virtual void __stdcall RSSetState(ID3D11RasterizerState*) = 0;
  virtual void __stdcall RSSetViewports(UINT, const D3D11_VIEWPORT*) = 0;
  virtual void __stdcall RSSetScissorRects(UINT, const D3D11_RECT*) = 0;
  virtual void __stdcall CopySubresourceRegion(ID3D11Resource*, UINT, UINT, UINT, UINT, ID3D11Resource*, UINT, const D3D11_BOX*) = 0;
  virtual void __stdcall CopyResource(ID3D11Resource*, ID3D11Resource*) = 0;
  virtual void __stdcall UpdateSubresource(ID3D11Resource*, UINT, const D3D11_BOX*, const void*, UINT, UINT) = 0;
  virtual void __stdcall CopyStructureCount(ID3D11Buffer*, UINT, ID3D11UnorderedAccessView*) = 0;
  virtual void __stdcall ClearRenderTargetView(ID3D11RenderTargetView*, const FLOAT[4]) = 0;
  virtual void __stdcall ClearUnorderedAccessViewUint(ID3D11UnorderedAccessView*, const UINT[4]) = 0;
  virtual void __stdcall ClearUnorderedAccessViewFloat(ID3D11UnorderedAccessView*, const FLOAT[4]) = 0;
  virtual void __stdcall ClearDepthStencilView(ID3D11DepthStencilView*, UINT, FLOAT, UINT8) = 0;
  virtual void __stdcall GenerateMips(ID3D11ShaderResourceView*) = 0;
  virtual void __stdcall SetResourceMinLOD(ID3D11Resource*, FLOAT) = 0;
  virtual FLOAT __stdcall GetResourceMinLOD(ID3D11Resource*) = 0;
  virtual void __stdcall ResolveSubresource(ID3D11Resource*, UINT, ID3D11Resource*, UINT, DXGI_FORMAT) = 0;
  virtual void __stdcall ExecuteCommandList(ID3D11CommandList*, BOOL) = 0;
  virtual void __stdcall HSSetShaderResources(UINT, UINT, ID3D11ShaderResourceView* const*) = 0;
  virtual void __stdcall HSSetShader(ID3D11HullShader*, ID3D11ClassInstance* const*, UINT) = 0;
  virtual void __stdcall HSSetSamplers(UINT, UINT, ID3D11SamplerState* const*) = 0;
  virtual void __stdcall HSSetConstantBuffers(UINT, UINT, ID3D11Buffer* const*) = 0;
  virtual void __stdcall DSSetShaderResources(UINT, UINT, ID3D11ShaderResourceView* const*) = 0;
  virtual void __stdcall DSSetShader(ID3D11DomainShader*, ID3D11ClassInstance* const*, UINT) = 0;
  virtual void __stdcall DSSetSamplers(UINT, UINT, ID3D11SamplerState* const* ppSamplers) = 0;
  virtual void __stdcall DSSetConstantBuffers(UINT, UINT, ID3D11Buffer* const*) = 0;
  virtual void __stdcall CSSetShaderResources(UINT, UINT, ID3D11ShaderResourceView* const*) = 0;
  virtual void __stdcall CSSetUnorderedAccessViews(UINT, UINT, ID3D11UnorderedAccessView* const*, const UINT*) = 0;
  virtual void __stdcall CSSetShader(ID3D11ComputeShader*, ID3D11ClassInstance* const*, UINT) = 0;
  virtual void __stdcall CSSetSamplers(UINT, UINT, ID3D11SamplerState* const*) = 0;
  virtual void __stdcall CSSetConstantBuffers(UINT, UINT, ID3D11Buffer* const*) = 0;
  virtual void __stdcall VSGetConstantBuffers(UINT, UINT, ID3D11Buffer**) = 0;
  virtual void __stdcall PSGetShaderResources(UINT, UINT, ID3D11ShaderResourceView**) = 0;
  virtual void __stdcall PSGetShader(ID3D11PixelShader**, ID3D11ClassInstance**, UINT*) = 0;
  virtual void __stdcall PSGetSamplers(UINT, UINT NumSamplers, ID3D11SamplerState**) = 0;
  virtual void __stdcall VSGetShader(ID3D11VertexShader**, ID3D11ClassInstance**, UINT*) = 0;
  virtual void __stdcall PSGetConstantBuffers(UINT, UINT, ID3D11Buffer**) = 0;
  virtual void __stdcall IAGetInputLayout(ID3D11InputLayout**) = 0;
  virtual void __stdcall IAGetVertexBuffers(UINT, UINT, ID3D11Buffer**, UINT*, UINT*) = 0;
  virtual void __stdcall IAGetIndexBuffer(ID3D11Buffer**, DXGI_FORMAT*, UINT*) = 0;
  virtual void __stdcall GSGetConstantBuffers(UINT, UINT, ID3D11Buffer**) = 0;
  virtual void __stdcall GSGetShader(ID3D11GeometryShader**, ID3D11ClassInstance**, UINT*) = 0;
  virtual void __stdcall IAGetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY*) = 0;
  virtual void __stdcall VSGetShaderResources(UINT, UINT, ID3D11ShaderResourceView**) = 0;
  virtual void __stdcall VSGetSamplers(UINT, UINT, ID3D11SamplerState**) = 0;
  virtual void __stdcall GetPredication(ID3D11Predicate**, BOOL*) = 0;
  virtual void __stdcall GSGetShaderResources(UINT, UINT, ID3D11ShaderResourceView**) = 0;
  virtual void __stdcall GSGetSamplers(UINT, UINT, ID3D11SamplerState**) = 0;
  virtual void __stdcall OMGetRenderTargets(UINT, ID3D11RenderTargetView**, ID3D11DepthStencilView**) = 0;
  virtual void __stdcall OMGetRenderTargetsAndUnorderedAccessViews(UINT, ID3D11RenderTargetView**, ID3D11DepthStencilView**, UINT, UINT, ID3D11UnorderedAccessView**) = 0;
  virtual void __stdcall OMGetBlendState(ID3D11BlendState**, FLOAT[4], UINT*) = 0;
  virtual void __stdcall OMGetDepthStencilState(ID3D11DepthStencilState**, UINT*) = 0;
  virtual void __stdcall SOGetTargets(UINT, ID3D11Buffer**) = 0;
  virtual void __stdcall RSGetState(ID3D11RasterizerState**) = 0;
  virtual void __stdcall RSGetViewports(UINT*, D3D11_VIEWPORT*) = 0;
  virtual void __stdcall RSGetScissorRects(UINT*, D3D11_RECT*) = 0;
  virtual void __stdcall HSGetShaderResources(UINT, UINT, ID3D11ShaderResourceView**) = 0;
  virtual void __stdcall HSGetShader(ID3D11HullShader**, ID3D11ClassInstance**, UINT*) = 0;
  virtual void __stdcall HSGetSamplers(UINT, UINT, ID3D11SamplerState**) = 0;
  virtual void __stdcall HSGetConstantBuffers(UINT, UINT, ID3D11Buffer**) = 0;
  virtual void __stdcall DSGetShaderResources(UINT, UINT, ID3D11ShaderResourceView**) = 0;
  virtual void __stdcall DSGetShader(ID3D11DomainShader**, ID3D11ClassInstance**, UINT*) = 0;
  virtual void __stdcall DSGetSamplers(UINT, UINT, ID3D11SamplerState**) = 0;
  virtual void __stdcall DSGetConstantBuffers(UINT, UINT, ID3D11Buffer**) = 0;
  virtual void __stdcall CSGetShaderResources(UINT, UINT, ID3D11ShaderResourceView**) = 0;
  virtual void __stdcall CSGetUnorderedAccessViews(UINT, UINT, ID3D11UnorderedAccessView**) = 0;
  virtual void __stdcall CSGetShader(ID3D11ComputeShader**, ID3D11ClassInstance**, UINT*) = 0;
  virtual void __stdcall CSGetSamplers(UINT, UINT, ID3D11SamplerState**) = 0;
  virtual void __stdcall CSGetConstantBuffers(UINT, UINT, ID3D11Buffer**) = 0;
  virtual void __stdcall ClearState() = 0;
  virtual void __stdcall Flush() = 0;
  virtual D3D11_DEVICE_CONTEXT_TYPE __stdcall GetType() = 0;
  virtual UINT __stdcall GetContextFlags() = 0;
  virtual HRESULT __stdcall FinishCommandList(BOOL, ID3D11CommandList**) = 0;
};

MIDL_INTERFACE("db6f6ddb-ac77-4e88-8253-819df9bbf140")
ID3D11Device : public IUnknown {
  virtual HRESULT __stdcall CreateBuffer(
    const D3D11_BUFFER_DESC*, const D3D11_SUBRESOURCE_DATA*, ID3D11Buffer**) = 0;
  virtual HRESULT __stdcall CreateTexture1D(
    const D3D11_TEXTURE1D_DESC*, const D3D11_SUBRESOURCE_DATA*, ID3D11Texture1D**) = 0;
  virtual HRESULT __stdcall CreateTexture2D(
    const D3D11_TEXTURE2D_DESC*, const D3D11_SUBRESOURCE_DATA*, ID3D11Texture2D**) = 0;
  virtual HRESULT __stdcall CreateTexture3D(
    const D3D11_TEXTURE3D_DESC*, const D3D11_SUBRESOURCE_DATA*, ID3D11Texture3D**) = 0;
  virtual HRESULT __stdcall CreateShaderResourceView(
    ID3D11Resource*, const D3D11_SHADER_RESOURCE_VIEW_DESC*, ID3D11ShaderResourceView**) = 0;
  virtual HRESULT __stdcall CreateUnorderedAccessView(
    ID3D11Resource*, const D3D11_UNORDERED_ACCESS_VIEW_DESC*, ID3D11UnorderedAccessView**) = 0;
  virtual HRESULT __stdcall CreateRenderTargetView(
    ID3D11Resource*, const D3D11_RENDER_TARGET_VIEW_DESC*, ID3D11RenderTargetView**) = 0;
  virtual HRESULT __stdcall CreateDepthStencilView(
    ID3D11Resource*, const D3D11_DEPTH_STENCIL_VIEW_DESC*, ID3D11DepthStencilView**) = 0;
  virtual HRESULT __stdcall CreateInputLayout(
    const D3D11_INPUT_ELEMENT_DESC*, UINT, const void*, SIZE_T, ID3D11InputLayout**) = 0;
  virtual HRESULT __stdcall CreateVertexShader(
    const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11VertexShader**) = 0;
  virtual HRESULT __stdcall CreateGeometryShader(
    const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11GeometryShader**) = 0;
  virtual HRESULT __stdcall CreateGeometryShaderWithStreamOutput(
    const void*, SIZE_T, const D3D11_SO_DECLARATION_ENTRY*, UINT,
    const UINT*, UINT, UINT, ID3D11ClassLinkage*, ID3D11GeometryShader**) = 0;
  virtual HRESULT __stdcall CreatePixelShader(const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11PixelShader**) = 0;
  virtual HRESULT __stdcall CreateHullShader(const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11HullShader**) = 0;
  virtual HRESULT __stdcall CreateDomainShader(const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11DomainShader**) = 0;
  virtual HRESULT __stdcall CreateComputeShader(const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11ComputeShader**) = 0;
  virtual HRESULT __stdcall CreateClassLinkage(ID3D11ClassLinkage**) = 0;
  virtual HRESULT __stdcall CreateBlendState(const D3D11_BLEND_DESC*, ID3D11BlendState**) = 0;
  virtual HRESULT __stdcall CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC*, ID3D11DepthStencilState**) = 0;
  virtual HRESULT __stdcall CreateRasterizerState(const D3D11_RASTERIZER_DESC*, ID3D11RasterizerState**) = 0;
  virtual HRESULT __stdcall CreateSamplerState(const D3D11_SAMPLER_DESC*, ID3D11SamplerState**) = 0;
  virtual HRESULT __stdcall CreateQuery(const D3D11_QUERY_DESC*, ID3D11Query**) = 0;
  virtual HRESULT __stdcall CreatePredicate(const D3D11_QUERY_DESC*, ID3D11Predicate**) = 0;
  virtual HRESULT __stdcall CreateCounter(const D3D11_COUNTER_DESC*, ID3D11Counter**) = 0;
  virtual HRESULT __stdcall CreateDeferredContext(UINT, ID3D11DeviceContext**) = 0;
  virtual HRESULT __stdcall OpenSharedResource(HANDLE, REFIID, void**) = 0;
  virtual HRESULT __stdcall CheckFormatSupport(DXGI_FORMAT, UINT*) = 0;
  virtual HRESULT __stdcall CheckMultisampleQualityLevels(DXGI_FORMAT, UINT, UINT*) = 0;
  virtual void __stdcall CheckCounterInfo(D3D11_COUNTER_INFO*) = 0;
  virtual HRESULT __stdcall CheckCounter(const D3D11_COUNTER_DESC*, D3D11_COUNTER_TYPE*, UINT*, LPSTR, UINT*, LPSTR, UINT*, LPSTR, UINT*) = 0;
  virtual HRESULT __stdcall CheckFeatureSupport(D3D11_FEATURE, void*, UINT) = 0;
  virtual HRESULT __stdcall GetPrivateData(REFGUID, UINT*, void*) = 0;
  virtual HRESULT __stdcall SetPrivateData(REFGUID, UINT, const void*) = 0;
  virtual HRESULT __stdcall SetPrivateDataInterface(REFGUID, const IUnknown*) = 0;
  virtual D3D_FEATURE_LEVEL __stdcall GetFeatureLevel() = 0;
  virtual UINT __stdcall GetCreationFlags() = 0;
  virtual HRESULT __stdcall GetDeviceRemovedReason() = 0;
  virtual void __stdcall GetImmediateContext(ID3D11DeviceContext**) = 0;
  virtual HRESULT __stdcall SetExceptionMode(UINT) = 0;
  virtual UINT __stdcall GetExceptionMode() = 0;
};

HRESULT __stdcall D3D11CreateDevice(
  IDXGIAdapter*, D3D_DRIVER_TYPE, HINSTANCE, unsigned,
  const D3D_FEATURE_LEVEL*, unsigned, unsigned,
  ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**);

__ywstd_cfunc_end

__ywstd_export namespace win {


}

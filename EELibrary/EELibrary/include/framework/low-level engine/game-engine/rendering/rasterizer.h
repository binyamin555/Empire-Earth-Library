#pragma once

#include "pch.h"

#include <vector>

#include "framework/low-level engine/.h"

#include "framework/low-level engine/game-engine/font/font.h"
#include "framework/low-level engine/string/string.h"
#include "framework/low-level engine/task-scheduler/critical-section.h"


// Placeholder for now
template <typename T>
class U2DPoint;

// Placeholder for now
template <typename T>
class U2DRectangle;


IMPORT class GERasterizer /* : public DX7Rasterizer */ {
public: static GERasterizer* __cdecl GetActiveRasterizer(void);
public: unsigned long GetAlphaTesting(unsigned long) const;
public: unsigned long GetAlphaTestingCompareState(unsigned long) const;
public: float GetAlphaTestingRefValue(unsigned long) const;
public: float GetAmbientIntensity() const;
public: unsigned long GetAntiAliasing(unsigned long) const;
public: void GetBlending(unsigned long&, unsigned long&, unsigned long) const;
public: unsigned long GetColorKeying(unsigned long) const;
public: unsigned long GetDithering(unsigned long) const;
public: unsigned long GetDrawStyle(unsigned long) const;
public: float GetDrawnPolyAreaPerFrame(unsigned long) const;
public: float GetDrawnPolyAreaPerSecond(unsigned long) const;
public: float GetDrawnPolysPerFrame(unsigned long) const;
public: float GetDrawnPolysPerSecond(unsigned long) const;
public: unsigned long GetFog(unsigned long) const;
public: void GetFogAttributes(struct GERFogAttributes&, unsigned long) const;
public: float GetFramesPerSecond(unsigned long) const;
public: BOOL GetIsActivated() const;
public: BOOL GetIsScreenActivated(unsigned long) const;
public: BOOL GetIsPolyAreaProfiling();
public: unsigned long GetLighting(unsigned long) const;
public: class GESurface* GetPrimarySurface(unsigned long) const;
public: static class GERasterizer* __cdecl GetRasterizer(unsigned long index);
public: static unsigned long __cdecl GetRasterizerCount();
public: class GESurface* GetRenderTarget(unsigned long) const;
public: class GEScreen* GetScreen(unsigned long) const;
public: unsigned long GetScreenCount() const;
public: float GetScenePolysPerFrame(unsigned long) const;
public: float GetScenePolysPerSecond(unsigned long) const;
public: class GESurface* GetSecondarySurface(unsigned long) const;
public: unsigned long GetShading(unsigned long) const;
public: unsigned long GetSpecular(unsigned long) const;
public: class GETextureManager* GetTextureManager(unsigned long) const;
public: float GetTotalTextureChangesPerFrame(unsigned long) const;
public: class GEViewport& GetViewport(unsigned long) const;
public: class GEWindow* GetWindow(unsigned long) const;
public: unsigned long GetZBuffer(unsigned long) const;
public: unsigned long GetZCompare(unsigned long) const;
public: void SetPolyAreaProfiling(BOOL);
public: void SetScreenID(unsigned long);
public: void SetWaterRippleEffect(float, float, float);
public: long Draw(class GELine*, unsigned long);
public: long Draw(class GEPoint*, unsigned long);
protected: void AddToDrawnPolyArea(float, unsigned long);
protected: void AddToDrawnPolyCount(unsigned long, unsigned long);
public: GERasterizer(class GERasterizer const&);
public: class GERasterizer& operator=(class GERasterizer const&);
public: unsigned long GetScreenID() const;
protected: GERasterizer(class UString const&);
public: long Activate();
public: long CreateFontBitmap(class GEFont*, unsigned long);
public: float GetPixelSize(class GEModel*, class GEViewport*, class GETransformation&, float, BOOL);
public: float GetPixelSize(class GEPhysicalModel const&, class GEViewport&, BOOL);
protected: void IsOrthographicModelVisible(class GEModel*, class GEViewport*, class GETransformation&, BOOL&, BOOL&);
protected: void IsPerspectiveModelVisible(class GEModel*, float, class GEViewport*, class GETransformation&, BOOL&, BOOL&);


// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::ActivateScreen(unsigned long,class GETextureManager *,class GEWindow *,unsigned long,BOOL,unsigned long)
public: virtual long ActivateScreen(unsigned long, class GETextureManager*, class GEWindow*, unsigned long, BOOL, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::ActivateRenderingSurface(unsigned long,class GETextureManager *,class GEWindow *,unsigned long,unsigned long)
public: virtual long ActivateRenderingSurface(unsigned long, class GETextureManager*, class GEWindow*, unsigned long, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::AddLight(class GELight &,unsigned long,unsigned long &)
public: virtual long AddLight(class GELight&, unsigned long, unsigned long&);
public: virtual long AddValidScreen(class GEScreen*);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::BeginScene(class GESurface *,unsigned long)
public: virtual long BeginScene(class GESurface*, unsigned long);
// dx7hrdisplay_public: virtual BOOL __thiscall DX7Rasterizer::CanDoCurrentState(class GETexture *,unsigned long)
public: virtual BOOL CanDoCurrentState(class GETexture*, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Clear(class GEColor const &,class GERectangle const &,unsigned long)
public: virtual long Clear(class GEColor const&, class GERectangle const&, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::ClearZBuffer(float,class GERectangle const &,unsigned long)
public: virtual long ClearZBuffer(float, class GERectangle const&, unsigned long);
// dx7hrdisplay_public: virtual class GEMovie * __thiscall DX7Rasterizer::CreateMovie(class FSFileSpec const &,unsigned long,class GERectangle const &,BOOL)
public: virtual class GEMovie* CreateMovie(class FSFileSpec const&, unsigned long, class GERectangle const&, BOOL);
// dx7hrdisplay_public: virtual class GEMovie * __thiscall DX7Rasterizer::CreateMovie(class FSFileSpec const &,unsigned long)
public: virtual class GEMovie* CreateMovie(class FSFileSpec const&, unsigned long);
// dx7hrdisplay_public: virtual class GEPolygonArray * __thiscall DX7Rasterizer::CreatePolygonArray(unsigned long)
public: virtual class GEPolygonArray* CreatePolygonArray(unsigned long);
// dx7hrdisplay_public: virtual class GEVertexArray * __thiscall DX7Rasterizer::CreateVertexArray(unsigned long,unsigned long)
public: virtual class GEVertexArray* CreateVertexArray(unsigned long, unsigned long);
public: virtual long Deactivate();
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GEPolygonArray &,unsigned long,class GEVertexArray &,unsigned long,class GETexture *,unsigned long,BOOL)
public: virtual long Draw(class GEPolygonArray&, unsigned long, class GEVertexArray&, unsigned long, class GETexture*, unsigned long, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GETerrainMesh &,unsigned long,BOOL)
public: virtual long Draw(class GETerrainMesh&, unsigned long, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GEText *,class GERectangle const &,class GESurface *)
public: virtual long Draw(class GEText*, class GERectangle const&, class GESurface*);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GEText *,class GESurface *)
public: virtual long Draw(class GEText*, class GESurface*);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GERhombus *,unsigned long)
public: virtual long Draw(class GERhombus*, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GEPoint *,unsigned long,unsigned long)
public: virtual long Draw(class GEPoint*, unsigned long, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GEModel *,unsigned long,float,BOOL)
public: virtual long Draw(class GEModel*, unsigned long, float, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GELine *,unsigned long,unsigned long)
public: virtual long Draw(class GELine*, unsigned long, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw(class GEBitmap *,unsigned long)
public: virtual long Draw(class GEBitmap*, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::Draw3DLine(class std::vector<struct std::pair<class GE3DPoint,float>,class std::allocator<struct std::pair<class GE3DPoint,float> > > &,class GETexture *,float,unsigned long,BOOL)
public: virtual long Draw3DLine(class std::vector<struct std::pair<class GE3DPoint, float>, class std::allocator<struct std::pair<class GE3DPoint, float> > >&, class GETexture*, float, unsigned long, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::DrawGridLines(class GETerrainMesh &,class std::vector<struct std::pair<class U2DPoint<long>,class U2DPoint<long> >,class std::allocator<struct std::pair<class U2DPoint<long>,class U2DPoint<long> > > > &,class GETexture *,float,unsigned long,BOOL)
public: virtual long DrawGridLines(class GETerrainMesh&, class std::vector<struct std::pair<class U2DPoint<long>, class U2DPoint<long> >, class std::allocator<struct std::pair<class U2DPoint<long>, class U2DPoint<long> > > >&, class GETexture*, float, unsigned long, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::DrawSky(class GEModel *,unsigned long,float,BOOL)
public: virtual long DrawSky(class GEModel*, unsigned long, float, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::DrawTerrainGrid(class GETerrainMesh &,unsigned long,BOOL)
public: virtual long DrawTerrainGrid(class GETerrainMesh&, unsigned long, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::DrawTerrainHighlight(class GETerrainMesh &,class U2DRectangle<long> const &,unsigned long,BOOL,class GEColor const &,float)
public: virtual long DrawTerrainHighlight(class GETerrainMesh&, class U2DRectangle<long> const&, unsigned long, BOOL, class GEColor const&, float);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::DrawWater(class GETerrainMesh &,unsigned long,BOOL)
public: virtual long DrawWater(class GETerrainMesh&, unsigned long, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::EndScene(unsigned long)
public: virtual long EndScene(unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::GetAvailableVideoMemory(unsigned long,unsigned long &)
public: virtual long GetAvailableVideoMemory(unsigned long, unsigned long&);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::GetTotalVideoMemory(unsigned long,unsigned long &)
public: virtual long GetTotalVideoMemory(unsigned long, unsigned long&);
// dx7hrdisplay_public: virtual unsigned long __thiscall DX7Rasterizer::GetCaps(unsigned long,unsigned long)
public: virtual unsigned long GetCaps(unsigned long, unsigned long);
// dx7hrdisplay_public: virtual BOOL __thiscall DX7Rasterizer::GetCanModulateTextureAlpha(unsigned long)
public: virtual BOOL GetCanModulateTextureAlpha(unsigned long);
// dx7hrdisplay_public: virtual BOOL __thiscall DX7Rasterizer::GetDirtyRectangleSupport(unsigned long)
public: virtual BOOL GetDirtyRectangleSupport(unsigned long);
// dx7hrdisplay_public: virtual void __thiscall DX7Rasterizer::Light(class GETerrainMesh &,unsigned long)
public: virtual void Light(class GETerrainMesh&, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::RemoveAllLights(unsigned long)
public: virtual long RemoveAllLights(unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::RemoveLight(unsigned long,unsigned long)
public: virtual long RemoveLight(unsigned long, unsigned long);
public: virtual void SetAlphaTesting(unsigned long, unsigned long);
public: virtual void SetAlphaTestingCompareState(unsigned long, unsigned long);
public: virtual void SetAlphaTestingRefValue(float, unsigned long);
public: virtual void SetAmbientColor(class GEColor const&, unsigned long);
public: virtual void SetAmbientIntensity(float, unsigned long);
public: virtual void SetAntiAliasing(unsigned long, unsigned long);
public: virtual void SetBlending(unsigned long, unsigned long, unsigned long);
public: virtual void SetColorKeying(unsigned long, unsigned long);
public: virtual void SetCulling(unsigned long);
// dx7hrdisplay_public: virtual void __thiscall DX7Rasterizer::SetDebugColor(class GEColor const &)
public: virtual void SetDebugColor(class GEColor const&);
public: virtual void SetDisplayOverdrawMode(BOOL, unsigned long);
public: virtual void DUP_SetDisplayOverdrawMode(BOOL, unsigned long);
public: virtual void SetDithering(unsigned long, unsigned long);
public: virtual void SetDrawStyle(unsigned long, unsigned long);
public: virtual void SetFog(unsigned long, unsigned long);
public: virtual void SetFogColor(class GEColor const&, unsigned long);
public: virtual void SetFogRange(float, float, unsigned long);
public: virtual void SetFogType(unsigned long, unsigned long);
public: virtual void SetFogValue(float, unsigned long);
public: virtual void SetLighting(unsigned long, unsigned long);
public: virtual void SetProjectionMode(unsigned long, unsigned long);
public: virtual void SetShading(unsigned long, unsigned long);
public: virtual void SetShadingColorSource(unsigned long, unsigned long);
public: virtual void SetSpecular(unsigned long, unsigned long);
// dx7hrdisplay_public: virtual void __thiscall DX7Rasterizer::SetTexture(class GETexture *,unsigned long)
public: virtual void SetTexture(class GETexture*, unsigned long);
public: virtual void SetViewport(class GEViewport const&, unsigned long);
public: virtual void SetWaitForVSync(BOOL, unsigned long);
public: virtual void SetZBuffer(unsigned long, unsigned long);
public: virtual void SetZCompare(unsigned long, unsigned long);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::ShowScene(unsigned long)
public: virtual long ShowScene(unsigned long);
// dx7hrdisplay_public: virtual void __thiscall DX7Rasterizer::TransformToCamera(class GETerrainMesh &,class GEViewport &,float,BOOL,BOOL)
public: virtual void TransformToCamera(class GETerrainMesh&, class GEViewport&, float, BOOL, BOOL);
// dx7hrdisplay_public: virtual long __thiscall DX7Rasterizer::UpdateLight(unsigned long,class GELight &,unsigned long)
public: virtual long UpdateLight(unsigned long, class GELight&, unsigned long);
protected: virtual ~GERasterizer();
// dx7hrdisplay_protected: virtual long __thiscall DX7Rasterizer::ActivateRasterizer(void)
public: virtual long ActivateRasterizer(); 
// dx7hrdisplay_protected: virtual long __thiscall DX7Rasterizer::ActivateTheScreen(unsigned long,class GESurface *,class GESurface *,class GETextureManager *,class GEWindow *)
public: virtual long ActivateTheScreen(unsigned long, class GESurface*, class GESurface*, class GETextureManager*, class GEWindow*);
// dx7hrdisplay_protected: virtual long __thiscall DX7Rasterizer::CreateTextureHandle(class GETexture *)
// It only returns 0
public: virtual long CreateTextureHandle(class GETexture*);
// This is a duplicate of CreateTextureHandle. Might be for compatibility or due to optimizations.
// It only returns 0
public: virtual long DUP_CreateTextureHandle(class GETexture*);
// This one doesn't do anything.
public: virtual void UNK_045();
// dx7hrdisplay_protected: virtual long __thiscall DX7Rasterizer::DrawModelHierarchy(class GEModel *,unsigned long,float,BOOL)
public: virtual long DrawModelHierarchy(class GEModel*, unsigned long, float, BOOL);
// Same as CreateTextureHandle. It only returns 0
public: virtual void UNK_047();
// dx7hrdisplay_protected: virtual void __thiscall DX7Rasterizer::SetRenderTarget(class GESurface *,unsigned long)
public: virtual void SetRenderTarget(class GESurface*, unsigned long);

private:
	float unk0[6];					// 4   + 24  = 28
	std::vector<void*> forms;		// 28  + 16  = 44
	GEFont* arialBoldFont;          // 44  + 4   = 48
	class GEText* text;				// 48  + 4   = 52
	char unk1[56 - 52];  			// 52  + ___ = 56
	TSCriticalSection* drawAccess;  // 56  + 4   = 60
	char unk5[64 - 60];  			// 60  + ___ = 64
	float unk4;						// 64  + 4   = 68
	float unk6;						// 68  + 4   = 72
	float unk7;						// 72  + 4   = 76
	uint32_t unk8;					// 76  + 4   = 80
	uint8_t unk9;					// 80  + 1   = 81
	uint8_t unk10;					// 81  + 1   = 82
									// 85  + @2  = 84
	char unk2[84 - 82];			    // 72  + ___ = 84
	UString rasterizerName;			// 84  + 16  = 100
	uint32_t unk11;					// 100 + 4   = 104
};

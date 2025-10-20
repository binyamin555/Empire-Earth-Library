#pragma once

#include <vector>

#include "framework/low-level engine/.h"

#include "framework/low-level engine/game-engine/font/font.h"
#include "framework/low-level engine/string/wide-string.h"
#include "framework/low-level engine/task-scheduler/critical-section.h"


class UIManager {
public: IMPORT virtual ~UIManager();
public: IMPORT virtual long ChangeIMECandidateWindow(struct UIIMECandidateList const&);
public: IMPORT virtual long ChangeIMECompositionString(class UWideString const&, class UString const&, unsigned long);
public: IMPORT virtual long CloseIMECandidateWindow();
public: IMPORT virtual long CloseIMECompositionString();
protected: virtual long Get0_A(void*);
protected: virtual long Get0_B(void*);
public: IMPORT virtual class UIForm* CreateForm(struct UIDbDataForms const&);
public: IMPORT virtual long OpenIMECandidateWindow();
public: IMPORT virtual long OpenIMECompositionString();
public: IMPORT virtual long UpdateUI(class GE2DPoint const&);
protected: IMPORT virtual long UpdateKeyboard();
protected: IMPORT virtual long UpdateMouse(class GE2DPoint const&);

public: IMPORT class SESoundManager* GetSoundManager() const;
public: IMPORT void AddEventToTrigger(class UIEvent*, class UIForm*, class UIEntity*);
public: IMPORT void AddForm(class UIForm*);
public: IMPORT void ChangeRasterizer(class GERasterizer*);
public: IMPORT void ForceUIUpdate();
public: IMPORT class UIForm* GetCurrentForm() const;
public: IMPORT BOOL GetDrawCandidateWindow() const;
public: IMPORT class GEFont* GetFont(unsigned long) const;
public: IMPORT unsigned long GetFormCount() const;
public: IMPORT class GESurface* GetDrawingSurface() const;
public: IMPORT static class ISEntity* __cdecl GetLMouseButton();
public: IMPORT static BOOL __cdecl GetMouseLeftHanded();
public: IMPORT static class ISEntity* __cdecl GetMouseWheel();
public: IMPORT class GEBitmap* GetRadioDownOff() const;
public: IMPORT class GEBitmap* GetRadioOff() const;
public: IMPORT class GEBitmap* GetRadioDownOn() const;
public: IMPORT class GEBitmap* GetRadioOn() const;
public: IMPORT class GERasterizer* GetRasterizer() const;
public: IMPORT static class ISEntity* __cdecl GetRMouseButton();
public: IMPORT class GEBitmap* GetSBBitmapDownNormal() const;
public: IMPORT class GEBitmap* GetSBBitmapDownPressed() const;
public: IMPORT class GEBitmap* GetSBBitmapLeftNormal() const;
public: IMPORT class GEBitmap* GetSBBitmapRightNormal() const;
public: IMPORT class GEBitmap* GetSBBitmapUpNormal() const;
public: IMPORT class GEBitmap* GetSBBitmapUpPressed() const;
public: IMPORT unsigned long GetUITextureBitDepth() const;
public: IMPORT unsigned long GetVisibleFormCount() const;
public: IMPORT BOOL IsFormOnStack(class UIForm*);
public: IMPORT BOOL IsFormVisible(class UIForm*);
public: IMPORT void LockUIForCopyData();
public: IMPORT void RegisterControlEventCallback(class UIEvent* (__cdecl*)(class UIForm*, unsigned long));
public: IMPORT void RegisterFormEventCallback(class UIEvent* (__cdecl*)(class UIManager*, unsigned long));
public: IMPORT void SetFont(unsigned long, class GEFont*);
public: IMPORT void SetNumberOfFonts(unsigned long);
public: IMPORT void UnlockUIForCopyData();
public: IMPORT UIManager(class UIManager const&);
public: IMPORT class UIManager& operator=(class UIManager const&);
public: IMPORT UIManager(class GERasterizer*, class SESoundManager*, unsigned long, unsigned long, class UResourceFile*, unsigned long);
private: IMPORT void AddClippedForms(unsigned long);
private: IMPORT unsigned long AddToVisibleForms(class UIForm*);
public: IMPORT void AddDirtyRectangle(class GERectangle const&, class UIForm*);
public: IMPORT void AddIMEResultString(class UWideString const&);
public: IMPORT long CopyData();
public: IMPORT void CreateBackgrounds();
private: IMPORT void CreateBitmap(class GEBitmap*, class GETextureCoordinate&, class GETextureCoordinate&, class GETextureCoordinate&, class GETextureCoordinate&);
public: IMPORT class GEBitmap* CreateBitmapForScaledControl(class GEBitmap*, class GERectangle const&);
public: IMPORT class UIEvent* CreateControlEvent(class UIForm*, unsigned long);
public: IMPORT class UIEvent* CreateFormEvent(unsigned long);
public: IMPORT void CreateIMECandidateWindow(class GEFont*);
public: IMPORT long DrawPolygons();
public: IMPORT long DrawTextA();
public: IMPORT class UIForm* GetFormByID(unsigned long) const;
public: IMPORT static long __cdecl GetMouseWheelScrollAmount();
public: IMPORT void LoadDatabase(class FSPath*, class UString const&);
private: IMPORT void LoadTexture(class UString const&, class GETexture*&);
public: IMPORT long Pop();
public: IMPORT long PopTo(class UIForm*);
public: IMPORT long Push(class UIForm*);
public: IMPORT void RedrawAll();
private: IMPORT void RemoveClippedForms(unsigned long);
private: IMPORT void ResetClippedForms();
public: IMPORT void RelayoutAllForms();
public: IMPORT void ProcessAllEventsForForm(class UIForm*);
protected: IMPORT void RemoveAndStopSoundInstance();
protected: IMPORT void RemoveSoundInstance();
public: IMPORT void RemoveDatabase();
protected: IMPORT void SetSoundInstance(class SESMInstanceNode*);
public: IMPORT long SwapForm(class UIForm*);
public: IMPORT static void __cdecl SetMouseLeftHanded(BOOL);
public: IMPORT void SetMusicVolume(float);
public: IMPORT void StartMusic(class UWideString const&);
public: IMPORT void StopMusic();
public: IMPORT long UpdateTranslatedKey(char const*, short);


private:
	TSCriticalSection* criticalSection;
	TSCriticalSection* drawCriticalSection;
	std::vector<void*> formEventCallbacks;
	std::vector<void*> controlEventCallbacks;
	std::vector<UIForm*> formStack;
	std::vector<void*> unkVec0;
	std::vector<UIForm*> visibleForms;
	struct {
		bool unk0;

		int32_t unk1, unk2, unk3, unk4;
	} unk1;
	std::vector<void*> unkVec1;
	std::vector<GEFont*> fonts;
	UWideString currentMusicFileName;
	GERasterizer* rasterizer;
	SESoundManager* soundManager;
	GETexture* uiControlsTexture;
	GEBitmap* uiControlsBitmaps[21];
	UResourceFile* resourceFile;
	int32_t unk2;
	int32_t currentPlayingMusicId;
	SESMInstanceNode* soundInstance;
	float musicVolume;
	uint32_t unk3;
	uint32_t screenId;
	uint32_t textureBitDepth;
	bool b0;
	bool drawCandidateWindow;
	bool b1;
	bool b2;
	bool b3;
	bool b4;
};

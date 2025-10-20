#pragma once

#include "pch.h"

#include <vector>

#include "framework/low-level engine/.h"

class UIControl;

class UIForm {

public: IMPORT UIForm(unsigned long, unsigned long, class UIManager*, unsigned long, BOOL);
public: IMPORT UIForm(class UIManager*, struct UIDbDataForms const&, BOOL);
public: IMPORT UIForm(class UIForm const&);
public: IMPORT virtual ~UIForm();

public: IMPORT virtual void Activate();
public: IMPORT virtual void AddIMEResultString(class UWideString const&);
public: IMPORT virtual long ChangeIMECompositionString(class UWideString const&, class UString const&, unsigned long);
public: IMPORT virtual long CloseIMECompositionString();
public: IMPORT virtual void Deactivate();
protected: IMPORT virtual long DrawBackground(class GERectangle const&);
public: IMPORT virtual long OpenIMECompositionString();
public: IMPORT virtual void RelayoutForm(class GERectangle const&);
public: IMPORT virtual void SetHelpTextPopupLocation();
public: IMPORT virtual void UpdateInformation();
public: IMPORT virtual long UpdateKeyboard();
public: IMPORT virtual long UpdateMouse();
public: IMPORT virtual long UpdateTranslatedKey(char const*, short);
protected: IMPORT virtual void Close();
protected: IMPORT virtual long CopyData();
protected: IMPORT virtual long DrawPolygons();
protected: IMPORT virtual long DrawTextA();
protected: IMPORT virtual void Open();
protected: IMPORT virtual void SetRectangle(class GERectangle const&);

public: IMPORT unsigned long GetTabStop() const;
public: IMPORT void AddDatabaseControl(struct UICDatabase const&);
public: IMPORT void AddEvent(struct UIEventData const&);
public: IMPORT void ClearAllClipRectangles();
public: IMPORT class std::vector<class GERectangle, class std::allocator<class GERectangle> > const& GetClipRectangles();
public: IMPORT UIControl* GetControl(unsigned long) const;
public: IMPORT unsigned long GetControlCount() const;
public: IMPORT unsigned long GetControlGroupCount() const;
public: IMPORT unsigned long GetDesignedWidth() const;
public: IMPORT class UIEntityGroup* GetEntityGroup(unsigned long) const;
public: IMPORT float GetFadeOpacity();
public: IMPORT class UIEvent* GetFormActivateEvent() const;
public: IMPORT class UIEvent* GetFormDeactivateEvent() const;
public: IMPORT unsigned long GetFormID() const;
public: IMPORT class UIEvent* GetFormUpdateEvent() const;
public: IMPORT class UIHotKey* GetHotKey(unsigned long, unsigned long) const;
public: IMPORT unsigned long GetHotKeyCount(unsigned long) const;
public: IMPORT unsigned long GetHowLongHasFormBeenOpen();
public: IMPORT BOOL GetIsKeyboardCaptured() const;
public: IMPORT BOOL GetIsMouseCaptured() const;
public: IMPORT BOOL GetUseExclusiveCoords() const;
public: IMPORT class UIEvent* GetMouseMoveEvent() const;
public: IMPORT class UIEvent* GetMouseRightButtonPressedEvent() const;
public: IMPORT static BOOL __cdecl GetNumLockOff();
public: IMPORT BOOL GetTabbingOn() const;
public: IMPORT BOOL GetUseGDIForText() const;
public: IMPORT void LockDrawBackground();
public: IMPORT void RemoveControl(UIControl*, unsigned long);
public: IMPORT void SetHelpTextTimeDelay(unsigned long);
public: IMPORT void SetLayout(class UILayoutUtility&);
public: IMPORT void SetMusicFileName(class UWideString const&);
public: IMPORT void SetUseToolTips(BOOL);
public: IMPORT void UnlockDrawBackground();
private: IMPORT void SetMouseCaptured(UIControl*);
public: IMPORT class UIForm& operator=(class UIForm const&);
public: IMPORT class GE2DPoint const& GetMouseLocation() const;
public: IMPORT void SetHelpTextLabel(class UITextLabel*);
public: IMPORT class UIEvent* GetMouseMiddleButtonPressedEvent() const;
public: IMPORT class UIEvent* GetMouseRightButtonDoublePressedEvent() const;
public: IMPORT class GERectangle const& GetRectangle() const;
public: IMPORT class UWideString const& GetMusicFileName() const;
public: IMPORT void AddBackground(class UIBackground*);
public: IMPORT void AddClipRectangle(class GERectangle const&);
public: IMPORT void AddControl(UIControl*, unsigned long);
private: IMPORT void AddCopyDirtyRectangle(class GERectangle const&);
public: IMPORT void AddDrawControl(unsigned long);
private: IMPORT void AddDirtyRectangle(class GERectangle const&);
public: IMPORT void AddHotKey(class UIHotKey const&, unsigned long);
public: IMPORT void AddHotKey(unsigned long, unsigned long, unsigned long, unsigned long, class UIEvent*, class UIEvent*, class UIEvent*, class UIEvent*, unsigned long, BOOL);
private: IMPORT void CheckedRadioButton(long&);
public: IMPORT static long __cdecl Create(class FSFileSpec&, class UIManager*);
public: IMPORT long DrawBackground(class GEBitmap*, class GERectangle const&, class GE2DPoint const&);
public: IMPORT long DrawBackground(class GEBitmap*, class GERectangle const&, class GERectangle const&, class GERectangle const&);
public: IMPORT long DrawClippedText(class GERectangle const&, class GEText*, UIControl*);
public: IMPORT BOOL GetAvailableIndex(unsigned long&) const;
public: IMPORT class UIBackground* GetBackgroundByID(unsigned long) const;
public: IMPORT UIControl* GetControlById(unsigned long);
public: IMPORT class UIEntityGroup* GetEntityGroupById(unsigned long) const;
public: IMPORT BOOL GetShouldFadeIn();
public: IMPORT void GetToolTipShadowRectangle(class GERectangle const&, class GERectangle&);
public: IMPORT void LoadBackgrounds();
private: IMPORT void Init();
public: IMPORT void RemoveAllHotKeys();
public: IMPORT void RemoveAllHotKeysForAGroup(unsigned long);
public: IMPORT void RemoveHotKey(unsigned long, unsigned long);
public: IMPORT void RemoveBackground(class UIBackground*);
public: IMPORT void RedrawIntersectControls(class GERectangle const&);
public: IMPORT void SetAllControlsDirty();
public: IMPORT void SetFormActivateEvent(class UIEvent*);
public: IMPORT void SetFormCloseEvent(class UIEvent*);
public: IMPORT void SetFormDeactivateEvent(class UIEvent*);
private: IMPORT void SetFormEvent(unsigned long, class UIEvent*);
public: IMPORT void SetFormKeyboardCapturedEvent(class UIEvent*);
public: IMPORT void SetFormOpenEvent(class UIEvent*);
public: IMPORT void SetFormManager(class UIFormManager*);
public: IMPORT void SetFormUpdateEvent(class UIEvent*);
public: IMPORT void SetHotKeyGroupEnabled(unsigned long, BOOL);
private: IMPORT void SetKeyboardCaptured(UIControl*);
public: IMPORT void SetMouseLeftButtonPressedEvent(class UIEvent*);
public: IMPORT void SetMouseLeftButtonUnpressedEvent(class UIEvent*);
public: IMPORT void SetMouseLeftButtonDoublePressedEvent(class UIEvent*);
public: IMPORT void SetMouseMiddleButtonPressedEvent(class UIEvent*);
public: IMPORT void SetMouseMiddleButtonUnpressedEvent(class UIEvent*);
public: IMPORT void SetMouseMiddleButtonDoublePressedEvent(class UIEvent*);
public: IMPORT void SetMouseMoveEvent(class UIEvent*);
private: IMPORT void SetMouseOverControl(UIControl*);
public: IMPORT void SetMouseRightButtonPressedEvent(class UIEvent*);
public: IMPORT void SetMouseRightButtonUnpressedEvent(class UIEvent*);
public: IMPORT void SetMouseRightButtonDoublePressedEvent(class UIEvent*);
public: IMPORT void SetMouseWheelMoveEvent(class UIEvent*);
public: IMPORT void SetPopup(UIControl*);
public: IMPORT void SetTabbing(BOOL);
public: IMPORT BOOL SetTabStop(unsigned long);
public: IMPORT void ShiftTab();
public: IMPORT void Tab();
public: IMPORT void UnloadBackgrounds();
public: IMPORT void UpdateHelpString();
private: IMPORT void UpdateHelpText(BOOL);
public: IMPORT void UpdateMouseLocation(class GE2DPoint const&);

private:
	void* vtable;					// 0   + 4   = 4
	char unk0[412]; 				// 4   + ___ = 416
};

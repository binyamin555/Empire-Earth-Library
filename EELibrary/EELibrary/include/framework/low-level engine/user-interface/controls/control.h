#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"

#include "framework/low-level engine/user-interface/entity.h"


IMPORT class UIControl : public UIEntity {
public:
	enum class Type : uint32_t {
		Button = 0x1,
		ComboBox = 0x3,
		EditBox = 0x4,
		ListBox = 0x5,
		ScrollBar = 0x7,
		Slider = 0x8,
		StatusBar = 0x9,
		Bitmap = 0xA,
		Movie = 0xA,
		TextLabel = 0xB,
		Graph = 0xD,
	};

public:
	template <typename T>
	bool Is(T*& output) {
		auto const type = GetType();

		if (type == static_cast<unsigned long>(T::StaticType)) {
			output = reinterpret_cast<T*>(this);
			return true;
		}
		else {
			output = nullptr;
			return false;
		}
	}

protected: UIControl(unsigned long, unsigned long, class GERectangle const&, class UIForm*, unsigned long, unsigned long);
public: UIControl(class UIControl const&);
public: virtual ~UIControl();

public: virtual void UNK_000();
public: virtual long ChangeIMECompositionString(class UWideString const&, class UString const&, unsigned long);
public: virtual void ChangeFont(class GEFont*);
public: virtual void UNK_002();
public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
public: virtual BOOL GetHelpString(class UWideString&) const;
public: virtual void UNK_003();
public: virtual void UNK_004();
public: virtual unsigned long GetType() const;
public: virtual void UNK_005();
public: virtual long MouseLButtonDown() = 0;
public: virtual long MouseLButtonUp() = 0;
public: virtual long MouseLButtonDoublePressed();
public: virtual long MouseMove(class GE2DPoint const&) = 0;
public: virtual void UNK_009() = 0;
public: virtual void UNK_010() = 0;
public: virtual void UNK_011();
public: virtual void UNK_012();
public: virtual void ReleaseCapturedKeyboard();
public: virtual void ReleaseCapturedMouse();
public: virtual void SetBgColor(class GEColor const&);
public: virtual void SetBgOpacity(float);
public: virtual void SetDirty(BOOL);
public: virtual void SetDisplayMode(unsigned long);
public: virtual void SetLocation(class GE2DPoint const&);
public: virtual void SetRectangle(class GERectangle const&);
public: virtual void TabbedTo() = 0;
public: virtual void TabbedFrom() = 0;
public: virtual long UpdateKeyboard() = 0;
public: virtual long UpdateTranslatedKey(char const*, short);
protected: virtual long DrawBorder(class GERectangle const&, unsigned long);

public: unsigned long GetBorderThickness();
public: static BOOL __cdecl AltKeyPressed();
public: static BOOL __cdecl ControlKeyPressed();
public: static BOOL __cdecl CopyKeyPressed();
public: static BOOL __cdecl CutKeyPressed();
public: BOOL GetAlwaysDirty();
public: static void __cdecl GetBorderColors(class GEColor&, class GEColor&);
public: float GetBorderOpacity() const;
public: float GetBgOpacity() const;
public: void GetBgColor(class GEColor&) const;
public: class GERectangle const& GetCopiedDrawRectangle() const;
public: unsigned long GetDrawCount() const;
public: unsigned long GetHeight() const;
public: BOOL GetIsDirty() const;
public: class GERectangle const& GetRectangle() const;
public: unsigned long GetWidth() const;
public: static BOOL __cdecl PasteKeyPressed();
public: void SetAlwaysDirty(BOOL);
public: static void __cdecl SetBorderColors(class GEColor const&, class GEColor const&);
public: void SetBorderOpacity(float);
public: void SetBorderThickness(unsigned long);
public: void SetBorderType(unsigned long);
public: void SetHotKey(class UIHotKey*);
public: void SetStringTableID(unsigned long);
public: class UIControl& operator=(class UIControl const&);
public: unsigned long GetStringTableID() const;
protected: void CaptureKeyboard();
protected: void CaptureMouse();
public: static BOOL __cdecl DeleteKeyPressed();
public: static BOOL __cdecl DownKeyPressed();
public: static BOOL __cdecl EnterKeyPressed();
public: static BOOL __cdecl EndKeyPressed();
public: void FireTriggerEvent(unsigned long);
public: class GESurface* GetDrawingSurface() const;
public: BOOL GetHasKeyboardCapture() const;
public: BOOL GetHasMouseCapture() const;
public: BOOL GetLeftMouseButtonDown() const;
protected: class GE2DPoint const& GetMouseLocation() const;
public: class GERasterizer* GetRasterizer() const;
public: BOOL GetRightMouseButtonDown() const;
public: unsigned long GetScreenIndex() const;
public: class SESoundManager* GetSoundManager() const;
public: class UIEvent* GetTriggerEvent(unsigned long);
public: static BOOL __cdecl HomeKeyPressed();
public: static BOOL __cdecl LeftKeyPressed();
protected: void SetBgRectangle(class GERectangle const&);
public: void SetTriggerEvent(unsigned long, class UIEvent*);
public: static BOOL __cdecl ShiftKeyPressed();
public: long UpdateMouse(class GE2DPoint const&);
public: static BOOL __cdecl UpKeyPressed();
public: static BOOL __cdecl RightKeyPressed();
};

#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIButton : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::Button;

public: UIButton(unsigned long, class GEBitmap*, class GEBitmap*, class GEBitmap*, class GERectangle const&, class UIForm*, unsigned long, unsigned long);
public: UIButton(class UIButton const&);
public: virtual ~UIButton() override;

public: class UIButton& operator=(class UIButton const&);

public: class GEBitmap* GetCurrentBitmap() const;
public: BOOL GetIsButtonDown() const;
public: void SetBitmapDrawOffset(class GE2DPoint const&);
public: void SetFocusedBitmap(class GEBitmap*);
public: void SetFocusedTextColor(class GEColor const&);
public: void SetNormalBitmap(class GEBitmap*);
public: void SetPressedBitmap(class GEBitmap*);
public: void SetText(class UWideString const&, class GEFont*);

public: virtual void UNK_000() override;
public: virtual long ChangeIMECompositionString(class UWideString const&, class UString const&, unsigned long) override;
public: virtual void ChangeFont(class GEFont*) override;
public: virtual void UNK_002() override;
public: virtual long CopyData() override;
public: virtual long DrawPolygons() override;
public: virtual long DrawTextA() override;
public: virtual BOOL GetHelpString(class UWideString&) const override;
public: virtual void UNK_003() override;
public: virtual void UNK_004() override;
public: virtual unsigned long GetType() const override;
public: virtual void UNK_005() override;
public: virtual long MouseLButtonDown() override;
public: virtual long MouseLButtonUp() override;
public: virtual long MouseLButtonDoublePressed() override;
public: virtual long MouseMove(class GE2DPoint const&) override;
public: virtual void UNK_009() override;
public: virtual void UNK_010() override;
public: virtual void UNK_011() override;
public: virtual void UNK_012() override;
public: virtual void ReleaseCapturedKeyboard() override;
public: virtual void ReleaseCapturedMouse() override;
public: virtual void SetBgColor(class GEColor const&) override;
public: virtual void SetBgOpacity(float) override;
public: virtual void SetDirty(BOOL) override;
public: virtual void SetDisplayMode(unsigned long) override;
public: virtual void SetLocation(class GE2DPoint const&) override;
public: virtual void SetRectangle(class GERectangle const&) override;
public: virtual void TabbedTo() override;
public: virtual void TabbedFrom() override;
public: virtual long UpdateKeyboard() override;
public: virtual long UpdateTranslatedKey(char const*, short) override;
protected: virtual long DrawBorder(class GERectangle const&, unsigned long) override;

public: void SetButtonDownSound(class UString const&);
public: void SetButtonUpSound(class UString const&);

protected: virtual void ButtonDown();
protected: virtual void ButtonUp();
protected: virtual void MouseOver();
};

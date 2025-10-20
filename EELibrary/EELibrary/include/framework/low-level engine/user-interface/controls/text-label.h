#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UITextLabel : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::TextLabel;

public: UITextLabel(class UWideString const&, class GEFont*, unsigned long, class GERectangle const&, class UIForm*, unsigned long, unsigned long, unsigned long);
public: UITextLabel(class UITextLabel const&);
public: virtual ~UITextLabel();

public: virtual void AppendText(class UWideString const&);
public: virtual void ChangeFont(class GEFont*);
protected: virtual void CheckScrollBar();
public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
protected: virtual long MouseLButtonDown();
protected: virtual long MouseLButtonUp();
protected: virtual long MouseMove(class GE2DPoint const&);
public: virtual long MouseWheelTurned(long);
public: virtual void RecomputeDisplayRange();
public: virtual long UpdateKeyboard();
public: virtual void SetLocation(class GE2DPoint const&);
public: virtual void SetRectangle(class GERectangle const&);

public: BOOL GetFitRectToText() const;
public: unsigned long GetLineCount() const;
public: class UIScrollBar const* GetScrollBar() const;
public: class GERectangle const& GetScrollBarRectangle() const;
public: class UWideString const& GetText(unsigned long) const;
public: long GetTextAsInt(unsigned long) const;
public: class GERectangle const& GetTextRectangle() const;
public: BOOL ScrollBarExists() const;
public: void SetStartingDisplayLine(unsigned long);
public: void SetScrollBarBgOpacity(float);
public: void SetScrollBarBgColor(class GEColor const&);
public: void SetText(class UWideString const&);
public: void SetText(long);
protected: void SetTextRectangle(class GERectangle const&);
public: class UITextLabel& operator=(class UITextLabel const&);
public: unsigned long GetNumberLinesDisplayed() const;
private: void ComputeTextLabelRect();
public: void DeleteArray();
public: void DeleteLine(unsigned long);
private: unsigned long ReadLine(char const*);
private: unsigned long ReadWord(char const*, char*);
public: void SetFitRectToText(BOOL);
private: void SetText(class UWideString const&, BOOL);
};

#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIEditBox : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::EditBox;

public: UIEditBox(unsigned long, class GEFont*, unsigned long, BOOL, class GERectangle const&, class UIForm*, unsigned long, unsigned long, BOOL, BOOL);
public: UIEditBox(class UIEditBox const&);
public: virtual ~UIEditBox();
public: class UIEditBox& operator=(class UIEditBox const&);

public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
public: virtual void ChangeFont(class GEFont*);
public: virtual BOOL GetIMEEnabled() const;
public: virtual long OpenIMECompositionString();
public: virtual long ChangeIMECompositionString(class UWideString const&, class UString const&, unsigned long);
public: virtual long CloseIMECompositionString();
public: virtual void AddIMEResultString(class UWideString const&);
public: virtual void ReleaseCapturedKeyboard();
public: virtual long UpdateKeyboard();
public: virtual long UpdateTranslatedKey(char const*, short);
protected: virtual long MouseLButtonDown();
protected: virtual long MouseLButtonDoublePressed();
protected: virtual long MouseLButtonUp();
protected: virtual long MouseMove(class GE2DPoint const&);
protected: virtual void ProcessEnterKey();
protected: virtual void TabbedFrom();
protected: virtual void TabbedTo();
public: virtual void SetLocation(class GE2DPoint const&);

public: void GetAllText(class UWideString&) const;
public: void GetCaretLocation(class GE2DPoint&) const;
public: BOOL GetCursorOn() const;
public: BOOL GetIsPasswordBox() const;
public: BOOL GetIsTextSelected() const;
public: unsigned long GetLineCount() const;
public: void GetSelectedTextIndices(unsigned long&, unsigned long&) const;
public: long GetStartingDisplayIndex() const;
public: char const* GetText(unsigned long) const;
public: long GetTextAsInt(unsigned long) const;
public: void GetSelectedText(class UWideString&) const;

public: void SetIsPasswordBox(BOOL);
public: void SetSelectedBgColor(class GEColor const&);
public: void SetIMETextColor(class GEColor const&);
public: void SetText(class UWideString const&);
public: void SetText(unsigned long);
public: void SetCaretLocation(unsigned long, unsigned long);

public: void CalculateCaretFromMouseLocation(unsigned long&, long&, class GE2DPoint const&) const;
public: void Copy();
public: void Cut();
public: void Paste();
public: void DeleteSelectedText();
public: void DeleteText(unsigned long, unsigned long, unsigned long, unsigned long);
public: void DeleteText();
public: void SelectText();
public: void SelectText(unsigned long, unsigned long, unsigned long, unsigned long);
public: void ChangeWidth(unsigned long);

private: char const* AddChar(char const*);
private: void BackSpaceChar();
private: void CheckScrollBar();
private: void ComputeCaretLocation(BOOL);
private: void ComputeDrawingIndex();
private: void DecrementCaretPos();
private: void DeleteChar();
private: void DeleteLine(unsigned long);
private: void GetLocationFromIndex(unsigned long, unsigned long, class GE2DPoint&) const;
private: void GetSelectedTextRectangle(unsigned long, unsigned long, unsigned long, class GERectangle&) const;
private: void GetText(unsigned long, unsigned long, unsigned long, unsigned long, class UWideString&) const;
private: void IncrementCaretPos(long);
private: void ProcessDownKey();
private: void ProcessEndKey();
private: void ProcessHomeKey();
private: BOOL ProcessControlInput(BOOL);
private: BOOL ProcessInput(BOOL);
private: BOOL ProcessShiftInput(BOOL);
private: void ProcessUpKey();
private: void RemoveIMECompositionString();
private: void ScrollLeft();
private: void ScrollRight(long);
private: void SetIndexFromUpDownOffset();
private: void SetupKeyboardForCapture();

};

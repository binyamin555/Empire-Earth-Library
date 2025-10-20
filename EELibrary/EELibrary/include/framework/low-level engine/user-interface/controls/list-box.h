#pragma once

#include <vector>

#include "framework/low-level engine/.h"

#include "framework/low-level engine/string/wide-string.h"

#include "./control.h"


template <typename ItemType>
class UIListBox : public UIControl { // TBD. For this, I'll need to RE the original class

};


template <>
class UIListBox<UWideString> : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::ListBox;

public: UIListBox(unsigned long, class std::vector<class UWideString, class std::allocator<class UWideString> >&, unsigned long, BOOL, class GERectangle const&, class UIForm*, unsigned long, unsigned long);
public: UIListBox(class UIListBox<class UWideString> const&);
public: virtual ~UIListBox();

public: class UIListBox<class UWideString>& operator=(class UIListBox<class UWideString> const&);

public: virtual void AppendLine(class UWideString const&);
public: virtual void AppendStringArray(class std::vector<class UWideString, class std::allocator<class UWideString> >&);
public: virtual void ChangeSelectionIndex(unsigned long, BOOL, BOOL);
public: virtual void ClearSelection();
public: virtual long CopyData();
public: virtual void DeleteAllEntries();
public: virtual void DeleteLine(unsigned long);
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
public: virtual long MouseWheelTurned(long);
public: virtual void SetLocation(class GE2DPoint const&);
public: virtual long UpdateKeyboard();

protected: virtual void ButtonDown();
protected: virtual void ButtonUp();
protected: virtual unsigned long GetNumLines() const;
protected: virtual long MouseLButtonDown();
protected: virtual long MouseLButtonUp();
protected: virtual long MouseLButtonDoublePressed();
protected: virtual long MouseMove(class GE2DPoint const&);
protected: virtual void ProcessDown();
protected: virtual void ProcessEnd();
protected: virtual void ProcessHome();
protected: virtual void ProcessUp();
protected: virtual void TabbedFrom();
protected: virtual void TabbedTo();

protected: class std::vector<class UWideString, class std::allocator<class UWideString> > const& GetCopyLineArray() const;
protected: void CheckScrollBar();
protected: long DrawScrollBarText();
protected: unsigned long GetDrawCount() const;

public: long GetCurrentSelection(unsigned long&) const;
public: unsigned long GetDisplayLine() const;
public: BOOL GetScrollBarCaptured() const;
public: class UWideString const& GetData(unsigned long) const;
public: BOOL GetHasSelection() const;
public: BOOL FindString(class UWideString const&, unsigned long&) const;
public: void ChangeWidth(unsigned long);
public: void InsertLine(class UWideString const&, unsigned long);
//public: void InsertLine(class UWideString const&, unsigned long, class UILBNoSort<class UWideString>&);
//public: void InsertLine(class UWideString const&, unsigned long, class UWSNoCaseAlphaSort&);
public: void ReplaceLine(class UWideString const&, unsigned long);
public: void SetAutoSelect(BOOL);
public: void SetFocusedRectColor(class GEColor const&);
public: void SetScrollBarBgOpacity(float);
public: void SetScrollBarBgColor(class GEColor const&);
public: void Sort();

public: class std::vector<class UWideString>::const_iterator Begin() const;
public: class std::vector<class UWideString>::const_iterator End() const;

};


template class IMPORT UIListBox<UWideString>;

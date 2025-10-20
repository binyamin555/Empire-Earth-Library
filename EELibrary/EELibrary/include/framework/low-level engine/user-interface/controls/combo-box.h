#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIComboBox : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::ComboBox;

public: UIComboBox(unsigned long, unsigned long, class std::vector<class UWideString, class std::allocator<class UWideString> >, class GEFont*, class GERectangle const&, unsigned long, class UIForm*, unsigned long, unsigned long, unsigned long);
public: UIComboBox(class UIComboBox const&);
public: virtual ~UIComboBox();

public: class UIComboBox& operator=(class UIComboBox const&);

protected: virtual long AddString();
protected: virtual void ChangeSelection();
protected: virtual void CloseListBox();
protected: virtual void HideControl();
protected: virtual long MouseLButtonDown();
protected: virtual long MouseLButtonUp();
protected: virtual long MouseMove(class GE2DPoint const&);
protected: virtual void OpenListBox();
protected: virtual void ProcessUp();
protected: virtual void TabbedTo();
protected: virtual void TabbedFrom();

public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
public: virtual long MouseWheelTurned(long);
public: virtual void SetLocation(class GE2DPoint const&);
public: virtual long UpdateKeyboard();
public: virtual long UpdateTranslatedKey(char const*, short);

public: long GetCurrentSelection(unsigned long&) const;
public: class UIEditBox const* GetEditBox() const;
public: class GEText* GetGEText() const;
public: class GERhombus* GetSelectedBackground() const;
public: class UITextLabel const* GetTextLabel() const;
public: unsigned long GetTextBoxType() const;
public: void AppendLine(class UWideString&);
public: void AppendStringArray(class std::vector<class UWideString, class std::allocator<class UWideString> >&);
public: void ChangeWidth(unsigned long);
public: void DeleteAllEntries();
public: void DeleteLine(unsigned long);
public: void InsertLine(class UWideString const&, unsigned long);
public: void SetCurrentSelection(unsigned long);
public: void SetListBoxAlwaysDirty(BOOL);
public: void SetListBoxBgColor(class GEColor const&);
public: void SetListBoxFocusedRectColor(class GEColor const&);
public: void SetListBoxSelectedBgColor(class GEColor const&);
public: void SetScrollBarBgColor(class GEColor const&);
public: void SetTextBoxBgColor(class GEColor const&);
public: void SetTextBoxBgOpacity(float);

};

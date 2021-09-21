#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/slider.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/panel.h>


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
private:

protected:
	wxStaticText* WxST_kontrast;
	wxSlider* WxSB_kontrast;

	wxStaticText* WxST_gamma;
	wxSlider* WxSB_gamma;

	wxStaticText* WxST_jasnosc;
	wxSlider* WxSB_jasnosc;
	wxPanel* WxPanel;
	wxButton* m_button1;
	wxButton* m_button2;
	wxButton* m_button3;

	wxCheckBox* m_checkBox1;
	wxGauge* m_gauge1;
	wxTextCtrl* m_textCtrl1;
	wxPanel* m_panel1;
	wxPanel* m_panel2;

	wxStaticText* WxST_R;
	wxSlider* WxSB_R;
	wxStaticText* m_staticTextR;

	wxStaticText* WxST_G;
	wxSlider* WxSB_G;
	wxStaticText* m_staticTextG;

	wxStaticText* WxST_B;
	wxSlider* WxSB_B;
	wxStaticText* m_staticTextB;

	wxStaticText* m_staticText1;
	wxStaticText* m_staticText2;
	wxStaticText* m_staticText3;

	wxStaticText* WxST_X;
	wxSlider* WxSB_X;
	wxStaticText* m_staticTextX;

	wxStaticText* WxST_Y;
	wxSlider* WxSB_Y;
	wxStaticText* m_staticTextY;



	// Virtual event handlers, overide them in your derived class
	virtual void onUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void LoadImg(wxCommandEvent& event) { event.Skip(); }
	virtual void Cenzure(wxCommandEvent& event) { event.Skip(); }
	virtual void Erode(wxCommandEvent& event) { event.Skip(); }
	virtual void Scrolls_Updated(wxScrollEvent& event) { event.Skip(); }
	virtual void HisUpdate(wxCommandEvent& event) { event.Skip(); }
	virtual void Save(wxCommandEvent& event) { event.Skip(); }





public:

	MyFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxString("GFK lab 8 Krzysztof Hrycalik"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1200, 680), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame();

};

#include "GUI.h"


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	bSizer2->SetMinSize(wxSize(300, -1));
	m_button1 = new wxButton(this, wxID_ANY, wxT("Wczytaj obrazek"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_button1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	fgSizer1->SetFlexibleDirection(wxBOTH);
	fgSizer1->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	m_staticText1 = new wxStaticText(this, wxID_ANY, _("kontrast :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->Wrap(-1);
	fgSizer1->Add(m_staticText1, 0, wxALL, 5);
	WxSB_kontrast = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	WxSB_kontrast->SetMinSize(wxSize(100, -1));

	fgSizer1->Add(WxSB_kontrast, 0, wxALL, 5);

	WxST_kontrast = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_kontrast->Wrap(-1);

	fgSizer1->Add(WxST_kontrast, 0, wxALL, 5);

	m_staticText2 = new wxStaticText(this, wxID_ANY, _("gamma :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	fgSizer1->Add(m_staticText2, 0, wxALL, 5);
	WxSB_gamma = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	WxSB_gamma->SetMinSize(wxSize(100, -1));

	fgSizer1->Add(WxSB_gamma, 0, wxALL, 5);

	WxST_gamma = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_gamma->Wrap(-1);

	fgSizer1->Add(WxST_gamma, 0, wxALL, 5);


	m_staticText3 = new wxStaticText(this, wxID_ANY, _("jasnoœæ :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText3->Wrap(-1);
	fgSizer1->Add(m_staticText3, 0, wxALL, 5);
	WxSB_jasnosc = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);

	fgSizer1->Add(WxSB_jasnosc, 0, wxALL, 5);

	WxST_jasnosc = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_jasnosc->Wrap(-1); 

	fgSizer1->Add(WxST_jasnosc, 0, wxALL, 5);

	m_staticTextR = new wxStaticText(this, wxID_ANY, _("R :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextR->Wrap(-1);
	fgSizer1->Add(m_staticTextR, 0, wxALL, 5);
	WxSB_R = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);

	fgSizer1->Add(WxSB_R, 0, wxALL, 5);

	WxST_R = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_R->Wrap(-1);

	fgSizer1->Add(WxST_R, 0, wxALL, 5);

	m_staticTextG = new wxStaticText(this, wxID_ANY, _("G :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextG->Wrap(-1);
	fgSizer1->Add(m_staticTextG, 0, wxALL, 5);
	WxSB_G = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);

	fgSizer1->Add(WxSB_G, 0, wxALL, 5);

	WxST_G = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_G->Wrap(-1);

	fgSizer1->Add(WxST_G, 0, wxALL, 5);

	m_staticTextB = new wxStaticText(this, wxID_ANY, _("B :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextB->Wrap(-1);
	fgSizer1->Add(m_staticTextB, 0, wxALL, 5);
	WxSB_B = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);

	fgSizer1->Add(WxSB_B, 0, wxALL, 5);

	WxST_B = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_B->Wrap(-1);

	fgSizer1->Add(WxST_B, 0, wxALL, 5);

	bSizer2->Add(fgSizer1, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 5);
	m_checkBox1 = new wxCheckBox(this, wxID_ANY, wxT("Praca na wycinku"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_checkBox1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);



	bSizer1->Add(bSizer2, 0, wxALL, 1);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));

	bSizer4->Add(m_panel1, 1, wxEXPAND | wxALL, 5);

	bSizer1->Add(bSizer4, 1, wxEXPAND, 5);

	m_panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(320,180), wxTAB_TRAVERSAL);
	m_panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	bSizer2->Add(m_panel2, 0, 1, 5);

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	fgSizer2->SetFlexibleDirection(wxBOTH);
	fgSizer2->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	m_staticTextX = new wxStaticText(this, wxID_ANY, _("X dla wycinka :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextX->Wrap(-1);
	fgSizer2->Add(m_staticTextX, 0, wxALL, 5);
	WxSB_X = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	WxSB_X->SetMinSize(wxSize(100, -1));

	fgSizer2->Add(WxSB_X, 0, wxALL, 5);

	WxST_X = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_X->Wrap(-1);

	fgSizer2->Add(WxST_X, 0, wxALL, 5);


	m_staticTextY = new wxStaticText(this, wxID_ANY, _("Y dla wycinka :"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextY->Wrap(-1);
	fgSizer2->Add(m_staticTextY, 0, wxALL, 5);
	WxSB_Y = new wxSlider(this, wxID_ANY, 5000, 0, 10000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	WxSB_Y->SetMinSize(wxSize(100, -1));

	fgSizer2->Add(WxSB_Y, 0, wxALL, 5);

	WxST_Y = new wxStaticText(this, wxID_ANY, _("50 %"), wxDefaultPosition, wxDefaultSize, 0);
	WxST_Y->Wrap(-1);

	fgSizer2->Add(WxST_Y, 0, wxALL, 5);


	bSizer2->Add(fgSizer2, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 5);

	m_button2 = new wxButton(this, wxID_ANY, wxT("Rysuj histogram"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_button2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_button3 = new wxButton(this, wxID_ANY, wxT("Zapisz"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_button3, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame::onUpdateUI));
	m_button1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::LoadImg), NULL, this);
	m_button2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::HisUpdate), NULL, this);
	m_button3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Save), NULL, this);


	WxSB_kontrast->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_gamma->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);


	WxSB_jasnosc->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_jasnosc->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_X->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_Y->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_R->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_G->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_B->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

}

MyFrame::~MyFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame::onUpdateUI));
	m_button1->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::LoadImg), NULL, this);
	m_button2->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::HisUpdate), NULL, this);
	m_button3->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Save), NULL, this);

	WxSB_kontrast->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_kontrast->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_jasnosc->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_gamma->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_gamma->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_X->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_X->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_Y->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_Y->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_R->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_R->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_G->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_G->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);

	WxSB_B->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
	WxSB_B->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::Scrolls_Updated), NULL, this);
}
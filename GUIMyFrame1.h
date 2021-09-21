#pragma once

#include "GUI.h"

//// end generated include


#include <wx/filedlg.h>
#include <wx/msw/filedlg.h>
#include <wx/dcbuffer.h>
#include <wx/window.h>

 
 
 
/** Implementing MyFrame1 */
class GUIMyFrame : public MyFrame
{
public:
	GUIMyFrame(wxWindow* parent);
	void refresh(wxClientDC& dc, int i) const;
	void  drawAxis(wxClientDC & dc);
	void  drawLine2d(wxClientDC & dc, double x1, double y1, double x2, double y2);
	void  drawValue(wxClientDC& dc,int x,double value);
	
	~GUIMyFrame();

protected:
	// Handlers for MyFrame1 events.
	void onUpdateUI(wxUpdateUIEvent& event) override;
	void LoadImg(wxCommandEvent& event) override;
	 
	void Scrolls_Updated(wxScrollEvent& event);
	void HisUpdate(wxCommandEvent& event)override;
	void Save(wxCommandEvent& event)override;



	wxImage* _ImgCpy;
	wxImage* _ImgOrg;

	wxImage* _ImgCpym;
	wxImage* _ImgHis;
	float* _histab;
};
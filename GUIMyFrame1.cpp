#include "GUIMyFrame1.h"
#include <cmath>
#include <limits>


GUIMyFrame::GUIMyFrame(wxWindow* parent) : MyFrame(parent) {
	_ImgCpy = new wxImage();
	_ImgHis = new wxImage(1, 1);
	_ImgOrg = new wxImage();
	_ImgCpym = new wxImage();
	_histab = new float[256];
	for (int i = 0; i < 256; i++) {
		_histab[i] = 0;
	}

	wxInitAllImageHandlers();
}

 
void GUIMyFrame::onUpdateUI(wxUpdateUIEvent& event) {
	wxClientDC dc(m_panel1);
	wxClientDC dc2(m_panel2);

	//inicjalizacja zmiennych
	float r = WxSB_R->GetValue();
	float g = WxSB_G->GetValue();
	float b = WxSB_B->GetValue();
	float gamma = exp(WxSB_gamma->GetValue() / 1000. - 5.);
	float jasnosc = (WxSB_jasnosc->GetValue() - 5000.) / 5000. * 255.;
	float kontrast;
	float val;
	if (WxSB_kontrast->GetValue() == 10000) kontrast = std::numeric_limits<float>::max();
	else kontrast = (5000. + (WxSB_kontrast->GetValue() - 5000.)) / (5000. - (WxSB_kontrast->GetValue() - 5000.));
	int i;


	//praca na wycinku
	if (m_checkBox1->IsChecked()) {
		if (!_ImgOrg->Ok()) return;

		wxRect rect((_ImgOrg->GetWidth() - 320) * WxSB_X->GetValue() / 10000, (_ImgOrg->GetHeight() - 180) * WxSB_Y->GetValue() / 10000, 320, 180);
		*_ImgCpym = _ImgOrg->Copy().GetSubImage(rect);
		unsigned char* imgData = _ImgCpym->GetData();

		#pragma omp parallel for private(i)
		for ( i = 0; i < _ImgCpym->GetWidth() * _ImgCpym->GetHeight(); i++) {
			val = round(pow(((float(imgData[i * 3]) - 128.) * kontrast + 128. + jasnosc + (r - 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgData[i * 3] = val > 255 ? 255 : val < 0 ? 0 : val;

			val = round(pow(((float(imgData[i * 3 + 1]) - 128.) * kontrast + 128. + jasnosc + (g - 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgData[i * 3 + 1] = val > 255 ? 255 : val < 0 ? 0 : val;

			val = round(pow(((float(imgData[i * 3 + 2]) - 128.) * kontrast + 128. + jasnosc + (b - 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgData[i * 3 + 2] = val > 255 ? 255 : val < 0 ? 0 : val;
			

		}
		refresh(dc2, 2);
	}

	//praca na miniaturce
	if (!m_checkBox1->IsChecked()) {
		if (!_ImgOrg->Ok()) return;
		*_ImgCpym = _ImgOrg->Copy();
		_ImgCpym->Rescale(dc2.GetSize().x, dc2.GetSize().y);
		unsigned char* imgDatam = _ImgCpym->GetData();

		#pragma omp parallel for private(i)
		for ( i = 0; i < _ImgCpym->GetWidth() * _ImgCpym->GetHeight(); i++) {
			val = round(pow(((float(imgDatam[i * 3]) - 128.) * kontrast + 128. + jasnosc + (r - 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgDatam[i * 3] = val > 255 ? 255 : val < 0 ? 0 : val;

			val = round(pow(((float(imgDatam[i * 3 + 1]) - 128.) * kontrast + 128. + jasnosc + (g- 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgDatam[i * 3 + 1] = val > 255 ? 255 : val < 0 ? 0 : val;

			val = round(pow(((float(imgDatam[i * 3 + 2]) - 128.) * kontrast + 128. + jasnosc + (b- 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgDatam[i * 3 + 2] = val > 255 ? 255 : val < 0 ? 0 : val;
			}
		
	
		refresh(dc2, 2);
	}
	 


	//wypisanie histogramu
	{

		float max = 0;
		for (int i = 0; i < 256; i++) {
			if (max < _histab[i])max = _histab[i];
		}

		for (int i = 0; i < 256; i++) {
			_histab[i] = (_histab[i] / max) * 100;
		}
		drawAxis(dc);


		for (int i = 50; i <= dc.GetSize().x-50; i++)
		{
			if (_histab[int((i - 50.) / (dc.GetSize().x - 100.) * 256.)] != 0)
				drawValue(dc,i-50, _histab[int(round((i - 50.) / (dc.GetSize().x - 100.) * 256.))]/100. * (dc.GetSize().y-100.));
		}

	}


}

void GUIMyFrame::LoadImg(wxCommandEvent& event) {
	wxClientDC dc(m_panel1);
	wxClientDC dc2(m_panel2);

	wxFileDialog* dialog = new wxFileDialog(this, "proszê wybraæ zdjêcie", "./", "", wxT("Obraz JPEG (*.jpg)|*.jpg"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (dialog->ShowModal() == wxID_CANCEL) return;
	if (!_ImgOrg->LoadFile(dialog->GetPath(), wxBITMAP_TYPE_JPEG)) return;
	 
	unsigned char* data = _ImgHis->GetData();
	data[0] = data[1] = data[2] = 255;
	refresh(dc2, 2);
	refresh(dc, 1);
}

void GUIMyFrame::refresh(wxClientDC& dc, int i) const {
	wxBufferedDC buff(&dc);
	if (i == 1) {
		if (_ImgHis->Ok()) {
			_ImgHis->Rescale(dc.GetSize().x, dc.GetSize().y);
			const wxBitmap bitmap(*_ImgHis);
			buff.DrawBitmap(bitmap, 0, 0);
		}
	}
	if (i == 2)
	{
		if (_ImgCpym->Ok()) {
			_ImgCpym->Rescale(dc.GetSize().x, dc.GetSize().y);
			const wxBitmap bitmap(*_ImgCpym);
			buff.DrawBitmap(bitmap, 0, 0);
		}
	}
}

GUIMyFrame::~GUIMyFrame() {
	delete _ImgCpy;
	delete _ImgOrg;
	delete _ImgCpym;
	delete _ImgHis;

}


void GUIMyFrame::Scrolls_Updated(wxScrollEvent& event)
{
	WxST_kontrast->SetLabel(wxString::Format(wxT("%g"), (WxSB_kontrast->GetValue()) / 100.0) + " %");
	WxST_gamma->SetLabel(wxString::Format(wxT("%g"), (WxSB_gamma->GetValue()) / 100.0) + " %");
	WxST_jasnosc->SetLabel(wxString::Format(wxT("%g"), (WxSB_jasnosc->GetValue()) / 100.0) + " %");

	WxST_X->SetLabel(wxString::Format(wxT("%g"), (WxSB_X->GetValue()) / 100.0) + " %");
	WxST_Y->SetLabel(wxString::Format(wxT("%g"), (WxSB_Y->GetValue()) / 100.0) + " %");

	WxST_R->SetLabel(wxString::Format(wxT("%g"), (WxSB_R->GetValue()) / 100.0) + " %");
	WxST_G->SetLabel(wxString::Format(wxT("%g"), (WxSB_G->GetValue()) / 100.0) + " %");
	WxST_B->SetLabel(wxString::Format(wxT("%g"), (WxSB_B->GetValue()) / 100.0) + " %");

}


void  GUIMyFrame::drawLine2d(wxClientDC& dc2, double x1, double y1, double x2, double y2)
{
	 
	dc2.DrawLine(x1,   y1, x2,  y2);
}

void  GUIMyFrame::drawAxis(wxClientDC& dc2)
{	
	wxCoord w, h;
	dc2.GetSize(&w, &h);
	drawLine2d(dc2,    50,h-50, w-50, h-50); //oX
}

void  GUIMyFrame::drawValue(wxClientDC& dc2, int x,double value)
{
	wxCoord w, h;
	dc2.GetSize(&w, &h);
   
	dc2.DrawLine((50) + x, h - 50, 50 + x, h-50 - value );
}

void GUIMyFrame::HisUpdate(wxCommandEvent& event) {
	wxClientDC dc(m_panel1);
	refresh(dc, 1);
	if (!_ImgOrg->Ok()) return;
	*_ImgCpy = _ImgOrg->Copy();
	unsigned char* imgData = _ImgCpy->GetData();
	float gamma = exp(WxSB_gamma->GetValue() / 1000. - 5.);
	float jasnosc = (WxSB_jasnosc->GetValue() - 5000.) / 5000. * 255.;
	float kontrast, val, minus;
	if (WxSB_kontrast->GetValue() == 10000) kontrast = std::numeric_limits<float>::max();
	else kontrast = (5000. + (WxSB_kontrast->GetValue() - 5000.)) / (5000. - (WxSB_kontrast->GetValue() - 5000.));
	int ind, i;
	float r = WxSB_R->GetValue();
	float g = WxSB_G->GetValue();
	float b = WxSB_B->GetValue();
	#pragma omp parallel for private(i)
	for ( i = 0; i < 256; i++) {
		_histab[i] = 0;
	}

	for (int i = 0; i < _ImgCpy->GetWidth() * _ImgCpy->GetHeight(); i++) {
		minus = ((float(imgData[i * 3]) - 128.) * kontrast + 128. + jasnosc + (r - 5000) / 5000. * 255.) / 255.;
		val = round(pow(minus <0 ? 0: minus , gamma) * 255.);
		ind = val > 255 ? 255 : val < 0 ? 0 : val;

		minus = ((float(imgData[i * 3 + 1]) - 128.) * kontrast + 128. + jasnosc + (g - 5000) / 5000. * 255.) / 255.;
		val = round(pow(minus < 0 ? 0 : minus, gamma) * 255.);
		ind += val > 255 ? 255 : val < 0 ? 0 : val;

		minus = ((float(imgData[i * 3 + 2]) - 128.) * kontrast + 128. + jasnosc + (b - 5000) / 5000. * 255.) / 255.;
		val = round(pow(minus < 0 ? 0 : minus, gamma) * 255.);
		ind += val > 255 ? 255 : val < 0 ? 0 : val;
		ind = ind / 3;
		_histab[ind]++;
	}

}

void GUIMyFrame::Save(wxCommandEvent& event) {
	wxFileDialog zapiszFileDialog(this, "Wybierz", "", "", "BMP files (*.bmp)|*.bmp|JPG files (*.jpg)|*.jpg|PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (zapiszFileDialog.ShowModal() == wxID_CANCEL)
		return;


	//inicjalizacja zmiennych
	float r = WxSB_R->GetValue();
	float g = WxSB_G->GetValue();
	float b = WxSB_B->GetValue();
	float gamma = exp(WxSB_gamma->GetValue() / 1000. - 5.);
	float jasnosc = (WxSB_jasnosc->GetValue() - 5000.) / 5000. * 255.;
	float kontrast;
	float val;
	if (WxSB_kontrast->GetValue() == 10000) kontrast = std::numeric_limits<float>::max();
	else kontrast = (5000. + (WxSB_kontrast->GetValue() - 5000.)) / (5000. - (WxSB_kontrast->GetValue() - 5000.));
	int i;


		if (!_ImgOrg->Ok()) return;

		*_ImgCpy = _ImgOrg->Copy();
		unsigned char* imgData = _ImgCpy->GetData();

#pragma omp parallel for private(i)
		for (i = 0; i < _ImgCpy->GetWidth() * _ImgCpy->GetHeight(); i++) {
			val = round(pow(((float(imgData[i * 3]) - 128.) * kontrast + 128. + jasnosc + (r - 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgData[i * 3] = val > 255 ? 255 : val < 0 ? 0 : val;

			val = round(pow(((float(imgData[i * 3 + 1]) - 128.) * kontrast + 128. + jasnosc + (g - 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgData[i * 3 + 1] = val > 255 ? 255 : val < 0 ? 0 : val;

			val = round(pow(((float(imgData[i * 3 + 2]) - 128.) * kontrast + 128. + jasnosc + (b - 5000.) / 5000. * 255.) / 255., gamma) * 255.);
			imgData[i * 3 + 2] = val > 255 ? 255 : val < 0 ? 0 : val;


		}



	_ImgCpy->AddHandler(new wxJPEGHandler);
	_ImgCpy->AddHandler(new wxPNGHandler);
	_ImgCpy->SaveFile(zapiszFileDialog.GetPath());
}
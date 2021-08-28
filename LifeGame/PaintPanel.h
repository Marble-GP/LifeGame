/*****************************************************************//**
 * \file   PaintPanel.h
 * \brief  This is abstruct class of Panel for Image and Graphics
 *
 * \author S-watanabe
 * \date   August 2021
 *********************************************************************/

#pragma once
#include <wx/wx.h>
class PaintPanel :
    public wxPanel
{
protected:
	virtual void OnPaint(wxPaintEvent& event) = 0;

public:
	virtual void OnInit();

	PaintPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(700, 500), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~PaintPanel();
};


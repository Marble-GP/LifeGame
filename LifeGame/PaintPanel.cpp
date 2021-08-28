/*****************************************************************//**
 * \file   PaintPanel.cpp
 * \brief  This is abstruct class of Panel for Image and Graphics
 * 
 * \author S-Watanabe
 * \date   August 2021
 *********************************************************************/

#include "PaintPanel.h"


void PaintPanel::OnInit()
{
	return;
}

PaintPanel::PaintPanel(wxWindow* parent, wxWindowID id,  const wxPoint& pos, const wxSize& size, long style):wxPanel(parent, id, pos, size, style)
{

	OnInit();
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(PaintPanel::OnPaint));

}

PaintPanel::~PaintPanel()
{
	this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(PaintPanel::OnPaint));
}
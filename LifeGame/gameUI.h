///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/tglbtn.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

#include "MyPaint.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		MyPaint* m_panel3;
		wxPanel* m_panel2;
		wxToggleButton* m_toggleBtn1;
		wxStaticText* m_staticText3;
		wxSpinCtrl* m_spinCtrl1;
		wxButton* m_button3;
		wxButton* m_button2;
		wxTimer* htim;



		// Virtual event handlers, overide them in your derived class
		virtual void evt_keyctrl( wxKeyEvent& event ) { event.Skip(); }
		virtual void evt_load( wxCommandEvent& event ) { event.Skip(); }
		virtual void evt_save( wxCommandEvent& event ) { event.Skip(); }

		virtual void OnTimer(wxTimerEvent& event) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Game of life"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};


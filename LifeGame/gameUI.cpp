///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gameUI.h"


#define TIMER_ID 155
///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_panel3 = new MyPaint( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer1->Add( m_panel3, 5, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer3->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );

	m_toggleBtn1 = new wxToggleButton( this, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_toggleBtn1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Generation delay (ms)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer3->Add( m_staticText3, 0, wxALL, 5 );

	m_spinCtrl1 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 100 );
	bSizer3->Add( m_spinCtrl1, 0, wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button3, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button2, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer3, 2, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_panel3->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( MyFrame1::evt_keyctrl ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::evt_load ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::evt_save ), NULL, this );
	
	
	this->Connect(TIMER_ID, wxEVT_TIMER, wxTimerEventHandler(MyFrame1::OnTimer));
	htim = new wxTimer(this, TIMER_ID);
	htim->Start(100);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_panel3->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( MyFrame1::evt_keyctrl ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::evt_load ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::evt_save ), NULL, this );

	this->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MyFrame1::OnTimer));
}

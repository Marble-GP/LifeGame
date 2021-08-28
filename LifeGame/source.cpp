#include "gameUI.h"
#include "PaintPanel.h"
#include <wx/wx.h>
#include <fstream>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public MyFrame1
{
public:
    using MyFrame1::MyFrame1;

private:

    void evt_keyctrl(wxKeyEvent& event)
    {
        auto dlg = new wxMessageDialog(this, "Cell map will be cleared, Are you OK?", "warning", wxYES_NO);
        auto key = event.GetKeyCode();

        switch (key+32)//�Ȃ���+32���Ȃ���ascii�ɂȂ�Ȃ�����
        {
        case 'w':
            m_panel3->y = (m_panel3->y - 1) % m_panel3->N;
            break;
        case 'a':
            m_panel3->x = (m_panel3->x - 1) % m_panel3->N;
            break;
        case 's':
            m_panel3->y = (m_panel3->y + 1) % m_panel3->N;
            break;
        case 'd':
            m_panel3->x = (m_panel3->x + 1) % m_panel3->N;
            break;
        case 'q'://�Z���̐ݒu/�폜
            m_panel3->ToggleCellState();
            break;

        case WXK_DELETE+32://�Ȃ���������͂��̂܂�
            if (dlg->ShowModal() == wxID_YES)
            {
                m_panel3->MapClear();
            }
            break;

        default:
            break;
        }

        this->Refresh();
        delete dlg;
    }

    void evt_load(wxCommandEvent& event)
    {
        m_panel3->LoadCellmapdata();
    }
    void evt_save(wxCommandEvent& event)
    {
        m_panel3->SaveCellmapdata();
    }
    void OnTimer(wxTimerEvent& event)
    {
        //Run�̃g�O���{�^����ON
        if (m_toggleBtn1->GetValue())
        {
            m_panel3->CellTransition();//�Z���̍X�V
            m_panel3->Refresh();//�`��̍X�V
        }

        //�^�C�}�����̃��Z�b�g
        htim->Start(this->m_spinCtrl1->GetValue());
    }

};

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(NULL);
    frame->Show(true);
    return true;
}

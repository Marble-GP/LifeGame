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

        switch (key+32)//なぜか+32しないとasciiにならなかった
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
        case 'q'://セルの設置/削除
            m_panel3->ToggleCellState();
            break;

        case WXK_DELETE+32://なぜかこちらはそのまま
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
        //RunのトグルボタンがON
        if (m_toggleBtn1->GetValue())
        {
            m_panel3->CellTransition();//セルの更新
            m_panel3->Refresh();//描画の更新
        }

        //タイマ周期のリセット
        htim->Start(this->m_spinCtrl1->GetValue());
    }

};

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(NULL);
    frame->Show(true);
    return true;
}

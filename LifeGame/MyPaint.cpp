/*****************************************************************//**
 * \file   MyPaint.cpp
 * \brief  This is main class of LifeGame UI and Process
 * 
 * \author S-Watanabe
 * \date   August 2021
 *********************************************************************/

#include "MyPaint.h"


//My Paint class

//********** private override functions **********
void MyPaint::OnInit()
{
    wxRect canvas = this->GetClientRect();
    w = canvas.GetWidth();
    h = canvas.GetHeight();

}

//OnPaintメソッドは再描画処理(userによるresize, refleshのコール)ごとに呼び出される
//Panelにグリッドを書き，セル(map)をペンとブラシで書き出す
void MyPaint::OnPaint(wxPaintEvent& event)
{
    auto dc = new wxPaintDC(this);

    wxRect canvas = this->GetClientRect();
    w = canvas.GetWidth();
    h = canvas.GetHeight();
    dc->SetBackground(*wxWHITE_BRUSH);
    cw = canvas.GetWidth() / N;
    ch = canvas.GetHeight() / N;
    dc->SetPen(wxPen(wxColour("gray"), 1, wxPENSTYLE_SOLID));
    //dc->SetPen(*wxGREY_PEN); //easier setting
    //グリッドの描画
    DrawMeshgrid(*dc, N, canvas);
    dc->SetPen(wxPen(wxColour("red"), 2, wxPENSTYLE_SOLID));
    //dc->SetPen(*wxRED_PEN); //easier setting
    //カーソルの描画
    DrawFrame(*dc, wxRect(canvas.GetWidth()*x/N, canvas.GetHeight()*y/N, cw, ch));
    //cell(map)の描画
    DrawCelldot(*dc);

    delete dc;
}


//**************************************



//********** public functions **********
void MyPaint::SetCellState(bool state)
{
    map[(x+1) % N][(y+1) % N][handle_buf] = (uint8_t)state;
}

bool MyPaint::GetCellState()
{
    return map[(x+1)%N][(y+1)%N][handle_buf];
}

void MyPaint::ToggleCellState()
{
    map[(x+1) % N][(y+1) % N][handle_buf] ^= (uint8_t)1;
}

//セルの変化はバッファ2つで処理
void MyPaint::CellTransition()
{
    uint8_t s_sum;

    for (uint32_t i = 1; i <= N; ++i)
    {
        for (uint32_t j = 1; j <= N; ++j)
        {   
            //sum of states of surround cells
            s_sum = map[i - 1][j][handle_buf] + map[i + 1][j][handle_buf] + map[i][j - 1][handle_buf] + map[i][j + 1][handle_buf]
                + map[i - 1][j - 1][handle_buf] + map[i - 1][j + 1][handle_buf] + map[i + 1][j - 1][handle_buf] + map[i + 1][j + 1][handle_buf];

            //birth or survival condition
            if (s_sum == 3 || (map[i][j][handle_buf] && (s_sum == 2)))
            {
                map[i][j][!handle_buf] = 1;
            }
            else//other = death
            {
                map[i][j][!handle_buf] = 0;
            }
        }
    }

    handle_buf ^= 1;
}

void MyPaint::MapClear()
{
    for (uint32_t i = 1; i <= N; ++i)
    {
        for (uint32_t j = 1; j <= N; ++j)
        {
            map[i][j][0] = map[i][j][1] = 0;
        }
    }
}

//mapをpublicにしたくなかったためクラス内で処理
void MyPaint::SaveCellmapdata()
{
    //端処理簡易化のため+2バイトしていることを忘れずバッファ確保
    uint8_t* pbuf = new uint8_t[size_t(N + 2) * size_t(N + 2)]{ 0 };
    auto fname = wxSaveFileSelector(wxString("select a save file"), wxString(".lgdat"), "noname.lgdat");

    if (fname != wxEmptyString)
    {
        auto pf = std::fopen(fname, "w");
        //端処理簡易化のため+2バイトしていることを忘れず
        for (uint32_t i = 0; i < N + 2; ++i)
        {
            for (uint32_t j = 0; j < N + 2; ++j)
            {
                pbuf[i * (N + 2) + j] = map[i][j][handle_buf];
            }
        }

        std::fwrite(pbuf, sizeof(uint8_t), size_t(N+2) * size_t(N+2), pf);
        std::fclose(pf);
    }

    delete[] pbuf;
}

void MyPaint::LoadCellmapdata()
{
    //端処理簡易化のため+2バイトしていることを忘れずバッファ確保
    uint8_t* pbuf = new uint8_t[size_t(N + 2) * size_t(N + 2)]{ 0 };
    size_t readsize;

    auto fname = wxLoadFileSelector(wxString("select a load file"), wxString(".lgdat"));
    if (fname != wxEmptyString)
    {
        auto pf = std::fopen(fname, "r");
        readsize = std::fread(pbuf, sizeof(uint8_t), size_t(N + 2) * size_t(N + 2), pf);
        std::fclose(pf);
        if (readsize != size_t(N + 2) * size_t(N + 2))
        {
            wxMessageBox("Invalid data");
            delete[] pbuf;
            return;
        }
        
        for (uint32_t i = 0; i < N + 2; ++i)
        {
            for (uint32_t j = 0; j < N + 2; ++j)
            {
                map[i][j][0] = pbuf[i*(N+2)+j];
            }
        }
    }

    handle_buf = 0;
    delete[] pbuf;
    this->Refresh();
    
}


//**************************************



//********** private functions **********

//Make meshgrid
void MyPaint::DrawMeshgrid(wxPaintDC& dc, size_t N, wxRect grid)
{
    for (uint32_t i = 0; i <= N; ++i)
    {
        dc.DrawLine(wxPoint(w * i / N, 0), wxPoint(w * i / N, h));
        dc.DrawLine(wxPoint(0, h * i / N), wxPoint(w, h * i / N));
    }
}

//Draw Rectangle frame (this is used for cell setting cursole)
void MyPaint::DrawFrame(wxPaintDC& dc, wxRect area)
{
    wxPoint p_list[5];
    p_list[0] = area.GetLeftTop();
    p_list[1] = area.GetRightTop();
    p_list[2] = area.GetRightBottom();
    p_list[3] = area.GetLeftBottom();
    p_list[4] = area.GetLeftTop();
    dc.DrawLines(5, p_list);
}

//Draw all cells
void MyPaint::DrawCelldot(wxPaintDC& dc)
{
    dc.SetPen(wxNullPen);
    dc.SetBrush(*wxBLACK_BRUSH);
    for (uint32_t i = 0; i < N; ++i)
    {
        for (uint32_t j = 0; j < N; ++j)
        {
            if (map[i+1][j+1][handle_buf])
            {
                dc.DrawRectangle(w * i / N, h * j / N, cw, ch);
            }
        }
    }
}

//**************************************


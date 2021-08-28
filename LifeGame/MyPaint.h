/*****************************************************************//**
 * \file   MyPaint.h
 * \brief  This is main class of LifeGame-UI and Process
 *
 * \author S-Watanabe
 * \date   August 2021
 *********************************************************************/
#pragma once
#include "PaintPanel.h"
#include <iostream>


#define MAP_SIZE 64

//My Paint class


class MyPaint :public PaintPanel
{
public:
    using PaintPanel::PaintPanel;

    uint32_t x = 0;
    uint32_t y = 0;
    const uint32_t N = MAP_SIZE;

    void SetCellState(bool state);
    bool GetCellState();
    void ToggleCellState();
    void CellTransition();
    void MapClear();
    
    void SaveCellmapdata();
    void LoadCellmapdata();

private:

    uint8_t handle_buf = 0;
    uint32_t w, h, cw, ch;
    uint8_t map[MAP_SIZE + 2][MAP_SIZE + 2][2] = { 0 };//ã´äEèàóùä»íPâªÇÃÇΩÇﬂ+2

    virtual void OnInit();

    virtual void OnPaint(wxPaintEvent& event);

    void DrawMeshgrid(wxPaintDC& dc, size_t N, wxRect grid);

    void DrawFrame(wxPaintDC& dc, wxRect area);

    void DrawCelldot(wxPaintDC& dc);


};



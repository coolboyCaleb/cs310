#ifndef SHAPEMAKER_H
#define SHAPEMAKER_H

#include <iostream>

using namespace std;

class shapeMaker {
    private:
        int width;
        int height;
        char drawingSymbol;
    public:
        shapeMaker(): width(21), height(21), drawingSymbol('*'){};
        shapeMaker(int w, int h, char symb): width(w) {};
        int getCanvasWidth() const;
        int getCanvasHeight() const;
        int getDrawingSymbol() const;
        void setCanvasWidth(int w);
        void setCanvasHeight(int h);
        void setDrawingSymbol(char s);
        void drawHorizontalLine();
        void drawVerticalLine();
        void drawFilledSquare();
        void drawOpenSquare();
        void drawSmileyFace();
        void drawOpenCircle();

};

#endif
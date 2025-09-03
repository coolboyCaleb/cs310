#include "shapemaker.h"

int shapeMaker::getCanvasWidth() const
{
    return width;
}
int shapeMaker::getCanvasHeight() const
{
    return height;
}
int shapeMaker::getDrawingSymbol() const
{
    return drawingSymbol;
}
void shapeMaker::setCanvasWidth(int w)
{
    width = w;
}
void shapeMaker::setCanvasHeight(int h)
{
    height = h;
}
void shapeMaker::setDrawingSymbol(char s)
{
    drawingSymbol = s;
}
void shapeMaker::drawHorizontalLine()
{
    int midpoint = height / 2;
    if (height % 2 == 1)
    {
        for (int i = 0; i < midpoint; i++)
        {
            cout << "\n";
        }
        for (int j = 0; j < width; j++)
        {
            cout << drawingSymbol;
        }
        for (int k = 0; k < midpoint + 1; k++)
        {
            cout << "\n";
        }
    }
    else
    {
        for (int i = 0; i < midpoint; i++)
        {
            cout << "\n";
        }
        for (int j = 0; j < width; j++)
        {
            cout << drawingSymbol;
        }
        for (int k = 0; k < midpoint; k++)
        {
            cout << "\n";
        }
    }
}
void shapeMaker::drawVerticalLine()
{
   int midpoint = width / 2;
   if (width % 2 == 1){
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < midpoint; j++)
      {
        cout << "  ";
      }
      cout << drawingSymbol;
      for (int k = 0; k < midpoint + 1; k++){
        cout << "  ";
      }
      cout << endl;
   }
   }
   else{
    for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < midpoint; j++)
      {
        cout << "  ";
      }
      cout << drawingSymbol;
      for (int k = 0; k < midpoint; k++){
        cout << "  ";
      }
      cout << endl;
   }
   }
}
void shapeMaker::drawFilledSquare()
{
    for (int i = 0; i < width; )
}
void shapeMaker::drawOpenSquare()
{
}
void shapeMaker::drawSmileyFace()
{
}
void shapeMaker::drawOpenCircle()
{
}

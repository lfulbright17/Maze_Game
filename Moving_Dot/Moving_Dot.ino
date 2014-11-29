/*
  Moving_Dot.pde
 
 * Adapted from "Blink,"  The basic Arduino example.  

*/

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

//Global Variables go here
int xcoord = 3;
int ycoord = 4;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();   // Required code, line 2 of 2.
  SetAuxLEDs(0);

}

void loop()                     // run over and over again
{
  
  
  CheckButtonsPress();
  if (Button_Right)
  {
    if (xcoord < 7)
      {
        if(ReadPx(xcoord+1, ycoord)==Red)
        {
        }
        else 
        {
          xcoord++;
        }
        if(ReadPx(xcoord, ycoord)==Green)
        {
          GAMEOVER();
        }
      }
    else
    {
      xcoord = 7;
    } 
  }

  if (Button_Left)
  {
    if (xcoord > 0)
      {
        if(ReadPx(xcoord-1, ycoord)==Red)
        {
        }
        else 
        {
          xcoord--;
        }
        if(ReadPx(xcoord, ycoord)==Green)
        {
          GAMEOVER();
        }
      }
    else
    {
      xcoord = 0;
    }     
  }
  
  if (Button_Up)
  {
    if (ycoord < 7)
      {
        if(ReadPx(xcoord, ycoord+1)==Red)
        {
        }
        else 
        {
          ycoord++;
        }
        if(ReadPx(xcoord, ycoord)==Green)
        {
          GAMEOVER();
        }  //right here is where i would have the condition for if the whole screen is lit up
           // to trigger level 2 (whole screen must be lit up, then step on orange dot) 
     }  
        
    else
    {
      ycoord = 7;
    }     
  }
  
  if (Button_Down)
  {
    if (ycoord > 0)
      {
        if(ReadPx(xcoord, ycoord-1)==Red)
        {
        }
        else 
        {
          ycoord--;
        }
        if(ReadPx(xcoord, ycoord)==Green)
        {
          GAMEOVER();
        }
      }
    else
    {
      ycoord = 0;
    }     
  }
  
  START();
  DisplaySlate();
  
  if(ReadPx(xcoord+1, ycoord+1)==0);
    {
      DrawPx(xcoord, ycoord, Green);
    }
   

}

void OBSTACLES()
{
  DrawPx(2, 4, Red); 
  DrawPx(2, 3, Red);
  DrawPx(2, 2, Red);
  
  DrawPx(2, 6, Red);
  DrawPx(2, 7, Red);
  DrawPx(3, 6, Red);
  DrawPx(3, 7, Red);
  
  
  DrawPx(6, 1, Red);
  DrawPx(6, 2, Red);
  DrawPx(6, 3, Red);
  DrawPx(6, 4, Red);
  DrawPx(6, 5, Red);
  DrawPx(6, 6, Red);
  DrawPx(6, 7, Red);
}

void ENDONE()
{
  DrawPx(7, 7, Orange); 
}

void ENEMIES()
{
  DrawPx(3, 2, Blue); 
}

void GAMEOVER()
{
  Tone_Start(ToneC5, 100);
  delay(100);
  Tone_Start(ToneB5, 100);
  delay(100);
  Tone_Start(ToneA5, 100);
  delay(1000);
  ClearSlate();
  NEWSTART();
}

void START()
{
  DrawPx(xcoord, ycoord, DimAqua);
  DisplaySlate();
  OBSTACLES();
  DisplaySlate();
  ENDONE();
  DisplaySlate();
}

void NEWSTART()
{
  ClearSlate();
  xcoord = 3;
  ycoord = 4;
  DisplaySlate();
  OBSTACLES();
  DisplaySlate();
  ENDONE();
  DisplaySlate();
}

void seconddrawSKYTHREE() //WHERE LEVEL TWO SHOULD GO!!!
{
  for(int o=0; o<8; o++)
    DrawPx(o, 1, Blue);
  for(int s=0; s<8; s++)
    DrawPx(s, 0, Blue);
} 




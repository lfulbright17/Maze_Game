/*
  Moving_Dot.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

//Global Variables go here
int xcoord = 3;
int ycoord = 4;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
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
        }
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
  DrawPx(7, 7, Yellow); 
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



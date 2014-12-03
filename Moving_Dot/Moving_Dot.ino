/*
  Moving_Dot.pde
 
 * Adapted from "Blink,"  The basic Arduino example.  

*/

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

//Global Variables go here
int xcoord = 3;
int ycoord = 4;
int level = 1;




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
        if(isThereBlack()==false)
        { 
          if(level==1)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==2)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==3)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          delay(100);
          ClearSlate();
          level++;
          if(level==4)
            {
              WINNINGSCREEN();
            }
        }
        if(ReadPx(xcoord, ycoord)==Orange)
        {
          if(isThereBlack()==true)
          {
            GAMEOVER();
          }
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
        if(isThereBlack()==false)
        { 
          if(level==1)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==2)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==3)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          delay(100);
          ClearSlate();
          level++;
          if(level==4)
            {
              WINNINGSCREEN();
            }
        }
        if(ReadPx(xcoord, ycoord)==Orange)
        {
          if(isThereBlack()==true)
          {
            GAMEOVER();
          }
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
        if(isThereBlack()==false)
        { 
          if(level==1)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==2)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==3)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          delay(100);
          ClearSlate();
          level++;
          if(level==4)
            {
              WINNINGSCREEN();
            }
        }
        if(ReadPx(xcoord, ycoord)==Orange)
        {
          if(isThereBlack()==true)
          {
            GAMEOVER();
          }
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
        if(isThereBlack()==false)
        { 
          if(level==1)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==2)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          if(level==3)
            {
              Tone_Start(ToneC6, 100);
              delay(100);
            }
          delay(100);
          ClearSlate();
          level++;
          if(level==4)
            {
              WINNINGSCREEN();
            }
        }
        if(ReadPx(xcoord, ycoord)==Orange)
        {
          if(isThereBlack()==true)
          {
            GAMEOVER();
          }
        }
      }
    else
    {
      ycoord = 0;
    }     
  }
  

  if(level==1)
    {
      START();
    }

  if(level==2)
    {
      level2();
    }
  
  if(level==3)
    {
      level3();
    }
  if(ReadPx(xcoord+1, ycoord+1)==0);
    {
      DrawPx(xcoord, ycoord, Green);
    }
  
  
  
 
  
  
  
  
  
   
}


void OBSTACLES1()
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

void OBSTACLES2()
{
  DrawPx(1, 3, Red);
  
  DrawPx(2, 3, Red);
  DrawPx(2, 5, Red);
  
  DrawPx(3, 1, Red);
  DrawPx(3, 2, Red);
  DrawPx(3, 3, Red);
  DrawPx(3, 5, Red);
  
  DrawPx(4, 3, Red);
  DrawPx(4, 4, Red);
  DrawPx(4, 5, Red);
}

void OBSTACLES3()
{
  DrawPx(0, 6, Red);
  DrawPx(0, 7, Red);
  
  DrawPx(1, 6, Red);
  DrawPx(1, 7, Red);
  
  DrawPx(3, 2, Red);
  DrawPx(3, 3, Red);
  
  DrawPx(4, 4, Red);
  
  DrawPx(5, 5, Red);
  DrawPx(5, 6, Red);
  
  DrawPx(6, 6, Red);
  
  DrawPx(7, 2, Red);

}

void END()
{
  DrawPx(7, 7, Orange); 
}
void END2()
{
  DrawPx(3, 4, Orange); 
}
void END3()
{
  DrawPx(7, 4, Orange);
}

void ENEMIES()
{
  DrawPx(3, 2, Blue);
   delay(100);
  ClearSlate(); 
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
  if(level==1)
  {
    NEWSTART1();
  }
  if(level==2)
  {
    NEWSTART2();
  }
  if(level==3)
  {
    NEWSTART3();
  }
}

void WINNINGSCREEN()
{
  Tone_Start(ToneA5, 100);
  delay(1000);
  Tone_Start(ToneA5, 100);
  delay(1000);
  Tone_Start(ToneA5, 100);
  delay(1000);
  NEWSTART1();
  DrawPx(xcoord, ycoord, DimAqua);
  level = 1;
  if(level = 1)
    xcoord=3;
    ycoord=4;
}
  

void START()
{
  DrawPx(xcoord, ycoord, DimAqua);
  DisplaySlate();
  END();
  DisplaySlate();
  OBSTACLES1();
  DisplaySlate();
}

void NEWSTART1()
{
  ClearSlate();
  xcoord = 3;
  ycoord = 4;
  DisplaySlate();
  OBSTACLES1();
  DisplaySlate();
  END();
  DisplaySlate();
}

void NEWSTART2()
{
  ClearSlate();
  xcoord = 7;
  ycoord = 7;
  DisplaySlate();
  OBSTACLES2();
  DisplaySlate();
  END2();
  DisplaySlate();
}

void NEWSTART3()
{
  ClearSlate();
  xcoord = 3;
  ycoord = 4;
  DisplaySlate();
  OBSTACLES3();
  DisplaySlate();
  END3();
  DisplaySlate();
}

void level2()
{
  DrawPx(xcoord, ycoord, DimAqua);
  DisplaySlate();
  END2();
  DisplaySlate();
  OBSTACLES2();
  DisplaySlate();
  
} 

void level3()
{
  DrawPx(xcoord, ycoord, DimAqua);
  DisplaySlate();
  END3();
  DisplaySlate();
  OBSTACLES3();
  DisplaySlate();
  
} 

boolean isThereBlack()
{
  for (int x = 0; x < 8; x++)
    {
      for (int y = 0; y < 8; y++) 
      {
        if(ReadPx(x,y)==0)
          return true;
      }
    } 
  return false;
}
     
  



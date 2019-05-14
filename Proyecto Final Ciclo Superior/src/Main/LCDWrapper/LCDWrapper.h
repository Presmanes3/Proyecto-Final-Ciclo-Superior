#ifndef _LCD_CLASS_H
#define _LCD_CLASS_H

#include "../Common.h"
#include "Arduino.h"
#include "LiquidCrystal_I2C.h"
#include "Wire.h"

class LcdWrapper : public LiquidCrystal_I2C
{
public:
  LcdWrapper(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows,
             LCDFrame *initialFrame);

  /*Update the current frame*/
  void update();

  /*Change the current frame if possible*/
  void changeFrame(LCDFrame *frame);

  /*Add Frame to framePool if is not already in*/
  void addFrame(LCDFrame *newFrame);

  /*Check if Frame is in the framePool*/
  bool existsFrame(LCDFrame *frame);

  LCDFrame *getDefaultFrame();

  void setup();

private:
  /*Pool of frames*/
  LCDFrame **framePool;

  /*Frame which is being treated*/
  LCDFrame *currentFrame;

  LCDFrame *defaultFrame;

  /*Number of total frames*/
  uint8_t totalFrames;
};

#endif

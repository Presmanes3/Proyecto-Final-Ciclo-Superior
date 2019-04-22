#ifndef _LCD_CLASS_H
#define _LCD_CLASS_H

#include "../Common.h"
#include "Arduino.h"
#include "Frame.h"
#include "LiquidCrystal_I2C.h"
#include "Wire.h"

class LcdWrapper : public LiquidCrystal_I2C {
public:
  LcdWrapper(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows,
             Frame *initialFrame = nullptr, Frame **framePool = nullptr);

  /*Update the current frame*/
  void update();

  /*Change the current frame if possible*/
  void changeFrame(Frame *frame);

  /*Add Frame to framePool if is not already in*/
  void addFrame(Frame *newFrame);

  /*Check if Frame is in the framePool*/
  bool existsFrame(Frame *frame);

private:
  Frame **framePool;
  Frame *currentFrame;
  uint8_t totalFrames;
};

#endif

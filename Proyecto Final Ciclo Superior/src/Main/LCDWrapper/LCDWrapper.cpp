#include "LCDWrapper.h"

LcdWrapper::LcdWrapper(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows,
                       Frame *initialFrame, Frame **framePool)
    : LiquidCrystal_I2C(lcd_Addr, lcd_cols, lcd_rows) {

  if (framePool == nullptr) {
    this->addFrame(initialFrame);
  }
  this->currentFrame = initialFrame;
}

/*Update the current frame*/
void LcdWrapper::update() { this->currentFrame->show(); }

/*Change the current frame if possible*/
void LcdWrapper::changeFrame(Frame *frame) {
  /*If the frame exists and it is not the current frame, change it*/

  if (this->existsFrame(frame) && !(this->currentFrame == frame)) {
#if LCD_SERIAL_DEBUG
    Serial.println(F("Changuing to ") + this->framePool[id]->getName());
#endif
    this->currentFrame = frame;
  }

#if LCD_SERIAL_DEBUG
  Serial.println(F("Frame doesnt exist, add it"));
#endif
}

/*Add a frame in the pool if it is not in yet*/
void LcdWrapper::addFrame(Frame *newFrame) {

  if (this->existsFrame(newFrame)) {
#if LCD_SERIAL_DEBUG
    Serial.print(newFrame->getName());
    Serial.println(F(" already exists!"));
#endif
    return;
  } else {
    /*If the frame is not in the pool add it*/
    this->framePool[this->totalFrames] = newFrame;
    this->totalFrames++;
#if LCD_SERIAL_DEBUG
    Serial.println(F("Frame added :") +
                   this->framePool[thi->totalFrames - 1]->getName());
#endif
  }
}

/*Check if a Frame is inside the pool*/
bool LcdWrapper::existsFrame(Frame *frame) {
  for (uint8_t id = 0; id < this->totalFrames; id++) {
    if (&this->framePool[id] == &frame) {
      return true;
    }
  }
  return false;
}

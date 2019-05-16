#include "LCDWrapper.h"

LcdWrapper::LcdWrapper(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows)
    : LiquidCrystal_I2C(lcd_Addr, lcd_cols, lcd_rows) {
  // this->addFrame(initialFrame);
  /*this->currentFrame = initialFrame;
  this->defaultFrame = this->currentFrame;*/

  this->totalFrames  = 0;
  this->framePool    = nullptr;
  this->defaultFrame = nullptr;
  this->currentFrame = nullptr;
}

void LcdWrapper::setup( ) {
#if LCD_SERIAL_DEBUG
  Serial.println(F("=============== Iniciando Lcd ==============="));
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
#endif
  this->init( );
  this->backlight( );
}
/*Update the current frame*/
void LcdWrapper::update( ) { this->currentFrame->showLcdData( ); }

/*Change the current frame if possible*/
void LcdWrapper::changeFrame(LCDFrame* frame) {
  /*If the frame exists and it is not the current frame, change it*/
#if LCD_SERIAL_DEBUG
  Serial.print(SERIAL_DEBUG_TAG);
  Serial.print(F("Changuing to : "));
  Serial.println(frame->getName( ));
#endif
  this->currentFrame = frame;
}

/*Add a frame in the pool if it is not in yet*/
void LcdWrapper::addFrame(LCDFrame* newFrame) {
  uint8_t index = this->totalFrames;
  // this->framePool[index] = newFrame;

#if LCD_SERIAL_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.print(F("Frame added :"));
  // Serial.println(this->framePool[index]->getName( ));
  // Serial.println(this->framePool[index]->getName( ));
#endif

  this->totalFrames++;
}

/*Check if a Frame is inside the pool*/
bool LcdWrapper::existsFrame(LCDFrame* frame) {
  for(uint8_t id = 0; id < this->totalFrames; id++) {
    if(&this->framePool[id] == &frame) { return true; }
  }
  return false;
}

LCDFrame* LcdWrapper::getDefaultFrame( ) { return this->defaultFrame; }

void LcdWrapper::setDefaultFrame(LCDFrame* newFrame) {
  this->defaultFrame = newFrame;
}

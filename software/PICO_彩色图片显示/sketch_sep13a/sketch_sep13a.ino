#include <stdint.h>
#include <pgmspace.h>
#include <SPI.h>//导入库
#include <TFT_eSPI.h>
extern const uint16_t yuan[0x3200] PROGMEM;
extern const uint16_t yuan1[0x3200] PROGMEM;
extern const uint16_t ssshal[0x3200] PROGMEM;
extern const uint16_t a2[0x3200] PROGMEM;

TFT_eSPI tft = TFT_eSPI();




void setup() {
  tft.init();
  tft.setRotation(3);//横屏
  tft.fillScreen(TFT_BLACK);//黑色
  tft.setSwapBytes(true);      //RGB->BGR 加上这句才能正确显示颜色


}

void loop() {
    tft.pushImage(0, 0, 160, 80, yuan);
    delay(6000);
    tft.pushImage(0, 0, 160, 80, yuan1);
    delay(6000);



}

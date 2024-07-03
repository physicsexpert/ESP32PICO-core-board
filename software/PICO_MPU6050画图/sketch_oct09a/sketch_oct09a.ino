#include <SPI.h>//导入库
#include <TFT_eSPI.h>

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

TFT_eSPI tft = TFT_eSPI();



int t;


void setup(void) {
  Serial.begin(115200);
  tft.init();//初始化
  tft.setRotation(3);//横屏
  tft.fillScreen(TFT_BLACK);//黑色
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  delay(10); //初始化MPU-6050传感器。
  Serial.println("Adafruit MPU6050 test!");
  // 尝试初始化
  if (!mpu.begin()) {
    Serial.println("not find MPU6050");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("加速计范围设置为: ");
  switch (mpu.getAccelerometerRange()) {
    case MPU6050_RANGE_2_G:
      Serial.println("+-2G");
      break;
    case MPU6050_RANGE_4_G:
      Serial.println("+-4G");
      break;
    case MPU6050_RANGE_8_G:
      Serial.println("+-8G");
      break;
    case MPU6050_RANGE_16_G:
      Serial.println("+-16G");
      break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("陀螺仪量程设置为: ");
  switch (mpu.getGyroRange()) {
    case MPU6050_RANGE_250_DEG:
      Serial.println("+- 250 deg/s");
      break;
    case MPU6050_RANGE_500_DEG:
      Serial.println("+- 500 deg/s");
      break;
    case MPU6050_RANGE_1000_DEG:
      Serial.println("+- 1000 deg/s");
      break;
    case MPU6050_RANGE_2000_DEG:
      Serial.println("+- 2000 deg/s");
      break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("过滤器带宽设置为: ");
  switch (mpu.getFilterBandwidth()) {
    case MPU6050_BAND_260_HZ:
      Serial.println("260 Hz");
      break;
    case MPU6050_BAND_184_HZ:
      Serial.println("184 Hz");
      break;
    case MPU6050_BAND_94_HZ:
      Serial.println("94 Hz");
      break;
    case MPU6050_BAND_44_HZ:
      Serial.println("44 Hz");
      break;
    case MPU6050_BAND_21_HZ:
      Serial.println("21 Hz");
      break;
    case MPU6050_BAND_10_HZ:
      Serial.println("10 Hz");
      break;
    case MPU6050_BAND_5_HZ:
      Serial.println("5 Hz");
      break;
  }

  Serial.println("");
  delay(100);
}

void loop() {
  /* 通过读数获取新的传感器事件 */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  t = t + 1;
  if (t == 160)
  {
    t = 0;
    tft.fillScreen(TFT_BLACK);
  }

  tft.drawFastHLine(0, 60, 160, TFT_WHITE ); //水平线
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setTextSize(1);
  tft.setCursor(5,5, 1);
  tft.print("X:");//显示文字
  tft.setTextSize(1);
  tft.setCursor(30, 5, 1);
  tft.print(a.acceleration.x);//显示文字
//  tft.drawPixel( t, 44 - a.acceleration.x * 1 , TFT_RED); // 画点
  tft.drawPixel( t, 60 - a.acceleration.x * .5 , TFT_RED); // 画点
//  tft.drawPixel( t, 46 - a.acceleration.x * 1 , TFT_RED); // 画点

  tft.setTextSize(1);
  tft.setCursor(90,5, 1);
  tft.print(g.gyro.x);//显示文字

  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.setTextSize(1);
  tft.setCursor(5, 15, 1);
  tft.print("Y:");//显示文字
  tft.setTextSize(1);
  tft.setCursor(30, 15, 1);
  tft.print(a.acceleration.y);//显示文字
//  tft.drawPixel( t, 44 - a.acceleration.y * 1 , TFT_BLUE); // 画点
  tft.drawPixel( t, 60 - a.acceleration.y * 1.5 , TFT_BLUE); // 画点
//  tft.drawPixel( t, 46 - a.acceleration.y * 1 , TFT_BLUE); // 画点

  tft.setTextSize(1);
  tft.setCursor(90, 15, 1);
  tft.print(g.gyro.y);//显示文字






  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(1);
  tft.setCursor(5, 25, 1);
  tft.print("Z:");//显示文字
  tft.setTextSize(1);
  tft.setCursor(30, 25, 1);
  tft.print(a.acceleration.z);//显示文字
//  tft.drawPixel( t, 44 - a.acceleration.z * 1 , TFT_GREEN); // 画点
  tft.drawPixel( t, 60 - a.acceleration.z * 1.5 , TFT_GREEN); // 画点
//  tft.drawPixel( t, 46 - a.acceleration.z * 1 , TFT_GREEN); // 画点





  tft.setTextSize(1);
  tft.setCursor(90, 25, 1);
  tft.print(g.gyro.z);//显示文字


  delay(2);
}

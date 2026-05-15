#ifndef myoptions_h
#define myoptions_h

// *******************************************************

// Файл налашуваннь yoRadio для ESP32 WROVER або ESP32 WROOM, який необхідно відредагувати залежно від використовуваних компонентів
// Скопіюйте цей файл у кореневий каталог проєкту (поруч із файлом yoRadio.ino)
// Розкоментуйте потрібні рядки, щоб змінити значення за замовчуванням та встановити значення відповідно до підключеного обладнання.
// Для спрощення процесу визначення пінів підключення, використовуйте генератор:
// https://trip5.github.io/ehRadio_myoptions/generator.html

// **************************************************************************

// !!! Attention !!!
// Ця конфігурація залежить від деяких додаткових бібліотек.
// Будь ласка, встановіть їх за допомогою менеджера бібліотек.:
// Adafruit_GFX, Adafruit_ST7735*, Adafruit_SSD1306*, Adafruit_PCD8544*,
// Adafruit_SH110X*, Adafruit_SSD1327*, Adafruit_ILI9341*,
// Adafruit_SSD1305*, XPT2046_Touchscreen, RTCLib

// **************************************************************************

#define L10N_LANGUAGE     RU        //  Language (EN, RU). More info in yoRadio/locale/displayL10n_(en|ru).h 

// **************************************************************************

//#define LED_BUILTIN     2       //  Вбудований світлодіодний контакт
//#define LED_INVERT      false     //  Інвертувати вбудований світлодіод?
//#define USE_BUILTIN_LED   false   	//  Не використовувати вбудований RGB-світлодіод S3

// **************************************************************************

// Display
#define DSP_MODEL     DSP_DUMMY        // Якщо дисплей не використовується.
//#define DSP_MODEL   DSP_ILI9341      // ILI9341 320x240
//#define DSP_MODEL   DSP_ILI9488      // ILI9488 480X320
//#define DSP_MODEL   DSP_SH1106       // Select SH1106-128х64
//#define DSP_MODEL   DSP_ST7735       // Select ST7735
//#define DSP_MODEL   DSP_ST7789_76    // ST7789 284x76
//#define DSP_MODEL   DSP_ST7789_170   // ST7789 320x170
//#define DSP_MODEL   DSP_ST7789_240   // ST7789 240x240
//#define DSP_MODEL   DSP_ST7789       // ST7789 320x240
//#define DSP_MODEL   DSP_ST7796       // ST7796 480X320
//#define DSP_MODEL   DSP_SSD1306x32   // Select SSD1306-128х32
//#define DTYPE       INITR_GREENTAB   // ST7735 display submodel. По умолчанию "INITR_BLACKTAB"

/*
 * !!! Важливо !!!
 * якщо ви використовуєте кольорові TFT-дисплеї з esp32 wroom, через брак пам'яті необхідно змінити файл Arduino/libraries/AsyncTCP/src/AsyncTCP.cpp
 * замінити рядок 221
 * xTaskCreateUniversal(_async_service_task, "async_tcp", 8192 * 2, NULL, 3, &_async_service_task_handle, CONFIG_ASYNC_TCP_RUNNING_CORE);
 * на
 * xTaskCreateUniversal(_async_service_task, "async_tcp", 8192 / 2, NULL, 3, &_async_service_task_handle, CONFIG_ASYNC_TCP_RUNNING_CORE);
*/

// **************************************************************************

//  VSPI PINS
//#define TFT_SCK          18   // Пін дисплея "SCL"
//#define TFT_MOSI         23   // Пін дисплея "SDA"
//#define TFT_DC           2    // Пін дисплея "DC"
//#define TFT_CS           4    // Пін дисплея "CS"
//#define TFT_RST          -1   // Пін дисплея "RESET" підключити до Esp EN pin
//#define BRIGHTNESS_PIN   15    // Пін дисплея "BL"
//#define DEF_SPI_FREQ     80000000UL   // Частота SPI для дисплея (80 МГц)

// **************************************************************************

/*  NEXTION  */
//#define NEXTION_RX    255                   /*  Nextion RX pin  */
//#define NEXTION_TX    255                   /*  Nextion TX pin  */
  
/*  I2C PINS  */
//#define I2C_SDA           21                /*  I2C SDA pin. It is best to connect to pin 21.  */
//#define I2C_SCL           22                /*  I2C SCL pin. It is best to connect to pin 22.  */
//#define I2C_RST           -1                /*  I2C RST pin. Set to -1 if not used  */

// **************************************************************************

/*        I2S DAC                 */
#define I2S_DOUT          25        // SDIN, DIN
#define I2S_BCLK          26        // SCLK, BCK
#define I2S_LRC           27        // RLCLK, LRCK, WSEL
//#define I2S_MCLK		  24		// MCLK - Master Clock (Тількі для CJMCU-4344)

// **************************************************************************

#define VS1053_CS         255               /*  Вивід XCS. Слід встановити значення 255, якщо плата не використовується. */
/*  VS1053 VSPI PINS. VS1053 SCK must be connected to pin 18
                      VS1053 MISO must be connected to pin 19
                      VS1053 MOSI must be connected to pin 23  */
//#define VS1053_DCS        25                /*  XDCS pin.  */
//#define VS1053_DREQ       26                /*  DREQ pin.  */
//#define VS1053_RST        -1                /*  XRESET pin. Set to -1 if connected to Esp EN pin */

/*  VS1053 HSPI PINS. VS1053 SCK must be connected to pin 14
                      VS1053 MISO must be connected to pin 12
                      VS1053 MOSI must be connected to pin 13  */
//#define VS_HSPI           false             /*  Use HSPI for VS  */

// **************************************************************************

/*  BUTTONS  */
//#define BTN_LEFT              255           //  VolDown, Prev
//#define BTN_CENTER            255           //  Play, Stop, Show playlist
//#define BTN_RIGHT             255           //  VolUp, Next
//#define BTN_UP                255        //  Prev, Move Up
//#define BTN_DOWN              255        //  Next, Move Down
//#define BTN_INTERNALPULLUP        true   //  Enable the weak pull up resistors
//#define BTN_LONGPRESS_LOOP_DELAY   200   //  Delay between calling DuringLongPress event
//#define BTN_CLICK_TICKS            300   //  Event Timing https://github.com/mathertel/OneButton#event-timing
//#define BTN_PRESS_TICKS            500   //  Event Timing https://github.com/mathertel/OneButton#event-timing

//#define BTN_MODE              36            // Перемикач РЕЖИМУ

//#define WAKE_PIN       BTN_CENTER            // Wake Pin (для ручного пробудження з режиму сну. може збігатися з BTN_XXXX, ENC_BTNB, ENC2_BTNB. має бути одним із: 0,2,4,12,13,14,15,25,26,27,32,33,34,35,36,39)
                                           // Для прикладу #define ENC_BTNB 36 - наступний рядок - #define WAKE_PIN ENC_BTNB
// **************************************************************************

/*  ENCODER  */
//#define ENC_BTNL              255           /*  Left rotation */
//#define ENC_BTNB              255           /*  Encoder button */
//#define ENC_BTNR              255           /*  Right rotation */
//#define ENC_INTERNALPULLUP    false          /*  Enable the weak pull up resistors */
//#define ENC_HALFQUARD         true          /*  Experiment  with it */

/*  ENCODER2  */
//#define ENC2_BTNL              255           /*  Left rotation */
//#define ENC2_BTNB              255           /*  Encoder button */
//#define ENC2_BTNR              255           /*  Right rotation */
//#define ENC2_INTERNALPULLUP    true          /*  Enable the weak pull up resistors */
//#define ENC2_HALFQUARD         false         /*  (true, false, 255) Experiment  with it */

// **************************************************************************

/*  SDCARD  */
/*  MISO is the same as D0, MOSI is the same as D1 */
/*  SD VSPI PINS. SD SCK must be connected to pin 18
                  SD MISO must be connected to pin 19
                  SD MOSI must be connected to pin 23  */
/*  SD HSPI PINS. SD SCK must be connected to pin 14
                  SD MISO must be connected to pin 12
                  SD MOSI must be connected to pin 13  */
//#define SDC_CS                 5           /* SDCARD CS pin */
//#define SD_HSPI       				 false				 /* use HSPI for SD (miso=12, mosi=13, clk=14) instead of VSPI (by default)	*/

// **************************************************************************

/*        RTC                     */
//#define RTC_MODULE            DS3231	/*	one of DS3231, DS1307, RTC_MODULE_UNDEFINED(default)	*/
//#define RTC_SDA               21						 /*	RTC_SDA	*/
//#define RTC_SCL               22						 /*	RTC_SCL	*/

// **************************************************************************

/*  LCD DISPLAY 1602  */
//#define LCD_RS                255           /*  RS Pin */
//#define LCD_E                 255           /*  E Pin  */
//#define LCD_D4                255           /*  D4 Pin */
//#define LCD_D5                255           /*  D5 Pin */
//#define LCD_D6                255           /*  D6 Pin */
//#define LCD_D7                255           /*  D7 Pin */

// **************************************************************************

/*  TOUCHSCREEN  */
//#define TS_MODEL              TS_MODEL_UNDEFINED  /*  See description/available values in yoRadio/src/core/options.h  */

/*  Resistive SPI touch screen  */
/*  TS VSPI PINS. CLK must be connected to pin 18
                  DIN must be connected to pin 23
                  DO  must be connected to pin 19
                  IRQ - not connected */
//#define TS_CS                 255           /*  Touch screen CS pin  */
/*  TS HSPI PINS. CLK must be connected to pin 14
                  DIN must be connected to pin 13
                  DO  must be connected to pin 12
                  IRQ - not connected */
//#define TS_HSPI               false         /*  Use HSPI for Touch screen  */

/*  Capacitive I2C touch screen  */
//#define TS_SDA                33
//#define TS_SCL                32
//#define TS_INT                21
//#define TS_RST                25

// **************************************************************************

/*  IR control  */
//#define IR_PIN                13
//#define IR_TIMEOUT            80              /*  see kTimeout description in IRremoteESP8266 example https://github.com/crankyoldgit/IRremoteESP8266/blob/master/examples/IRrecvDumpV2/IRrecvDumpV2.ino */

// **************************************************************************

// *** Погода ***
//#define MUTE_PIN          32     // MUTE Pin підсилювача або XSMT pin DAC
//#define MUTE_VAL          HIGH   // Значення рівня на нозі mute_pin, коли плеєр зупинено. HIGH-високий рівень; LOW-низький рівень.

// **************************************************************************

// *** Погода ***
//#define HIDE_WEATHER
#define EXT_WEATHER				true		// Розширена погода "true", скорочена "false"

// **************************************************************************

// *** Інші налаштування. ***
//#define DTYPE             INITR_BLACKTAB    /*  ST7735 display submodel */
                                              /*  Could be one of: */
                                              /*  INITR_BLACKTAB        1.8' https://aliexpress.com/item/1005002822797745.html  */
                                              /*  (See this note If INITR_BLACKTAB have a noisy line on one side of the screen https://github.com/e2002/yoradio#note-if-initr_blacktab-dsp-have-a-noisy-line-on-one-side-of-the-screen-then-in-adafruit_st7735cpp ) */
                                              /*  INITR_144GREENTAB     // 1.44' https://aliexpress.com/item/1005002822797745.html  */
                                              /*  INITR_MINI160x80      // 0.96' 160x80 ST7735S   https://????  */
                                              /*  INITR_GREENTAB  */
                                              /*  INITR_REDTAB  */
											  
//#define PLAYER_FORCE_MONO false             /*  моно (false - стерео, true - моно).  */
//#define I2S_INTERNAL      true             /*  використовувати внутрішній ЦАП esp32  */

//#define LIGHT_SENSOR      255               /*  Light sensor  */
//#define AUTOBACKLIGHT(x)  *function*        /*  Autobacklight function. See options.h for example  */

//#define BITRATE_FULL		true	// true - Включення "картинки" з бітрейтом
//#define BOOMBOX_STYLE				// Волюметр у BOOMBOX стилі
//#define CLOCKFONT_MONO	true	// Вимкнути/Увімкнути моношрифти для годинників TFT дисплеїв. За промовчанням "true"
//#define DOWN_LEVEL		2		// найнижчий рівень яскравості (from 0 to 255) За промовчанням "2". (МОД Maleksm)
//#define DOWN_INTERVAL		60		// інтервал для вимкнення підсвічування в секундах (60 сек = 1 хв) За промовчанням "60". (МОД Maleksm)
//#define DSP_INVERT_TITLE	false	// Інверсні кольори станції (заголовок дисплея). За промовчанням "true"
//#define HIDE_DATE					// Приховати дату. (МОД nva_lw)
//#define HIDE_HEAPBAR				// Сховати відображення смужки буфера
//#define HIDE_IP					// Сховати відображення IP
//#define HIDE_RSSI					// Сховати відображення RSSI	
//#define HIDE_SECONDS				// Приховати відображення секунд
//#define HIDE_VOL_CONTROL			// Прибрати повністю керування гучністю з енкодера, тільки пульт та веб
//#define HIDE_VOLBAR				// Прибрати смужку гучності
//#define HIDE_VOLPAGE				// Приховати сторінку "Гучність", орієнтуємося на прогрес гучності.
//#define NAME_STRIM				// Показувати ім'я станції зі стриму. (МОД Maleksm)
//#define RSSI_DIGIT        true   	// Графічний/цифровий значок Wi-Fi. (false - драбинка, true - цифри)
//#define VU_PEAK					// Показувати пікові значення волюметра.

// **************************************************************************

//#define USE_OTA    true
//#define OTA_PASS "pass"

/* ************************************************************************** */

//#define HTTP_USER "user"
//#define HTTP_PASS ""

/* ************************************************************************** */

#endif

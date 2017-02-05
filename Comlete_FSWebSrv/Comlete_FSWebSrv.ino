/*
   Шаг №7
   Запись и чтение параметров конфигурации в файл

*/
#include <ESP8266WiFi.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step1-wifi
#include <ESP8266WebServer.h>   //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step2-webserver
#include <ESP8266SSDP.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step3-ssdp
#include <FS.h>                 //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step4-fswebserver
//                    ПЕРЕДАЧА ДАННЫХ НА WEB СТРАНИЦУ. Видео с уроком http://esp8266-arduinoide.ru/step5-datapages/
//                    ПЕРЕДАЧА ДАННЫХ С WEB СТРАНИЦЫ.  Видео с уроком http://esp8266-arduinoide.ru/step6-datasend/
#include <ArduinoJson.h>        //Установить из менеджера библиотек.
IPAddress apIP(192, 168, 4, 1);

// Web интерфейс для устройства
ESP8266WebServer HTTP(80);
// Для файловой системы
File fsUploadFile;

// Определяем переменные wifi
String _ssid     = "HP_LaserJet_1153"; // Для хранения SSID
String _password = "verylongwifipassword"; // Для хранения пароля сети
String _ssidAP = "esp";   // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа
String SSDP_Name = "SendToWeb"; // Имя SSDP
int timezone = 3;               // часовой пояс GTM

String jsonConfig = "{}";

void setup() {
  Serial.begin(115200);
  Serial.println("");
  //Запускаем файловую систему 
  Serial.print("FS init.. ");
   FS_init();
  Serial.print("ok.\r\nWIFI init.. ");
   //Запускаем WIFI
  WIFIinit();
    //Настраиваем и запускаем SSDP интерфейс
  Serial.print("ok.\r\nSSDP init.. "); // обнаружение в сети
  SSDP_init();
  //Настраиваем и запускаем HTTP интерфейс
  Serial.print("ok.\r\nWebServer init.. ");
  HTTP_init();
  Serial.print("ok.\r\nInitialisation finished sucsesfully. Now working.");

}

void loop() {
  HTTP.handleClient();
  delay(1);
}




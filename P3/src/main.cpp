
//Web 1

/*
#include <Arduino.h>
#include <WiFi.h> 
#include <WebServer.h> 
void handle_root();
// SSID & Password 
const char* ssid = "Nautilus";  // Enter your SSID here 
const char* password = "20000Leguas";  //Enter your Password here 
WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult) 
void setup() { 
 Serial.begin(115200); 
 Serial.println("Try Connecting to "); 
 Serial.println(ssid); 
 // Connect to your wi-fi modem 
 WiFi.begin(ssid, password); 
 // Check wi-fi is connected to wi-fi network 
 while (WiFi.status() != WL_CONNECTED) { 
 delay(1000); 
 Serial.print("."); 
 } 
 Serial.println(""); 
 Serial.println("WiFi connected successfully"); 
 Serial.print("Got IP: "); 
 Serial.println(WiFi.localIP());  //Show ESP32 IP on serial 
 server.on("/", handle_root); 
 server.begin(); 
 Serial.println("HTTP server started"); 
 delay(100);  
} 
void loop() { 
 server.handleClient(); 
} 
// HTML & CSS contents which display on web server 
String HTML = "<!DOCTYPE html>\ 
<html>\ 
<body>\ 
<h1>My Primera Pagina con ESP32 - Station Mode &#128522;</h1>\ 
</body>\ 
</html>"; 
// Handle root url (/) 
void handle_root() { 
 server.send(200, "text/html", HTML); 
}*/

//Web 2

/*#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void handle_root();

// SSID & Password 
const char* ssid = "Nautilus";  // Enter your SSID here 
const char* password = "20000Leguas";  //Enter your Password here 

WebServer server(80);  // Object of WebServer(HTTP port, 80 is default) 

void setup() { 
  Serial.begin(115200); 
  Serial.println("Try Connecting to "); 
  Serial.println(ssid); 

  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000); 
    Serial.print("."); 
  } 

  Serial.println(""); 
  Serial.println("WiFi connected successfully"); 
  Serial.print("Got IP: "); 
  Serial.println(WiFi.localIP());  // Show ESP32 IP on serial 
  
  server.on("/", handle_root); 
  server.begin(); 
  Serial.println("HTTP server started"); 
  delay(100);  
} 

void loop() { 
  server.handleClient(); 
} 

//HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<head>\
  <style>\collect2: error: ld returned 1 exit status
* [.pio/build/esp32-s3-devkitm-1/firmware.elf] Error 1
    body {\
      display: flex;\
      justify-content: center;\
      align-items: center;\
      height: 100vh;\
      background-color: #282c34;\
      margin: 0;\
      color: white;\
      font-family: Arial, sans-serif;\
    }\
    .circle {\
      width: 100px;\
      height: 100px;\
      background-color: #4CAF50;\
      border-radius: 50%;\
      <html>\
<body>
</html>";

// Handle root URL (/)
void handle_root() { 
  server.send(200, "text/html", HTML); 
}
*/

 //Bluetooth


/*

 #include <Arduino.h>#include "BluetoothSerial.h"
  #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
  #endif
  BluetoothSerial SerialBT;
   void setup() {
   Serial.begin(115200);
   SerialBT.begin("Nuria_COM8"); //Bluetooth device name
   Serial.println("The device started, now you can pair it with bluetooth!");
   }
   void loop() {
   if (Serial.available()) {
   SerialBT.write(Serial.read());
   }
   if (SerialBT.available()) {
   Serial.write(SerialBT.read());
    }
    delay(20);
    }
  
*/


//Mejora Web

/*#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void handle_root();
// Configuración del Access Point (AP)
const char* ssid = "Nautilus";    // Nombre de la red WiFi creada por el ESP32
const char* password = "20000Leguas"; // Contraseña del AP (mínimo 8 caracteres)

WebServer server(80); // Servidor web en el puerto 80

// Página HTML que se mostrará en el navegador
String HTML = "<!DOCTYPE html>\
<html>\
<head><title>ESP32 AP</title></head>\
<body>\
<h1>Modo AP</h1>\
<p>Estás conectado al ESP32 en modo Access Point.</p>\
</body>\
</html>";

// Manejo de la raíz "/"
void handle_root() {
    server.send(200, "text/html", HTML);
}

void setup() {
    Serial.begin(115200);
    Serial.println("Iniciando Access Point...");

    // Configurar el ESP32 como Access Point (sin conexión a internet)
    WiFi.softAP(ssid, password);

    // Mostrar la dirección IP del AP
    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());

    // Configurar el servidor web
    server.on("/", handle_root);
    server.begin();
    Serial.println("Servidor web iniciado en modo AP.");
}

void loop() {
    server.handleClient(); // Manejar solicitudes de clientes
}*/


// Parte de Mejora 2 (Bluetooth)



/*#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// Definir UUIDs para el servicio y la característica
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando trabajo con BLE!");

  // Inicializar el dispositivo BLE con un nombre
  BLEDevice::init("MyESP32");

  // Crear el servidor BLE
  BLEServer *pServer = BLEDevice::createServer();

  // Crear el servicio BLE
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Crear la característica BLE con permisos de lectura y escritura
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  // Establecer un valor inicial para la característica
  pCharacteristic->setValue("Hola Mundo desde ESP32");
  
  // Iniciar el servicio
  pService->start();

  // Iniciar la publicidad para que otros dispositivos puedan encontrar el servidor
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // Funciones que ayudan con problemas de conexión en iPhone
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();

  Serial.println("¡Característica definida! Ahora puedes leerla en tu dispositivo.");
}

void loop() {
  // Código principal que se ejecuta repetidamente
  delay(2000);
}
*/

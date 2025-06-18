# Practica-8-PD



## **1 Bucle de comunicacion uart2**
**Codigo main.cpp:**
```
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 16, 17); // RX=16, TX=17
  Serial.println("Sistema iniciado. Escribe algo:");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial2.write(c);
    Serial.print(">> Enviado a UART2: ");
    Serial.println(c);
  }

  if (Serial2.available()) {
    char c = Serial2.read();
    Serial.write("<< Recibido de UART2: ");
    Serial.println(c);
  }

```
Este código permite al ESP32 actuar como un puente de comunicación entre el puerto serie principal (USB) y el puerto UART2 (hemos elegido los pines RX=16, TX=17).
En el setup(), inicia ambos puertos a 115200 baudios y muestra un mensaje de bienvenida.
En el loop(), si recibe datos desde el puerto USB (Serial), los reenvía al UART2 (Serial2) y los muestra en pantalla.
Si llegan datos desde UART2, los reenvía al puerto USB y también los imprime.


// Controlar entradas e saídas usando nodemcu e cayenne


//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

// WiFi network info.
char ssid[] = "SSID"; //Nome da rede Wifi
char wifiPassword[] = "PASSWORD"; //Senha da rede wifi

// Informações de autenticação do cayenne. Pode ser obtido no dashboard cayenne my devices.
char username[] = "username";
char password[] = "password";
char clientID[] = "clientID";

unsigned long lastMillis = 0;

void setup() {
  pinMode(4,OUTPUT);
  Serial.begin(115200);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
  Cayenne.loop();
}

// Função default para enviar informações de sensores ao cayenne.
// Os canais também podem ser específicados, ex: CAYENNE_OUT(1) para enviar ao channel 1.
//CAYENNE_OUT_DEFAULT()

  


// Função default para para processar comandos de atuadores no dashboard do cayenne.
// Os canais também podem ser específicados, ex: CAYENNE_IN(1) para enviar ao channel 1.
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  //Essa função lê o comando do dashboard ativando ou desativando a saída;
    int i = getValue.asInt();
    digitalWrite(4,i);
}


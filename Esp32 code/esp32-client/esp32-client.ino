#include <WiFi.h>
#include <WiFiClient.h>

const char* ssid = "brisa-3221534";
const char* password = "3mnkwxuu";
const char* serverIP = "192.168.1.10";  // Endereço IP do servidor Node.js
const int serverPort = 3000;  // Porta do servidor Node.js

WiFiClient client;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando à rede WiFi...");
  }
  Serial.println("Conectado à rede WiFi!");
Serial.println("Conectando ao servidor...");
  if (client.connect(serverIP, serverPort)) {
    Serial.println("Conectado ao servidor!");
  } else {
    Serial.println("Falha na conexão com o servidor.");
  }
 
}

void loop() {
    String dataToSend = "Estes são os dados enviados pelo ESP32.";
    long time1 = millis();
    client.print(dataToSend);
    //client.println();

    Serial.println("Dados enviados para o servidor.");
    long totalTime = 0;

   while (client.available()) {
        String response = client.readStringUntil('\n');
        Serial.println("Resposta do servidor: " + response);
      totalTime = millis() - time1;
      Serial.print("Tempo Total decorrido: "); 
      Serial.print(totalTime);     
      Serial.println("ms"); 
    }

      //client.stop(); // Encerrar a conexão
      //Serial.println("Conexão encerrada");
  delay(5000);
}
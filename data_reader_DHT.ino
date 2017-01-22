/* Programme de teste pour Adafruit sd breakout
 *  Dev by : Areour
 *  E-mail : openhardwaredz@gmail.com
 
 Le circuit:
 Cablage du lecteur SD au port du protocole SPI sur l'Arduino UNO :
 ** CS  ------> pin 10
 ** DI  ------> pin 11
 ** DO  ------> pin 12
 ** CLK ------> pin 13
 ** GND ------> GND
 ** 5V  ------> 5V

*/

#include <SD.h>
#include <SPI.h>

File myFile;                // instance de la classe File

void setup()
{
  Serial.begin(9600);        // ouverture de la liaison série
  Serial.print("Initialisation de la carte SD...");
  pinMode(10, OUTPUT);

  if (!SD.begin(10)) {
    Serial.println("Echec d'initialisation!");
    return;
  }

Serial.println("Initialisation OK");

myFile = SD.open("Data_DHT.csv");

if (myFile) {
  Serial.println("Data_DHT.csv:");

  while (myFile.available()) {
    Serial.write(myFile.read());
  }
  myFile.close();
  } 

  else {
    Serial.println("erreur a l'ouverture du fichier");
  }

}

void loop(){
}

/* Programme de teste pour Adafruit sd breakout
 *  Dev by : Areour
 *  E-mail : openhardwaredz@gmail.com
 
 le circuit:
 cablage du lecteur SD au port du protocole SPI sur l'Arduino UNO :
 ** CS  ------> pin 10
 ** DI  ------> pin 11
 ** DO  ------> pin 12
 ** CLK ------> pin 13
 ** GND ------> GND
 ** 5V  ------> 5V
 
 Cablage du du capteur DHT (11 ou 22)
 ** Sign -----> pin 2
 ** GND  -----> GND
 ** VCC  -----> 5V
 
 */

 #include <SD.h>
 #include <SPI.h>
 #include "DHT.h"

 #define DHTPIN 2           // le pin de connexion du capteur DHT11
 #define DHTTYPE DHT11

 unsigned long previousTime = 0;
 unsigned long cycle = 60000; 
 unsigned int i = 1;
 float h,t;
 
 File data_DHT;             // instance de la classe File

 DHT dht(DHTPIN, DHTTYPE);  // instance de la classe DHT

 void setup(){

  dht.begin();
  pinMode(10, OUTPUT);                             // Démarage du capteur
  SD.begin(10);                                    // démarage du lecteur 

  data_DHT = SD.open("Data_DHT.csv",FILE_WRITE);   // ouverture du fichier "Data_DHT.csv" en mode ecriture 
  data_DHT.println("N°,Humidité,Température");     // le titre des colonnes de données
  data_DHT.close();                                // firmeture du fichier 
 }

void loop(){

  float h,t;
  unsigned long currentTime = millis();            // l'utilisation de millis() évite l'utilisation de Delay()
  
  if(currentTime - previousTime > cycle){
    previousTime = currentTime;

    data_DHT = SD.open("Data_DHT.csv",FILE_WRITE); // ouverture du fichier 
  
    h = dht.readHumidity();
    t = dht.readTemperature();
    data_DHT.print(i);
    data_DHT.print(",");
    data_DHT.print(h);
    data_DHT.print(",");
    data_DHT.println(t);                          // la lecture des données fournie par le capteur puis leurs écriture dans le fichier 
    data_DHT.close();                             // fermeture du fichier 
    i++;
    }
}


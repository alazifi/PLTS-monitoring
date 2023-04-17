#define BLYNK_TEMPLATE_ID       "XXXXX"
#define BLYNK_DEVICE_NAME       "XXXXX"
#define BLYNK_FIRMWARE_VERSION  "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_WEMOS_D1_MINI

#include "Nextion.h"
#include "BlynkEdgent.h"
#include <PZEM004Tv30.h>
#include <PZEM017v1.h>
#define RX_PZEMDC1  D7
#define TX_PZEMDC1  D2
#define RX_PZEMDC2  D3
#define TX_PZEMDC2  D4
#define RX_PZEMAC1  D5
#define TX_PZEMAC1  D6

unsigned long previousMillis = 0;
unsigned long interval = 2000;

PZEM004Tv30 pzemac1(RX_PZEMAC1, TX_PZEMAC1);
PZEM017v1 pzemdc1(RX_PZEMDC1, TX_PZEMDC1);
PZEM017v1 pzemdc2(RX_PZEMDC2, TX_PZEMDC2);

float voltageac1()  {return pzemac1.voltage();  }
float currentac1()  {return pzemac1.current();  }
float powerac1()    {return pzemac1.power();    }
float energyac1()   {return pzemac1.energy();   }
float frequencyac1(){return pzemac1.frequency();}
float pfac1()       {return pzemac1.pf();       }
float voltagedc1()  {return pzemdc1.voltage();  }
float currentdc1()  {return pzemdc1.current();  }
float powerdc1()    {return pzemdc1.power();    }
float energydc1()   {return pzemdc1.energy();   }
float voltagedc2()  {return pzemdc2.voltage();  }
float currentdc2()  {return pzemdc2.current();  }
float powerdc2()    {return pzemdc2.power();    }
float energydc2()   {return pzemdc2.energy();   }

NexText tvac1 = NexText(0, 2, "tvac1");
NexText tcac1 = NexText(0, 3, "tcac1");
NexText tpac1 = NexText(0, 4, "tpac1");
NexText teac1 = NexText(0, 5, "teac1");
NexText tpfcac1 = NexText(0, 6, "tpfcac1");
NexText tfac1 = NexText(0, 7, "tfac1");
NexText tvdc1 = NexText(0, 8, "tvdc1");
NexText tcdc1 = NexText(0, 9, "tcdc1");
NexText tpdc1 = NexText(0, 10, "tpdc1");
NexText tedc1 = NexText(0, 11, "tedc1");
NexText tvdc2 = NexText(0, 12, "tvdc2");
NexText tcdc2 = NexText(0, 13, "tcdc2");
NexText tpdc2 = NexText(0, 14, "tpdc2");
NexText tedc2 = NexText(0, 15, "tedc2");

void printBlynk(){
  Blynk.virtualWrite(V0, voltageac1());
  Blynk.virtualWrite(V1, currentac1());
  Blynk.virtualWrite(V2, powerac1());
  Blynk.virtualWrite(V3, energyac1());
  Blynk.virtualWrite(V4, pfac1());
  Blynk.virtualWrite(V5, frequencyac1());
  
  Blynk.virtualWrite(V6, voltagedc1());
  Blynk.virtualWrite(V7, currentdc1());
  Blynk.virtualWrite(V8, powerdc1());
  Blynk.virtualWrite(V9, energydc1());
  
  Blynk.virtualWrite(V10, voltagedc2());
  Blynk.virtualWrite(V11, currentdc2());
  Blynk.virtualWrite(V12, powerdc2());
  Blynk.virtualWrite(V13, energydc2());
}
void printMonitor(){
  Serial.print("Voltage 1: ");        Serial.print(voltagedc1());   Serial.println(" V");
  Serial.print("Current 1: ");        Serial.print(currentdc1(),4); Serial.println(" A");
  Serial.print("Power 1: ");          Serial.print(powerdc1());     Serial.println(" W");
  Serial.print("Energy 1: ");         Serial.print(energydc1(),3);  Serial.println(" kWh");

  Serial.print("Voltage 2: ");        Serial.print(voltagedc2());   Serial.println(" V");
  Serial.print("Current 2: ");        Serial.print(currentdc2(),4); Serial.println(" A");
  Serial.print("Power 2: ");          Serial.print(powerdc2());     Serial.println(" W");
  Serial.print("Energy 2: ");         Serial.print(energydc2(),3);  Serial.println(" kWh");  

  Serial.print("Voltage AC: ");       Serial.print(voltageac1());   Serial.println(" V");
  Serial.print("Current AC: ");       Serial.print(currentac1(),4); Serial.println(" A");
  Serial.print("Power AC: ");         Serial.print(powerac1());     Serial.println(" W");
  Serial.print("Energy AC: ");        Serial.print(energyac1(),3);  Serial.println(" kWh");  
  Serial.print("Frekuensi AC: ");     Serial.print(frequencyac1()); Serial.println(" Hz");
  Serial.print("Power Factor AC: ");  Serial.println(pfac1());      Serial.println("------");
  }

void printNextion(){
  
  static char vac3[10];
  dtostrf(voltageac1(), 6, 1, vac3);
  tvac1.setText(vac3);

  static char cac1[6];
  dtostrf(currentac1(), 6, 3, cac1);
  tcac1.setText(cac1);

  static char vac1[10];
  dtostrf(voltageac1(), 6, 1, vac1);
  tvac1.setText(vac1);
  
  static char pac1[6];
  dtostrf(powerac1(), 6, 1, pac1);
  tpac1.setText(pac1);
  
  static char eac1[6];
  dtostrf(energyac1(), 6, 3, eac1);
  teac1.setText(eac1);  
  
  static char pfcac1[6];
  dtostrf(pfac1(), 6, 2, pfcac1);
  tpfcac1.setText(pfcac1); 
  
  static char fac1[6];
  dtostrf(frequencyac1(), 6, 1, fac1);
  tfac1.setText(fac1);
  
  static char vdc1[6];
  dtostrf(voltagedc1(), 6, 2, vdc1);
  tvdc1.setText(vdc1);

  static char cdc1[6];
  dtostrf(currentdc1(), 6, 2, cdc1);
  tcdc1.setText(cdc1);

  static char pdc1[6];
  dtostrf(powerdc1(), 6, 1, pdc1);
  tpdc1.setText(pdc1);

  static char edc1[6];
  dtostrf(energydc1(), 6, 3, edc1);
  tedc1.setText(edc1);

  static char vdc2[6];
  dtostrf(voltagedc2(), 6, 2, vdc2);
  tvdc2.setText(vdc2);

  static char cdc2[6];
  dtostrf(currentdc2(), 6, 2, cdc2);  
  tcdc2.setText(cdc2);  
  
  static char pdc2[6];
  dtostrf(powerdc2(), 6, 1, pdc2);  
  tpdc2.setText(pdc2);  

  static char edc2[6];
  dtostrf(energydc2(), 6, 3, edc2);  
  tedc2.setText(edc2);  
  }

void setup(void)
{
  Serial.begin(9600);
  BlynkEdgent.begin();

  nexInit();
}

void loop(void) {
  BlynkEdgent.run();
    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    printBlynk();
  }
  printNextion();
  printMonitor();  
}

// Define entradas digitais
const int pedestrian_button = 5; // botão para permitir a travessia de pedestres

// Define saídas digitais
const int traffic_red_light = 10; // luz vermelha de trânsito
const int tom_329_Hz        = 9;  // tom 329 Herz
const int traffic_yellow_light = 11; // luz amarela de trânsito
const int traffic_green_light = 12; // luz verde de trânsito
const int pedestrian_red_light = 6; // luz vermelha de pedestres
const int pedestrian_green_light = 7; // luz verde de pedestres

void setup() {

  Serial.begin(9600);
  // Inicializar saídas digitais
  pinMode(traffic_red_light, OUTPUT);
  pinMode(traffic_yellow_light, OUTPUT);
  pinMode(traffic_green_light, OUTPUT);
  pinMode(pedestrian_red_light, OUTPUT);
  pinMode(pedestrian_green_light, OUTPUT);
  
  // Inicializar entrada digital
  pinMode(pedestrian_button, INPUT_PULLUP); // usando resistor de pull-up interno
  
  Serial.println("Acende led vermelho trafego, delay 3 segundos ");
  digitalWrite(traffic_red_light, HIGH);

  delay(3000);

  Serial.println("Acende led amarelo trafego, delay 3 segundos ");
  digitalWrite(traffic_yellow_light, HIGH);

  delay(3000);

  Serial.println("Acende led verde trafego, delay 3 segundos ");
  digitalWrite(traffic_green_light, HIGH); // luz verde de trânsito

  delay(3000);

  Serial.println("Acende led vermelho pedestre, delay 3 segundos ");
  digitalWrite(pedestrian_red_light, HIGH); // luz vermelha de pedestre

  delay(3000);

  Serial.println("Acende led verde pedestre, delay 3 segundos ");
  digitalWrite(pedestrian_green_light, HIGH); // luz verde de pedestres

  delay(3000);
  
  Serial.println("Tom 329 Herz por 1/2 segundo ");
  tone(tom_329_Hz,329,500);



}

void loop() {
   
   if (digitalRead(pedestrian_button)  == LOW) 

  // LUZ VERDE (SEMAFARO CARROS)
    {
        
    Serial.println("Apaga todas os leds ");

    digitalWrite(traffic_red_light, LOW);
    digitalWrite(traffic_yellow_light, LOW);
    digitalWrite(traffic_green_light, LOW); // luz verde de trânsito
    digitalWrite(pedestrian_red_light, LOW); // luz vermelha de pedestres
    digitalWrite(pedestrian_green_light, LOW); // luz verde de pedestres

    delay(10);

    }

}



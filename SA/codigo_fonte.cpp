// Define entradas digitais
const int pedestrian_button = 5; // botão para permitir a travessia de pedestres

// Define saídas digitais
const int traffic_red_light = 10; // luz vermelha de trânsito
const int tom_329_Hz        = 9;
const int traffic_yellow_light = 11; // luz amarela de trânsito
const int traffic_green_light = 12; // luz verde de trânsito
const int pedestrian_red_light = 6; // luz vermelha de pedestres
const int pedestrian_green_light = 7; // luz verde de pedestres
unsigned long timeGreenLightInit = 0;
unsigned long deltaTimeGreenLight  = 0;


bool greenLightOn=true;
bool redLightNormalTiming    = true;
// bool pedestrian_buttonPressed = false;

void setup() {
  // Inicializar saídas digitais
  pinMode(traffic_red_light, OUTPUT);
  pinMode(traffic_yellow_light, OUTPUT);
  pinMode(traffic_green_light, OUTPUT);
  pinMode(pedestrian_red_light, OUTPUT);
  pinMode(pedestrian_green_light, OUTPUT);
  
  // Inicializar entrada digital
  pinMode(pedestrian_button, INPUT_PULLUP); // usando resistor de pull-up interno

  Serial.begin(9600);

}

void loop() {

    Serial.println("Inicio Luz Vermelha ");
    Serial.println("redLightNormalTiming: ");
    Serial.println(redLightNormalTiming );


  // Condição inicial LUZ VERMELHA (SEMAFORO CARROS)
  digitalWrite(traffic_red_light, HIGH); // luz vermelha de trânsito
  digitalWrite(traffic_yellow_light, LOW); // luz amarela de trânsito
  digitalWrite(traffic_green_light, LOW); // luz verde de trânsito
  digitalWrite(pedestrian_red_light, LOW); // luz vermelha de pedestres
  digitalWrite(pedestrian_green_light, HIGH); // luz verde de pedestres
  if(redLightNormalTiming)
  {
    Serial.println("Delay luz vermelha 80 segundos ");
    delay(80000); // 80 segundos

  }
  else{
        Serial.println("Delay luz vermelha 20 segundos ");
        delay(20000); // 20 segundos
        redLightNormalTiming = true;  // reseto a flag

  }
  
  // Ativar sinal sonoro para pedestres
  // 10 segundos total
  for (int i = 0; i < 4; i++) {
    tone(tom_329_Hz,329,1000);
    delay(1500);
  }
  
  // LUZ VERDE (SEMAFARO CARROS)
  timeGreenLightInit = millis();
  digitalWrite(traffic_red_light, LOW);
  digitalWrite(traffic_yellow_light, LOW);
  digitalWrite(traffic_green_light, HIGH); // luz verde de trânsito
  digitalWrite(pedestrian_red_light, HIGH); // luz vermelha de pedestres
  digitalWrite(pedestrian_green_light, LOW); // luz verde de pedestres
  greenLightOn = true;
  while(greenLightOn)
  {

    delay(1000); // 1 segundo 
    deltaTimeGreenLight = millis() - timeGreenLightInit;

    Serial.println(deltaTimeGreenLight);

    //if (digitalRead(pedestrian_button) == LOW && !pedestrian_buttonPressed) 
    if (digitalRead(pedestrian_button) == LOW ) 

        {
        // reduz tempo de espera para 10 segundos para o pedestre, 
        // caso contrario espera terminar o tempo normal
        // pedestrian_buttonPressed = true;
        if(deltaTimeGreenLight < 70000) 
            {
                Serial.println("Botao pedestre pressionado no inicio do verde de carros, 10 segundos para virar vermelho ");

                // aguarda 10 segundos
                delay(10100);
                // se pedestre apertou o botão logo que o sinal
                // ficou verde, o tempo de red será reduzido para 30 segundos;
              redLightNormalTiming = false;
          		greenLightOn = false;
            }
        }
    if(deltaTimeGreenLight >80000)
        {
            Serial.println("Botao pedestre pressionado no fim do sinal verde ou botao nao pressionado");
            greenLightOn = false;
        }  
  }

  // reseta flag de botao de pedestre;
  // pedestrian_buttonPressed = false; 
  // LUZ AMARELA (SEMAFARO CARROS)
  digitalWrite(traffic_green_light, LOW);
  digitalWrite(traffic_yellow_light, HIGH); // luz amarela de trânsito
  delay(6000); // 6 segundos
  
  delay(10);
}



/* 
 * Brewery Control
 * Boil Kettle / Hot Liquor Tank Power Control
 * 
 * This is a coarse PWM with a very low frequency to control a camco 5500W 240V 30A
 * heating element.
*/

/* Constants */
int POT_PIN = 2; // select the input pin for the potentiometer
int SSR_PIN = 13; // select the pin for SSR - also the inbuilt LED
int CYCLE_LENGTH = 2000; // How many miliseconds is the full duty cycle
int CYCLE_RESOLUTION = 100; // Check the potentiometer every 50ms to see if we need to adjust the duty cycle
int POT_MAX = 1023; // Max reading from the pot
int POT_MIN = 0; // Min reading from the pot

/* Variables */
int pot_val = 0; // variable to store the value coming from the sensor
int last_pot_val = 0; // variable to store the last value coming from the sensor
int cycle_time_left = 0;
int time_to_stay_on = 0;
int time_to_switch_state = 0;
float percent_time_on = 0.0;

void setup() {
  pinMode(SSR_PIN, OUTPUT);
  Serial.begin(115200);
  // Element should start in an off state
  digitalWrite(SSR_PIN, LOW);
}

void loop() {
  // read the value from the pot
  pot_val = analogRead(POT_PIN);

  // If we complete a duty cycle or the potentiometer changes, we start another cycle
  if ((cycle_time_left <= 0) || 
      ((pot_val != last_pot_val) && ((pot_val+1 < last_pot_val) || (pot_val-1 > last_pot_val)) )) {
    Serial.print("New cycle: time_left: ");
    Serial.println(cycle_time_left);
    Serial.print("pot_val: ");
    Serial.println(pot_val);
    last_pot_val = pot_val;
    
    percent_time_on = float(pot_val)/float(POT_MAX);    
    time_to_stay_on = int(percent_time_on * float(CYCLE_LENGTH));
    time_to_switch_state = CYCLE_LENGTH - time_to_stay_on;
    cycle_time_left = CYCLE_LENGTH;
    
    // Ignite coil!
    if (pot_val > POT_MIN) {
      digitalWrite(SSR_PIN, HIGH);    
    }
  } else {
    if ((cycle_time_left <= time_to_switch_state) && (pot_val < POT_MAX)) {
      // Extinguish coil
      digitalWrite(SSR_PIN, LOW);
    }
    cycle_time_left -= CYCLE_RESOLUTION;
  }
  delay(CYCLE_RESOLUTION);
}

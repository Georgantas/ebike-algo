
// pins
const int THROTTLE_INPUT_PIN = 5;
const int TORQUE_INPUT_PIN = 4;
const int MOTOR_PIN = 3;

// constants
const int MINIMUM_THROTTLE_VAL = 1 * 1023 / 5;
const int MAXIMUM_THROTTLE_VAL = 4 * 1023 / 5;

// reused vals
int throttle_val = 0;
int torque_val = 0;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // read the throttle value
  throttle_val =  analogRead(THROTTLE_INPUT_PIN);

  // calibrate the throttle value
  if(throttle_val <= MINIMUM_THROTTLE_VAL){
    throttle_val = 0;
  } else if(throttle_val >= MAXIMUM_THROTTLE_VAL) {
    throttle_val = 1023;
  }

  // read the torque value
  torque_val = analogRead(TORQUE_INPUT_PIN);

  // determine output
  analogWrite(MOTOR_PIN, torque_val > throttle_val ? torque_val / 4 : throttle_val / 4);
  
}

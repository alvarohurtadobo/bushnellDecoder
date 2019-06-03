

/* Arduino Radar Gun
   Data Read Test Code - Arduino Leonardo
   http://www.kevindarrah.com/wiki/index.php?title=Arduino_Radar_Gun
*/


int segment[4][7];//LCD segment data stored here

int measuredSpeed, oldSpeed;//converted data to speed


void setup() {
  Serial.begin(115200);//for debugging

}//setup



void loop() {
  delay(250);// update rate
  //Serial.println("Looping");


  unsigned long scanTimeStart = millis();//timeout for scanning LCD

  while (millis() - scanTimeStart < 100) {//jump in and scan the LCD!
    for (int i = 7; i < 11; i++) { //sweep the common pins
      if (analogRead(i) > 600) {// LOW
        for (int j = 0; j < 7; j++) {//sweep the segments after we find an enabled common
          if (analogRead(j) < 10) {//HIGH
            segment[i - 7][j] = 1;//set the segment to a 1
          }
        }
      }
    }
  }
  /*
  for (int k = 0; k <11; k++){
    Serial.print(analogRead(k));
    Serial.print(" ");
  }
  Serial.println(" ");
  */

  measuredSpeed = 0;//clear the speed, and we'll set it now based on the segment data

  /*
   *  ONES POSITION
   */

  //     3,5
  // 3,4     2,5
  //     2,4
  // 1,4     1,5
  //     0,5

  //Zero - Ones
  if (segment[3][4] == 1 && segment[3][5] == 1 && segment[2][5] == 1 && segment[2][4] == 0 && segment[1][4] == 1 && segment[1][5] == 1 && segment[0][5] == 1) {
    measuredSpeed = 0;
  }
  //One - Ones
  if (segment[3][4] == 0 && segment[3][5] == 0 && segment[2][5] == 1 && segment[2][4] == 0 && segment[1][4] == 0 && segment[1][5] == 1 && segment[0][5] == 0) {
    measuredSpeed = 1;
  }
  //Two - Ones
  if (segment[3][4] == 0 && segment[3][5] == 1 && segment[2][5] == 1 && segment[2][4] == 1 && segment[1][4] == 1 && segment[1][5] == 0 && segment[0][5] == 1) {
    measuredSpeed = 2;
  }
  //Three - Ones
  if (segment[3][4] == 0 && segment[3][5] == 1 && segment[2][5] == 1 && segment[2][4] == 1 && segment[1][4] == 0 && segment[1][5] == 1 && segment[0][5] == 1) {
    measuredSpeed = 3;
  }
  //Four - Ones
  if (segment[3][4] == 1 && segment[3][5] == 0 && segment[2][5] == 1 && segment[2][4] == 1 && segment[1][4] == 0 && segment[1][5] == 1 && segment[0][5] == 0) {
    measuredSpeed = 4;
  }
  //Five - Ones
  if (segment[3][4] == 1 && segment[3][5] == 1 && segment[2][5] == 0 && segment[2][4] == 1 && segment[1][4] == 0 && segment[1][5] == 1 && segment[0][5] == 1) {
    measuredSpeed = 5;
  }
  //Six - Ones
  if (segment[3][4] == 1 && segment[3][5] == 1 && segment[2][5] == 0 && segment[2][4] == 1 && segment[1][4] == 1 && segment[1][5] == 1 && segment[0][5] == 1) {
    measuredSpeed = 6;
  }
  //Seven - Ones
  if (segment[3][4] == 0 && segment[3][5] == 1 && segment[2][5] == 1 && segment[2][4] == 0 && segment[1][4] == 0 && segment[1][5] == 1 && segment[0][5] == 0) {
    measuredSpeed = 7;
  }
  //Eight - Ones
  if (segment[3][4] == 1 && segment[3][5] == 1 && segment[2][5] == 1 && segment[2][4] == 1 && segment[1][4] == 1 && segment[1][5] == 1 && segment[0][5] == 1) {
    measuredSpeed = 8;
  }
  //Nine - Ones
  if (segment[3][4] == 1 && segment[3][5] == 1 && segment[2][5] == 1 && segment[2][4] == 1 && segment[1][4] == 0 && segment[1][5] == 1 && segment[0][5] == 1) {
    measuredSpeed = 9;
  }


/*
 * TENS POSITION
 */
  //     3,3
  // 3,2     2,3
  //     2,2
  // 1,2     1,3
  //     0,3

  //One - Tens
  if (segment[3][2] == 0 && segment[2][2] == 0 && segment[2][3] == 1 && segment[3][3] == 0 && segment[1][2] == 0 && segment[1][3] == 1 && segment[0][3] == 0) {
    measuredSpeed = measuredSpeed + (1 * 10);
  }
  //Two - Tens
  if (segment[3][2] == 0 && segment[2][2] == 1 && segment[2][3] == 1 && segment[3][3] == 1 && segment[1][2] == 1 && segment[1][3] == 0 && segment[0][3] == 1) {
    measuredSpeed = measuredSpeed + (2 * 10);
  }
  //Three - Tens
  if (segment[3][2] == 0 && segment[2][2] == 1 && segment[2][3] == 1 && segment[3][3] == 1 && segment[1][2] == 0 && segment[1][3] == 1 && segment[0][3] == 1) {
    measuredSpeed = measuredSpeed + (3 * 10);
  }
  //Four - Tens
  if (segment[3][2] == 1 && segment[2][2] == 1 && segment[2][3] == 1 && segment[3][3] == 0 && segment[1][2] == 0 && segment[1][3] == 1 && segment[0][3] == 0) {
    measuredSpeed = measuredSpeed + (4 * 10);
  }
  //Five - Tens
  if (segment[3][2] == 1 && segment[2][2] == 1 && segment[2][3] == 0 && segment[3][3] == 1 && segment[1][2] == 0 && segment[1][3] == 1 && segment[0][3] == 1) {
    measuredSpeed = measuredSpeed + (5 * 10);
  }
  //Six - Tens
  if (segment[3][2] == 1 && segment[2][2] == 1 && segment[2][3] == 0 && segment[3][3] == 1 && segment[1][2] == 1 && segment[1][3] == 1 && segment[0][3] == 1) {
    measuredSpeed = measuredSpeed + (6 * 10);
  }
  //Seven - Tens
  if (segment[3][2] == 0 && segment[2][2] == 0 && segment[2][3] == 1 && segment[3][3] == 1 && segment[1][2] == 0 && segment[1][3] == 1 && segment[0][3] == 0) {
    measuredSpeed = measuredSpeed + (7 * 10);
  }
  //Eight - Tens
  if (segment[3][2] == 1 && segment[2][2] == 1 && segment[2][3] == 1 && segment[3][3] == 1 && segment[1][2] == 1 && segment[1][3] == 1 && segment[0][3] == 1) {
    measuredSpeed = measuredSpeed + (8 * 10);
  }
  //Nine - Tens
  if (segment[3][2] == 1 && segment[2][2] == 1 && segment[2][3] == 1 && segment[3][3] == 1 && segment[1][2] == 0 && segment[1][3] == 1 && segment[0][3] == 1) {
    measuredSpeed = measuredSpeed + (9 * 10);
  }

/*
 * HUNDREDS
 */
  //     3,1
  // 3,0     2,1
  //     2,0
  // 1,0     1,1
  //     0,1
  //One - Hundreds
  if (segment[3][1] == 0 && segment[3][0] == 0 && segment[2][1] == 1 && segment[2][0] == 0 && segment[1][0] == 0 && segment[1][1] == 1 && segment[0][1] == 0) {
    measuredSpeed = measuredSpeed + (1 * 100);
  }
  if (segment[3][1] == 1 && segment[3][0] == 0 && segment[2][1] == 1 && segment[2][0] == 1 && segment[1][0] == 1 && segment[1][1] == 0 && segment[0][1] == 1) {
    measuredSpeed = measuredSpeed + (2 * 100);
  }



  if (oldSpeed != measuredSpeed) {//ony print speed if it's new
    Serial.print("Speed ");
    Serial.print(measuredSpeed);
    Serial.println(" mph");
    
  }
  Serial.println("Measurement: ");
  for (int i = 0; i < 4; i++) {//for degugging and clearing segment data
    Serial.print(i);
    Serial.print(": ");
    for (int j = 0; j < 7; j++) {
      Serial.print(segment[i][j]);
      Serial.print(",");
    }
    Serial.println("  ");
  }
  oldSpeed = measuredSpeed;

  for (int i = 0; i < 4; i++) {//for degugging and clearing segment data
    //Serial.print(i);
    //Serial.print(": ");
    for (int j = 0; j < 7; j++) {
      //Serial.print(segment[i][j]);
      //Serial.print(",");
      segment[i][j] = 0;
    }
    //Serial.println("  ");
  }


}

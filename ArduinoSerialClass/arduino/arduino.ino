uint8_t startSignature[3]={255,53,128};


void setup() {
  Serial.begin(9600);

}

void loop() {
  static unsigned int test=0;

  test++;
  byte data[2];

  data[1]=test&0x00ff;
  data[0]=(test>>8)&0x00ff;

  for(int i=0; i<3; i++)Serial.write(startSignature[i]);
  for(int i=0; i<2; i++)Serial.write(data[i]);
  delay(500);

}

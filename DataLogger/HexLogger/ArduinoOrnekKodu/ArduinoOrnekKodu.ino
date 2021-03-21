// | Başlangıç işareti | kanal sayısı | zaman | data büyüklüğü | data |

const uint8_t startSignature[3]={255,0,127};
const uint8_t channelSize=10;
const uint8_t dataSize=2;
uint32_t timeStep=0;

int datas[10]={0};

void setup() {
  Serial.begin(9600);

}

uint8_t sinus=0;
void loop() {

  timeStep+=1;
  
  delay(100);
  send_datas();

  sinus++;
  if(sinus==180)sinus=0;
  
  datas[0]=sin(sinus)*25;
  datas[1]=0;
  datas[2]=0;
  datas[3]=0;
  datas[4]=0;
  datas[5]=0;
  datas[6]=0;
  datas[7]=0;
  datas[8]=0;
  datas[9]=0;
}

void send_datas(){
  for(int i=0; i<3; i++)Serial.write(startSignature[i]);
  Serial.write(channelSize);

  Serial.write((timeStep>>24)&0x000000ff);
  Serial.write((timeStep>>16)&0x000000ff);
  Serial.write((timeStep>>8)&0x000000ff);
  Serial.write(timeStep&0x000000ff);

  Serial.write(dataSize);
  for(int i=0; i<channelSize; i++){
    for(int k=1; k>=0; k--){
      uint8_t tempData=(datas[i]>>(8*k))&0x00ff;
      Serial.write(tempData);
    }
  }

}

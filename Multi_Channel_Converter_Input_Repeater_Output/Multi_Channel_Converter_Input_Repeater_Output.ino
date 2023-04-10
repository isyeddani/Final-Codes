#define debug

#define MOSI 11
#define SCK 13
#include <SPI.h>

int Pin = 2;
float clock_speed = F_CPU_ACTUAL;
const int array_size = 3000;
float buffer1[array_size];
float buffer_isr[array_size];
int logic_holder[array_size];
int write_index = 0;
int read_index = 0;
uint32_t current_val = 0;
uint32_t previous_val = 0;
uint32_t cycle_time1 = 0;
uint32_t cycle_time2 = 0;
float Data_check[2500];
int x = 0;
volatile boolean Seconds_round_flag = true;
uint32_t exit_flag = 0;
volatile boolean flag = true;
volatile boolean wrong_flag = false;

int led_counter = 0;
int p = 0;
int loop_w = 0;
int sum_times1 = 0;
int sum_times2 = 0;
int sum = 0;
int sum_check = 0;
int temp_first_half[2500];
int tfh_index = 0;
int index_thirty[512];
int Brightness[3];
int z = 0;
uint32_t int_var;
volatile boolean int_flag = false;
volatile boolean int_flag_1 = true;

int RED[512];
int GREEN[512];
int BLUE[512];

struct thirty
{
  int data_array[10];
  int logic_array[10];
};

struct logic_thirty
{
  int logic_array[30];
};

struct RGB_array
{
  unsigned char R[8];
  unsigned char G[8];
  unsigned char B[8];
};

int SPI_RED[512];
int SPI_GREEN[512];
int SPI_BLUE[512];

uint16_t header48bit[6] = {0xFF, 0x00, 0xFC, 0x3F, 0x00, 0x3F};


void setup()
{
  ////////////////////////////////////// INTERRUPT SETUP ///////////////////////////////////
  ARM_DEMCR |= ARM_DEMCR_TRCENA;
  ARM_DWT_CTRL |= ARM_DWT_CTRL_CYCCNTENA; // Clock Cycle Setup & Register Deffination
  attachInterrupt(digitalPinToInterrupt(Pin), pulseReceived, CHANGE);   // Interrrupt call on every change in pulse on PIN-4


  /////////////////////////////////////// SPI SETUP ////////////////////////////////////////
  pinMode(MOSI, OUTPUT);    // set the MOSI pin as an output
  pinMode(SCK, OUTPUT);   // set the CLK pin as an output
  SPI.begin();    // initialize the SPI library
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));    //SPI setting 1Mhz MSB first and SPI_MODE1 clock low on idle.
  delay(50);    // unnecessary delay :(

}

void pulseReceived()    // Interrupt Service Routine
{
  if (flag == true)  // flag for interrupt enable
  {
    current_val = ARM_DWT_CYCCNT;   //store teensy4.1 clock cycle
    int_var = current_val - previous_val;   //get the clock cycle differnece between two interrupts
    if (((int_var > 24000) && (int_var < 25000)) || (int_flag == true))   //if clock cycle is between 24k and 25k then throught and int_flag will help through after
    {
      int_flag = true;    //int_flag get through after first data recieved
      if (previous_val != 0 && write_index < 3000)    // previous cycle will >0 after first interrupt, read data until 3000 counts
      {
        buffer_isr[write_index] = current_val - previous_val;   // store value in array
        logic_holder[write_index] = digitalRead(2);   //store digital value in array
        write_index += 1;   //increase the count
      }
    }
    previous_val = current_val ;
  }
}
void loop()
{
  if ((int_flag == true) && (flag == true)) // thorugh if recieve first 24k cycle
  {
    exit_flag = ARM_DWT_CYCCNT - previous_val;    // Continously calculates the cycles passed since previous interrupt
    if (exit_flag > 30000 && exit_flag < 35000)  // True if cycle passed since previous interrupt is greater than 50k
    {
      flag = false;   //flag(false) will skip interrupt
      int_flag = false;
      //      Serial.println(write_index);
      if ((flag == false) && (int_flag == false))
      {
        if (led_counter == 5)
        {
          digitalWrite(3, HIGH);
          led_counter = 0;
        }
        led_counter += 1;
        noInterrupts();
        struct RGB_array access_RGB_array[512];
        struct logic_thirty access_logic_thirty[512];
        struct thirty access_thirty[512];

        ////////////////////////////////////////////////////// Printing Sorted Data started from 41usec  /////////////////////////////////////
        read_index = 0;
        while ((read_index < write_index) && (flag == false))
        {
          buffer1[read_index] = (buffer_isr[read_index] * 1 / (clock_speed) * 1e9);
          buffer_isr[read_index] = 0;
          logic_holder[read_index] = logic_holder[(read_index) + 1];
          read_index += 1;
        }
        loop_w = 0;
        sum_times1 = 0;
        sum_times2 = 0;
        Seconds_round_flag = true;
        int j = 0;
        int k = 0;

        //////////////////////////////////////////////////////       Seperating RGB from Sorted Data    ///////////////////////////////////////

        if ((buffer1[0] > 40750) && (buffer1[0] < 41250) && (logic_holder[0] == 0))
        {
          if ((buffer1[1] > 4250) && (buffer1[1] < 4750) && (logic_holder[1] == 1))
          {
            int i = 2;
            j = 0;
            while (loop_w < 512)
            {
              sum = 0;
              sum_check = 0;
              j = 0;
              k = 0;
              while (((sum_check == 0) && (sum_times1 < 256)))
              {
                sum = buffer1[i] + sum;
                access_thirty[loop_w].data_array[j] = buffer1[i];
                access_thirty[loop_w].logic_array[j] = logic_holder[i];
                index_thirty[loop_w] = k;
                j += 1;
                k += 1;
                if (sum_times1 < 255)
                {
                  if ((sum > 29250) && (sum < 31250))
                  {
                    sum_times1 += 1;
                    sum_check = 1;
                  }
                }
                if (sum_times1 == 255)
                {
                  if ((sum > 35250) && (sum < 37750))
                  {
                    sum_times1 += 1;
                    sum_check = 1;
                  }
                }
                i++;
              }
              if ((sum_times1 >= 256) && (loop_w > 255))
              {

                if (((buffer1[i] > 16750) && (buffer1[i + 1] > 750) && (buffer1[i + 1] < 1250) && (buffer1[i + 2] > 22750) && (buffer1[i + 2] < 23250) && (buffer1[i + 3] > 4250) && (buffer1[i + 3] < 4750))  || (sum_times1 >= 256) )
                {
                  if (((logic_holder[i] == 0) && (logic_holder[i + 1] == 1) && (logic_holder[i + 2] == 0) && (logic_holder[i + 3] == 1)) || (sum_times1 >= 256))
                  {
                    if (Seconds_round_flag == true)
                    {
                      i = i + 4;
                      Seconds_round_flag = false;
                    }
                    sum = 0;
                    sum_check = 0;
                    j = 0;
                    while (((sum_check == 0) && (sum_times2 < 256)))
                    {
                      sum = buffer1[i] + sum;
                      j += 1;
                      k += 1;

                      if ((sum_times2 < 255))
                      {
                        if ((sum > 29250) && (sum < 31250))
                        {
                          sum_times2 += 1;
                          sum_check = 1;
                        }
                      }
                      if ((sum_times2 == 255))
                      {
                        if ((sum > 35250) && (sum < 37750))
                        {
                          sum_times2 += 1;
                          sum_check = 1;
                        }
                      }
                      i++;
                    }
                  }
                  else
                  {
                    wrong_flag = true;
                    Serial.println("wrong_flag1");
                    digitalWrite(4, HIGH);
                  }
                }
                else
                {
                  wrong_flag = true;
                  Serial.println("wrong_flag2");
                  digitalWrite(4, HIGH);
                }

              }
              loop_w += 1;
            }
            if (loop_w >= 512)
            {
              sum = 0;
              int Brightness_array = 0;
              while (sum <= 41000)
              {
                sum = sum + buffer1[i];
                sum = round(sum);
                z = round( (buffer1[i]) / 1000.0);
                for (int j = 0; j < z ; j++)
                {
                  if (Brightness_array == 17)
                  {
                    Brightness[0] = logic_holder[i];
                  }
                  if (Brightness_array == 18)
                  {
                    Brightness[1] = logic_holder[i];
                  }
                  if (Brightness_array == 19)
                  {
                    Brightness[2] = logic_holder[i];
                  }
                  Brightness_array = Brightness_array + 1;
                }
                i = i + 1;
              }
            }
            loop_w = 0;
            sum_times1 = 0;
            sum_times2 = 0;
            Seconds_round_flag = true;
          }
          else
          {
            wrong_flag = true;
            Serial.println("wrong_flag4");
            digitalWrite(4, HIGH);
          }
        }
        else
        {
          wrong_flag = true;
          Serial.println("wrong_flag5");
          digitalWrite(4, HIGH);
        }
        z = 0;
        if (wrong_flag == false)
        {
          ////////////////////////////  Brightness Print and Conversion Decimal 0-7 //////////////////////////////

          Serial.println();
          Serial.println();
          Serial.println("Brightness");
          Serial.print(Brightness[0]);
          Serial.print(Brightness[1]);
          Serial.println(Brightness[2]);
          String s = String(Brightness[2]);
          String t = String(Brightness[1]);
          String u = String(Brightness[0]);
          String v = s + t + u;
          int n = v.length();
          char input_binary_string[n + 1];
          strcpy(input_binary_string, v.c_str());
          long Brightness_value_dec = strtol(input_binary_string, NULL, 2);
          Serial.print("Brightness in Decimal : ");
          Serial.println(Brightness_value_dec);
          Serial.println();


          /////////////////////////////////////////////////   Converting Microseconds into Logic 0-1 For RGB /////////////////////////////////////////

          int temp_holder_r = 0;
          int temp_holder_g = 0;
          int temp_holder_b = 0;

          for (int i = 0; i < 256; i++)
          {
            temp_holder_r = 0;
            temp_holder_g = 0;
            temp_holder_b = 0;
            int l = 0;
            for (int j = 0; j <= index_thirty[i] ; j++)
            {
              z = round((access_thirty[i].data_array[j]) / 1000.0);
              for (int k = 0; k < z; k++)
              {
                access_logic_thirty[i].logic_array[l] = access_thirty[i].logic_array[j];
                //          Serial.println(access_logic_thirty[i].logic_array[l]);
                if (l >= 1 && l <= 8)
                {
                  access_RGB_array[i].R[(l - 1) % 8] = access_thirty[i].logic_array[j];
                }
                if ((l >= 9) && (l <= 16))
                {
                  access_RGB_array[i].G[(l - 1) % 8] = access_thirty[i].logic_array[j];
                }
                if (l >= 17 && l <= 24)
                {
                  access_RGB_array[i].B[(l - 1) % 8] = access_thirty[i].logic_array[j];
                }
                l += 1;
              }
            }

            /////////////////////// Converting Logic Array into Number Array /////////////////////////

            for (int j = 0; j < 8; j++)
            {
              if ((access_RGB_array[i].R[j]) == 1)
              {
                temp_holder_r = temp_holder_r + 1;
              }
              if ((access_RGB_array[i].G[j]) == 1)
              {
                temp_holder_g = temp_holder_g + 1;
              }
              if ((access_RGB_array[i].B[j]) == 1)
              {
                temp_holder_b = temp_holder_b + 1;
              }
            }
            RED[i] = temp_holder_r;
            GREEN[i] = temp_holder_g;
            BLUE[i] = temp_holder_b;
            //            Serial.println();
            //                        Serial.println(i);
            /////////////////////////// RGB & DATA CALCULATION FOR SPI //////////////////////

            if (RED[i] != 0)
            {
              SPI_RED[i] = (8192 * (RED[i] - 1)) + (1024 * ((Brightness_value_dec) + 1));
              if (SPI_RED[i] == 65536)
              {
                SPI_RED[i] -= 1;
              }
            }
            else
            {
              SPI_RED[i] = 0;
            }
            if (GREEN[i] != 0)
            {
              SPI_GREEN[i] = (8192 * (GREEN[i]  - 1)) + (1024 * ((Brightness_value_dec) + 1));
              if (SPI_GREEN[i] == 65536)
              {
                SPI_GREEN[i] -= 1;
              }
            }
            else
            {
              SPI_GREEN[i] = 0;
            }
            if (BLUE[i]  != 0)
            {
              SPI_BLUE[i] = (8192 * (BLUE[i] - 1)) + (1024 * ((Brightness_value_dec) + 1));
              if (SPI_BLUE[i] == 65536)
              {
                SPI_BLUE[i] -= 1;
              }
            }
            else
            {
              SPI_BLUE[i] = 0;
            }
            //            Serial.println(SPI_RED[i]);
            //            Serial.println(SPI_GREEN[i]);
            //            Serial.println(SPI_BLUE[i]);
            //            Serial.println();
          }
          ////////////////////////////////////////////////////////////////////////////////
          //////////////////////////////////// SPI ///////////////////////////////////////
          ////////////////////////////////////////////////////////////////////////////////
          SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
          for (int i = 0; i < 6; i++)
          {
            SPI.transfer(header48bit[i]);
          }
          for (int i = 0; i < 256; i++)
          {
            SPI.transfer16(SPI_BLUE[i]);  //Blue
            SPI.transfer16(SPI_GREEN[i]);
            SPI.transfer16(SPI_RED[i]);   //Red
          }
          SPI.endTransaction();
          digitalWrite(11, LOW);
          Serial.println(x);
        }
        previous_val = 0;
        current_val  = 0;
        flag = true;
        int_flag = false;
        write_index = 0;
        wrong_flag = false;
        exit_flag = 0;
         digitalWrite(4, LOW);
        if (led_counter == 2)
        {
          digitalWrite(3, LOW);
        }
//        x = x + 1;
        interrupts();
      }
    }
  }
}

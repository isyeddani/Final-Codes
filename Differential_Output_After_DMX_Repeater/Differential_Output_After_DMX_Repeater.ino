#define PIN_D6
#define PIN_A0
//unsigned char R[256], G[256], B[256];
unsigned char Rtemp = 0, Gtemp = 0, Btemp = 0;
unsigned char bright_var;
struct Color_Inputs   // Structure for color inputs
{
  unsigned char Rd_var;
  unsigned char Gr_var;
  unsigned char Bl_var;
  unsigned char Rd_var_alt;
  unsigned char Gr_var_alt;
  unsigned char Bl_var_alt;
  unsigned char alt;
  int Bright;
} colors;

struct data
{
  unsigned char R[256];
  unsigned char G[256];
  unsigned char B[256];
} inp_data;

struct Color_Inputs inputs();   // Function Prototypes
struct data data_loop(struct Color_Inputs *c);  // Function Prototype

/////////////////////// SETUP ///////////////////////

void setup()
{
  Serial.begin(152000);
  colors = inputs();
  inp_data = data_loop(&colors);
  pinMode(6, OUTPUT);       // LED OUTPUT
  pinMode(A0, OUTPUT);      //Output Enable
  digitalWrite(A0, LOW);

}
////////////////////// MAIN LOOP ///////////////////
void loop()
{
  digitalWrite(6, LOW);
  delayMicroseconds(41);
  digitalWrite(6, HIGH); //Break
  delayNanoseconds(4500);// 6.6usec

  for (int i = 0; i < 256; i++)
  {
    //////////////  //// RED////  ////////////////
    Rtemp = inp_data.R[i];
    Gtemp = inp_data.G[i];
    Btemp = inp_data.B[i];
    {
      digitalWrite(6, LOW); // markafterbreak
      delayMicroseconds(1);
      switch (Rtemp)
      {
        case 0:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayMicroseconds(8); break;
        case 1:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(970);
          break;
        case 2:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(6);
          delayNanoseconds(5970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(2);
          delayNanoseconds(1970);
          break;
        case 3:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(4970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(2970);
          break;
        case 4:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(4);
          delayNanoseconds(3800);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(4);
          delayNanoseconds(3800);
          break;
        case 5:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(2970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(4970);
          break;
        case 6:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(1970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(5970);
          break;
        case 7:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(990);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(6990);
          break;
        case 8:
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayMicroseconds(8);
          break;
      }
      ////////// GREEN START //////////////
      switch (Gtemp)
      {
        case 0:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayMicroseconds(8); break;
        case 1:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(970);
          break;
        case 2:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(6);
          delayNanoseconds(5970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(2);
          delayNanoseconds(1970);
          break;
        case 3:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(4970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause itsGREEN
          delayNanoseconds(2970);
          break;
        case 4:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3970);
          break;
        case 5:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(2970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(4970);
          break;
        case 6:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(1970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(5970);
          break;
        case 7:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(990);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(6990);
          break;
        case 8:
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayMicroseconds(8);
          break;
      }
      /////////// GREEN END //////////////

      ////////// BLUE STARTS //////////////
      switch (Btemp)
      {
        case 0:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayMicroseconds(8); break;
        case 1:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(920);
          break;
        case 2:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(6);
          delayNanoseconds(5920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(2);
          delayNanoseconds(1920);
          break;
        case 3:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(4970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(2970);
          break;
        case 4:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3940);
          break;
        case 5:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(2940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(4940);
          break;
        case 6:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(1940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(5940);
          break;
        case 7:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(990);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6990);
          break;
        case 8:
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayMicroseconds(8);
          break;
      }
      ///////////// BLUE END //////////////////
    }
    if (i < 255)
    {
      digitalWrite(6, HIGH); //Stop
      delayNanoseconds(4500);
    }
    else
    {
      digitalWrite(6, HIGH); //Stop
      delayNanoseconds(11500);
    }
    ///////////////////////////////////////////////////////////////////////////////                  ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////first 256 complete///////////////////////////////////////////////////////////////////////////
  }
  /////////////////////second 256 start///////////////////
  digitalWrite(6, LOW); //1/3 of GAP
  delayNanoseconds(16970);
  digitalWrite(6, HIGH); // 2/3 of GAP
  delayNanoseconds(970);
  digitalWrite(6, LOW); // 3/3 of GAP
  delayNanoseconds(22970);
  digitalWrite(6, HIGH); //Break
  delayNanoseconds(4500);

  for (int i = 0; i < 256; i++)
  {
    Rtemp = inp_data.R[i];
    Gtemp = inp_data.G[i];
    Btemp = inp_data.B[i];
    {
      digitalWrite(6, LOW); // markafterbreak
      delayMicroseconds(1);
      //////////////  //// RED////  ////////////////
      switch (Rtemp)
      {
        case 0:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayMicroseconds(8); break;
        case 1:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(920);
          break;
        case 2:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(6);
          delayNanoseconds(5920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(2);
          delayNanoseconds(1920);
          break;
        case 3:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayMicroseconds(5);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayMicroseconds(3);
          break;
        case 4:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(4);
          delayNanoseconds(3800);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(4);
          delayNanoseconds(3800);
          break;
        case 5:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(2970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(4970);
          break;
        case 6:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(1970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(5970);
          break;
        case 7:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayNanoseconds(6940);
          break;
        case 8:
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          delayMicroseconds(8);
          break;
      }
      ////////// GREEN START //////////////
      switch (Gtemp)
      {
        case 0:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayMicroseconds(8); break;
        case 1:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(920);
          break;
        case 2:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(6);
          delayNanoseconds(5920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(2);
          delayNanoseconds(1920);
          break;
        case 3:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(4970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause itsGREEN
          delayNanoseconds(2970);
          break;
        case 4:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3800);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3800);
          break;
        case 5:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(2970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(4970);
          break;
        case 6:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(1970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(5970);
          break;
        case 7:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayNanoseconds(6940);
          break;
        case 8:
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          delayMicroseconds(8);
          break;
      }
      /////////// GREEN END //////////////

      switch (Btemp)
      {
        case 0:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayMicroseconds(8); break;
        case 1:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(920);
          break;
        case 2:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(6);
          delayNanoseconds(5920);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its RED
          //delayMicroseconds(2);
          delayNanoseconds(1920);
          break;
        case 3:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(4970);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(2970);
          break;
        case 4:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its GREEN
          // delayMicroseconds(4);
          delayNanoseconds(3940);
          break;
        case 5:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(2940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(4940);
          break;
        case 6:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(1940);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(5940);
          break;
        case 7:
          digitalWrite(6, LOW); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(990);
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayNanoseconds(6990);
          break;
        case 8:
          digitalWrite(6, HIGH); //  1/3 of RGB, zero cause its BLUE
          delayMicroseconds(8);
          break;
      }
      ///////////// BLUE END //////////////////
    }
    if (i < 255)
    {
      digitalWrite(6, HIGH); //Stop
      delayNanoseconds(4500);
    }
    else

    {
      digitalWrite(6, HIGH); //Stop
      delayNanoseconds(11500);
    }
    ///////////////////////////////////////////////////////////////////////////////                  ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////Second 256 complete///////////////////////////////////////////////////////////////////////////
  }
  bright_var = colors.Bright;
  switch (bright_var)
  {
    case 1:
      digitalWrite(6, LOW); //1/3 of GAP
      delayNanoseconds(20970);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayNanoseconds(18970);
      digitalWrite(6, HIGH);
      break;
    case 2:
      digitalWrite(6, LOW); //1/3 of GAP
      delayMicroseconds(17);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayMicroseconds(1);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayMicroseconds(3);
      digitalWrite(6, HIGH);
      delayMicroseconds(1);
      digitalWrite(6, LOW);
      delayMicroseconds(19);
      digitalWrite(6, HIGH);
      break;
    case 3:
      digitalWrite(6, LOW); //1/3 of GAP
      delayMicroseconds(18);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayMicroseconds(1);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayMicroseconds(2);
      digitalWrite(6, HIGH);
      delayMicroseconds(1);
      digitalWrite(6, LOW);
      delayMicroseconds(19);
      digitalWrite(6, HIGH);
      break;
    case 4:
      digitalWrite(6, LOW); //1/3 of GAP
      delayMicroseconds(17);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayMicroseconds(2);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayMicroseconds(2);
      digitalWrite(6, HIGH);
      delayMicroseconds(1);
      digitalWrite(6, LOW);
      delayMicroseconds(19);
      digitalWrite(6, HIGH);
      break;
    case 5:
      digitalWrite(6, LOW); //1/3 of GAP
      delayNanoseconds(18970);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, HIGH); // 3/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayNanoseconds(18970);
      digitalWrite(6, HIGH);
      break;
    case 6:
      digitalWrite(6, LOW); //1/3 of GAP
      delayNanoseconds(16970);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, LOW); // 2/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, LOW);
      delayNanoseconds(970);
      digitalWrite(6, HIGH);
      delayNanoseconds(970);
      digitalWrite(6, LOW);
      delayNanoseconds(18970);
      digitalWrite(6, HIGH);
      break;
    case 7:
      digitalWrite(6, LOW); //1/3 of GAP
      delayNanoseconds(17970);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayNanoseconds(1970);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, HIGH);
      delayNanoseconds(970);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayNanoseconds(18970);
      digitalWrite(6, HIGH);
      break;
    case 8:
      digitalWrite(6, LOW); //1/3 of GAP
      delayNanoseconds(16970);
      digitalWrite(6, HIGH); // 2/3 of GAP
      delayNanoseconds(2970);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayNanoseconds(970);
      digitalWrite(6, HIGH);
      delayNanoseconds(970);
      digitalWrite(6, LOW); // 3/3 of GAP
      delayNanoseconds(18970);
      digitalWrite(6, HIGH);
      break;
  }
  delay(18);
}


////////////////////second 256 complete///////////
// Function definition
struct Color_Inputs inputs()
{
  struct Color_Inputs x;
  {
    Serial.println("Enter Color and Intensity");
    Serial.print("Enter Red Intensity from 0 to8 '0'=OFF, '8'=FULL : ");
    while (!Serial.available() > 0) {} //wait for an input
    x.Rd_var = Serial.read() - 48;
    int dustbin = Serial.read();
    Serial.println(x.Rd_var);

    Serial.print("Enter Green Intensity from 0 to 8 '0'=OFF, '8'=FULL : ");
    while (!Serial.available() > 0) {} //wait for an input
    x.Gr_var = Serial.read() - 48;
    dustbin = Serial.read();
    Serial.println(x.Gr_var);

    Serial.print("Enter Blue Intensity from 0 to 8 '0'=OFF, '8'=FULL : ");
    while (!Serial.available() > 0) {} //wait for an input
    x.Bl_var = Serial.read() - 48;
    dustbin = Serial.read();
    Serial.println(x.Bl_var);

    Serial.print("Enter '1' if you want alterante : ");
    while (!Serial.available() > 0) {} //wait for an input
    x.alt = Serial.read() - 48;
    dustbin = Serial.read();
    Serial.println(x.alt);

    if (x.alt == 1 )
    {
      Serial.println("Enter Alternate Color and Intensity");
      Serial.print("Enter Alternate Red Intensity from 0 to 8 '0'=OFF, '8'=FULL : ");
      while (!Serial.available() > 0) {} //wait for an input
      x.Rd_var_alt = Serial.read() - 48;
      int dustbin = Serial.read();
      Serial.println(x.Rd_var_alt);

      Serial.print("Enter Green Alternate Intensity from 0 to 8 '0'=OFF, '8'=FULL : ");
      while (!Serial.available() > 0) {} //wait for an input
      x.Gr_var_alt = Serial.read() - 48;
      dustbin = Serial.read();
      Serial.println(x.Gr_var_alt);

      Serial.print("Enter Blue Alterante Intensity from 0 to 8 '0'=OFF, '8'=FULL : ");
      while (!Serial.available() > 0) {} //wait for an input
      x.Bl_var_alt = Serial.read() - 48;
      dustbin = Serial.read();
      Serial.println(x.Bl_var_alt);
    }
    else if (x.alt != 0 )
    {
      Serial.print("Invalid Inputs : ");
    }
    Serial.print("Enter Brightness Levels from 0 to 8 : ");
    while (!Serial.available() > 0) {} //wait for an input
    x.Bright = Serial.read() - 48;
    dustbin = Serial.read();
    Serial.println(x.Bright);
  }

  return x;
}

struct data data_loop(struct Color_Inputs *c)
{
  struct data d;
  {
    if (c->alt == 1)
    {
      for (int jj = 0; jj < 256; jj++)
      {
        if ((jj % 2) == 0)
        {
          d.R[jj] = c->Rd_var;
          d.G[jj] = c->Gr_var;
          d.B[jj] = c->Bl_var;
        }
        else
        {
          d.R[jj] = c->Rd_var_alt;
          d.G[jj] = c->Gr_var_alt;
          d.B[jj] = c->Bl_var_alt;
        }
      }
    }
    else if (c->alt == 0)
    {
      for (int jj = 0; jj < 256; jj++)
      {
        d.R[jj] = c->Rd_var;
        d.G[jj] = c->Gr_var;
        d.B[jj] = c->Bl_var;
      }
    }
    else
    {
      Serial.print("Wrong alternate input");
    }
  }
  return d;
}

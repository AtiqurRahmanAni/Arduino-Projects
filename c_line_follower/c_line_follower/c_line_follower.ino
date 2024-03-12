#define ina   4
#define inb   5
#define inc   6
#define ind   7
#define ena   3
#define enb   9

int leftbasespeed = 87;
int rightbasespeed = 87;
int maxspeed =150;

#define num_sensors 6
int thresholds[num_sensors]={450,450,450,450,450,450};
int svalues[num_sensors],lastsensor;

double kp=1.3;
double kd=14;
int preverror;
void initialize();
void linefollow();
int readsensor();
void wheel();

void setup()
{
   initialize();
}
void loop()
{
  linefollow();
}

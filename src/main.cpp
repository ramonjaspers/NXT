#include <iostream>
#include "ultrasonic.h"
#include "IR.h"
#include "RGB.h"
#include "motion.h"
#include <unistd.h>
#include <signal.h>
#include <vector>

using namespace std;
BrickPi3 BP;

void exit_signal_handler(int signo);

vector<int16_t> vecIR;
vector<int16_t> vecRGB;
int STATE = 0;

IR ir(PORT_1);
RGB rgb(PORT_2);
Ultrasonic sonic(PORT_3);
Motion m(50);

void readSensor(){
    signal(SIGINT, exit_signal_handler);
    while(true){
        uint16_t IR_data = ir.get_current_value(true);
        uint16_t RGB_data = rgb.get_current_value(true);
        float SONIC_data = sonic.get_distance();

        cout << "=================================" << endl;
        cout << "IR:        " << IR_data << endl;
        cout << "RGB:       " << RGB_data << endl;
        cout << "RGB BLACK:       " << rgb.is_black() << endl;
        cout << "SONIC:     " << SONIC_data << endl;
        usleep(100*1000);
    }
}

void follow(){
    int16_t IRmin = vecIR[0];
    int16_t IRmax = vecIR[1];
    int16_t RGBmin = vecRGB[0];
    int16_t RGBmax = vecRGB[1];
    int last_left = 10;

    int g = 0;
    int head_on_count = 0;
    int last_right = 10;
    while(true){
        ir.set_current_value();
        rgb.set_current_value();
        //IRdata = ir.get_current_value(true);
        //RGBdata = rgb.get_current_value(true);
        bool isBlackRGB = rgb.is_black();
        bool isBlackIR = ir.is_black();
 /*       cout << "==================================" << endl;
        cout << "RGBMIN:\t\t" << RGBmin << endl;
        cout << "RGBMAX:\t\t" << RGBmax << endl;
        cout << "RGBDATA:\t" << RGBdata << endl;
*/
		switch(STATE){
			case 0:
                g = 0;
				if(isBlackIR && isBlackRGB){
                    cout << "STOP" << endl;
					m.turnDeg(90);
				}else if(isBlackIR && !isBlackRGB){

					cout << "LINKS" << endl;
					m.turn('l', last_left);

					head_on_count = 0;
					last_left += last_left + 60;
				}else if(!isBlackIR && isBlackRGB){

					cout << "RECHTS" << endl;
					m.turn('r', last_right);

					head_on_count = 0;
					last_right += last_right + 60;

				}else if(!isBlackIR && !isBlackRGB){
					m.drive();
					head_on_count++;
					if(head_on_count == 70){

						cout << "head on reset" << endl;
						last_left = 10;
						last_right = 10;
					}
				cout << "UP" << endl;
				STATE = 1;
				break;

            case 1:
                if(sonic.get_distance() <= 25){
                    STATE = 2;
                }else{
                    STATE = 0;
                }
                break;

            case 2:

                m.turnDeg(90.0);
                m.sensorTurn(90);

                m.drive();

                usleep(1*1000000);

                while(sonic.get_distance() <= 30){
                    usleep(0.1*1000000);
                }
                STATE = 5;

                break;

            case 3:
                cout << STATE << endl;
                m.sensorTurn(90);
                STATE = 4;
                break;

            case 4:
                if(sonic.get_distance() <= 30){
                    usleep(1*1000000);
                }else{
                    STATE = 5;
                }
                break;
            case 5:

            // deze state moet de correctie hebben
            // op dit moment is het nog niet mogelijk om de lijn terug te vinden
                m.turnDeg(-60.0);
                m.sensorTurn(0);
                m.drive();

                while(true){
// isBlackIR en RGB werden niet geupdatet.
                ir.set_current_value();
                rgb.set_current_value();
                    cout << "============= result ================" << rgb.is_black()  << ir.is_black()  << endl;
                    if(ir.is_black() && !rgb.is_black()){
                        break;
                    }else if(!ir.is_black() && rgb.is_black()){
                        m.emergency_stop();
                        break;
                    }
                    else if(ir.is_black()  && rgb.is_black()){
                        m.emergency_stop();
                        break;
                    }
                        cout << "============= LOOP ================" << endl;

                    }
                STATE = 0;
                cout << "STATE => 0" << endl;
                break;

            case 6:
                if(sonic.get_distance() <= 30){
                    usleep(0.2*1000000);
                }else{
                    STATE = 7;
                }
                break;

            case 7:
                m.turnDeg(45.0);
                m.drive();
                usleep(0.2*1000000);
                STATE = 8;
                break;

            case 8:
                m.sensorTurn(0);
                m.emergency_stop();
                STATE = 0;
                break;

            default:
                STATE = 0;
                m.drive();
                break;
            }
        }
	}
}
void setRanges(){
    signal(SIGINT, exit_signal_handler);
    cout << "IJKEN BEGINT ZO" << endl;
    usleep(5*1000000);
    ir.set_ranges();
    cout << "IR GEIJKT, GRB WORDT GEIJKT" << endl;
    rgb.set_ranges();
    cout << "RGB GEIJKT" << endl;

    vecIR = ir.get_ranges();
    vecRGB = rgb.get_ranges();

    for(unsigned int i=0; i<4; i++){
        cout << "==================================" << endl;
        cout << "IR," << i << ":    " << vecIR[i] << endl;
        cout << "RGB," << i << ":   " << vecRGB[i] << endl;
    }
}

int main(){
    signal(SIGINT, exit_signal_handler);
    setRanges();
    follow();
    //readSensor();
}

void exit_signal_handler(int signo){
  if(signo == SIGINT){
    BP.reset_all();    // Reset everything so there are no run-away motors
    BP.set_sensor_type(PORT_2, SENSOR_TYPE_NXT_COLOR_OFF);
    exit(-2);
  }
}

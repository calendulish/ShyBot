/*  
 *  Lara Maia <dev@lara.click> 2016
 *   
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Arduino.h>

#define ULTRASONIC_TIMEOUT 1986

unsigned long distance;
unsigned long duration;

long sonar(byte trigger, byte echo) {
    digitalWrite(trigger, LOW);
    delayMicroseconds(10);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(20);
    digitalWrite(trigger, LOW);
    
    duration = pulseIn(echo, HIGH, ULTRASONIC_TIMEOUT);
    // Believe, 38 is the right value for this case.
    // I calibrated the sensor manually with a measuring tape
    distance = (duration / 2) / 38;
    
    return distance;
}

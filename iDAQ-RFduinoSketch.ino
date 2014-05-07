// Copyright (c) 2014 Tactition Programming.  All right reserved.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3.0 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//This software allows you to create a low-cost version of the iDAQ
//from Tactition Programming. This single channel version works with the
//"BT-iDAQ" App in the iOS App Store. It allows you to monitor a single data
//channel remotely over a BT-LE connection on an iPhone or iPad.

//For a professionally assembled, full featured version with a free app visit:
//
//http://tactitionprogramming.com/idaq.html
//

*********************************** SETUP ***************************************
//To use this sketch:
//Purchase an RFduino device from rfduino.com and setup your arduino environment
//according to the instructions at https://github.com/RFduino/RFduino/
//Remember to get an appropriate power source with your order. The RFduino
//runs well from a pair of AA batteries using their battery shield, or it
//can be powered by a 5V USB supply combined with the USB shield.
//You will also need a USB shield to program your device.
//Once your computer is setup to work with the RFduino, upload this sketch
//to your device. It will immediately begin transmitting analog data to
//your iPad/iPhone! Use the BT-iDAQ App from Tactition Programming to monitor
//this data and see your signal in real time.

//By default, this file is configured to sense on pin 4.
//Connect your equipment to pin 4 and ground, and make sure you do not
//exceed 3.3V for safe operation.


#include "RFduinoBLE.h"
#define ANALOGLEVEL DEFAULT

int analogPin = 4; // you can adjust the pin used here

void setup() {
  analogReference(ANALOGLEVEL);
  RFduinoBLE.advertisementData = "iDAQ-BT"; //Adjust broadcast name here
  RFduinoBLE.begin();
  
}

void loop() {
  RFduino_ULPDelay( MILLISECONDS(500) );//This delay determines the data rate
  int analogValue = analogRead(analogPin);
  RFduinoBLE.sendInt(analogValue);
}

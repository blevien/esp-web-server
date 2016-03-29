/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
	server.send(200, "text/html", 
"<h1>Connected!</h1>"
"<h2>Here's what worked for me:</h2>"
"<ol>"
"<li>Wire it up based on <a href=""http://www.arduinesp.com/wifiwebserver"">this diagram<a>. The Flash and Reset buttons are really nice to have</li>"
"<ul><li>Using my FTDI power supply, I had to <a href=""http://internetofhomethings.com/homethings/?p=396"">add a capacitor to prevent Watchdog Reset</a></li></ul>"
"<li>Install the ESP Board Manager from the Arduino <a href=""https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon"">Board Manager</a></li>"
"<li>In Tools Menu, set Board to Generic ESP8266, and Programmer Speed to 921600 otherwise the upload is pretty slow. NOTE: Don't worry about not having an esptools listed as the programmer in the Tools menu!</li>"
"<li>Install <a href=""https://github.com/me-no-dev/EspExceptionDecoder"">ESP Exception Decoder</a> to decode stack traces by pasting all the bits between the <<<stack<<<< </li>"
"<li>You should now be ready to upload the Example Sketch called ""ESP8266WiFi -> WiFiAccessPoint""</li>"
"<li>Open the Serial Monitor to watch for output and press the reset button</li>"
"<li>If you get an IP Address, we're almost there! Connect your computer/phone/whatever to the SSID (ESPap if you didn't change it)</li>"
"<li>Browse to the IP Address listed, and you should see ""You are connected!""</li>"
"</ol>"

"<p>I hope this works for you, and I am looking forward to more fun ESP8266 Projects!</p>"


);
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}

# esp-web-server

My first attempt at an ESP8266 Arduino Project, with links to tips that helped me get it up and running.

The HTML in my sketch that is served when you get it running contains the following helpful hits, but here it is again:

<h2>Here's what worked for me:</h2>
<ol>
<li>Wire it up based on <a href="http://www.arduinesp.com/wifiwebserver">this diagram<a>. The Flash and Reset buttons are really nice to have</li>
<ul><li>Using my FTDI power supply, I had to <a href="http://internetofhomethings.com/homethings/?p=396">add a capacitor to prevent Watchdog Reset</a></li></ul>
<li>Install the ESP Board Manager from the Arduino <a href="https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon">Board Manager</a></li>
<li>In Tools Menu, set Board to Generic ESP8266, and Programmer Speed to 921600 otherwise the upload is pretty slow.</li>
<ul><li>NOTE: Don't worry about not having an esptools listed as the programmer in the Tools menu!</li></ul>
<li>Install <a href="https://github.com/me-no-dev/EspExceptionDecoder">ESP Exception Decoder</a> to decode stack traces by pasting all the bits between the stack lines </li>
<li>You should now be ready to upload the Example Sketch called "ESP8266WiFi -> WiFiAccessPoint"</li>
<li>Open the Serial Monitor to watch for output and press the reset button</li>
<li>If you get an IP Address, we're almost there! Connect your computer/phone/whatever to the SSID (ESPap if you didn't change it)</li>
<li>Browse to the IP Address listed, and you should see "You are connected!"</li>
</ol>

<p>I hope this works for you, and I am looking forward to more fun ESP8266 Projects!</p>

# Miss-You
A cross-national notifying system that allows every possesor of the android app to notify their close one, when they are being missed. Each dedicated android app, feature two buttons which stores data (on or off instruction) in a FireBase database.
At the adressee end, an esp8266 reads the instructions from the FireBase and toggles the LED/Lamp, corresponding to the particular app user, through a relay. 
The adressee can turn all the lamps off with a press on a physical button, when required.

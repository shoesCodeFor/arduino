# arduino-light-driven-outlet-controller
This is a simple power outlet controller using a light sensor, 120V relay and Arduino.

Instructions:
1) Wire up the relay with your outlet off.  I bought an old power strip from the thrift store and gutted it.  Older power strips have extra room to store our Arduino(Nano or Micro is preferrable).  Wire 1 2-Outlet relay or 2 1-Outlet relay to achieve the results in the sketch. The relays have a normally open side and normally closed side.  In this sketch we use the 'Normally Open' side.  It is symbolized by the disconnected wire.  Wire the live side of you Black(Hot) wire into the input of the relay with the output wire connected to the normally open side or the relay.  The White(Common) and Green/Gold(Neutral/GND) wire go directly into the outlet bypassing the relay.

You can control as many relays as you have digital write availability, but I think a Nano will only drive 4 of these reliably.  

2) Wire your digital outs corresponding to the relay Digital Input.  In our sketch it is Digital 2 & 3.  The 5V and GND will connect to our relay as well.  If these are seperate relays you can use the 5V & Ground header on the ICSP as I was having issues driving to relays on one 5V lead.  I think these might be regulated seperately on Arduino.  

3) Upload the code and test you relay WITHOUT PLUGGING IT IN.  DO NOT PLUG IT IN until you have verified functionality.  You should see lights on the relays corresponding to daylight or no light(you can emulate this with a good flashlight or the one on your phone).

4) If you are satisfied with everything you can try plugging this into a GFCI socket for safety.  If there is a wiring fault it will trip the circuit.  If there is an amperage overlaod it will not detect it but our relay is only good to 15A so use a powerstrip for the final project to plug into and it should save the relay.  Also know your AMPERAGE loads.  At 120v the info is required to be listed on your equipment.  0.9A means 9/10 of an amp and so on.  Keep the total load on each relay to less than 7amps unless the one cylce is lower voltage(ie - 12A AC Daylight unit and/3A Night Lights are okay and vice versa.  Most household socket groups are rated at 15A total(3-4 outlet), so do not push Amperage higher than your household circuit breaker can handle. 

Finishing UP.. More to come

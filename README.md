# Fruitbar QMK Firmware - HansTheIV

I ordered a [Fruitbar](https://github.com/blewis308/Fruitbar/) as my first 40% keyboard since it had arrow keys, which are the things I was squeamish about for transitioning to anything smaller than a 65%. I also thought the OLED screen and rotary encoder were a cool addition. My first mechanical keyboard was a Steelseries Apex 7, which I had tried to write software to push spotify titles to the screen. However, it was a bit of a pain to get that to work, since it had an unhelpfully documented API and required me to send POSTs to a web server to update my keyboard. Very odd. In light of that, I liked the idea of a QMK-compatible OLED that I could program myself. 

So here we are. The `Music_ID` folder contains the required software (WIP) to push the titles of currently playing songs (pulled from windows media player) over raw HID to the keyboard. It requires the following libraries:
- hidapi
- hid
- libusb
- pywin32

The `firmware` folder contains, aptly enough, the firmware for the keyboard. 
This will need to be dropped into your QMK firmware directory before it can be used. In fact, outside of the qmk_firmware directory, it will show a *lot* of errors. This is because it relies on definitions from within QMK.

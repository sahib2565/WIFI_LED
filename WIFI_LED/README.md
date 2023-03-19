# WIFI LED

![language](https://img.shields.io/badge/language-c%2B%2B-red)
![Testing](https://img.shields.io/badge/Test-Pass-green)
## Description
In this project we are going to switch on and off a LED via a website,using the WiFi module that is present inside the ESP32.

## Getting started

You just have to connect the led to the ESP32 as shown in the schematics,once you do that install the libraries needed for the project and install the ESP32 devkit board

### Modify this part of the code
```c++
const char* ssid = ""; // the name of your WiFi
const char* password = ""; // the password of your WiFi
```

and in the html file put the ip address that is shown in your serial monitor

```
const endpoint = 'http://192.168.1.9:80/switch';
```

## Author

### Il_kima

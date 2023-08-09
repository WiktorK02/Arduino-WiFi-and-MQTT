# Arduino WiFi and MQTT
*Arduino Board I use: ARDUINO UNO WiFi REV2*<br>
## About
The Arduino WiFi and MQTT Project explores the synergy between Arduino boards, WiFi connectivity, and the MQTT protocol, enabling the creation of robust IoT solutions. With step-by-step explanation, learn to connect Arduino devices to WiFi networks, implement MQTT's publish-subscribe mechanism, and develop applications such as sensor data monitoring and remote device control.
# Node-Red
## Screenshot
![Screenshot1](https://github.com/WiktorK02/arduino-wifi-and-mqtt/assets/123249470/1014dcbf-0f6c-4290-ac38-928838bf142e)
## Importing to Node-Red
**Add libraries before import:**<br>
* node-red-contrib-aedes (or use any other borker; if so then remove broker node and change IP in MQTT node)*
```
[
    {
        "id": "2c6873d2.992abc",
        "type": "mqtt out",
        "z": "fcb6a21e80097fe7",
        "name": "",
        "topic": "led/control",
        "qos": "0",
        "retain": "false",
        "respTopic": "",
        "contentType": "",
        "userProps": "",
        "correl": "",
        "expiry": "",
        "broker": "407a01e4.6b637",
        "x": 650,
        "y": 260,
        "wires": []
    },
    {
        "id": "407a01e4.6b637",
        "type": "mqtt-broker",
        "name": "",
        "broker": "localhost",
        "port": "1883",
        "clientid": "",
        "autoConnect": true,
        "usetls": false,
        "protocolVersion": "4",
        "keepalive": "60",
        "cleansession": true,
        "birthTopic": "",
        "birthQos": "0",
        "birthPayload": "",
        "birthMsg": {},
        "closeTopic": "",
        "closePayload": "",
        "closeMsg": {},
        "willTopic": "",
        "willQos": "0",
        "willPayload": "",
        "willMsg": {},
        "userProps": "",
        "sessionExpiry": "",
        "credentials": {}
    }
]
```
## How to Contribute
1. Fork the Project
2. Clone repo with your GitHub username instead of ```YOUR-USERNAME```:<br>
```
$ git clone https://github.com/YOUR-USERNAME/arduino-wifi-and-mqtt
```
3. Create new branch:<br>
```
$ git branch BRANCH-NAME 
$ git checkout BRANCH-NAME
```
4. Make changes and test<br>
5. Submit Pull Request with comprehensive description of change
## License 
[MIT license](LICENSE)

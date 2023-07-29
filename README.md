# Arduino WiFi and MQTT

# Node-Red
## Screenshot
![Screenshot1](https://github.com/WiktorK02/arduino-wifi-and-mqtt/assets/123249470/1014dcbf-0f6c-4290-ac38-928838bf142e)
## Import to Node-Red
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

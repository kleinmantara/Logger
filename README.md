# Logger

## Introduction

Logger Library for the ESP8266 to show the logs with the WebServer.

## Usage

Initialize a new Logger: `Logger log = Logger(levelInfo);`

Log some informations: `log.info("My message");`

Get all logs to send it via the webserver:

```c++
String msg = "<html>";
msg.concat(F("<h2>Logging</h2>"));
msg.concat(F("<pre>"));
msg.concat("<a href=\"/mark\">Mark</a> | <a href=\"/clear\">Clear</a>\n\n");
msg.concat(log.getMessages());
msg.concat(F("</pre>"));
server.send(200, htmlType, msg);
```

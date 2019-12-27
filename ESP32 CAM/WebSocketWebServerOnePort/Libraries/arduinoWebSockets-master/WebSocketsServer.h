/**
 * @file WebSocketsServer.h
 * @date 20.05.2015
 * @author Markus Sattler
 * @co-date 25.12.2019
 * @co-author Aldrin John O. Manalansan
 *
 * Copyright (c) 2015 Markus Sattler. All rights reserved.
 * This file is part of the WebSockets for Arduino.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
//#include <Arduino.h>
const char camwebpage[] PROGMEM = "HTTP/1.1 200 OK\r\n"
"Content-Type: text/html\r\n"
"Content-Length: 4610\r\n"
"Connection: closed\r\n\r\n"
"<html>\n"
"\t<head>\n"
"\t\t<title>Thesis IP Camera</title>\n"
"\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"\t\t<style>\n"
"\t\t\timg\n"
"\t\t\t{\n"
"\t\t\t\tdisplay: block;\n"
"\t\t\t\tmargin-left: auto;\n"
"\t\t\t\tmargin-right: auto;\n"
"\t\t\t\theight: 100%;\n"
"\t\t\t\twidth: auto;\n"
"\t\t\t}\n"
"\t\t\t.switch {\n"
"\t\t\t\tposition: relative;\n"
"\t\t\t\tdisplay: inline-block;\n"
"\t\t\t\twidth: 60px;\n"
"\t\t\t\theight: 34px;\n"
"\t\t\t}\n"
"\t\t\t.switch input { \n"
"\t\t\t\topacity: 0;\n"
"\t\t\t\twidth: 0;\n"
"\t\t\t\theight: 0;\n"
"\t\t\t}\n"
"\t\t\t.slider {\n"
"\t\t\t\tposition: absolute;\n"
"\t\t\t\tcursor: pointer;\n"
"\t\t\t\ttop: 0;\n"
"\t\t\t\tleft: 0;\n"
"\t\t\t\tright: 0;\n"
"\t\t\t\tbottom: 0;\n"
"\t\t\t\tbackground-color: #ccc;\n"
"\t\t\t\t-webkit-transition: .4s;\n"
"\t\t\t\ttransition: .4s;\n"
"\t\t\t}\n"
"\t\t\t.slider:before {\n"
"\t\t\t\tposition: absolute;\n"
"\t\t\t\tcontent: \"\";\n"
"\t\t\t\theight: 26px;\n"
"\t\t\t\twidth: 26px;\n"
"\t\t\t\tleft: 4px;\n"
"\t\t\t\tbottom: 4px;\n"
"\t\t\t\tbackground-color: white;\n"
"\t\t\t\t-webkit-transition: .4s;\n"
"\t\t\t\ttransition: .4s;\n"
"\t\t\t}\n"
"\t\t\tinput:checked + .slider {\n"
"\t\t\t\tbackground-color: #2196F3;\n"
"\t\t\t}\n"
"\t\t\tinput:focus + .slider {\n"
"\t\t\t\tbox-shadow: 0 0 1px #2196F3;\n"
"\t\t\t}\n"
"\t\t\tinput:checked + .slider:before {\n"
"\t\t\t\t-webkit-transform: translateX(26px);\n"
"\t\t\t\t-ms-transform: translateX(26px);\n"
"\t\t\t\ttransform: translateX(26px);\n"
"\t\t\t}\n"
"\t\t\t.slider.round {\n"
"\t\t\t\tborder-radius: 34px;\n"
"\t\t\t}\n"
"\t\t\t.slider.round:before {\n"
"\t\t\t\tborder-radius: 50%;\n"
"\t\t\t}\n"
"\t\t\t.button {\n"
"\t\t\t\tbackground-color: #4CAF50;\n"
"\t\t\t\tborder: none;\n"
"\t\t\t\tcolor: white;\n"
"\t\t\t\tpadding: 5px;\n"
"\t\t\t\ttext-align: center;\n"
"\t\t\t\ttext-decoration: none;\n"
"\t\t\t\tdisplay: inline-block;\n"
"\t\t\t\tfont-size: 16px;\n"
"\t\t\t\tcursor: pointer;\n"
"\t\t\t}\n"
"\t\t\t.flipcambutton {border-radius: 20px;}\n"
"\t\t\t.dropbtn {\n"
"\t\t\t\tbackground-color: #4CAF50;\n"
"\t\t\t\tcolor: white;\n"
"\t\t\t\tpadding: 16px;\n"
"\t\t\t\tfont-size: 16px;\n"
"\t\t\t\tborder: none;\n"
"\t\t\t\tcursor: pointer;\n"
"\t\t\t}\n"
"\t\t\t.dropdown {\n"
"\t\t\t\tposition: relative;\n"
"\t\t\t\tdisplay: inline-block;\n"
"\t\t\t}\n"
"\t\t\t.dropdown-content {\n"
"\t\t\t\tdisplay: none;\n"
"\t\t\t\tposition: absolute;\n"
"\t\t\t\tbackground-color: #f9f9f9;\n"
"\t\t\t\tmin-width: 180px;\n"
"\t\t\t\tbox-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);\n"
"\t\t\t\tz-index: 1;\n"
"\t\t\t}\n"
"\t\t\t.dropdown-content a {\n"
"\t\t\t\tcolor: black;\n"
"\t\t\t\tpadding: 12px 16px;\n"
"\t\t\t\ttext-decoration: none;\n"
"\t\t\t\tdisplay: block;\n"
"\t\t\t}\n"
"\t\t\t.dropdown-content a:hover {background-color: #f1f1f1}\n"
"\t\t\t.dropdown:hover .dropdown-content {\n"
"\t\t\t\tdisplay: block;\n"
"\t\t\t}\n"
"\t\t\t.dropdown:hover .dropbtn {\n"
"\t\t\t\tbackground-color: #3e8e41;\n"
"\t\t\t}\n"
"\t\t</style>\n"
"\t</head>\n"
"\t<body style=\"background-color:#FFFFFF\">\n"
"\t\t<div class=\"dropdown\">\n"
"\t\t\t<button class=\"dropbtn\">Settings</button>\n"
"\t\t\t<div class=\"dropdown-content\">\n"
"\t\t\t\t<a href=\"#\">\n"
"\t\t\t\t\t<div style=\"position:relative; float:left;\">\n"
"\t\t\t\t\t\t<b>FlashLight:</b>\n"
"\t\t\t\t\t</div>\n"
"\t\t\t\t\t<div style=\"position:relative; float:left;\">\n"
"\t\t\t\t\t\t<label class=\"switch\">\n"
"\t\t\t\t\t\t\t<input type=\"checkbox\" id=\"flashlight\" onclick=\"setflashlight()\">\n"
"\t\t\t\t\t\t\t<span class=\"slider round\"></span>\n"
"\t\t\t\t\t\t</label>\n"
"\t\t\t\t\t</div><br>\n"
"\t\t\t\t</a>\n"
"\t\t\t\t<a href=\"#\">\n"
"\t\t\t\t\t<button class=\"button flipcambutton\" onclick=\"flipcamera()\">Flip Camera</button>\n"
"\t\t\t\t</a>\n"
"\t\t\t\t<a href=\"#\">\n"
"\t\t\t\t\t<select id=\"resolution\" onchange=\"changeresolution()\">\n"
"\t\t\t\t\t\t<option value=\"0\">QQVGA -- 160x120</option>\n"
"\t\t\t\t\t\t<option value=\"1\">QQVGA2 - 128x160</option>\n"
"\t\t\t\t\t\t<option value=\"2\">QCIF --- 176x144</option>\n"
"\t\t\t\t\t\t<option value=\"3\">HQVGA -- 240x176</option>\n"
"\t\t\t\t\t\t<option value=\"4\">QVGA --- 320x240</option>\n"
"\t\t\t\t\t\t<option value=\"5\">CIF ---- 400x296</option>\n"
"\t\t\t   <option value=\"6\" selected>VGA ---- 640x480</option>\n"
"\t\t\t\t\t\t<option value=\"7\">SVGA --- 800x600</option>\n"
"\t\t\t\t\t\t<option value=\"8\">XGA ---- 1024x768</option>\n"
"\t\t\t\t\t\t<option value=\"9\">SXGA --- 1280x1024</option>\n"
"\t\t\t\t\t   <option value=\"10\">UXGA --- 1600x1200</option>\n"
"\t\t\t\t\t</select>\n"
"\t\t\t\t</a>\n"
"\t\t\t</div>\n"
"\t\t</div>\n"
"\t\t<img src=\"\">\n"
"\t\t<script>\n"
"\t\t\tconst img = document.querySelector('img');\n"
"\t\t\tconst WS_URL = (location.protocol === 'https:' ? 'wss' : 'ws') + '://' + window.location.hostname + '/ws';\n"
"\t\t\tconst ws = new WebSocket(WS_URL);\n"
"\t\t\tws.onerror = function() {\n"
"\t\t\tlocation.reload(true);\n"
"\t\t\t}\n"
"\t\t\tlet urlObject;\n"
"\t\t\tws.onmessage = message => {\n"
"\t\t\t\tconst arrayBuffer = message.data;\n"
"\t\t\t\tif(urlObject){\n"
"\t\t\t\t\tURL.revokeObjectURL(urlObject);\n"
"\t\t\t\t}\n"
"\t\t\t\turlObject = URL.createObjectURL(new Blob([arrayBuffer]));\n"
"\t\t\t\tdelete arrayBuffer;\n"
"\t\t\t\tdelete message;\n"
"\t\t\t\timg.src = urlObject;\n"
"\t\t\t}\n"
"\t\t\twindow.stop();\n"
"\t\t\tif ($.browser.msie) {document.execCommand(\"Stop\");};\n"
"\t\t\tfunction setflashlight(){\n"
"\t\t\t\tws.send(\"#\"+(document.getElementById(\"flashlight\").checked==true?1:0));\n"
"\t\t\t}\n"
"\t\t\tfunction flipcamera(){\n"
"\t\t\t\tws.send(\"@\");\n"
"\t\t\t}\n"
"\t\t\tfunction changeresolution(){\n"
"\t\t\t\tws.send(\"!\"+document.getElementById(\"resolution\").value);\n"
"\t\t\t}\n"
"\t\t</script>\n"
"\t</body>\n"
"</html>\r\n";

#ifndef WEBSOCKETSSERVER_H_
#define WEBSOCKETSSERVER_H_

#include "WebSockets.h"

#ifndef WEBSOCKETS_SERVER_CLIENT_MAX
#define WEBSOCKETS_SERVER_CLIENT_MAX (8)
#endif

class WebSocketsServer : protected WebSockets {
  public:
#ifdef __AVR__
    typedef void (*WebSocketServerEvent)(uint8_t num, WStype_t type, uint8_t * payload, size_t length);
    typedef bool (*WebSocketServerHttpHeaderValFunc)(String headerName, String headerValue);
#else
    typedef std::function<void(uint8_t num, WStype_t type, uint8_t * payload, size_t length)> WebSocketServerEvent;
    typedef std::function<bool(String headerName, String headerValue)> WebSocketServerHttpHeaderValFunc;
#endif

    WebSocketsServer(uint16_t port, String origin = "", String protocol = "arduino");
    virtual ~WebSocketsServer(void);

    void begin(void);
    void close(void);

#if(WEBSOCKETS_NETWORK_TYPE != NETWORK_ESP8266_ASYNC)
    void loop(void);
#else
    // Async interface not need a loop call
    void loop(void) __attribute__((deprecated)) {}
#endif

    void onEvent(WebSocketServerEvent cbEvent);
    void onValidateHttpHeader(
        WebSocketServerHttpHeaderValFunc validationFunc,
        const char * mandatoryHttpHeaders[],
        size_t mandatoryHttpHeaderCount);

    bool sendTXT(uint8_t num, uint8_t * payload, size_t length = 0, bool headerToPayload = false);
    bool sendTXT(uint8_t num, const uint8_t * payload, size_t length = 0);
    bool sendTXT(uint8_t num, char * payload, size_t length = 0, bool headerToPayload = false);
    bool sendTXT(uint8_t num, const char * payload, size_t length = 0);
    bool sendTXT(uint8_t num, String & payload);

    bool broadcastTXT(uint8_t * payload, size_t length = 0, bool headerToPayload = false);
    bool broadcastTXT(const uint8_t * payload, size_t length = 0);
    bool broadcastTXT(char * payload, size_t length = 0, bool headerToPayload = false);
    bool broadcastTXT(const char * payload, size_t length = 0);
    bool broadcastTXT(String & payload);

    bool sendBIN(uint8_t num, uint8_t * payload, size_t length, bool headerToPayload = false);
    bool sendBIN(uint8_t num, const uint8_t * payload, size_t length);

    bool broadcastBIN(uint8_t * payload, size_t length, bool headerToPayload = false);
    bool broadcastBIN(const uint8_t * payload, size_t length);

    bool sendPing(uint8_t num, uint8_t * payload = NULL, size_t length = 0);
    bool sendPing(uint8_t num, String & payload);

    bool broadcastPing(uint8_t * payload = NULL, size_t length = 0);
    bool broadcastPing(String & payload);

    void disconnect(void);
    void disconnect(uint8_t num);

    void setAuthorization(const char * user, const char * password);
    void setAuthorization(const char * auth);

    int connectedClients(bool ping = false);

#if(WEBSOCKETS_NETWORK_TYPE == NETWORK_ESP8266) || (WEBSOCKETS_NETWORK_TYPE == NETWORK_ESP8266_ASYNC) || (WEBSOCKETS_NETWORK_TYPE == NETWORK_ESP32)
    IPAddress remoteIP(uint8_t num);
#endif

  protected:
    uint16_t _port;
    String _origin;
    String _protocol;
    String _base64Authorization;    ///< Base64 encoded Auth request
    String * _mandatoryHttpHeaders;
    size_t _mandatoryHttpHeaderCount;

    WEBSOCKETS_NETWORK_SERVER_CLASS * _server;

    WSclient_t _clients[WEBSOCKETS_SERVER_CLIENT_MAX];

    WebSocketServerEvent _cbEvent;
    WebSocketServerHttpHeaderValFunc _httpHeaderValidationFunc;

    bool _runnning;

    bool newClient(WEBSOCKETS_NETWORK_CLASS * TCPclient);

    void messageReceived(WSclient_t * client, WSopcode_t opcode, uint8_t * payload, size_t length, bool fin);

    void clientDisconnect(WSclient_t * client);
    bool clientIsConnected(WSclient_t * client);

#if(WEBSOCKETS_NETWORK_TYPE != NETWORK_ESP8266_ASYNC)
    void handleNewClients(void);
    void handleClientData(void);
#endif

    void handleHeader(WSclient_t * client, String * headerLine);

    /**
         * called if a non Websocket connection is coming in.
         * Note: can be override
         * @param client WSclient_t *  ptr to the client struct
         */
    //virtual void handleNonWebsocketConnection(WSclient_t * client) {
    //    DEBUG_WEBSOCKETS("[WS-Server][%d][handleHeader] no Websocket connection close.\n", client->num);
    //    client->tcp->write(
    //        "HTTP/1.1 401 Unauthorized\r\n"
    //        "Server: arduino-WebSocket-Server\r\n"
    //        "Content-Type: text/plain\r\n"
    //        "Content-Length: 45\r\n"
    //        "Connection: close\r\n"
    //        "Sec-WebSocket-Version: 13\r\n"
    //        "WWW-Authenticate: Basic realm=\"WebSocket Server\""
    //        "\r\n"
    //        "This Websocket server requires Authorization!");
    //    clientDisconnect(client);
    //}
	
	virtual void handleNonWebsocketConnection(WSclient_t * client)
	{
		client->tcp->write_P(camwebpage,sizeof(camwebpage));
		//write(client,(uint8_t *)camwebpage,sizeof(camwebpage));
	}

    /**
         * called if a non Authorization connection is coming in.
         * Note: can be override
         * @param client WSclient_t *  ptr to the client struct
         */
    virtual void handleAuthorizationFailed(WSclient_t * client) {
        client->tcp->write(
            "HTTP/1.1 401 Unauthorized\r\n"
            "Server: arduino-WebSocket-Server\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 45\r\n"
            "Connection: close\r\n"
            "Sec-WebSocket-Version: 13\r\n"
            "WWW-Authenticate: Basic realm=\"WebSocket Server\""
            "\r\n"
            "This Websocket server requires Authorization!");
        clientDisconnect(client);
    }

    /**
         * called for sending a Event to the app
         * @param num uint8_t
         * @param type WStype_t
         * @param payload uint8_t *
         * @param length size_t
         */
    virtual void runCbEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
        if(_cbEvent) {
            _cbEvent(num, type, payload, length);
        }
    }

    /*
         * Called at client socket connect handshake negotiation time for each http header that is not
         * a websocket specific http header (not Connection, Upgrade, Sec-WebSocket-*)
         * If the custom httpHeaderValidationFunc returns false for any headerName / headerValue passed, the
         * socket negotiation is considered invalid and the upgrade to websockets request is denied / rejected
         * This mechanism can be used to enable custom authentication schemes e.g. test the value
         * of a session cookie to determine if a user is logged on / authenticated
         */
    virtual bool execHttpHeaderValidation(String headerName, String headerValue) {
        if(_httpHeaderValidationFunc) {
            //return the value of the custom http header validation function
            return _httpHeaderValidationFunc(headerName, headerValue);
        }
        //no custom http header validation so just assume all is good
        return true;
    }

  private:
    /*
         * returns an indicator whether the given named header exists in the configured _mandatoryHttpHeaders collection
         * @param headerName String ///< the name of the header being checked
         */
    bool hasMandatoryHeader(String headerName);
};

#endif /* WEBSOCKETSSERVER_H_ */

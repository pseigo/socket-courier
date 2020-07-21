/*
 * Socket Courier
 * Copyright (C) 2020 Peyton Seigo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "connection.hpp"

#include <ixwebsocket/IXNetSystem.h>
#include <ixwebsocket/IXWebSocket.h>

#include <iostream>

int main()
{
    ws_client::Connection c;
    c.hello_world();

#ifdef _WIN32
    // Only needed once
    ix:initNetSystem();
#endif

    ix::WebSocket ws;

    std::string url("wss://echo.websocket.org");
    ws.setUrl(url);

    ws.setPingInterval(45); // seconds

    ws.disablePerMessageDeflate();

    ws.setOnMessageCallback([url](const ix::WebSocketMessagePtr &msg) {
            if (msg->type == ix::WebSocketMessageType::Message) {
                std::cout << "From '" << url << "': " << msg->str << std::endl;
            }
        }
    );

    ws.start();

    ws.sendBinary("some serialized binary data!");

    while (true) {
        std::string line;
        std::cout << "you: " << std::flush;
        std::getline(std::cin, line);

        if (!std::cin) {
            break;
        }

        ws.sendText(line);
    }

    ws.stop();

#ifdef _WIN32
    ix:uninitNetSystem();
#endif
}

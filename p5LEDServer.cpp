#include <jsonrpccpp/server/connectors/httpserver.h>
#include <stdio.h>

#include <iostream>

#include "gen/abstractstubserver.h"

using namespace jsonrpc;
using namespace std;

class P5LEDServer : public AbstractStubServer {
 public:
  P5LEDServer(AbstractServerConnector& connector, serverVersion_t type);

  virtual void imageData() override;
};

P5LEDServer::P5LEDServer(AbstractServerConnector& connector,
                         serverVersion_t type)
    : AbstractStubServer(connector, type) {}

void P5LEDServer::imageData() { std::cout << "YO, IMAGE DATA RECEIVED"; }

int main() {
  HttpServer httpserver(8383);
  P5LEDServer s(httpserver,
                JSONRPC_SERVER_V1V2);  // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();

  return 0;
}

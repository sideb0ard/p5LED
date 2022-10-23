# jsonrpcstub spec.json --cpp-server=AbstractStubServer --cpp-client=StubClient

g++ -L${HOME}/homebrew/lib -I${HOME}/homebrew/include p5LEDServer.cpp -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -o p5LEDServer

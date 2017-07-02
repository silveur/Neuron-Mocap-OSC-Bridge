#include "includes.h"
#include "socket.hpp"
#include "data.hpp"

Socket* theSocketConnexion;
DataReceiver* theDataReceiver;

std::string destIp;
int destPort;

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    std::cout << "Missing IP or Port" << std::endl;
    return -1;
  }
  else
  {
    destIp = std::string(argv[1]);
    destPort = stoi(argv[2]);
  }
  
  theSocketConnexion = new Socket((char*)destIp.c_str(), destPort);
  theDataReceiver = new DataReceiver();
  
  while(1)
  {
    usleep(10000);
  }
  return 0;
}
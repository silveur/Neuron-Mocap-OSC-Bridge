#include "includes.h"
#include "socket.hpp"
#include "data.hpp"

Socket* theSocketConnexion;
DataReceiver* theDataReceiver;

int main()
{
  theSocketConnexion = new Socket(ipAddress, port);
  theDataReceiver = new DataReceiver();
  
  while(1)
  {
    usleep(10000);
  }
  return 0;
}
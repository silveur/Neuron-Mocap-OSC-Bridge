//
//  include.h
//  NeuronOSCBridge
//
//  Created by Silvere Letellier on 07/09/2016.
//  Copyright © 2016 Fede. All rights reserved.
//

#ifndef include_h
#define include_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;
#include "include/DataType.h"
#include "include/NeuronDataReader.h"

//char ipAddress[] = "10.211.55.3";
char ipAddress[] = "192.168.178.65";
int port = 7001;

struct SensorData
{
  std::string name;
  int boneIndex;
  float value;
};

#endif /* include_h */

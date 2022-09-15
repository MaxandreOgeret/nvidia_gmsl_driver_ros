// Created by Maxandre Ogeret.
// (c) 2022 University of Tartu - Autonomous Driving Lab.

#pragma once

#include <dw/core/Logger.h>
#include <ros/ros.h>

#include <iostream>
#include <string>

#include "exceptions/NvidiaGmslDriverRosFatalException.h"

dwLogCallback ros_log_wrapper();

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

using namespace std;

void Robot::RobotInit() {

  lMotorFront->RestoreFactoryDefaults();
  lMotorBack->RestoreFactoryDefaults();
  rMotorFront->RestoreFactoryDefaults();
  rMotorBack->RestoreFactoryDefaults();

  lMotorFront->SetInverted(true);
  lMotorBack->Follow(*lMotorFront, false);
  rMotorFront->SetInverted(false);
  rMotorBack->Follow(*rMotorFront, false);

  

}

  
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
// L_X = 0, L_Y = 1, R_X = 4, R_Y = 5


double dz = 0.08; // Deadzone
double x = y_j->GetY(); // Raw Y value

if (abs(x) > dz) {

  double y = (1/(1-dz)) * abs(x) + (1 - (1/(1-dz)));
  y = copysign(y, x);

  //y = y * y;

  //if (x < 0) {
    //y = -y;
  //}
  lMotorFront->Set(y);
  rMotorFront->Set(-y);

  // TODO: Invert Motors

} else {
  lMotorFront->Set(0);
  rMotorFront->Set(0);
}
}
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

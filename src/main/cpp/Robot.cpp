// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

using namespace std;

void Robot::RobotInit() {

  lMotorFront->SetInverted(false);
  lMotorBack->Follow(*lMotorFront, false);
  rMotorFront->SetInverted(false);
  rMotorBack->Follow(*rMotorFront, false);

  lMotorFront->RestoreFactoryDefaults();
  lMotorBack->RestoreFactoryDefaults();
  rMotorFront->RestoreFactoryDefaults();
  rMotorBack->RestoreFactoryDefaults();

}

  
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
// L_X = 0, L_Y = 1, R_X = 4, R_Y = 5
// GetRawAxis(1)
double dz = 0.08;
double x = y_j->GetY();
double abs_x = abs(x);

if (abs_x > dz) {
// 1/(1-dz) 1.0869 * 0.08 + (1 - (1.0869)) = 0
// 1/(1-(-0.08)) 0.9259 * -0.08 + (1 - 0.9259)

  double y = (1/(1-dz)) * abs_x + (1 - (1/(1-dz)));
  //y = y * y;
  //double y = std::copysign(y, x);

  if (x < 0) {
    y = -y;
  }
  lMotorFront->Set(y);
  rMotorFront->Set(-y);

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

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"


void Robot::RobotInit() {

  lMotorFront->SetInverted(true);
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

lMotorFront->Set(y_j->GetY());
rMotorFront->Set(y_j->GetY());

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

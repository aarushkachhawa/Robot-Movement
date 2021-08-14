// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <rev/CANSparkMax.h>



using namespace frc;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;


  // Motor IDs
  const int rMotorFrontID = 1;
  const int rMotorBackID = 2;
  const int lMotorFrontID = 3;
  const int lMotorBackID = 4;

  rev::CANSparkMax * lMotorFront = new rev::CANSparkMax(lMotorFrontID, rev::CANSparkMax::MotorType::kBrushless);
  rev::CANSparkMax * lMotorBack = new rev::CANSparkMax(lMotorBackID, rev::CANSparkMax::MotorType::kBrushless);
  rev::CANSparkMax * rMotorFront = new rev::CANSparkMax(rMotorFrontID, rev::CANSparkMax::MotorType::kBrushless);
  rev::CANSparkMax * rMotorBack = new rev::CANSparkMax(rMotorBackID, rev::CANSparkMax::MotorType::kBrushless);

  Joystick * y_j = new Joystick(0);
  Joystick * x_j = new Joystick(1);

};

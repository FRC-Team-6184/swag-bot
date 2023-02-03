#pragma once

#include "ctre/Phoenix.h"
#include "ctre/phoenix/motorcontrol/can/VictorSPX.h"
#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"
#include "frc/XboxController.h"
#include <frc/TimedRobot.h>

using ctre::phoenix::motorcontrol::can::TalonSRX;
using ctre::phoenix::motorcontrol::can::TalonFX;
using ctre::phoenix::motorcontrol::ControlMode;
using ctre::phoenix::motorcontrol::ControlMode;
using frc::StartRobot;
using frc::TimedRobot;
using frc::XboxController;

class Robot: public TimedRobot {

 public:
  enum motorControllerPort {
    frontRightPort = 14,
    backRightPort = 20,
    frontLeftPort = 13,
    backLeftPort = 41,
    shooterPort = 12, // TODO: VERIFY CAN ADDRESSES
    feederPort = 15 // TODO: VERIFY CAN ADDRESSES
  };
  enum gameControllerPort {
    driver = 0
  };

  TalonSRX frontRight{motorControllerPort::frontRightPort};
  TalonSRX backRight{motorControllerPort::backRightPort};
  TalonSRX frontLeft{motorControllerPort::frontLeftPort};
  TalonSRX backLeft{motorControllerPort::backLeftPort};
  TalonFX shooter{motorControllerPort::shooterPort};
  TalonFX feeder{motorControllerPort::feederPort};
  XboxController driverController{gameControllerPort::driver};

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

  void SimulationInit() override;
  void SimulationPeriodic() override;
  
};

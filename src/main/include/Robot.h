#pragma once

#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <frc/XboxController.h>
#include <frc/TimedRobot.h>

using ctre::phoenix::motorcontrol::ControlMode;
using ctre::phoenix::motorcontrol::can::TalonFX;
using ctre::phoenix::motorcontrol::can::TalonSRX;
using frc::StartRobot;
using frc::TimedRobot;
using frc::XboxController;
using std::string;

class Robot : public TimedRobot
{

public:
  enum motorControllerPort
  {
    frontRightPort = 1,
    backRightPort = 2,
    frontLeftPort = 3,
    backLeftPort = 4,
    feederPort = 5,  // TODO: VERIFY CAN ADDRESSES
    shooterPort = 6, // TODO: VERIFY CAN ADDRESSES
    spinnerPort = 7
  };
  enum gameControllerPort
  {
    driver = 0
  };

  TalonSRX frontRight{motorControllerPort::frontRightPort};
  TalonSRX backRight{motorControllerPort::backRightPort};
  TalonSRX frontLeft{motorControllerPort::frontLeftPort};
  TalonSRX backLeft{motorControllerPort::backLeftPort};
  VictorSPX shooter{motorControllerPort::shooterPort};
  VictorSPX feeder{motorControllerPort::feederPort};
  TalonSRX spinner{motorControllerPort::spinnerPort};
  XboxController driverXboxController{gameControllerPort::driver};

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

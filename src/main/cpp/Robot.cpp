#include <Robot.h>

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
  frontRight.SetNeutralMode(Brake);
  frontLeft.SetNeutralMode(Brake);
  backRight.SetNeutralMode(Brake);
  backLeft.SetNeutralMode(Brake);
  frontRight.Set(ControlMode::Follower, Robot::motorControllerPort::backRightPort);
  frontLeft.Set(ControlMode::Follower, Robot::motorControllerPort::backLeftPort);
  shooter.Set(ControlMode::PercentOutput, 0);
}

void Robot::TeleopPeriodic()
{
  if (driverXboxController.GetRightBumper())
  {
    speedMultiplier = TURTLE_SPEED;
  }
  else if (driverXboxController.GetLeftBumper())
  {
    speedMultiplier = TURBO_SPEED;
  }

  backRight.Set(
      ControlMode::PercentOutput,
      driverXboxController.GetRightY() * speedMultiplier);
  backLeft.Set(
      ControlMode::PercentOutput,
      -(driverXboxController.GetLeftY() * speedMultiplier));

  if (driverXboxController.GetAButton())
  {
    shooter.Set(ControlMode::PercentOutput, 0.3);
  }
  if (driverXboxController.GetBButton())
  {
    shooter.Set(ControlMode::PercentOutput, 0);
  }
  if (driverXboxController.GetRightBumper())
  {
    feeder.Set(ControlMode::PercentOutput, 1);
  }
  else
  {
    feeder.Set(ControlMode::PercentOutput, 0);
  }

  if (driverXboxController.GetXButton())
  {
    spinner.Set(ControlMode::PercentOutput, .2);
  }
  if (driverXboxController.GetYButton())
  {
    spinner.Set(ControlMode::PercentOutput, 0);
  }

  if (driverXboxController.GetLeftBumper())
  {
    feeder.Set(ControlMode::PercentOutput, -.2);
  }
}

void Robot::DisabledInit()
{
  shooter.Set(ControlMode::PercentOutput, 0);
}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic()
{
  if (driverXboxController.GetAButtonPressed())
  {
    shooter.Set(ControlMode::PercentOutput, 1);
  }
  if (driverXboxController.GetBButtonPressed())
  {
    shooter.Set(ControlMode::PercentOutput, 0);
  }
}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return StartRobot<Robot>();
}
#endif

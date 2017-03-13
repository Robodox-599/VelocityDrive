#include "RunMotor.h"

RunMotor::RunMotor(int seconds, float motorSpeed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//Requires(driveBase);

	SetTimeout(seconds);

	speed = motorSpeed;
}

// Called just before this Command runs the first time
void RunMotor::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunMotor::Execute() {

	driveBase->getLeftSpeed();
	driveBase->setLeftSpeed(speed);
	driveBase->getRightSpeed();
	driveBase->setRightSpeed(speed);

	SmartDashboard::PutNumber("LF Voltage: ", driveBase->getLeftFrontVoltage());
	SmartDashboard::PutNumber("LF Current: ", driveBase->getLeftFrontCurrent());

	SmartDashboard::PutNumber("RF Voltage: ", driveBase->getRightFrontVoltage());
	SmartDashboard::PutNumber("RF Current: ", driveBase->getRightFrontCurrent());

	SmartDashboard::PutNumber("Right Encoder: ", driveBase->getRightEncoder());
	SmartDashboard::PutNumber("Left Encoder: ", driveBase->getLeftEncoder());

	return;
}

// Make this return true when this Command no longer needs to run execute()
bool RunMotor::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void RunMotor::End() {
	driveBase->setLeftSpeed(0);
	driveBase->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunMotor::Interrupted() {
	End();
}

#ifndef DriveBase_H
#define DriveBase_H

#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "WPILib.h"
#include "../Commands/JoystickDrive.h"

class DriveBase : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	DoubleSolenoid* shifter;

public:
	DriveBase();
	void InitDefaultCommand();
	void setLeftSpeed(float speed);
	void setRightSpeed(float speed);
	int getLeftSpeed();
	int getRightSpeed();
	void shiftHighGear();
	void shiftLowGear();
	double getLeftFrontCurrent();
	double getRightFrontCurrent();
	double getLeftFrontVoltage();
	double getRightFrontVoltage();
	int getLeftEncoder();
	int getRightEncoder();

};

#endif  // DriveBase_H

#ifndef RunMotor_H
#define RunMotor_H

#include "../CommandBase.h"
#include "../Subsystems/DriveBase.h"

class RunMotor : public CommandBase {
public:
	RunMotor(int seconds, float motorSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	float speed;
};

#endif  // RunMotor_H

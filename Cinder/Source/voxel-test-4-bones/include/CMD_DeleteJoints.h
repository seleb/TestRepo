#pragma once

#include <vector>

#include "Command.h"

class Node;
class NodeHierarchical;
class NodeChild;

class CMD_DeleteJoints : public Command{
public:
	CMD_DeleteJoints(std::vector<Joint *> * joints);
	~CMD_DeleteJoints(void);

	void execute();
	void unexecute();

private:
	std::vector<Joint *> * joints;
	
	// The joints which this command is in reference to
	std::vector<Joint *> jointsForDeletion;
	// The joints which have been deleted by this command
	std::vector<Joint *> deletedJoints;
	
	// Location in jointForDeletion's parent's list of children (or the joint list if it was a root) at which jointForDeletion exists
	std::vector<unsigned long int> indices;

	// If jointForDeletion had children, a copy of them are stored here
	std::vector<std::vector<NodeChild *>> children;
};
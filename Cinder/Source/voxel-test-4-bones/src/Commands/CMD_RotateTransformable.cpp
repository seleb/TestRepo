#pragma once

#include "Commands/CMD_RotateTransformable.h"
#include "node/NodeTransformable.h"

CMD_RotateTransformable::CMD_RotateTransformable(NodeTransformable * _node, glm::quat _rotation, bool _relative, CoordinateSpace _space) :
	node(_node),
	rotation(_rotation),
	relative(_relative),
	space(_space)
{
}

bool CMD_RotateTransformable::execute(){
	if(space == kWORLD){
		warn("World-space rotation not implemented; command aborted");
		return false;
	}

	if(node != nullptr){
		if(firstRun){
			oldOrientation = node->transform->orientation;
		}

		if(relative){
			node->transform->rotate(rotation, space);
		}else{
			node->transform->orientation = rotation;
		}
	}else{
		error("Node is null");
		return false;
	}
	return true;
}

bool CMD_RotateTransformable::unexecute(){
	if(node != nullptr){
		node->transform->orientation = oldOrientation;
	}else{
		error("Node is null");
		return false;
	}
	return true;
}

CMD_RotateTransformable::~CMD_RotateTransformable(void){}
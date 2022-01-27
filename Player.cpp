#include "Player.h"

void Player::move(glm::vec3 v)
{
	position += v;
	lookingAt += v;
}

void Player::rotate()
{
	lookingAt = glm::rotate(lookingAt, .05f, upVec+position);
}

void Player::defaultPos()
{
	position =  glm::vec3(0.0f, 0.0f, 0.0f);
	lookingAt = glm::vec3(0.0f, 0.0f, -1.0f);
	upVec = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Player::Look()
{
	//gluLookAt(position.x, position.y, position.z, position.x + lookingAt.x, position.y + lookingAt.y, position.z + lookingAt.z, upVec.x, upVec.y, upVec.z);
	return glm::lookAt(position, position + lookingAt, upVec);
}

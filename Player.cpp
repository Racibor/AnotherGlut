#include "Player.h"

void Player::move(glm::vec3 v)
{
	position += v;
	lookingAt += v;
}

void Player::defaultPos()
{
	position =  glm::vec3(0.0f, 0.0f, 0.0f);
	lookingAt = glm::vec3(0.0f, 0.0f, -1.0f);
	upVec = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Player::getCameraViewMatrix()
{
	return glm::lookAt(position, position + lookingAt, upVec);
}

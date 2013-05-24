/*
 * PointLight.cpp
 *
 *  Created on: 24.09.2012
 *      Author: nopper
 */

#include "../../layer2/debug/DebugDraw.h"

#include "PointLight.h"

using namespace boost;

using namespace std;

PointLight::PointLight(const Point4& position, float constantAttenuation, float linearAttenuation, float quadraticAttenuation, const Color& ambient, const Color& diffuse,
		const Color& specular) :
		Light(ambient, diffuse, specular), constantAttenuation(constantAttenuation), linearAttenuation(linearAttenuation), quadraticAttenuation(quadraticAttenuation)
{
	setPosition(position);
}

PointLight::~PointLight()
{
}

float PointLight::getConstantAttenuation() const
{
	return constantAttenuation;
}

void PointLight::setConstantAttenuation(float constantAttenuation)
{
	this->constantAttenuation = constantAttenuation;
}

float PointLight::getLinearAttenuation() const
{
	return linearAttenuation;
}

void PointLight::setLinearAttenuation(float linearAttenuation)
{
	this->linearAttenuation = linearAttenuation;
}

float PointLight::getQuadraticAttenuation() const
{
	return quadraticAttenuation;
}

void PointLight::setQuadraticAttenuation(float quadraticAttenuation)
{
	this->quadraticAttenuation = quadraticAttenuation;
}

void PointLight::setLightProperties(uint32_t lightNumber, const ProgramSP& program) const
{
	glUniform1i(program->getUniformLocation(string(u_lightType) + to_string(lightNumber) + "]"), 1);

	glUniform4fv(program->getUniformLocation(string(u_light) + to_string(lightNumber) + u_ambientLightColor), 1, ambient.getRGBA());
	glUniform4fv(program->getUniformLocation(string(u_light) + to_string(lightNumber) + u_diffuseLightColor), 1, diffuse.getRGBA());
	glUniform4fv(program->getUniformLocation(string(u_light) + to_string(lightNumber) + u_specularLightColor), 1, specular.getRGBA());

	glUniform4fv(program->getUniformLocation(string(u_light) + to_string(lightNumber) + u_lightPosition), 1, position.getP());

	glUniform1f(program->getUniformLocation(string(u_light) + to_string(lightNumber) + u_lightConstantAttenuation), constantAttenuation);
	glUniform1f(program->getUniformLocation(string(u_light) + to_string(lightNumber) + u_lightLinearAttenuation), linearAttenuation);
	glUniform1f(program->getUniformLocation(string(u_light) + to_string(lightNumber) + u_lightQuadraticAttenuation), quadraticAttenuation);
}

void PointLight::debugDraw() const
{
	DebugDraw::drawer.drawSphere(getPosition(), Vector3(0.0f, 0.0f, 0.0f), 0.5f, Color::YELLOW);
}

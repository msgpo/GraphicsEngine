/*
 * PerlinNoise.h
 *
 *  Created on: 17.04.2013
 *      Author: nopper
 */

#ifndef PERLINNOISE_H_
#define PERLINNOISE_H_

#include "../../UsedLibs.h"

class PerlinNoise
{
	protected:

		float* data;
		boost::int32_t dataSize;

		boost::int32_t seed;

		float frequencyStart;
		float frequencyFactor;

		float amplitudeStart;
		float amplitudeFactor;

		boost::int32_t octaves;

		float minValue;
		float maxValue;

		float getRandomValue(boost::int32_t n) const;

		float getInterpolatedValue(float value0, float value1, float t) const;

	public:

		PerlinNoise(boost::int32_t seed, float frequencyStart, float frequencyFactor, float amplitudeStart, float amplitudeFactor, boost::int32_t octaves);
		virtual ~PerlinNoise();

		void freeData();

		const float* getData() const;

		boost::int32_t getDataSize() const;

		float getMinValue() const;

		float getMaxValue() const;

};

#endif /* PERLINNOISE_H_ */

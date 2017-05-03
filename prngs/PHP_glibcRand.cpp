/*
    Copyright Bishop Fox 2014

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "PHP_glibcRand.h"
#include "../ConsoleColors.h"
#include <climits>

PHP_glibcRand::PHP_glibcRand() {}

PHP_glibcRand::~PHP_glibcRand() {}

const std::string PHP_glibcRand::getName()
{
    return PHP_GLIBC_RAND;
}

uint32_t PHP_glibcRand::random()
{
    int32_t result = GlibcRand::random();
    
    RAND_RANGE(result, m_minBound, m_maxBound);

    return result;
}

void PHP_glibcRand::setBounds(uint32_t min, uint32_t max)
{
    m_minBound = min;
    m_maxBound = max;
    m_isBounded = true;
}

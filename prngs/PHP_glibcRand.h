#ifndef PHP_GLIBCRAND_H_
#define PHP_GLIBCRAND_H_

#include "GlibcRand.h"

// adapted from PHP 7.0 source code
#define RAND_RANGE(__n, __min, __max) \
    (__n) = (uint32_t) (__min) + (uint32_t) ((double) ((double) (__max) - (__min) + 1.0) * ((__n) / 2147483648.0))

static const std::string PHP_GLIBC_RAND = "php-glibc-rand";

class PHP_glibcRand: public GlibcRand
{
public:
    PHP_glibcRand();
    virtual ~PHP_glibcRand();
    
    const std::string getName(void);
    uint32_t random(void);
    void setBounds(uint32_t, uint32_t);
};

#endif /* PHP_GLIBCRAND_H_ */

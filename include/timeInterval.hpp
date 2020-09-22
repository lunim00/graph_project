#ifndef TIMEINTERVAL_HPP
#define TIMEINTERVAL_HPP

class TimeInterval
{
public:
    TimeInterval();
    TimeInterval& operator<(const TimeInterval& other) const;
};

#endif
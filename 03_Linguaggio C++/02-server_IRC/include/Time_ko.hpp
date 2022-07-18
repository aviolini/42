#pragma once
#include <cstring>
#include <ctime>
#include <iostream>

#if __APPLE__
class time_ko : public std::map<int,long>
{
public:
    long min;
    time_t used;
    struct timeval oldused;
    int *expired;

    typedef std::map<int, long>::iterator ko_iter;

    time_ko() : std::map<int,long>(), min(0), used(std::time(NULL)), expired(NULL) { };
    ~time_ko() {
        if(this->expired)
            delete [] this->expired;
    };
    struct timeval get_timeval(long usec)
    {
        struct timeval ret;
        ret.tv_sec = usec ? usec / MSEC : 0;
        ret.tv_usec = usec ? usec % MSEC : 0;
        return ret;
    }
    struct timeval* last_ko()
    {
        if (this->empty())
            return NULL;
        this->oldused = get_timeval(TIME_REFILL);
        return &this->oldused;
    }
    int* update_ko()
    {
        if (this->empty())
            return NULL;
        long passed = this->used - std::time(&this->used);
        passed *= -MSEC;
        this->expired = new int[this->size()];
        bzero(this->expired, sizeof(int)*this->size());
        int x = 0;
        for (ko_iter ko_it = this->begin(); ko_it != this->end(); ++ko_it)
        {
            if (ko_it->second == 0 || ko_it->second <= passed)
            {
                this->expired[x] = ko_it->first;
                ++x;
            }
            ko_it->second -= passed;
        }
        if (x)
            return this->expired;
        delete [] this->expired;
		this->expired = NULL;
        return NULL;
    }
};
#else
class time_ko : public std::map<int,long>
{
public:
    long min;
    struct timeval used;
    int *expired;

    typedef std::map<int, long>::iterator ko_iter;

    time_ko() : std::map<int,long>(), min(0), used(get_timeval(0)), expired(NULL) {};
    ~time_ko() {
        if(this->expired)
            delete [] this->expired;
    };
    struct timeval get_timeval(long usec)
    {
        struct timeval ret;
        ret.tv_sec = usec ? usec / MSEC : 0;
        ret.tv_usec = usec ? usec % MSEC : 0;
        return ret;
    }
    long get_long(struct timeval tval)
    {
        return tval.tv_sec * MSEC + tval.tv_usec;
    }
    struct timeval* last_ko()
    {
        if (this->empty())
            return NULL;
        ko_iter ko_it = this->begin();
        this->min = ko_it->second;
        for (;ko_it != this->end(); ++ko_it)
        {
            if (ko_it->second < min)
                min = ko_it->second;
        }
        this->used = get_timeval(min);
        return &this->used;
    }
    int* update_ko()
    {
        if (this->empty())
            return NULL;
        long passed = min - this->get_long(this->used);
        this->expired = new int[this->size()];
        bzero(this->expired, sizeof(int)*this->size());
        int x = 0;
        for (ko_iter ko_it = this->begin(); ko_it != this->end(); ++ko_it)
        {
            if (ko_it->second == 0 || ko_it->second < passed)
            {
                this->expired[x] = ko_it->first;
                ++x;
            }
            ko_it->second -= passed;
        }
        if (x)
            return this->expired;
        delete [] this->expired;
		this->expired = NULL;
        return NULL;
    }
};
#endif
#ifndef CLOCK_H
#define CLOCK_H


class Clock{
    private:
        std::string name;
    public:
        Clock(std::string n);
        void operator()();
};

#endif
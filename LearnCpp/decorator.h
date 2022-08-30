#pragma once

class decfoo
{
public:
    virtual void do_work() = 0;
};

class decfoo_concrete : public decfoo
{
public:
    virtual void do_work() override {}
};

class decfoo_decorator : public decfoo
{
public:
    decfoo_decorator(decfoo& f)
        : f(f)
    {}

    virtual void do_work() override
    {
        //decoration code
        f.do_work();
    }

private:
    decfoo& f;
};

void decbar(decfoo& f)
{
    f.do_work();
}
